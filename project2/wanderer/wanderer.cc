#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>

double front_dist;

void laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
  front_dist = DBL_MAX;
  for( int i = 0; i < msg->ranges.size(); i++ )
  {
    float angle = msg->angle_min + i*msg->angle_increment;
    double xdist = msg->ranges[i] * sin(angle);
    double ydist = msg->ranges[i] * cos(angle);

  /*********************************/
    // place your code here

  /*********************************/
  }
}

int main( int argc, char* argv[] )
{
  ros::init(argc,argv,"wanderer");
  ros::NodeHandle nh;
  ros::Rate loop_rate(10);

  ros::Subscriber laser_sub = nh.subscribe("/base_scan", 1000, laserCallback);
  ros::Publisher cmd_vel = nh.advertise<geometry_msgs::Twist>("/cmd_vel",1000);
  geometry_msgs::Twist cmd_vel_msg;
  double des_vel = 1.0;

  while( ros::ok() )
  {
    double lvel = des_vel;

  /***************************************/
    //place your code here

  /***************************************/

    cmd_vel_msg.linear.x = lvel;
    cmd_vel.publish(cmd_vel_msg);
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
