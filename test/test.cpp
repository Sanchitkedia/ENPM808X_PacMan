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
 * @file test.cpp
 * @author Driver: Sanchit Kedia (sanchit@terpmail.umd.edu) Navigator: Tanmay Haldankar (tanmayh@umd.edu)
 * @brief  Test file for the project to test the algorithms
 * @version 0.1
 * @date 2022-12-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <gtest/gtest.h>
#include <memory>
#include <utility>

# include "../include/trajectory.hpp"

/**
 * @brief Construct a new TEST object for the circle trajectory
 * 
 */
TEST(AlgorithmTest,CircleTest) {
  Trajectory traj;
  traj.setCenter(0,0);
  traj.setNumberOfRobots(24);
  std::vector<std::vector<double>> circle = traj.circleTrajectory();
  EXPECT_EQ(circle.size(),24);
}
/**
 * @brief Construct a new TEST object for the square trajectory
 * 
 */
TEST(AlgorithmTest,SquareTest) {
  Trajectory traj;
  traj.setCenter(0,0);
  traj.setNumberOfRobots(24);
  std::vector<std::vector<double>> square = traj.squareTrajectory();
  EXPECT_EQ(square.size(),24);
}
/**
 * @brief Construct a new TEST object for the triangle trajectory
 * 
 */
TEST(AlgorithmTest,TriangleTest) {
  Trajectory traj;
  traj.setCenter(0,0);
  traj.setNumberOfRobots(24);
  std::vector<std::vector<double>> triangle = traj.triangleTrajectory();
  EXPECT_EQ(triangle.size(),24);
}