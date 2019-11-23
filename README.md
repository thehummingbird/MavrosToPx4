# MavrosToPx4
This task aims at receiving odometry data from a vio sensor (rosbag in our case) and sending it to px4 using MAVROS. To do this, we use an iris quadcopter in gazebo controlled by PX4 firmware. 

Process-
1. I started off by reading up on MAVROS, px4 and eventually establishing a connection between them. Px4 dev guide (https://dev.px4.io/v1.9.0/en/) and mavros wiki (http://wiki.ros.org/mavros) were the major sources for this step
2. After reading up on these, I set up MAVROS package in ROS along with px4 firmware. To esablish and test mavros-px4 connection, I then ran a simple simulation where I control iris in the following sequence - change to offboard mode, arm and fly using local setpoints  
3. Next, I wrote "tester" package with 2 nodes-  
   **a. MavrosToPx4_node -** This node changes the vehicle's mode to offboard and arms it. Before sending odom data, local setpoint data is continuously sent until the vehicle is armed. Once armed, the node sends odom data on "mavros/odometry/out". Source of this odometry data - "vio_odom" topic   
   **b. vio_pub_node -** This node opens the rosbag file and CONTINUOUSLY publishes odometry data on topic "vio_odom"  
4. Currently, this node is able to change to offboard mode, arm and fly iris using local setpoints, but odom data sent on "/mavros/odometry/out" does not lead to any change. If it succeeded, I expected a feedback from FCU on topic "/mavros/local_position/odom" reflecting sent odometry.  

Thus, this needs to be fixed.
