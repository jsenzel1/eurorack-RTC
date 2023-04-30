#include <stdio.h>
#include "pico/stdlib.h"
#include "jfunc.h"

class AlgoVari
{
    private:

        int seqA[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
        int seqB[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
        int curSeq[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 

        bool bPlaying=false;

        int seqMax=0;
        int seqInd=0;

        bool played=false;

        int maxRepeats=0;
        int repeats=0;

        int weekday=0;
        int cyclePos=0;

        int resetLED=0;

        bool resetOn = false;
        int resetDur = 0;

   public:
        int ID=0;

        int inPin;
        int outPin;

        void init();
        void tick();

        //(trying out using the ID system)        
        //ID, weekday, cycle
        AlgoVari(int,int,int); 

        ~AlgoVari();
};
