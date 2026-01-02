#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class HelloNode : public rclcpp::Node
{
public:
  HelloNode()
  : Node("hello_world_node")
  {
    // Create a timer that fires every 1000ms (1s)
    timer_ = this->create_wall_timer(
      1000ms, std::bind(&HelloNode::timer_callback, this));
  }

private:
  void timer_callback()
  {
    // Log the required message
    RCLCPP_INFO(this->get_logger(), "Hello, World!");
  }

  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<HelloNode>());
  rclcpp::shutdown();
  return 0;
}
