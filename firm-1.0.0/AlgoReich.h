#include <stdio.h>
#include "pico/stdlib.h"
#include "jfunc.h" 
class AlgoReich 
{
  private:
    int testVarSeqMax=-1;
    
    int seq[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int mute[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    int muteInd=0;
    int seqMax;
    int seqInd=0;
    
    int timer;

    bool shouldPlay;
    bool played;

    int myWeekday;
    int cyclePos;

    bool isA; 
    int spread;

    //new vars
    int seqDensity=50;
    
   
    
  public:

   int inPin;  
   int outPin;  

   //isA, inPin, outPin, weekday, cycle, //[maybe]spread
   void init(bool,int,int,int,int);//,int);
   
   void tick();
   bool stepVal;


   AlgoReich();
   
   ~AlgoReich();
 };
