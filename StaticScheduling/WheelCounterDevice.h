#pragma once

#include "mbed.h"

#include "USBSerial.h"

namespace static_scheduling {
class WheelCounterDevice {
    public:
        WheelCounterDevice();

        // method called for getting the current wheel rotation count
        int getCurrentRotationCount() const;
        // method called for resetting the counter
        void reset();
        static constexpr std::chrono::milliseconds TASK_PERIOD = 400ms;
    private:
        static constexpr std::chrono::microseconds TASK_RUN_TIME = 200000us;
        static constexpr std::chrono::microseconds WHEEL_ROTATION_TIME = 100000us;
        LowPowerTicker m_ticker;
        int m_rotationCount;
        void turn();

        //Thread m_thread;
};

}