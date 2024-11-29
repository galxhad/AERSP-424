#ifndef ROBOT_H
#define ROBOT_H

#include <thread> // For std::thread
#include <mutex>  // For std::mutex
#include <vector>

#define NUM_ROBOTS 5
#define NUM_TOOLS 5

typedef struct 
{
    int id;  // Robot ID
    std::thread thread;  // Thread for the robot
} Robot;

// Mutexes for each tool
extern std::mutex tools[NUM_TOOLS];

// Function declarations
void robot_task(Robot* robot);
void init_robots(std::vector<Robot>& robots);

#endif // ROBOT_H
