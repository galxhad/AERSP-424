#ifndef AEROSPACE_CONTROL_SYSTEM_H
#define AEROSPACE_CONTROL_SYSTEM_H

#include <vector>
#include "Sensor.h"

class AerospaceControlSystem 
{
private:
    std::vector<Sensor*> sensors;

public:
    ~AerospaceControlSystem();

    void addSensor(Sensor* sensor);
    void monitorAndAdjust();
};

#endif // AEROSPACE_CONTROL_SYSTEM_H
