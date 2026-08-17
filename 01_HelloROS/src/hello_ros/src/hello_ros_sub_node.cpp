#include <memory>

#include "rclcpp/rclcpp.hpp"

#include "hello_ros_msgs/msg/robot_pose_msg.hpp"

class HelloSubscriber : public rclcpp::Node {
public:
  HelloSubscriber() : Node("hello_ros_sub_node") {
    sub_ = this->create_subscription<hello_ros_msgs::msg::RobotPoseMsg>(
      "robot_pose", 10, std::bind(&HelloSubscriber::topic_callback, this, std::placeholders::_1));
  }

private:
  void topic_callback(const hello_ros_msgs::msg::RobotPoseMsg::SharedPtr msg) const {
    if (msg->angles.data.size() >= 3) {
      RCLCPP_INFO(this->get_logger(), "收到数据: x=%.2f, yaw=%.2f", msg->x, msg->angles.data[2]);
    }
  }

  rclcpp::Subscription<hello_ros_msgs::msg::RobotPoseMsg>::SharedPtr sub_;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<HelloSubscriber>());
  rclcpp::shutdown();
  return 0;
}