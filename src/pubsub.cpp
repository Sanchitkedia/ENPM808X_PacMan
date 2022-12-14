#include <geometry_msgs/msg/twist.hpp>
#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/odometry.hpp>

#include <string>

using std::placeholders::_1;
using namespace std::chrono_literals;

using TWIST = geometry_msgs::msg::Twist;
using ODOM = nav_msgs::msg::Odometry;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class RoomBa : public rclcpp::Node {
 public:

  RoomBa() : Node("x_pubsub") {
    // creates publisher to publish /cmd_vel topic
    publisher_0 = this->create_publisher<TWIST> ("/tb0/cmd_vel", 10);
    publisher_1 = this->create_publisher<TWIST> ("/tb1/cmd_vel", 10);
    publisher_2 = this->create_publisher<TWIST> ("/tb2/cmd_vel", 10);
    publisher_3 = this->create_publisher<TWIST> ("/tb3/cmd_vel", 10);
    publisher_4 = this->create_publisher<TWIST> ("/tb4/cmd_vel", 10);
    publisher_5 = this->create_publisher<TWIST> ("/tb5/cmd_vel", 10);
    publisher_6 = this->create_publisher<TWIST> ("/tb6/cmd_vel", 10);
    publisher_7 = this->create_publisher<TWIST> ("/tb7/cmd_vel", 10);
    publisher_8 = this->create_publisher<TWIST> ("/tb8/cmd_vel", 10);
    publisher_9 = this->create_publisher<TWIST> ("/tb9/cmd_vel", 10);
    publisher_10 = this->create_publisher<TWIST> ("/tb10/cmd_vel", 10);
    publisher_11 = this->create_publisher<TWIST> ("/tb11/cmd_vel", 10);


    auto subTopicName = "/tb0/odom";
    auto subCallback = std::bind(&RoomBa::subscribe_callback, this, _1);
    subscription_ =
        this->create_subscription<ODOM>(subTopicName, 10, subCallback);

    auto processCallback = std::bind(&RoomBa::process_callback, this);
    timer_ = this->create_wall_timer(100ms, processCallback);
  }


 private:
    void subscribe_callback(const ODOM &msg) {  
      std::cout << "The pose in x is " << msg.pose.pose.position.x<<std::endl;
    }

    void process_callback() {
        auto message = TWIST();
        message.linear.x = 0.1;
        publisher_0->publish(message);
        publisher_1->publish(message);
        publisher_2->publish(message);
        publisher_3->publish(message);
        publisher_4->publish(message);
        publisher_5->publish(message);
        publisher_6->publish(message);
        publisher_7->publish(message);
        publisher_8->publish(message);
        publisher_9->publish(message);
        publisher_10->publish(message);
        publisher_11->publish(message);
    }

  rclcpp::Subscription<ODOM>::SharedPtr subscription_;
  rclcpp::Publisher<TWIST>::SharedPtr publisher_0;
  rclcpp::Publisher<TWIST>::SharedPtr publisher_1;
  rclcpp::Publisher<TWIST>::SharedPtr publisher_2;
  rclcpp::Publisher<TWIST>::SharedPtr publisher_3;
  rclcpp::Publisher<TWIST>::SharedPtr publisher_4;
  rclcpp::Publisher<TWIST>::SharedPtr publisher_5;
  rclcpp::Publisher<TWIST>::SharedPtr publisher_6;
  rclcpp::Publisher<TWIST>::SharedPtr publisher_7;
  rclcpp::Publisher<TWIST>::SharedPtr publisher_8;
  rclcpp::Publisher<TWIST>::SharedPtr publisher_9;
  rclcpp::Publisher<TWIST>::SharedPtr publisher_10;
  rclcpp::Publisher<TWIST>::SharedPtr publisher_11;
  rclcpp::TimerBase::SharedPtr timer_;

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RoomBa>());
  rclcpp::shutdown();
  return 0;
}