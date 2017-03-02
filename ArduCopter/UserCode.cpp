#include "Copter.h"

#ifdef USERHOOK_INIT
void Copter::userhook_init()
{
    // put your initialisation code here
    // this will be called once at start-up
    //
    Previous_flow = 0; 
    hal.console->printf_P(PSTR("Previous_flow is initialised"));
    Current_flow = 0;  
    hal.console->printf_P(PSTR("Current_flow is initialised"));  
    Previous_time = 0;    
    hal.console->printf_P(PSTR("Previous_time is initialised"));
    Current_time = 0; 
    hal.console->printf_P(PSTR("Current_time is initialised"));   
    Flow_displacement = 0; 
    hal.console->printf_P(PSTR("Flow_displacement is initialised"));
}
#endif

#ifdef USERHOOK_FASTLOOP
void Copter::userhook_FastLoop()
{
    // put your 100Hz code here
    // Matthew's Note: This loop will run at 400Hz in Pixhawk
    // Matthew's Note: ! Remember to change this loop to run at 200Hz in /ArduCopter/ArduCopter.cpp
    // Matthew's Note: 
       
    Current_flow = optflow.flow_comp_m_y;
    hal.console->printf_P(PSTR("Current Flow rate is %f\n meter per sec"),Current_flow);        
    Current_time = AP_HAL::millis();    
    Flow_displacement = (Current_time-Previous_time)*(Current_flow-Previous_flow)/2 + Flow_displacement;
    hal.console->printf_P(PSTR("Distance travelled is %f\n meter"),Flow_displacement);        
    Previous_flow = Current_flow;
    Previous_time = Current_time;    
}
#endif

#ifdef USERHOOK_50HZLOOP
void Copter::userhook_50Hz()
{
    // put your 50Hz code here
}
#endif

#ifdef USERHOOK_MEDIUMLOOP
void Copter::userhook_MediumLoop()
{
    // put your 10Hz code here
}
#endif

#ifdef USERHOOK_SLOWLOOP
void Copter::userhook_SlowLoop()
{
    // put your 3.3Hz code here
}
#endif

#ifdef USERHOOK_SUPERSLOWLOOP
void Copter::userhook_SuperSlowLoop()
{
    // put your 1Hz code here
}
#endif
