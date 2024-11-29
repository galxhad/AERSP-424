#include <iostream>
#include "AerospaceControlSystem.h"
#include "SensorFactory.h"

int main() 
{
    // Create the control system
    AerospaceControlSystem ctrlSys;

    // Add sensors to the system
    ctrlSys.addSensor(SensorFactory::createSensor("Temperature"));
    ctrlSys.addSensor(SensorFactory::createSensor("Pressure"));
    ctrlSys.addSensor(SensorFactory::createSensor("Altitude"));

    // Monitor and adjust the system
    ctrlSys.monitorAndAdjust();

    return 0;
}
