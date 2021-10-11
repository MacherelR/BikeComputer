#pragma once

#include "mbed.h"
#include "GearSystemDevice.h"
#include "WheelCounterDevice.h"
#include "ResetDevice.h"
#include "LCDDisplay.h"
#include <chrono>

#if defined(MBED_CONF_MBED_TRACE_ENABLE)
#include "mbed_trace.h"
#define TRACE_GROUP  "main"
#endif // MBED_CONF_MBED_TRACE_ENABLE

namespace static_scheduling {
    class BikeSystem {
        public:
            BikeSystem();

            void start();
  
        private:
            void updateCurrentGear();
            void updateWheelRotationCount();
            void checkAndPerformReset();
            void updateDisplay(int subTaskIndex = -1);
            void logPeriodAndExecutionTime(int taskIndex,std::chrono::microseconds taskStartTime,std::chrono::microseconds execTime);
            int m_wheelRotationCount;
            int m_gear;
            Timer m_timer;
            static constexpr int NBR_OF_TASKS = 4;
            static constexpr int RESET_TASK_INDEX = 0;
            static constexpr int GEAR_TASK_INDEX = 1;
            static constexpr int COUNT_TASK_INDEX = 2;
            static constexpr int DISPLAY_TASK_INDEX = 3;
            constexpr static const char*  TASK_DESCRIPTORS[] = {"Reset", "Gear", "Count","Display"};

            
            std::chrono::microseconds m_taskStartTime[4];
            std::chrono::microseconds m_resetTime;

            GearSystemDevice m_gearSystemDevice;
            WheelCounterDevice m_wheelCounterDevice;
            ResetDevice m_resetDevice;
            LCDDisplay m_lcdDisplay;

            

    };

}