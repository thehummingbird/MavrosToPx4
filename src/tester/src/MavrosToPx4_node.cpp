
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>

#include <nav_msgs/Odometry.h>

bool OffboardandArmed = false; //flag to check drone's tatus

mavros_msgs::State current_state;

ros::Publisher vio_pub; //vio data publisher, sends data on /mavros/odometry/out

nav_msgs::Odometry pubmsg; 

//callback to check drone's current state
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

//callback to receive rosbag data continuously on topic "/vio_odom"
void vio_cb(const nav_msgs::Odometry::ConstPtr& msg){
    
    //publish data to "/mavros/odometry/out" if drone is armed and is in offboard flight mode
    if(((current_state.mode == "OFFBOARD") && (current_state.armed)) || OffboardandArmed)
    {
      OffboardandArmed = true;
      pubmsg.header = msg->header;
      pubmsg.pose = msg->pose;
      pubmsg.twist = msg->twist;
      pubmsg.child_frame_id = "base_link";
      pubmsg.header.frame_id = "map";
      vio_pub.publish(pubmsg);
      ROS_INFO("Publishing vio odom to /mavros/odometry/out\n");
    }
}

int main(int argc, char **argv)
{
    //init and node handler for node "MavrosToPx4_node"
    ros::init(argc, argv, "MavrosToPx4_node");
    ros::NodeHandle nh;

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>("mavros/state", 10, state_cb);                     //subscriber to check the current state
    ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>("mavros/setpoint_position/local", 10);  //publisher to send out initial setpoints until the drone is in offboard mode and armed

    ros::Subscriber vio_sub = nh.subscribe<nav_msgs::Odometry>("/vio_odom",10,vio_cb);                              // subscriber to receive rosbag data continuously published by vio_pub_node

    vio_pub = nh.advertise<nav_msgs::Odometry>("/mavros/odometry/out", 10);                                         //publisher to send odom data to FCU using /mavros/odometry/out

    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>("mavros/cmd/arming");             //service clients to arm and set offboard mode respectively
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("mavros/set_mode");

    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);
    
    // wait for FCU connection
    while(ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    geometry_msgs::PoseStamped pose;
    pose.pose.position.x = 0;
    pose.pose.position.y = 0;
    pose.pose.position.z = 2;

    //send a few setpoints before starting
    for(int i = 100; ros::ok() && i > 0; --i){
        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }

    mavros_msgs::SetMode offb_set_mode;
    offb_set_mode.request.custom_mode = "OFFBOARD";

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();

    //set offboard mode and arm the drone
    while((current_state.mode != "OFFBOARD")||(!current_state.armed)){
        if( current_state.mode != "OFFBOARD" &&
            (ros::Time::now() - last_request > ros::Duration(5.0))){
            if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.mode_sent){
                ROS_INFO("Offboard enabled");
            }
            last_request = ros::Time::now();
        } else {
            if( !current_state.armed &&
                (ros::Time::now() - last_request > ros::Duration(5.0))){
                if( arming_client.call(arm_cmd) &&
                    arm_cmd.response.success){
                    ROS_INFO("Vehicle armed");
                }
                last_request = ros::Time::now();
            }
        }

        local_pos_pub.publish(pose);

        ros::spinOnce();
        rate.sleep();
    }
    
    //offboard + arming achieved, spin now (odom data is now continuously published on /mavros/odometry/out)
    ros::spin();
    return 0;
}
