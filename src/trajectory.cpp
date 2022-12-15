
#include "../include/trajectory.hpp"

using std::vector;

Trajectory::Trajectory() {
  xCenter = 0;
  yCenter = 0;
  radius = 9.6;
}

void Trajectory::setCenter(double x, double y) {
  xCenter = x;
  yCenter = y;
}

void Trajectory::setNumberOfRobots(double n) { numberOfRobots = n; }

int Trajectory::getNumberOfRobots() { return numberOfRobots; }

vector<vector<double>> Trajectory::circleTrajectory() {
  vector<vector<double>> circleTrajectory(numberOfRobots, vector<double>(2, 0));
  double angle = 0;
  double angleIncrement = 2 * M_PI / numberOfRobots;
  for (int i = 0; i < numberOfRobots; i++) {
    circleTrajectory[i][0] = xCenter + radius * cos(angle);
    circleTrajectory[i][1] = yCenter + radius * sin(angle);
    angle += angleIncrement;
  }
  return circleTrajectory;
}
