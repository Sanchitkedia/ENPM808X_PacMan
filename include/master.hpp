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
 * @file master.hpp
 * @author Driver: Sanchit Kedia (sanchit@terpmail.umd.edu) Navigator: Tanmay
 * Haldankar (tanmayh@umd.edu)
 * @brief  Master class to control the robots
 * @version 0.1
 * @date 2022-12-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef INCLUDE_MASTER_HPP_
#define INCLUDE_MASTER_HPP_

#include <vector>
#include <memory>
#include "../include/pubsub.hpp"

using TWIST = geometry_msgs::msg::Twist;
using ODOM = nav_msgs::msg::Odometry;
/**
 * @brief Master class to control the robots and spawn nodes
 *
 */
class Master : public rclcpp::Node {
 private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<TWIST>::SharedPtr publisher_;
  std::vector<std::shared_ptr<RoomBa>> robot_array;

 public:
  /**
   * @brief Construct a new Master object
   *
   * @param robot_array  Vector of robot objects
   */
  explicit Master(std::vector<std::shared_ptr<RoomBa>> const &robot_array);
  /**
   * @brief Empty function to be called by publisher
   *
   */
  void process_callback();
  /**
   * @brief Function to select the robot trajectory to be followed and call the
   * respective function
   *
   */
  void traj();
};

#endif  // INCLUDE_MASTER_HPP_
