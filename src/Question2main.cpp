#include "robot.h"
#include <iostream>
#include <thread>
#include <chrono>

// Initialize tools as mutexes
std::mutex tools[NUM_TOOLS];

// Function to simulate the robot task
void robot_task(Robot* robot) 
{
    int left_tool = robot->id;
    int right_tool = (robot->id + 1) % NUM_ROBOTS;  // The robot on the right

    while (true) 
    {
        std::cout << "Robot " << robot->id << ": Waiting to grab tools " << left_tool << " and " << right_tool << "...\n";

        // Grab the left tool
        tools[left_tool].lock();
        std::cout << "Robot " << robot->id << ": Grabbed tool " << left_tool << "\n";

        // Grab the right tool
        tools[right_tool].lock();
        std::cout << "Robot " << robot->id << ": Grabbed tool " << right_tool << "\n";

        // Perform the task (simulate for 5 seconds)
        std::cout << "Robot " << robot->id << ": Performing task with tools " << left_tool << " and " << right_tool << "...\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));  // Simulate 5 seconds of task time

        // Return the tools
        tools[left_tool].unlock();
        std::cout << "Robot " << robot->id << ": Returned tool " << left_tool << "\n";
        tools[right_tool].unlock();
        std::cout << "Robot " << robot->id << ": Returned tool " << right_tool << "\n";

        // Break after task completion for demonstration purposes
        break;
    }
}

// Function to initialize robots and start their threads
void init_robots(std::vector<Robot>& robots) 
{
    for (int i = 0; i < NUM_ROBOTS; i++) 
    {
        robots[i].id = i;
        robots[i].thread = std::thread(robot_task, &robots[i]);
    }

    // Join threads to wait for all robots to finish their tasks
    for (int i = 0; i < NUM_ROBOTS; i++) 
    {
        robots[i].thread.join();
    }
}

int main() 
{
    // Declare and initialize robots
    std::vector<Robot> robots(NUM_ROBOTS);

    // Initialize mutexes for tools
    for (int i = 0; i < NUM_TOOLS; i++) 
    {
        // Mutex initialization is not necessary for std::mutex, as it is default-initialized
    }

    // Initialize robots and start their tasks
    init_robots(robots);

    return 0;
}
