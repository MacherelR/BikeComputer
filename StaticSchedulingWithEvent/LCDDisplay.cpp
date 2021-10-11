#include "LCDDisplay.h"

namespace static_scheduling_withEvent{

    const int LCDDisplay::NBR_OF_SUBTASKS = 3;
    LCDDisplay::LCDDisplay(){
        //m_thread.start(callback(this,&LCDDisplay::show));
    }
    void LCDDisplay::show(int currentGear, int currentRotationCount,int subTaskIndex){
        //printf("Main Display : \n");
        switch (subTaskIndex) {
        case 1 :
            printf("Current gear : %d\tRotation count : %d\tSub task index : %d\n",currentGear,currentRotationCount,subTaskIndex);
            break;
        case 2 :
            break;          
        case 3 :
            break;
        default:
            wait_us(TASK_RUN_TIME.count()/NBR_OF_SUBTASKS);
        }
        
    }


}