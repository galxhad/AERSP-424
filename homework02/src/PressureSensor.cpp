#include "PressureSensor.h"
#include <iostream>

void PressureSensor::gatherData() const 
{
    std::cout << "Gathering data from Pressure Sensor." << std::endl;
}

void PressureSensor::processData() const 
{
    std::cout << "Processing data from Pressure Sensor." << std::endl;
}
