#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class YamlPublisher : public rclcpp::Node {
public:
  YamlPublisher() : Node("yaml_pub_node") {
    // 声明参数
    this->declare_parameter<float>("initial_x", 0.0);
    this->declare_parameter<float>("initial_y", 0.0);
    this->declare_parameter<float>("initial_z", 0.0);

    // 读取参数
    this->get_parameter("initial_x", initX_);
    this->get_parameter("initial_y", initY_);
    this->get_parameter("initial_z", initZ_);

    timer_ = this->create_wall_timer(
      2000ms, std::bind(&YamlPublisher::timer_callback, this));
  }

private:
  void timer_callback() {
    RCLCPP_INFO(this->get_logger(), "从Yaml读取的初始坐标: x=%.2f, y=%.2f, z=%.2f", 
                initX_, initY_, initZ_);
  }

  rclcpp::TimerBase::SharedPtr timer_;
  float initX_;
  float initY_;
  float initZ_;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<YamlPublisher>());
  rclcpp::shutdown();
  return 0;
}