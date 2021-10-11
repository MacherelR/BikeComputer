#include "led.h"
namespace static_scheduling {
LED::LED(PinName pin) : DigitalOut(pin){

}

LED::~LED(){
    
}

void LED::toggle(){
    write(! read());
}
}
