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
 * @file master.cpp
 * @author Driver: Sanchit Kedia (sanchit@terpmail.umd.edu) Navigator: Tanmay
 * Haldankar (tanmayh@umd.edu)
 * @brief  Master class for the project which creates a master node and executes
 * the trajectory algorithm
 * @version 0.1
 * @date 2022-12-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/master.hpp"
#include "../include/trajectory.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::placeholders::_1;
using namespace std::chrono_literals;

using TWIST = geometry_msgs::msg::Twist;
using ODOM = nav_msgs::msg::Odometry;
using RCL_NODE_PTR = std::shared_ptr<rclcpp::Node>;

Master::Master(std::vector<std::shared_ptr<RoomBa>> const &robot_array)
    : Node("master_node") {
  this->robot_array = robot_array;
  auto processCallback = std::bind(&Master::process_callback, this);
  this->timer_ = this->create_wall_timer(100ms, processCallback);
  this->traj();
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

  cout << "Enter which trajectory you want to follow: 1. Circle 2. Square 3. "
          "Triangle"
       << endl;
  cin >> choice;
  switch (choice) {
  case 1:
    cout << "Executing Circular Formation" << endl;
    for (int i = 0; i < static_cast<int>(circleTrajectory.size()); i++) {
      this->robot_array[i]->set_goal(circleTrajectory[i][0],
                                     circleTrajectory[i][1]);
    }
    break;
  case 2:
    cout << "Executing Square Formation" << endl;
    for (int i = 0; i < static_cast<int>(squareTrajectory.size()); i++) {
      this->robot_array[i]->set_goal(squareTrajectory[i][0],
                                     squareTrajectory[i][1]);
    }
    break;
  case 3:
    cout << "Executing Triangular Formation" << endl;
    for (int i = 0; i < static_cast<int>(triangleTrajectory.size()); i++) {
      this->robot_array[i]->set_goal(triangleTrajectory[i][0],
                                     triangleTrajectory[i][1]);
    }
    break;
  default:
    cout << "Invalid choice" << endl;
    break;
  }
}
