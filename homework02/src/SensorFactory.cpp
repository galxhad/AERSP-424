#include "SensorFactory.h"
#include <iostream>

Sensor* SensorFactory::createSensor(const std::string& sensorType) 
{
    if (sensorType == "Temperature") 
    {
        return new TemperatureSensor();
    } 
    else if (sensorType == "Pressure") 
    {
        return new PressureSensor();
    } 
    else if (sensorType == "Altitude") 
    {
        return new AltitudeSensor();
    } 
    else 
    {
        std::cout << "Unknown sensor type: " << sensorType << std::endl;
        return nullptr;
    }
}
