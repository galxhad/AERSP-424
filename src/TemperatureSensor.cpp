#include "TemperatureSensor.h"
#include <iostream>

void TemperatureSensor::gatherData() const 
{
    std::cout << "Gathering data from Temperature Sensor." << std::endl;
}

void TemperatureSensor::processData() const 
{
    std::cout << "Processing data from Temperature Sensor." << std::endl;
}
