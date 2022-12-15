#ifndef ENPM808X_PACMAN_INCLUDE_MASTER_HPP_
#define ENPM808X_PACMAN_INCLUDE_MASTER_HPP_

#include <vector>
#include <memory>
#include <chrono>
#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include "../include/pubsub.hpp"

using TWIST = geometry_msgs::msg::Twist;
using ODOM = nav_msgs::msg::Odometry;

class Master: public rclcpp::Node {
 private:
    rclcpp::TimerBase::SharedPtr  timer_;
    rclcpp::Publisher<TWIST>::SharedPtr publisher_;
    std::vector<std::shared_ptr<RoomBa>> robot_array;

 public:
    Master(std::vector<std::shared_ptr<RoomBa>> const &robot_array);
    void process_callback();
    void traj();
};

#endif  // ENPM808X_PACMAN_INCLUDE_MASTER_HPP_