#include "AlgoReich.h"

AlgoReich::AlgoReich(int tempID,int tempWeekday, int tempCycle, long tempSeed) 
{
  myWeekday=tempWeekday+1;
  cyclePos=tempCycle;
  seed=tempSeed;
  ID=tempID;
}

void AlgoReich:: init()
{

  //set to -1 to disable
  testVarSeqMax=-1;

  if(ID==1)
  //A
  {
      testVarSeqMax=6;
  } else {
  //B
      testVarSeqMax=7;
  }
  testVarSeqMax=-1;

  if(ID==1)
  {
      inPin=14;
      outPin=15;
      resetLED=22;
  } 

  if(ID==2)
  {
      inPin=13;
      outPin=12;
      resetLED=21;
  } 
  

  //spread=tempSpread;

  printf("\n");
  printf("ALGOOOREICH\n");

  switch (cyclePos)
  {
      //new moon
      case 0:
          seqMax=random(3,5+1);
          break;

      //waxing or waning crescent
      case 1:
      case 7:
          //seqMax=random(6,8+1);
          seqMax=random(3,5+1);
          break;

      //first or last quarter
      case 2:
      case 6:
          //seqMax=(8,10+1);         
          seqMax=random(4,7+1);
          break;

      //waxing or waning gibbous
      case 3:
          seqMax=4;
          break;
      case 5: 
          //srand(seed);
          seqMax=6;
          break;

      case 4:
          //seqMax=random(20,40+1);
          seqMax=8;
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

  bool empty=true; 
  for(int i=0; i<seqMax; i++)
  {
      if(seq[i] != 0)
      {
          empty=false;
          break;
      }
  }
  if(empty)
  {
      int rIndex=random(0,seqMax);
      seq[rIndex]=1;
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

          //reset
          muteInd=0;

          for(int i=0; i< seqMax; i++)
          {
            mute[i]=0;
          }
          resetOn=true;

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
