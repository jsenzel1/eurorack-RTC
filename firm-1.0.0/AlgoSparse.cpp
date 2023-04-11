#include "AlgoSparse.h"

AlgoSparse::AlgoSparse()
{

}


void AlgoSparse::init(int tempInPin, int tempOutPin, int tempWeekday, int tempCycle)
{
	outPin=tempOutPin;
	inPin=tempInPin;
	myWeekday=tempWeekday+1;
	cyclePos=tempCycle;

	printf("sparse week\n");
	printf("%d\n", myWeekday);

	densityPercent = map(myWeekday,1,7,5,15);
	printf("Density %\n");
	printf("%d\n", densityPercent);

        seqMax = random(20,31);
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
