#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std::chrono_literals;

class PeriodicTask : public rclcpp::Node
{
public:
    PeriodicTask(int task_id, const std::string &task_name)
    : Node("periodic_task_" + std::to_string(task_id)), task_id_(task_id), task_name_(task_name)
    {
        // Create a timer that triggers every second
        timer_ = this->create_wall_timer(
            1s, std::bind(&PeriodicTask::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto now = this->now();
        // Create a formatted time string
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(3) << now.seconds();

        RCLCPP_INFO(this->get_logger(), "[Task %d] %s executed at time: %s", task_id_, task_name_.c_str(), oss.str().c_str());
        // Add your task logic here
    }

    // Declare the member variables
    rclcpp::TimerBase::SharedPtr timer_;  // Timer for the periodic task
    int task_id_;          // Task ID
    std::string task_name_; // Task Name
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    // Create multiple periodic tasks
    auto task1 = std::make_shared<PeriodicTask>(1, "Task1");
    auto task2 = std::make_shared<PeriodicTask>(2, "Task2");
    auto task3 = std::make_shared<PeriodicTask>(3, "Task3");

    rclcpp::spin(task1); // Start spinning the first task
    rclcpp::shutdown();
    return 0;
}

