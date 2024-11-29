#ifndef SENSOR_H
#define SENSOR_H

#include <string>

// Abstract base class
class Sensor 
{
public:
    virtual ~Sensor() = default;
    virtual void gatherData() const = 0;  // Pure virtual function to gather data
    virtual void processData() const = 0;  // Pure virtual function to process data
};

#endif // SENSOR_H
