#include <gtest/gtest.h>
#include <memory>
#include <utility>
#include <vector>

TEST(CircleTest, test1) {
  std::vector<std::vector<double>> trajectory = {{0, 0}, {0, 0}, {0, 0}};
    EXPECT_EQ(trajectory[0][0], 0);  // expected location x coordinate
    EXPECT_EQ(trajectory[0][1], 0);  // expected location y coordinate
}