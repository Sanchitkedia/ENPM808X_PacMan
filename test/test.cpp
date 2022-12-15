#include <gtest/gtest.h>
#include <memory>
#include <utility>
#include <vector>

# include "../include/trajectory.hpp"

TEST(AlgorithmTest,CircleTest) {
  Trajectory traj;
  traj.setCenter(0,0);
  traj.setNumberOfRobots(24);
  std::vector<std::vector<double>> circle = traj.circleTrajectory();
  EXPECT_EQ(circle.size(),24);
}

TEST(AlgorithmTest,SquareTest) {
  Trajectory traj;
  traj.setCenter(0,0);
  traj.setNumberOfRobots(24);
  std::vector<std::vector<double>> square = traj.squareTrajectory();
  EXPECT_EQ(square.size(),24);
}

TEST(AlgorithmTest,TriangleTest) {
  Trajectory traj;
  traj.setCenter(0,0);
  traj.setNumberOfRobots(24);
  std::vector<std::vector<double>> triangle = traj.triangleTrajectory();
  EXPECT_EQ(triangle.size(),24);
}
