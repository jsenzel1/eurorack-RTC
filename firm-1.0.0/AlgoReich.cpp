#include "AlgoReich.h"


AlgoReich::AlgoReich()
{
}

void AlgoReich:: init(bool tempIsA, int tempInPin, int tempOutPin,int tempWeekday, int tempCycle, long tempSeed) //int tempSpread)
{

  //set to -1 to disable
  testVarSeqMax=-1;
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
  testVarSeqMax=-1;

  inPin=tempInPin;
  outPin=tempOutPin;
  myWeekday=tempWeekday+1;
  cyclePos=tempCycle;
  seed=tempSeed;

  //spread=tempSpread;
  isA=tempIsA;

  printf("\n");
  printf("ALGOOOREICH\n");

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

      case 4:
          //seqMax=random(20,40+1);
          seqMax=16;
          break;

  }

  //seqMax=random(4,8);

  //SETTING VARS FOR TESTING
  //myWeekday=
  //cyclePos=




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
