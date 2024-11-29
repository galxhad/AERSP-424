#ifndef PRESSURE_SENSOR_H
#define PRESSURE_SENSOR_H

#include "Sensor.h"

class PressureSensor : public Sensor 
{
public:
    void gatherData() const override;
    void processData() const override;
};

#endif // PRESSURE_SENSOR_H
