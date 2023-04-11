#include "AlgoVari.h"
#include "jfunc.h" 

AlgoVari::AlgoVari(int tempID, int tempWeekday, int tempCycle)
{
    ID = tempID

    if(ID==1)
    {
        inPin = 14;
        outPin= 15;
    }

    if(ID==2)
    {
        inPin = 13;
        outPin= 12;
    }

    weekday=tempWeekday;
    cyclePos=tempCycle;
}

void AlgoVari::init()
{
    for(int i=0; i<16; i++)
    {
        seqA[i]=random(2);
    }
    seqB=seqA;
    jfunc.shuffle(seqB); 

    curSeq=seqA;

    curSeq=seqB;

    seqMax=8;
}

void AlgoVari::tick()
{
    int state=gpio_get(inPin);

    if(state>0)
    {
        if(!played)
        {
            if(curSeq[seqInd]==1)
            {
                gpio_pit(outPin,0);
            }
            seqInd++;
            
            //Sequence is reset
            if(seqInd>seqMax-1)
            {
                seqInd=0;

                if(!bPlaying)
                { 
                    repeats++;

                    // -1 is index compensation
                    // other minus 1 is so that its one beat before the beat, so if max repeats =4, then you get 3 bars a, 1 bar b
                
                    if(repeats==maxRepeats-2)
                    {
                        curSeq=seqB;
                        bPlaying=true;
                    }

                //b playing
                } else {
                    curSeq=seqA;
                    bPlaying=false;
                    repeats=0;
                }
            }
            played=true;
        }
    } else {
        played=false;
        gpio_put(outPin,1);
    }

}

AlgoVari::~AlgoVari(){}
