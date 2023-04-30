#include "AlgoSparse.h"

AlgoSparse::AlgoSparse(int tempID, int tempWeekday, int tempCycle)
{
    ID=tempID;

    if(ID==1)
    {
        inPin = 14;
        outPin= 15;
        resetLED=22;
    }

    if(ID==2)
    {
        inPin = 13;
        outPin= 12;
        resetLED=21;
    }    

    myWeekday=tempWeekday;
    cyclePos=tempCycle;

}


void AlgoSparse::init()
{

	switch (cyclePos)
	{
			//new moon
			case 0:
					seqMax=random(10,25);
					break;

			//waxing or waning crescent
			case 1:
			case 7:
					seqMax=random(15,30+1);
					break;

			//first or last quarter
			case 2:
			case 6:
					seqMax=(20,32+1);
					break;

			//waxing or waning gibbous
			case 3:
					seqMax=16;
					break;
			case 5:
					seqMax=32;
					break;
			//full moon
			case 4:
					//seqMax=random(20,40+1);
					seqMax=32;
					break;

	}

	printf("sparse week\n");
	printf("%d\n", myWeekday);

	densityPercent = map(myWeekday,1,7,5,15);
	printf("Density %\n");
	printf("%d\n", densityPercent);

        //seqMax = random(20,31);
	printf("Seq Max\n");
	printf("%d\n", seqMax);
	//seqMax=32;
	//seqMax should def sometimes be set at 32 or 16, either
	//randomly or in response to time vars
	int seedStepInd = random(0,seqMax);
	printf("%d\n", seedStepInd);

	seq[seedStepInd]=1;

	for(int i=0; i< seqMax; i++)
	{
		if(random(100) < densityPercent)
		{
			printf("step marked\n");
			printf("%d\n", i);
			printf("%d\n", random(100));
			seq[i]=1;
		}
	}

	for(int i=0; i<32; i++)
	{
		printf("%d\n", seq[i]);
	}
}

void AlgoSparse::tick()
{
    if(resetOn)
    {
        resetDur++;

        gpio_put(resetLED,1);

        if(resetDur>90000)
        {
            resetDur=0;
            resetOn=false;
            gpio_put(resetLED,0);
        }
    }

	if( gpio_get(inPin)>0)
	{
    //printf("ON\n");
		if(!played)
		{
			played=true;

			if(seqInd > seqMax-1)
			{
				seqInd=0;
				printf("sparseReset\n");
                resetOn=true;
			}

			if(seq[seqInd]==1)
			{
				gpio_put(outPin,0);
				printf("sparseTrig\n");
			}
			seqInd++;
		}
	}

	if( gpio_get(inPin)==0)
	{
		played=false;
		gpio_put(outPin,1);
	}

}

AlgoSparse::~AlgoSparse(){}
