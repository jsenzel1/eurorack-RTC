#include "AlgoPlain.h"
#include "jfunc.h"

AlgoPlain::AlgoPlain(int tempInPin, int tempOutPin,int tempWeekday, int tempCycle, int tempSeed)
{
	outPin=tempOutPin;
	inPin=tempInPin;

	weekday=tempWeekday;
	cyclePos=tempCycle;
    seed=tempSeed;
}

void AlgoPlain::init()
{
	for(int i=0; i<64; i++)
	{
		seq[i]=random(2);
	}

    switch (cyclePos)
    {
        //new moon
        case 0:
            seqMax=random(5,6+1);
            break;

        //waxing or waning crescent
        case 1:
        case 7:
            seqMax=random(7,9+1);
            break;

        //first or last quarter
        case 2:
        case 6:
            seqMax=(10,12+1);
            break;

        //waxing or waning gibbous
        case 3:
        case 5:

            srand(seed);
            seqMax=random(13,15+1);
            break;
				//full moon
        case 4:
						//seqMax=random(20,40+1);
            seqMax=16;
            break;

    }

	//seqMax=random(4,24);
	printf("-----\n Max: ");
	printf("%d \n", seqMax);

	for(int i=0; i<seqMax; i++)
	{
		printf("%d ", seq[i]);
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
