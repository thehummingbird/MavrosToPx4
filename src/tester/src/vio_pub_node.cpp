#include <ros/ros.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <std_msgs/String.h>
#include <nav_msgs/Odometry.h>

#define foreach BOOST_FOREACH


int main(int argc, char** argv)
{
  ros::init(argc,argv,"vio_pub_node");
  ros::NodeHandle n;
  ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("vio_odom", 50);
  ros::Rate loop_rate(1);

  rosbag::Bag bag;
  bag.open("/home/sharad/catkin_ws/src/tester/src/Vimaan_Autonomy_Task1.bag", rosbag::bagmode::Read); //reading rosbag

  std::vector<std::string> topics;

  topics.push_back("/odometry/odom");
  ros::Duration(3).sleep();

//publishing data continuously on "/vio_odom"
  while(ros::ok())
  {
  rosbag::View view(bag, rosbag::TopicQuery(topics));

  foreach(rosbag::MessageInstance const m, view)
  {
    const std::string& topic_name = m.getTopic();

   nav_msgs::Odometry::ConstPtr i = m.instantiate<nav_msgs::Odometry>();
    if (i != NULL)
        odom_pub.publish(i);
  }

  ros::spinOnce();
  loop_rate.sleep();

  }
 
  return 0;
}
