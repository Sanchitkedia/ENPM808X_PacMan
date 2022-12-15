#ifndef ENPM808X_PACMAN_INCLUDE_PUBSUB_HPP_
#define ENPM808X_PACMAN_INCLUDE_PUBSUB_HPP_


#include <geometry_msgs/msg/twist.hpp>
#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <string>
#include <memory>
#include <chrono>
#include <vector>
#include <iostream>

using std::placeholders::_1;
using namespace std::chrono_literals;

using TWIST = geometry_msgs::msg::Twist;
using ODOM = nav_msgs::msg::Odometry;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class RoomBa : public rclcpp::Node {
 public:

  RoomBa(std::string node_name,std::string robot_name) : Node(node_name),robot_ns{robot_name},goal_x{0.0},goal_y{0.0}{

    callback_grp = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

    auto cmd_vel_topic = "/" + robot_ns + "/cmd_vel";
    auto pose_topic = "/" + robot_ns + "/odom";

    // creates publisher to publish /cmd_vel topic
    publisher_velocity = this->create_publisher<TWIST> (cmd_vel_topic, 1);

    auto subCallback0 = std::bind(&RoomBa::subscribe_callback, this, _1);
    subscription_pose = this->create_subscription<ODOM>(pose_topic, 1, subCallback0);

    auto processCallback = std::bind(&RoomBa::process_callback, this);
    timer_ = this->create_wall_timer(100ms, processCallback,callback_grp);
  }

  void set_goal(double x, double y) {
        goal_x = x;
        goal_y = y;
        RCLCPP_INFO_STREAM(this->get_logger(), "Going to goal: [" << goal_x << "," << goal_y << "]");
  }

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
  void subscribe_callback(const ODOM &msg);
  void process_callback();
  void move(double linear, double angular);

};

#endif   // ENPM808X_PACMAN_INCLUDE_PUBSUB_HPP_

