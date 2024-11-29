#ifndef SENSOR_FACTORY_H
#define SENSOR_FACTORY_H

#include "Sensor.h"
#include "TemperatureSensor.h"
#include "PressureSensor.h"
#include "AltitudeSensor.h"

class SensorFactory 
{
public:
    static Sensor* createSensor(const std::string& sensorType);
};

#endif // SENSOR_FACTORY_H
