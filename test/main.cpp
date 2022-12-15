
#include <gtest/gtest.h>
#include <rclcpp/rclcpp.hpp>

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  ::testing::InitGoogleTest(&argc, argv);
  int result = RUN_ALL_TESTS();
  std::cout << "DONE SHUTTING DOWN" << std::endl;
  rclcpp::shutdown();
  return result;
}