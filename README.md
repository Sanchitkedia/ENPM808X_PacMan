# ACME Robotics - Project PAC-MAN
[![Build Status](https://github.com/Sanchitkedia/ENPM808X_PacMan/actions/workflows/cmake.yml/badge.svg)](https://github.com/Sanchitkedia/ENPM808X_PacMan/actions)
[![Coverage Status](https://coveralls.io/repos/github/Sanchitkedia/ENPM808X_PacMan/badge.svg?branch=main)](https://coveralls.io/github/Sanchitkedia/ENPM808X_PacMan?branch=main)
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
- Product Backlog Sheet: https://docs.google.com/spreadsheets/d/1_XSTd1-wi_uMZ9-BQOxIDgdvlIyRzfR8E8bqWFlsN4M/edit?usp=sharing
- Sprint planning notes and review: https://docs.google.com/document/d/1OrpvB-jz40Q4PKwc-l2--GUYys8l9m8VKom_AwE1LNQ/edit?usp=sharing

## License

MIT License

Copyright (c) 2022 Qamar Syed, Sanchit Kedia, Tanmay Haldankar

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
