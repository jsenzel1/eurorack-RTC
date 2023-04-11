#include "AlgoReich.h"


AlgoReich::AlgoReich()
{
}

void AlgoReich:: init(bool tempIsA, int tempInPin, int tempOutPin,int tempWeekday, int tempCycle) //int tempSpread)
{

  //set to -1 to disable
  testVarSeqMax=6;
  //testVarSeqMax=-1;
  //

  if(isA)
  //A
  {
      testVarSeqMax=6;
  } else {
  //B
      testVarSeqMax=7;
  }

  inPin=tempInPin;
  outPin=tempOutPin;
  myWeekday=tempWeekday+1;
  cyclePos=tempCycle;

  //spread=tempSpread;
  isA=tempIsA;

  printf("\n");
  printf("ALGOOOREICH\n");


  //seqMax=random(4,8);

  //SETTING VARS FOR TESTING
  //myWeekday=
  //cyclePos=
  if(cyclePos==0)
  {
	seqMax=6+random(-1,1);
  }

  //Pre full(add first quarter specific?
  if(cyclePos>0 && cyclePos < 4)
  {
	seqMax=map(cyclePos,1,3,5,9)+random(-2,2);
	printf("%d\n", map(1,1,3,5,9)+random(-2,2));
  }

  //Full Moon
  if(cyclePos==4)
  {
	seqMax=9+random(-3,3);
  }

  //Post full
  if(cyclePos>4)// && cyclePos<8)
  {
	int minProb=map(cyclePos,5,7,6,3);
	int maxProb=map(cyclePos,5,7,10,6);

	seqMax=random(minProb,maxProb);
  }

  if(testVarSeqMax > -1)
  {
    seqMax=testVarSeqMax;
  }

  for(int i=0; i<32; i++)
  {
    //seq[i]=random(2);
    if(random(100) < seqDensity)
    {
	    seq[i]=1;
    }
  }

  //LOG TO CONSOLE
  //
  
  //printf("reich cycle read: %d \n",cyclePos);
  
  printf("Reich Seq Density: %d \n", seqDensity);
  printf("Reich Seq Max: %d \n",seqMax);

  printf("\n");

  for(int i=0;i<seqMax;i++)
  {
	  printf("%d ", seq[i]);
  }
  printf("\n");

	  printf("");


  printf("\n");

  timer=300;
}

void AlgoReich:: tick()
{

  //metronomeTest
  //gpio_put(19,gpio_get(inPin));
//  gpio_put(outPin,gpio_get(inPin));

  /*
  if(timer%10==0){
  printf("timer: %d \n",timer);
  }

  timer--;

  if(timer<100)
  {
      //timer=0;
  } 

  int div=100/timer;
  printf("div: %d \n",100/timer);

  sleep_ms(20);


  //printf("reichtick\n");
  //
  */

  if(gpio_get(inPin)>0)
  {
    //printf("got to 1 \n");
    //printf("reichTICK\n");
    if(!played)
    {

      played=true;
    
      //CHECK MAX RESET
      if(seqInd > seqMax-1)
      {

        printf("seqInd:  %d \n",seqInd);

        seqInd=0;
        printf("reset\n");
        mute[muteInd]=1;
        muteInd++;

        //if(muteInd > seqMax-1)
        if(muteInd > seqMax)
        {


          muteInd=0;

          for(int i=0; i< seqMax; i++)
          {
            mute[i]=0;
          }

        }
      }


      if(seq[seqInd]==1 && mute[seqInd]==1)
      {

        gpio_put(outPin,0);
        gpio_put(19,1);

        //printf("click \n");

      }

      //printf("%d\n", seqInd);
      //printf("%d\n", muteInd);
      //

      seqInd++;


    }

  }


  if(gpio_get(inPin)==0)
  {
    played=false;
    gpio_put(outPin,1);
    gpio_put(19,0);
  }

}

AlgoReich::~AlgoReich(){}
