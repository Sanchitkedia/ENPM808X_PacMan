#include <geometry_msgs/msg/twist.hpp>
#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/odometry.hpp>

#include <string>

using std::placeholders::_1;
using namespace std::chrono_literals;

using TWIST = geometry_msgs::msg::Twist;


/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class RoomBa : public rclcpp::Node {
 public:

  RoomBa() : Node("x_pubsub") {
    // creates publisher to publish /cmd_vel topic
    auto pubTopicName = "/tb0/cmd_vel";
    publisher_ = this->create_publisher<TWIST>(pubTopicName, 10);

    auto processCallback = std::bind(&RoomBa::process_callback, this);
    timer_ = this->create_wall_timer(100ms, processCallback);
  }


 private:

    void process_callback() {
        auto message = TWIST();
        message.linear.x = 0.1;
    
        publisher_->publish(message);
    }

  rclcpp::Publisher<TWIST>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RoomBa>());
  rclcpp::shutdown();
  return 0;
}