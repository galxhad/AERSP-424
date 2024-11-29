#include "airport_simulator.h"
#include <iostream>
#include <chrono>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <random>
#include <thread>

std::mutex runway_mutex;  // Mutex to protect runway
std::condition_variable runway_cv;  // Condition variable to signal when runway is available
std::queue<int> waiting_aircraft;  // Queue to hold aircraft waiting to land
bool runway_free = true;  // Whether the runway is free or not

void aircraft_landing(int id) 
{
    std::cout << "Aircraft " << id << " is requesting landing.\n";
}

void handle_arrival(int aircraft_id) 
{
    {
        std::unique_lock<std::mutex> lock(runway_mutex);  // Locking the runway before landing
        
        // If the runway is not free, the aircraft must wait
        while (!runway_free) 
        {
            std::cout << "Aircraft " << aircraft_id << " is waiting.\n";
            runway_cv.wait(lock);  // Wait until the runway is free
        }

        // Landing the aircraft
        runway_free = false;  // Runway is now occupied
        std::cout << "Aircraft " << aircraft_id << " is cleared to land. Runway is now occupied.\n";
        aircraft_landing(aircraft_id);
        
        // After landing, free the runway and notify the next aircraft
        runway_free = true;
        std::cout << "Aircraft " << aircraft_id << " has landed. Runway is now free.\n";
        runway_cv.notify_one();  // Notify the next aircraft waiting
    }
}

void simulate_aircraft_arrival() 
{
    // Random number generation for aircraft arrival time
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);  // Random delay for aircraft arrivals
    
    // Array to store threads for each aircraft arrival
    std::vector<std::thread> threads;

    // Simulate 10 aircraft arrivals with random times
    for (int i = 0; i < 10; ++i) 
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(dist(gen)));  // Simulate random arrival time
        std::cout << "Aircraft " << i << " is arriving.\n";
        
        // Each aircraft arrival spawns a new thread to handle the arrival
        threads.push_back(std::thread(handle_arrival, i));
    }
    
    // Wait for all threads to finish
    for (auto& t : threads) 
    {
        t.join();
    }
}


