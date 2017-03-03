// user defined variables

// example variables used in Wii camera testing - replace with your own
// variables
#ifdef USERHOOK_VARIABLES

float       Previous_flow;
float       Current_flow;
uint32_t    Previous_time;
uint32_t    Current_time;
uint32_t    Start_time;
uint32_t    Time_taken;
float       Flow_displacement;


#if WII_CAMERA == 1
WiiCamera           ircam;
int                 WiiRange=0;
int                 WiiRotation=0;
int                 WiiDisplacementX=0;
int                 WiiDisplacementY=0;
#endif  // WII_CAMERA

#endif  // USERHOOK_VARIABLES


