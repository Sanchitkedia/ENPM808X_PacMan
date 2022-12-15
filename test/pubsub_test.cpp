#include <gtest/gtest.h>
#include <stdlib.h>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include "std_msgs/msg/string.hpp"
#include "../include/pubsub.hpp"


class TestPublisher : public testing::Test {
 protected:
  rclcpp::Node::SharedPtr node_;
};

TEST_F(TestPublisher, test_num_publishers) {
  node_ = rclcpp::Node::make_shared("test_pub");
  auto test_pub = node_->create_publisher<std_msgs::msg::String>
                    ("I_am_Publishing", 10.0);

  auto pub = node_->count_publishers("I_am_Publishing");
  EXPECT_EQ(0, static_cast<int>(pub));
}