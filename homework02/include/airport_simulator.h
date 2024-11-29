#ifndef AIRPORT_SIMULATOR_H
#define AIRPORT_SIMULATOR_H

#include <queue>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <thread>

extern std::mutex runway_mutex;  // Mutex for the runway
extern std::condition_variable runway_cv;  // Condition variable for the runway

void simulate_aircraft_arrival();
void aircraft_landing(int id);
void handle_arrival(int aircraft_id);

#endif // AIRPORT_SIMULATOR_H
