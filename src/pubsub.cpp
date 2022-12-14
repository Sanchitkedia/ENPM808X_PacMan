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

    auto subCallback0 = std::bind(&RoomBa::subscribe_callback0, this, _1);
    subscription_0 = this->create_subscription<ODOM>("/tb0/odom", 10, subCallback0);

    auto subCallback1 = std::bind(&RoomBa::subscribe_callback1, this, _1);
    subscription_1 = this->create_subscription<ODOM>("/tb1/odom", 10, subCallback1);

    auto subCallback2 = std::bind(&RoomBa::subscribe_callback2, this, _1);
    subscription_2 = this->create_subscription<ODOM>("/tb2/odom", 10, subCallback2);

    auto subCallback3 = std::bind(&RoomBa::subscribe_callback3, this, _1);
    subscription_3 = this->create_subscription<ODOM>("/tb3/odom", 10, subCallback3);

    auto subCallback4 = std::bind(&RoomBa::subscribe_callback4, this, _1);
    subscription_4 = this->create_subscription<ODOM>("/tb4/odom", 10, subCallback4);

    auto subCallback5 = std::bind(&RoomBa::subscribe_callback5, this, _1);
    subscription_5 = this->create_subscription<ODOM>("/tb5/odom", 10, subCallback5);

    auto subCallback6 = std::bind(&RoomBa::subscribe_callback6, this, _1);
    subscription_6 = this->create_subscription<ODOM>("/tb6/odom", 10, subCallback6);

    auto subCallback7 = std::bind(&RoomBa::subscribe_callback7, this, _1);
    subscription_7 = this->create_subscription<ODOM>("/tb7/odom", 10, subCallback7);

    auto subCallback8 = std::bind(&RoomBa::subscribe_callback8, this, _1);
    subscription_8 = this->create_subscription<ODOM>("/tb8/odom", 10, subCallback8);

    auto subCallback9 = std::bind(&RoomBa::subscribe_callback9, this, _1);
    subscription_9 = this->create_subscription<ODOM>("/tb9/odom", 10, subCallback9);

    auto subCallback10 = std::bind(&RoomBa::subscribe_callback10, this, _1);
    subscription_10 = this->create_subscription<ODOM>("/tb10/odom", 10, subCallback10);

    auto subCallback11 = std::bind(&RoomBa::subscribe_callback11, this, _1);
    subscription_11 = this->create_subscription<ODOM>("/tb11/odom", 10, subCallback11);


    

    auto processCallback = std::bind(&RoomBa::process_callback, this);
    timer_ = this->create_wall_timer(100ms, processCallback);
  }


 private:
    void subscribe_callback0(const ODOM &msg) {  
      float x = msg.pose.pose.position.x;
      float y = msg.pose.pose.position.y;
      float z = msg.pose.pose.position.z;
    }

    void subscribe_callback1(const ODOM &msg) {  
      float x = msg.pose.pose.position.x;
      float y = msg.pose.pose.position.y;
      float z = msg.pose.pose.position.z;
    }

    void subscribe_callback2(const ODOM &msg) {  
      float x = msg.pose.pose.position.x;
      float y = msg.pose.pose.position.y;
      float z = msg.pose.pose.position.z;
    }

    void subscribe_callback3(const ODOM &msg) {  
      float x = msg.pose.pose.position.x;
      float y = msg.pose.pose.position.y;
      float z = msg.pose.pose.position.z;
    }

    void subscribe_callback4(const ODOM &msg) {  
      float x = msg.pose.pose.position.x;
      float y = msg.pose.pose.position.y;
      float z = msg.pose.pose.position.z;
    }

    void subscribe_callback5(const ODOM &msg) {  
      float x = msg.pose.pose.position.x;
      float y = msg.pose.pose.position.y;
      float z = msg.pose.pose.position.z;
    }

    void subscribe_callback6(const ODOM &msg) {  
      float x = msg.pose.pose.position.x;
      float y = msg.pose.pose.position.y;
      float z = msg.pose.pose.position.z;
    }

    void subscribe_callback7(const ODOM &msg) {  
      float x = msg.pose.pose.position.x;
      float y = msg.pose.pose.position.y;
      float z = msg.pose.pose.position.z;
    }

    void subscribe_callback8(const ODOM &msg) {  
      float x = msg.pose.pose.position.x;
      float y = msg.pose.pose.position.y;
      float z = msg.pose.pose.position.z;
    }

    void subscribe_callback9(const ODOM &msg) {  
      float x = msg.pose.pose.position.x;
      float y = msg.pose.pose.position.y;
      float z = msg.pose.pose.position.z;
    }

    void subscribe_callback10(const ODOM &msg) {  
      float x = msg.pose.pose.position.x;
      float y = msg.pose.pose.position.y;
      float z = msg.pose.pose.position.z;
    }

    void subscribe_callback11(const ODOM &msg) {  
      float x = msg.pose.pose.position.x;
      float y = msg.pose.pose.position.y;
      float z = msg.pose.pose.position.z;
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

  rclcpp::Subscription<ODOM>::SharedPtr subscription_0;
  rclcpp::Subscription<ODOM>::SharedPtr subscription_1;
  rclcpp::Subscription<ODOM>::SharedPtr subscription_2;
  rclcpp::Subscription<ODOM>::SharedPtr subscription_3;
  rclcpp::Subscription<ODOM>::SharedPtr subscription_4;
  rclcpp::Subscription<ODOM>::SharedPtr subscription_5;
  rclcpp::Subscription<ODOM>::SharedPtr subscription_6;
  rclcpp::Subscription<ODOM>::SharedPtr subscription_7;
  rclcpp::Subscription<ODOM>::SharedPtr subscription_8;
  rclcpp::Subscription<ODOM>::SharedPtr subscription_9;
  rclcpp::Subscription<ODOM>::SharedPtr subscription_10;
  rclcpp::Subscription<ODOM>::SharedPtr subscription_11;

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