#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class Talker : public rclcpp::Node
{
public:
    Talker() : Node("talker_node"), count_(0)
    {
        price_desc.description = "话题价格参数，取值范围1~1000，默认值100";
        price_desc.integer_range.resize(1);
        price_desc.integer_range[0].from_value = 1;
        price_desc.integer_range[0].to_value = 1000;
        price_desc.integer_range[0].step = 1;
        this->declare_parameter("price", price, price_desc);
        publisher_ = this->create_publisher<std_msgs::msg::String>("chatter", 10);
        timer_ = this->create_wall_timer(
            500ms, std::bind(&Talker::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto message = std_msgs::msg::String();
        message.data = "Hello, ROS2! Count: " + std::to_string(count_++);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
        publisher_->publish(message);
        this->get_parameter("price", price);
        RCLCPP_INFO(this->get_logger(), "Current price: %d", price);
    }
    
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    size_t count_;
    int price;
    rcl_interfaces::msg::ParameterDescriptor price_desc;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Talker>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
