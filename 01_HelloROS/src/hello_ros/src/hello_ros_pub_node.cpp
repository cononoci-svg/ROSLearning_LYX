#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class HelloPublisher : public rclcpp::Node {
public:
  HelloPublisher() : Node("hello_ros_pub_node") {
    pub_ = this->create_publisher<std_msgs::msg::String>("my_topic", 10);
    timer_ = this->create_wall_timer(
      1000ms, std::bind(&HelloPublisher::timer_callback, this));
  }

private:
  void timer_callback() {
    auto msg = std_msgs::msg::String();
    msg.data = "Hello ROS! 这是发布者的测试内容。";
    RCLCPP_INFO(this->get_logger(), "发布: '%s'", msg.data.c_str());
    pub_->publish(msg);
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<HelloPublisher>());
  rclcpp::shutdown();
  return 0;
}