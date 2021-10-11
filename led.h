#pragma once

#include "mbed.h"
namespace static_scheduling {
class LED : public DigitalOut{
    public:
        LED(PinName pin);
        ~LED();

        void toggle();

    private:
};
}
