# ACME Robotics - Project PAC-MAN
[![Build Status](https://github.com/Sanchitkedia/ENPM808X_PacMan/actions/workflows/cmake.yml/badge.svg)](https://github.com/Sanchitkedia/ENPM808X_PacMan/actions)
[![codecov](https://codecov.io/gh/Sanchitkedia/ENPM808X_PacMan/branch/main/graph/badge.svg?token=FJTEUVQ8H4)](https://codecov.io/gh/Sanchitkedia/ENPM808X_PacMan)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Project Description

## Overview

- The aim of this project is to design and impement a swarm algorithm for ACME Robotics.
- This implementaion is based on Turtlebot, which is a robot kit with open source software. 
- Our software will simulate a swarm operation, where the target will be chased and captured by a swarm of robots. The simulation will be realised in a physics environment in Gazebo, which is an advanced robot simulator. The simulation aims to demonstrate the performance of our algorithm, which is a product for ACME Robotics.

## Method
- This project will be implemented by utilising ROS and ROS 2 sofware tools and libraries. 
- The swarm will consist of 25 turtlebots, and the target will be controleld by the user using Teleop.
- We will initialize a node which will subscribe to the the topic that provides the current location of the target. This data will be used by the algorithm to calculate the updated target location for each agent, and the node will also publish this update to each swarm agent. 
- A three sprint Agile Iterative Process approach and test driven development style is utilized in the making of this project.

## Contributors
- **Qamar Syed** UID: 119128824 
- **Sanchit Kedia** UID: 119159620
- **Tanmay Haldankar** UID: 119175460

## Agile Iterative Process
- Product Backlog Sheet: [Link](https://docs.google.com/spreadsheets/d/1_XSTd1-wi_uMZ9-BQOxIDgdvlIyRzfR8E8bqWFlsN4M/edit?usp=sharing)
- Sprint planning notes and review: [Link](https://docs.google.com/document/d/1OrpvB-jz40Q4PKwc-l2--GUYys8l9m8VKom_AwE1LNQ/edit?usp=sharing)

## Activity Diagram

## Simulation and Presentation
- Simulation: [link](https://drive.google.com/file/d/1T11eL3_IVbmVFgl1fYkIi01qjOhaYyTw/view?usp=sharing)
- Presentation: [link](https://docs.google.com/presentation/d/1-_5ZGSgR0FNOgI5PsZH_h_N7zl6swRR-dhcLRzTt8d8/edit?usp=sharing)

## Dependencies
- [Ubuntu 22.04](https://ubuntu.com/download/desktop) : Operating System
- [ROS2 Humble Hawksbill](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html) : Robot Operating System 2 (ROS2) Binary Install
- [Gazebo 11.5.1](http://gazebosim.org/tutorials?tut=install_ubuntu&cat=install) : Robot Simulator
- [Turtlebot3 Packages](https://emanual.robotis.com/docs/en/platform/turtlebot3/quick-start/) : Turtlebot3 Packages for ROS2
- [Python 3.8.10](https://www.python.org/downloads/) : Python3 programming language 

## Build Instructions
- Install Turtlebot3 packages
```
sudo apt-get install ros-humble-turtlebot3* #If not already installed
```
- Clone the repository
```
cd ros2_ws/src
git clone https://github.com/Sanchitkedia/ENPM808X_PacMan.git
```
- Source ROS2
```
cd ..
source /opt/ros/humble/setup.bash
```
- Build the project
```
colcon build --symlink-install
colcon build --packages-select ENPM808X_PacMan
```
- Source the project
```
. install/local_setup.bash
```

## Run Instructions
- Launch the simulation
```
ros2 launch ENPM808X_PacMan empty_world.launch.py
```
- Run the swarm algorithm
```
ros2 run ENPM808X_PacMan x_pubsub
```
## Run Tests
- Run unit tests
```
colcon test --event-handlers console_direct+ --packages-select ENPM808X_PacMan
```

## Doxygen Documentation
- The procedure to create doxygen documents has been automated in the CMakeLists.txt file. 
- Pre-generated documentation converted from latex to PDF is available in the docs directory [Project_PacMan_PDF](https://github.com/Sanchitkedia/ENPM808X_PacMan/blob/main/docs/Project_PacMan_Docs.pdf)
- To view the doxygen documentation in your browser, run the following command in the root directory of the project
```
firefox ./docs/html/index.html # Replace firefox with your browser of choice
```

## CppLint Report
- To generate the report, run the following command in the src directory of the project
```
cpplint main.cpp > ../results/cpplint_main.txt
cpplint master.cpp > ../results/cpplint_master.txt
cpplint pubsub.cpp > ../results/cpplint_pubsub.txt
cpplint trajectory.cpp > ../results/cpplint_trajectory.txt
cpplint ../include/master.hpp > ../results/cpplint_master_hpp.txt
cpplint ../include/pubsub.hpp > ../results/cpplint_pubsub_hpp.txt
cpplint ../include/trajectory.hpp > ../results/cpplint_trajectory_hpp.txt
```

## CppCheck Report
- To generate the report, run the following command in the root directory of the project
```
cppcheck --enable=all --std=c++17 src/*.cpp include/*.hpp test/*.cpp --suppress=missingIncludeSystem --suppress=missingInclude --suppress=unmatchedSuppression --suppress=unusedFunction --suppress=unreadVariable --suppress=useInitializationList > ./results/cppcheck.txt
```

## License

MIT License

Copyright (c) 2022 Qamar Syed, Sanchit Kedia, Tanmay Haldankar

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.