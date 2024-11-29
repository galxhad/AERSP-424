#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "Sensor.h"

class TemperatureSensor : public Sensor 
{
public:
    void gatherData() const override;
    void processData() const override;
};

#endif // TEMPERATURE_SENSOR_H
