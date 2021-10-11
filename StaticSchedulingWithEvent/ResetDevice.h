#pragma once

#include "mbed.h"
#include "Button.h"

#include "USBSerial.h"


namespace static_scheduling_withEvent {
    
    class ResetDevice {
        public:
            ResetDevice(mbed::Callback<void()> cb);
    // method called for checking the reset status
            bool checkReset();
            void readBtn();
        private:
        // reading rate in milliseconds when running a separate thread
        // The gear value is updated every second
        static constexpr std::chrono::milliseconds READING_RATE = 1000ms;;

        // definition of task execution time
        static constexpr std::chrono::microseconds TASK_RUN_TIME = 100000us;;

        

        bool isChecked = false;
  
        Thread m_thread;
        InterruptIn m_resetButton;
            
};

}