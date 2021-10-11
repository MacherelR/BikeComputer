#include "mbed.h"
//#include "StaticScheduling/ResetDevice.h"
#include "BikeSystem.h"
#include <cstdio>
// main() runs in its own thread in the OS
//using namespace static_scheduling;
constexpr std::chrono::milliseconds BLINKING_RATE = 500ms;
using namespace static_scheduling;
int main()
{
    //mbed_trace_init();
    BikeSystem system;
    printf("Programm started\n");
    //tr_info("Programm started \n");
    system.start();
    //tr_info("Programm ended \n");
}

