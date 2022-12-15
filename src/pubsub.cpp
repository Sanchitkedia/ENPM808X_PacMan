
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "../include/pubsub.hpp"
#include "../include/trajectory.hpp"

using std::placeholders::_1;
using std::cout;
using std::cin;
using std::endl;

void RoomBa::subscribe_callback(const ODOM &msg) {
    pose.first = msg.pose.pose.position.x;
    pose.second = msg.pose.pose.position.y;
    theta = asin(msg.pose.pose.orientation.z) * 2;
}

void RoomBa::move(double linear, double angular)
{
    geometry_msgs::msg::Twist msg;
    msg.linear.x = linear;
    msg.angular.z = angular;
    publisher_velocity->publish(msg);
}

void RoomBa::stop()
{
    geometry_msgs::msg::Twist cmd_vel_msg;
    cmd_vel_msg.linear.x = 0;
    cmd_vel_msg.angular.z = 0;
    publisher_velocity ->publish(cmd_vel_msg);
}

void RoomBa::process_callback()
{
    std::pair<double, double> goal{goal_x, goal_y};
    double K_linear = 10;
    double K_angular = 4.0;
    double distance = abs(sqrt(pow((goal_x-(pose.first)), 2) + pow((goal_y-(pose.second)), 2)));
    double linear_speed = distance * K_linear;
    double desired_angle_goal = atan2(goal_y-pose.second, goal_x-pose.first);
    double angular_speed = (desired_angle_goal-theta)*K_angular;

    move(linear_speed, angular_speed);

    if (distance < 0.1){
        stop();
        RCLCPP_INFO(this->get_logger(), "I have reached the goal");
    }
}
