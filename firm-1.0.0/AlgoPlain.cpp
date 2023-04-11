#include "AlgoPlain.h"
#include "jfunc.h"

AlgoPlain::AlgoPlain(int tempInPin, int tempOutPin,int tempWeekday, int tempCycle)
{
	outPin=tempOutPin;
	inPin=tempInPin;

	weekday=tempWeekday;
	cyclePos=tempCycle;
}

void AlgoPlain::init()
{
	for(int i=0; i<64; i++)
	{
		seq[i]=random(2);
	}

    switch (cyclePos)
    {
        case 0:
            seqMax=8;
            break;

        case 1:
            seqMax=12;
            break;

        case 2:
            seqMax=16;
            break;
        
        case 3:
            seqMax=32;
            break;

        case 4:
            seqMax=random(20,40+1);
            break;

        case 5:
            seqMax=random(10,30+1); 

            break;

        case 6:
            seqMax=random(5,20+1);;
            break;
        
        case 7:
            seqMax=(5,16+1);
            break;
    }
   
	//seqMax=random(4,24);
	printf("-----\n Max: ");
	printf("%d \n", seqMax);

	for(int i=0; i<seqMax; i++)
	{
		printf("%d", seq[i]);
	}
    printf("\n -----");
}

void AlgoPlain:: tick()
{
	//printf("gp %d \n", gpio_get(inPin));
    
    int state=gpio_get(inPin);

    if(state>0)
    {
        if(!played)
        {
           if(seq[seqInd]==1)
           {
               printf("blip");
               gpio_put(outPin,0);
           } 

           seqInd++;

           if(seqInd>seqMax-1)
           {
               seqInd=0;
           }

           played=true;
        }

    } else {
        played=false;
        gpio_put(outPin,1);
    }

}

AlgoPlain::~AlgoPlain(){}
