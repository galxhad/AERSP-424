#include "AerospaceControlSystem.h"
#include <iostream>

AerospaceControlSystem::~AerospaceControlSystem() 
{
    for (Sensor* sensor : sensors) 
    {
        delete sensor;
    }
}

void AerospaceControlSystem::addSensor(Sensor* sensor) 
{
    sensors.push_back(sensor);
}

void AerospaceControlSystem::monitorAndAdjust() 
{
    for (Sensor* sensor : sensors) 
    {
        sensor->gatherData();
        sensor->processData();
        std::cout << "Adjusting controls based on sensor data." << std::endl;
    }
}
