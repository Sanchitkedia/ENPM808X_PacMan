/******************************************************************************
  *MIT License

  *Copyright (c) 2022 Qamar Syed, Sanchit Kedia, Tanmay Haldankar

  *Permission is hereby granted, free of charge, to any person obtaining a copy
  *of this software and associated documentation files (the "Software"), to deal
  *in the Software without restriction, including without limitation the rights
  *to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  *copies of the Software, and to permit persons to whom the Software is
  *furnished to do so, subject to the following conditions:

  *The above copyright notice and this permission notice shall be included in all
  *copies or substantial portions of the Software.

  *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  *SOFTWARE.
  ******************************************************************************/
/**
 * @file pubsub_test.cpp
 * @author Driver: Sanchit Kedia (sanchit@terpmail.umd.edu) Navigator: Tanmay Haldankar (tanmayh@umd.edu)
 * @brief  Test file for the project which tests the publisher and subscriber
 * @version 0.1
 * @date 2022-12-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <gtest/gtest.h>
#include <stdlib.h>
#include "std_msgs/msg/string.hpp"
#include "../include/pubsub.hpp"

/**
 * @brief Test fixture class for the project
 * 
 */
class TestPubSub : public testing::Test {
 protected:
  rclcpp::Node::SharedPtr node_;
};
/**
 * @brief Construct a new test f object to test the publisher
 * 
 */
TEST_F(TestPubSub, test_num_publishers) {
  node_ = rclcpp::Node::make_shared("test_pub");
  auto test_pub = node_->create_publisher<std_msgs::msg::String>
                    ("I_am_Publishing", 10.0);
    
  auto pub = node_->count_publishers("I_am_Publishing");
  EXPECT_EQ(1, static_cast<int>(pub));
}
/**
 * @brief Construct a new test f object to test the subscriber
 * 
 */
TEST_F(TestPubSub, test_num_subscribers) {
  node_ = rclcpp::Node::make_shared("test_sub");
  auto test_sub = node_->create_subscription<std_msgs::msg::String>("I_am_Publishing", 10.0,
    [](const std_msgs::msg::String::SharedPtr msg) {
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "I heard: '%s'", msg->data.c_str());
    });

  auto sub = node_->count_subscribers("I_am_Subscribing");
  EXPECT_EQ(0, static_cast<int>(sub));
}