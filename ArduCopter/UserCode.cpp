#include "Copter.h"

#ifdef USERHOOK_INIT
void Copter::userhook_init()
{
    // put your initialisation code here
    // this will be called once at start-up
    //
    Previous_flow = 0; 
    hal.console->printf("Previous_flow is initialised \n");
    Current_flow = 0;  
    hal.console->printf("Current_flow is initialised \n");  
    Previous_time = 0;    
    hal.console->printf("Previous_time is initialised \n");
    Current_time = 0; 
    hal.console->printf("Current_time is initialised \n");   
    Flow_displacement = 0; 
    hal.console->printf("Flow_displacement is initialised \n");
    Start_time = 0;
    hal.console->printf("Start_time is initialised \n");
    Time_taken = 0;
    hal.console->printf("Time_taken is initialised \n");
}
#endif

#ifdef USERHOOK_FASTLOOP
void Copter::userhook_FastLoop()
{
    // put your 100Hz code here
    // Matthew's Note: This loop will run at 400Hz in Pixhawk
    // Matthew's Note: ! Remember to change this loop to run at 200Hz in /ArduCopter/ArduCopter.cpp
    // Matthew's Note: 
    Start_time = AP_HAL::micros();   
    Current_flow = optflow.flowRate().y;
    //hal.console->printf("Current Flow rate is %f meter per sec \n Distance travelled is %f meter \n Loop time taken is %u microsec \r",Current_flow,Flow_displacement);        
    Current_time = AP_HAL::millis();    
    Flow_displacement = (Current_time-Previous_time)*0.001f*(Current_flow-Previous_flow)/2 + Flow_displacement;
    //hal.console->printf("Distance travelled is %f meter \n",Flow_displacement);        
    Previous_flow = Current_flow;
    Previous_time = Current_time;
    Time_taken = AP_HAL::micros() - Start_time;
    hal.console->printf("Current Flow rate is %f meter per sec\tDistance travelled is %f meter\tLoop time taken is %u microsec\n",Current_flow,Flow_displacement,Time_taken);
    //hal.console->printf("Loop time taken is %u microsec \n",Time_taken);     
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
