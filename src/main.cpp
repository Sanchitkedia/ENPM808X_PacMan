
#include <cmath>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include "../include/pubsub.hpp"
#include "../include/master.hpp"
#include "../include/trajectory.hpp"


using std::cout;
using std::endl;
using std::vector;

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);
  rclcpp::executors::MultiThreadedExecutor exec;
  std::vector<std::shared_ptr<RoomBa>>robot_array;
  for (int i = 0 ; i < 24 ; i++) {
    auto r_namespace = "tb"+std::to_string(i);
    auto nodename = "tb"+std::to_string(i) + "_node";
    auto robot = std::make_shared<RoomBa>(nodename, r_namespace);
    exec.add_node(robot);
    robot_array.push_back(robot);
  }
  
  auto node = std::make_shared<Master>(robot_array);
  exec.add_node(node);
  exec.spin();
  rclcpp::shutdown();
  return 0;
}
