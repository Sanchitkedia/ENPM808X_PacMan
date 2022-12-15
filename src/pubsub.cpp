/******************************************************************************
  *MIT License

  *Copyright (c) 2022 Qamar Syed, Sanchit Kedia, Tanmay Haldankar

  *Permission is hereby granted, free of charge, to any person obtaining a copy
  *of this software and associated documentation files (the "Software"), to deal
  *in the Software without restriction, including without limitation the rights
  *to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  *copies of the Software, and to permit persons to whom the Software is
  *furnished to do so, subject to the following conditions:

  *The above copyright notice and this permission notice shall be included in
  all *copies or substantial portions of the Software.

  *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  *SOFTWARE.
  ******************************************************************************/
/**
 * @file pubsub.cpp
 * @author Driver: Tanmay Haldankar (tanmayh@umd.edu)  Navigator: Sanchit Kedia
 * (sanchit@terpmail.umd.edu)
 * @brief  RoomBa class for the project which creates a node and publishes and
 * subscribes to the required topics based on the robot number and namespace
 * @version 0.2
 * @date 2022-12-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/pubsub.hpp"
#include "../include/trajectory.hpp"
#include <std_msgs/msg/string.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::placeholders::_1;

void RoomBa::subscribe_callback(const ODOM &msg) {
  pose.first = msg.pose.pose.position.x;
  pose.second = msg.pose.pose.position.y;
  theta = asin(msg.pose.pose.orientation.z) * 2;
}

void RoomBa::move(double linear, double angular) {
  geometry_msgs::msg::Twist msg;
  msg.linear.x = linear;
  msg.angular.z = angular;
  publisher_velocity->publish(msg);
}

void RoomBa::stop() {
  geometry_msgs::msg::Twist cmd_vel_msg;
  cmd_vel_msg.linear.x = 0;
  cmd_vel_msg.angular.z = 0;
  publisher_velocity->publish(cmd_vel_msg);
}

void RoomBa::process_callback() {
  std::pair<double, double> goal{goal_x, goal_y};
  double K_linear = 0.1;
  double K_angular = 1.0;
  double distance = abs(
      sqrt(pow((goal_x - (pose.first)), 2) + pow((goal_y - (pose.second)), 2)));
  double linear_speed = distance * K_linear;
  double desired_angle_goal = atan2(goal_y - pose.second, goal_x - pose.first);
  double angular_speed = (desired_angle_goal - theta) * K_angular;

  move(linear_speed, angular_speed);

  if (distance < 0.1) {
    stop();
    RCLCPP_INFO(this->get_logger(), "I have reached the goal");
  }
}
