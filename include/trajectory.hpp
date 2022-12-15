
#ifndef ENPM808X_PACMAN_INCLUDE_TRAJECTORY_HPP_
#define ENPM808X_PACMAN_INCLUDE_TRAJECTORY_HPP_

#include <cmath>
#include <iostream>
#include <vector>

class Trajectory {
 private:
    double xCenter;
    double yCenter;
    double radius;
    double numberOfRobots;

 public:
    Trajectory();
    void setCenter(double x, double y);
    void setNumberOfRobots(double n);
    int getNumberOfRobots();

    std::vector<std::vector<double>> circleTrajectory();
};

#endif   // ENPM808X_PACMAN_INCLUDE_TRAJECTORY_HPP_
