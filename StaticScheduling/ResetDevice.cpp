#include "ResetDevice.h"
#include "Button.h"

#if defined(TARGET_DISCO_L475VG_IOT01A) 
#define PUSH_BUTTON BUTTON1
#define POLARITY_PRESSED 0
#elif defined(TARGET_EP_AGORA)
#define PUSH_BUTTON PIN_NAME_PUSH_BUTTON
#define POLARITY_PRESSED ACTIVE_LOW_POLARITY
#endif

namespace static_scheduling{

    ResetDevice::ResetDevice(): m_resetButton(PUSH_BUTTON)
    {
        //m_thread.start(callback(this, &ResetDevice::readBtn));
    }
    bool ResetDevice::checkReset(){
        // simulate task computation by waiting for the required task run time
        wait_us(TASK_RUN_TIME.count());
        return m_resetButton.read() == POLARITY_PRESSED;
    }
}