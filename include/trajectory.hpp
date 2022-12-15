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
 * @file trajectory.hpp
 * @author Driver: Sanchit Kedia (sanchit@terpmail.umd.edu) Navigator: Tanmay
 * Haldankar (tanmayh@umd.edu)
 * @brief  Header file for the trajectory class
 * @version 0.1
 * @date 2022-12-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef INCLUDE_TRAJECTORY_HPP_
#define INCLUDE_TRAJECTORY_HPP_

#include <cmath>
#include <iostream>
#include <vector>
/**
 * @brief Class for the trajectory
 *
 */
class Trajectory {
 private:
  double xCenter;
  double yCenter;
  double radius;
  double sideLength;
  double numberOfRobots;
  double circumRadius;

 public:
  /**
   * @brief Construct a new Trajectory object and initialize the variables
   *
   */
  Trajectory();
  /**
   * @brief Set the Center of the object
   *
   * @param x  x coordinate of the center
   * @param y  y coordinate of the center
   */
  void setCenter(double x, double y);
  /**
   * @brief Set the Number Of Robots object
   *
   * @param n  number of robots
   */
  void setNumberOfRobots(double n);
  /**
   * @brief Get the Number Of Robots object
   *
   * @return int number of robots
   */
  int getNumberOfRobots();
  /**
   * @brief Function to calculate the circle shape trajectory
   *
   * @return std::vector<std::vector<double>>  vector of vectors containing the
   * x and y coordinates of the robots
   */
  std::vector<std::vector<double>> circleTrajectory();
  /**
   * @brief Function to calculate the square shape trajectory
   *
   * @return std::vector<std::vector<double>>  vector of vectors containing the
   * x and y coordinates of the robots
   */
  std::vector<std::vector<double>> squareTrajectory();
  /**
   * @brief Function to calculate the triangle shape trajectory
   *
   * @return std::vector<std::vector<double>>  vector of vectors containing the
   * x and y coordinates of the robots
   */
  std::vector<std::vector<double>> triangleTrajectory();
};

#endif  // INCLUDE_TRAJECTORY_HPP_
