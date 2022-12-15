
#include "../include/trajectory.hpp"

using std::vector;

Trajectory::Trajectory() {
  xCenter = 0;
  yCenter = 0;
  radius = 9.6;
  circumRadius = 9.6;
  sideLength = 9.6;
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

vector<vector<double>> Trajectory::squareTrajectory() {
  vector<vector<double>> squareTrajectory(numberOfRobots, vector<double>(2, 0));
  double x = xCenter - sideLength / 2;
  double y = yCenter - sideLength / 2;
  for (int i = 0; i < numberOfRobots; i++) {
    if (i < numberOfRobots / 4) {
      x = x + sideLength / (numberOfRobots / 4);
    } else if (i < numberOfRobots / 2) {
      y = y + sideLength / (numberOfRobots / 4);
    } else if (i < 3 * numberOfRobots / 4) {
      x = x - sideLength / (numberOfRobots / 4);
    } else {
      y = y - sideLength / (numberOfRobots / 4);
    }
    squareTrajectory[i][0] = x;
    squareTrajectory[i][1] = y;
  }
  return squareTrajectory;
}

vector<vector<double>> Trajectory::triangleTrajectory() {
  vector<vector<double>> triangleTrajectory(numberOfRobots,
                                            vector<double>(2, 0));
  double x = xCenter - circumRadius;
  double y = yCenter + (3 * circumRadius / 2 - circumRadius);
  for (int i = 0; i < numberOfRobots; i++) {
    if (i < numberOfRobots / 3) {
      x = x + circumRadius / (numberOfRobots / 3);
      y = y - circumRadius / (numberOfRobots / 3);
    } else if (i < 2 * numberOfRobots / 3) {
      x = x + circumRadius / (numberOfRobots / 3);
      y = y + circumRadius / (numberOfRobots / 3);
    } else {
      x = x - 2 * (circumRadius / (numberOfRobots / 3));
      y = y;
    }
    triangleTrajectory[i][0] = x;
    triangleTrajectory[i][1] = y;
  }

  return triangleTrajectory;
}