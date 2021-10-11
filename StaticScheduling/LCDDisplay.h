#pragma once

#include "mbed.h"

#include "USBSerial.h"

namespace static_scheduling {
    class LCDDisplay {
    public:
        LCDDisplay();

        // method called for displaying information
        void show(int currentGear, int currentRotationCount,              
                int subTaskIndex = -1);
        static constexpr std::chrono::milliseconds TASK_PERIOD = 1600ms;

    private:
        // definition of task execution time
        static constexpr std::chrono::microseconds TASK_RUN_TIME = 300000us;
        static constexpr std::chrono::microseconds SUBTASK_RUN_TIME = 100000us;
        static const int NBR_OF_SUBTASKS;
        //Thread m_thread;
    };
}