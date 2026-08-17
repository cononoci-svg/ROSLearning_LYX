#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"

#include "hello_ros_msgs/msg/robot_pose_msg.hpp"

using namespace std::chrono_literals;

class HelloPublisher : public rclcpp::Node {
public:
  HelloPublisher() : Node("hello_ros_pub_node"), currentVal_(0.0) {
    pub_ = this->create_publisher<hello_ros_msgs::msg::RobotPoseMsg>("robot_pose", 10);
    timer_ = this->create_wall_timer(
      1000ms, std::bind(&HelloPublisher::timer_callback, this));
  }

private:
  void timer_callback() {
    auto msg = hello_ros_msgs::msg::RobotPoseMsg();
    msg.x = currentVal_;
    msg.y = currentVal_;
    msg.z = currentVal_;
    msg.angles.data.clear();
    msg.angles.data.push_back(currentVal_);
    msg.angles.data.push_back(currentVal_);
    msg.angles.data.push_back(currentVal_);

    RCLCPP_INFO(this->get_logger(), "发布数据: x=%.2f, roll=%.2f", msg.x, msg.angles.data[0]);
    pub_->publish(msg);

    currentVal_ += 0.1;
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<hello_ros_msgs::msg::RobotPoseMsg>::SharedPtr pub_;
  float currentVal_;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<HelloPublisher>());
  rclcpp::shutdown();
  return 0;
}