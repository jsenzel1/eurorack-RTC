//TODO 
//Phases should align with a search online/a look at the moon outside - always
//nothing matters except that the display on the module matches the phase of the moon that's actually in the sky
//so numbers should be tweaked to reflect when other sources say that the new phase changes ie it might be that at 11.6 days into the cycle, even though technically we're closer to some cycle, another one is 'officially started'
//
//
//also just basically, need to map the moon phase here from how many days since new moon (x/27) to phase in cycle (x/8) <- give or take
//
//map(daysSinceNewMoon,0,27,0,8) <- something like that
//
//might help to talk to someone that actually knows shit about the moon or read some more about moon phases, their significance etc.

//----------------
//UPDATE: fuck, it varies month to month - maybe that's ok? 
//
//I really should have looked this up more before doing it
//full, new, and quarters only last for one day each 
//and everything repeats (/is inverted)
//meaning that there's only really 4 states 
//could have more granularity under the hood not shown or use the brightness of LEDS to show the progression through the waxing/waning phases - that would be great
//also kinda cool to have a cycle element that is dif from days of the week which is a ramp and reset element 

#include <stdio.h>
#include "pico/stdlib.h"
#include "jfunc.h" 
class Moon
{
  public:
    //String phaseWords[8] = {"New Moon", "Waxing Cresent", "First Quarter", "Waxing Gibbous", "Full Moon", "Waning Gibbous", "Last Quarter", "Waning Crescent"};

    int phases[30]={0,1,1,1,1,1,1,1,2,3,3,3,3,3,3,4,5,5,5,5,5,5,6,7,7,7,7,7,7,7};
    int epoch=0;
    //disregard final zero, maybe this should be 29 long 
    //stable phase length based off almanac.com readings 
    //good enuf fer dem, good enuf fer me
    double jdPublic;
    double jd;

    int cyclePos(int y, int m, int d)
    {
      if(m==1 || m==2)
      {
        y=y-1;
        m+=12;
      }
      //TODO test above for jan/february dates against known phases
     
      int32_t a = y/100;
      int32_t b = a/4;
      int32_t c = 2 - a + b;
       
      int32_t e = 365.25 * (y+4716);
      int32_t e2 = 365.25 * (y-2020);
      
      int32_t f = 30.6001 * (m+1);
      jd = c + d + e + f -1524.5;

      //printf("JD INSIDE\n");
     
      jdPublic = jd;

      long double daysSinceLast = (jd-2451549.5);
      long double newMoons = (daysSinceLast/29.53);

      //printf("New Moons: \n");
      

      //doing the above, before reassigning newMoons 
      newMoons = newMoons - (int)newMoons;
      
      double daysSinceNewMoon = newMoons*29.53;

      printf("Month: %d \n", m);
      printf("Day: %d \n", d);
      
      printf("days since new: %.2f\n", daysSinceNewMoon);

      int cycleVal = round(daysSinceNewMoon);

      //printf("rounded: %d \n",cycleVal);
      
      //cycleVal+=1;
      //should cycle val +=1 be reinstated?
      
      int phaseVal=phases[cycleVal];
          //printf("phase val:\n");
     //printf("phase calced old %d\n", phaseVal);

      double phaseValDecimal = (daysSinceNewMoon/29.53)*7;

      //printf("new calc, %.3f \n",phaseValDecimal);
      //int phaseVal=round(phaseValDecimal);

          //printf("%d\n", phaseWords[phaseVal]);

        
    //String phaseWords[8] = {"New Moon", "Waxing Cresent", "First Quarter", "Waxing Gibbous", "Full Moon", "Waning Gibbous", "Last Quarter", "Waning Crescent"};
    //
      
      epoch = (int)newMoons%8; 
      printf("Current Epoch: ");
      printf("%d\n", epoch);

      switch(phaseVal){
        case 0:
            printf("current phase: New Moon\n");
          break;

        case 1:
            printf("current phase: Waxing Cresent\n");
          break;

        case 2:
            printf("current phase: First Quarter\n");
          break;

        case 3:
            printf("current phase: Waxing Gibbous\n");
          break;

        case 4:
            printf("current phase: Full Moon\n");
          break;

        case 5:
            printf("current phase: Waning Gibbous\n");
          break;

        case 6:
            printf("current phase: Last Quarter\n");
          break;

        case 7:
            printf("current phase: Waning Cresent\n");
          break;


      }

      printf("\n \n ");

      
      return phaseVal;   
      
      // NOTE: the +1 is just becuase the algorithm always
      // returns a number with a .66 remained, so it should always
      // be rounded during integer conversion
      // I am aware that this is stupid
    }
    //~Moon();
};
