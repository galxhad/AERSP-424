#ifndef ALTITUDE_SENSOR_H
#define ALTITUDE_SENSOR_H

#include "Sensor.h"

class AltitudeSensor : public Sensor 
{
public:
    void gatherData() const override;
    void processData() const override;
};

#endif // ALTITUDE_SENSOR_H
