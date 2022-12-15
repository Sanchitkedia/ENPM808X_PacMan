
#include <string>
#include <memory>
#include <chrono>
#include <vector>
#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include "../include/master.hpp"
#include "../include/trajectory.hpp"

using std::placeholders::_1;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using namespace std::chrono_literals;

using TWIST = geometry_msgs::msg::Twist;
using ODOM = nav_msgs::msg::Odometry;
using RCL_NODE_PTR = std::shared_ptr<rclcpp::Node>;


Master::Master(std::vector<std::shared_ptr<RoomBa>> const &robot_array):Node("master_node") {
this->robot_array=robot_array;
auto processCallback = std::bind(&Master::process_callback, this);
this->timer_ = this->create_wall_timer(100ms, processCallback);
this -> traj();
}

void Master::process_callback() {}

void Master::traj() {
  Trajectory trajectory;
  trajectory.setCenter(5, 0);
  trajectory.setNumberOfRobots(24);
  vector<vector<double>> circleTrajectory = trajectory.circleTrajectory();
  vector<vector<double>> squareTrajectory = trajectory.squareTrajectory();
  vector<vector<double>> triangleTrajectory = trajectory.triangleTrajectory();

 int choice;

  cout << "Enter which trajectory you want to follow: 1. Circle 2. Square 3. Triangle" << endl;
  cin >> choice;
    switch (choice) {
        case 1:
            cout << "Executing Circular Formation" << endl;
            for (int i = 0; i < static_cast<int>(circleTrajectory.size()); i++){
                this->robot_array[i]->set_goal(circleTrajectory[i][0], circleTrajectory[i][1]);
            }
            break;
        case 2:
            cout << "Executing Square Formation" << endl;
            for (int i = 0; i < static_cast<int>(squareTrajectory.size()); i++){
                this->robot_array[i]->set_goal(squareTrajectory[i][0], squareTrajectory[i][1]);
            }
            break;
        case 3:
            cout << "Executing Triangular Formation" << endl;
            for (int i = 0; i < static_cast<int>(triangleTrajectory.size()); i++){
                this->robot_array[i]->set_goal(triangleTrajectory[i][0], triangleTrajectory[i][1]);
            }
            break;  
        default:
            cout << "Invalid choice" << endl;
            break;
    }
}
