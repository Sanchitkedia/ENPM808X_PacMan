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
 * @file pubsub.hpp
 * @author Driver: Sanchit Kedia (sanchit@terpmail.umd.edu) Navigator: Tanmay
 * Haldankar (tanmayh@umd.edu)
 * @brief  Header file for the pubsub class
 * @version 0.1
 * @date 2022-12-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef INCLUDE_PUBSUB_HPP_
#define INCLUDE_PUBSUB_HPP_

#include <string>
#include <utility>
#include <chrono>
#include <iostream>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <rclcpp/rclcpp.hpp>


using std::placeholders::_1;
using namespace std::chrono_literals;

using TWIST = geometry_msgs::msg::Twist;
using ODOM = nav_msgs::msg::Odometry;

/**
 * @brief Class for the pubsub node
 *
 */
class RoomBa : public rclcpp::Node {
 public:
  /**
   * @brief Construct a new RoomBa object
   *
   * @param node_name  name of the node
   * @param robot_name  name of the robot
   */
  RoomBa(std::string const &node_name, std::string const &robot_name)
      : Node(node_name), robot_ns{robot_name}, goal_x{0.0}, goal_y{0.0} {
    callback_grp = this->create_callback_group(
        rclcpp::CallbackGroupType::MutuallyExclusive);

    auto cmd_vel_topic = "/" + robot_ns + "/cmd_vel";
    auto pose_topic = "/" + robot_ns + "/odom";

    // creates publisher to publish /cmd_vel topic
    publisher_velocity = this->create_publisher<TWIST>(cmd_vel_topic, 1);

    auto subCallback0 = std::bind(&RoomBa::subscribe_callback, this, _1);
    subscription_pose =
        this->create_subscription<ODOM>(pose_topic, 1, subCallback0);

    auto processCallback = std::bind(&RoomBa::process_callback, this);
    timer_ = this->create_wall_timer(100ms, processCallback, callback_grp);
  }
  /**
   * @brief Set the goal object
   *
   * @param x  x coordinate of the goal
   * @param y  y coordinate of the goal
   */
  void set_goal(double x, double y) {
    goal_x = x;
    goal_y = y;
    RCLCPP_INFO_STREAM(this->get_logger(),
                       "Going to goal: [" << goal_x << "," << goal_y << "]");
  }
  /**
   * @brief Stop the robot by publishing 0 velocity
   *
   */
  void stop();

 private:
  std::string robot_ns;
  double goal_x;
  double goal_y;

  rclcpp::CallbackGroup::SharedPtr callback_grp;
  rclcpp::Subscription<ODOM>::SharedPtr subscription_pose;
  rclcpp::Publisher<TWIST>::SharedPtr publisher_velocity;
  rclcpp::TimerBase::SharedPtr timer_;
  std::pair<double, double> pose;
  double theta;
  /**
   * @brief Subscribe callback function to get the pose of the robot
   *
   * @param msg  message of type ODOM
   */
  void subscribe_callback(const ODOM &msg);
  /**
   * @brief Process callback function to publish velocity to the robot
   *
   */
  void process_callback();
  /**
   * @brief Move the robot by publishing velocity
   *
   * @param linear  linear velocity
   * @param angular  angular velocity
   */
  void move(double linear, double angular);
};

#endif  // INCLUDE_PUBSUB_HPP_
