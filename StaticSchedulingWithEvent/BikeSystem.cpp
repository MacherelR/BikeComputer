#include "BikeSystem.h"
#include <chrono>
#include <cstdio>

namespace static_scheduling_withEvent {
    BikeSystem::BikeSystem():m_resetDevice(callback(this, &BikeSystem::setReset)){
        m_wheelRotationCount = 0;
        m_gear = 1;
        m_timer.reset();
        for (int i = 0; i < NBR_OF_TASKS; i++) {
            m_taskStartTime[i] = 0us;
        }
		m_timer.start();
    }

    void BikeSystem::setReset(){
        
    }
    void BikeSystem::start(){
        tr_info("Starting super loop");
        while(true){
            std::chrono::microseconds taskStartTime = m_timer.elapsed_time();
            updateCurrentGear();
            updateWheelRotationCount();
            updateDisplay(1);
            checkAndPerformReset();
            updateWheelRotationCount();
            updateDisplay(2);
            updateCurrentGear();
            updateWheelRotationCount();
            updateDisplay(3);
            checkAndPerformReset();
            updateWheelRotationCount();
            ThisThread::sleep_for(100ms);

            std::chrono::microseconds taskEndTime = m_timer.elapsed_time();
            std::chrono::microseconds execTime = taskEndTime - taskStartTime;
        }
    }

    void BikeSystem::updateCurrentGear(){
		std::chrono::microseconds taskStartTime = m_timer.elapsed_time();
        m_gear = m_gearSystemDevice.getCurrentGear();
		logPeriodAndExecutionTime(GEAR_TASK_INDEX, taskStartTime,m_timer.elapsed_time()-taskStartTime);
    }

    void BikeSystem::updateWheelRotationCount(){
		std::chrono::microseconds taskStartTime = m_timer.elapsed_time();
        m_wheelRotationCount = m_wheelCounterDevice.getCurrentRotationCount();
		logPeriodAndExecutionTime(COUNT_TASK_INDEX, taskStartTime,m_timer.elapsed_time()-taskStartTime);
    }

    void BikeSystem::checkAndPerformReset(){
		std::chrono::microseconds taskStartTime = m_timer.elapsed_time();
        if (m_resetDevice.checkReset()) {
            m_wheelCounterDevice.reset();
        }
		logPeriodAndExecutionTime(RESET_TASK_INDEX, taskStartTime,m_timer.elapsed_time()-taskStartTime);
    }

    void BikeSystem::updateDisplay(int subtaskindex){
		std::chrono::microseconds taskStartTime = m_timer.elapsed_time();
        m_lcdDisplay.show(m_gear, m_wheelRotationCount,subtaskindex);
		std::chrono::microseconds elTime = m_timer.elapsed_time();
        //std::chrono::microseconds execTime = taskStartTime - elTime;
		logPeriodAndExecutionTime(DISPLAY_TASK_INDEX, taskStartTime,elTime-taskStartTime);
    }

	void BikeSystem::logPeriodAndExecutionTime(int taskIndex,std::chrono::microseconds taskStartTime,std::chrono::microseconds execTime){
		std::chrono::microseconds periodTime = taskStartTime - m_taskStartTime[taskIndex];
		m_taskStartTime[taskIndex] = taskStartTime;
		printf("%s task : period %d usecs execution time %d us start time %d \n",TASK_DESCRIPTORS[taskIndex],periodTime,execTime,taskStartTime);
	}
}