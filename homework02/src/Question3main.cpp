#include "airport_simulator.h"

int main() 
{
    simulate_aircraft_arrival();  // Start simulating aircraft arrivals
    std::this_thread::sleep_for(std::chrono::seconds(5));  // Give enough time for all threads to complete
    return 0;
}
