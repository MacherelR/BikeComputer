#include "WheelCounterDevice.h"
#include <chrono>
#include <cstdio>


namespace static_scheduling_withEvent{

    WheelCounterDevice::WheelCounterDevice(){
        m_rotationCount = 0;
        this->m_ticker.attach(callback(this,&WheelCounterDevice::turn),WHEEL_ROTATION_TIME);
    }
    int WheelCounterDevice::getCurrentRotationCount() const{
        wait_us(TASK_RUN_TIME.count());
        return m_rotationCount; 
    }

    void WheelCounterDevice::reset(){
        m_rotationCount = 0;
    }

    void WheelCounterDevice::turn(){
        m_rotationCount++;
    }
}