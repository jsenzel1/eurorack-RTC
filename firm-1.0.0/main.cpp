//TEST VARS
bool usbWait=false;
bool clockWrite=false;

//set to -1 to disable
int testVarCycle=-1;
//set to -1 to disable
int testVarEpoch=-1;

// true=random rolls on startup
bool testVarRandom=false;
int  testVarSeed=150;

int curEpoch=0;
int seedOffset=1;

#define PICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS 1000
//#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 4096
//4096

#define PARAM_ASSERTIONS_ENABLE_ALL 0

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "pico/stdlib.h"
#include "tusb.h"
#include "Manager.h"
#include "AlgoPlain.h"
#include "AlgoReich.h"
#include "AlgoCulture.h"
#include "AlgoSparse.h"
#include "AlgoBlocks.h"
#include "AlgoWonk.h"
#include "AlgoOver.h"
#include "Moon.h"
#include "Clock.h"
#include "Light.h"
#include "PhaseData.h"

#include "hardware/gpio.h"
//#include "hardware/regs/addressmap.h"
#include "hardware/clocks.h"
//#include "hardware/structs/clocks.h"

//char greeting[] = "canireadthisinninja";
//char * otherThing = "canireadthisotherthinginninja";

//USB BOOT
//int usbTimeOut=0;
//bool timeOutLedFlip=true;
//bool usbReq=false;

//STARTUP
int loopCounter=0;

//PINS

int inPin1 = 14;
int inPin2 = 13;

int outPin1=15;
int outPin2=12;

int ledPin1=19;
int ledPin2=20;

// TIME VARS

bool timeChecked;

int today=6;
int curMonth=12;
int curYear=22;

int curWeekday=3;
int cycle=0;

long todaySeed=0;

//Classes

Clock *myClock;
Moon myMoon;
Light myLight;
PhaseData myPhaseData;

Manager myManager;

//Algo Classes

AlgoCulture *myCulture1;
AlgoCulture *myCulture2;

AlgoReich *myReich1;
AlgoReich *myReich2;

AlgoPlain *myPlain1;
AlgoPlain *myPlain2;

AlgoSparse *mySparse1;
AlgoSparse *mySparse2;

AlgoBlocks *myBlocks1;
AlgoBlocks *myBlocks2;

AlgoWonk *myWonk1;
AlgoWonk *myWonk2;

AlgoOver *myOver1;
AlgoOver *myOver2;

//string_t theDate="this is the date";


void shuffleArray(int * array, int size)
{
  int last = 0;
  int temp = array[last];
  for (int i=0; i<size; i++)
  {
    int index = random(size);
    array[last] = array[index];
    last = index;
  }
  array[last] = temp;
}

void setup()
{

  //printf(greeting[5]);
  //printf(otherThing);

  printf("\n----------\n Hello from Setup!\n----------\n");

  printf("fourth index: %d ",myPhaseData.phaseDataArray[4]);

  gpio_init(inPin1);
  gpio_init(inPin2);

  gpio_set_dir(inPin1,GPIO_IN);
  gpio_set_dir(inPin2,GPIO_IN);

  gpio_init(outPin1);
  gpio_init(outPin2);

  gpio_set_dir(outPin1,GPIO_OUT);
  gpio_set_dir(outPin2,GPIO_OUT);

  gpio_init(ledPin1);
  gpio_init(ledPin2);

  gpio_set_dir(ledPin1,GPIO_OUT);
  gpio_set_dir(ledPin2,GPIO_OUT);

  myClock = new Clock;
  gpio_init(3);
  gpio_set_dir(3,GPIO_OUT);

  if(clockWrite)
  {
      myClock->initClock();
      myClock->reset();
      myClock->writeClock();
      printf("WROTE CLOCK \n");
  }
}

void clockSetup()
{
    myClock->initClock();
    myClock->reset();
    myClock->readClock();

    curWeekday = myClock->weekday;

    printf("weekday: %d \n", myClock->weekday);

    today = myClock->day;
    curMonth = myClock->month;
    curYear = myClock->year;

    printf("%d : %d : %d \n",myClock->hour,myClock->minute,myClock->second);
    printf("date: %d / %d, %d \n",curMonth, today, curYear);

    struct tm tm = {0};
    time_t time1, time2;
    struct tm date1 = {0}, date2 = {0};

    // set the two dates
    date1.tm_year = 20+100; // year - 1900
    date1.tm_mon = 1 - 1; // month (0-11)
    date1.tm_mday = 1; // day of the month
    time1 = mktime(&date1);

    date2.tm_year = curYear+100;
    date2.tm_mon = curMonth - 1;
    date2.tm_mday = today;
    time2 = mktime(&date2);

    // get the difference in seconds
    long diff = difftime(time2, time1);

    // convert to days
    long days = (int) (diff / (60 * 60 * 24));

    printf("days since jan 1 2020: %d ",days);

    printf("corresponding value in array: %d \n", myPhaseData.phaseDataArray[days]);
    cycle=myPhaseData.phaseDataArray[days];

    if(testVarCycle > -1)
    {
        cycle=testVarCycle;
    }

    printf("cycle: %d \n",cycle);

    int cyclesPassed = 0;

    for(int i=0; i<days; i++)
    {
        if(myPhaseData.phaseDataArray[i]==0)
        {
            cyclesPassed=cyclesPassed+1;
        }
    }

    printf("cycles passed %d \n",cyclesPassed);

    curEpoch= cyclesPassed % 2;

    //curEpoch=myMoon.calcEpoch(curYear+2000,curMonth,today);
    //
    if(testVarEpoch > -1)
    {
        curEpoch=testVarEpoch;
    }

    printf("epoch: %d",curEpoch);

}

void algoSetup()
{
  printf("Reached algo setup \n");
  printf("\n");
  printf("----------\n");

  switch(curEpoch)
  {
	case 0:
	printf("CURRENT: Plain Algo\n");
	printf("cycle read: %d \n",cycle);

    myPlain1 = new AlgoPlain(inPin1,outPin1,curWeekday,cycle,todaySeed);

    if(cycle==4)
    {
        srand(todaySeed);
    }

    myPlain2 = new AlgoPlain(inPin2,outPin2,curWeekday,cycle,todaySeed);

    myPlain1->init();
    //srand(todaySeed);
    myPlain2->init();

    break;

	case 1:
		printf("CURRENT: Reich Algo\n");

    myReich1 = new AlgoReich();
    myReich2 = new AlgoReich();

    myReich1->init(true,inPin1,outPin1,curWeekday,cycle,todaySeed);

    if(cycle==4)
    {

        srand(todaySeed);
        myReich2->init(true,inPin2,outPin2,curWeekday,cycle,todaySeed);

    }else{

        myReich2->init(false,inPin2,outPin2,curWeekday,cycle,todaySeed);

    }

    //int seedOffsetter=random(-100,100);
    //^^THIS LINE OF CODE DESTROYS THE UNIVERSE FOR SOME REASON

    //This break wasn't here before but things seemed to be working?
    break;

  case 2:
		printf("CURRENT: Culture Algo\n");

    myCulture1 = new AlgoCulture;
    myCulture2 = new AlgoCulture;

    myCulture1->init(inPin1,outPin1,1,4);
    //Culture1->init(inPin1,outPin1,curWeekday,cycle);
    myCulture2->init(inPin2,outPin2,curWeekday,cycle);

    break;

	case 3:

		printf("CURRENT: Sparse Algo\n");

    mySparse1 = new AlgoSparse;
    mySparse2 = new AlgoSparse;

    mySparse1->init(inPin1,outPin1,curWeekday,cycle);
    mySparse2->init(inPin2,outPin2,curWeekday,cycle);

    break;

  case 4:

      printf("CURRENT: Blocks Algo\n");

      myBlocks1 = new AlgoBlocks;
      myBlocks2 = new AlgoBlocks;

      myBlocks1->init(inPin1,outPin1,curWeekday,cycle);
      myBlocks2->init(inPin2,outPin2,curWeekday,cycle);

      break;

  case 5:

		printf("CURRENT: WONK\n");

    myWonk1 = new AlgoWonk;
    myWonk2 = new AlgoWonk;

    myWonk1->init(inPin1,outPin1,curWeekday,cycle);
    myWonk2->init(inPin2,outPin2,curWeekday,cycle);

    break;

  case 6:

		printf("CURRENT: ALGO OVER\n");

    myOver1 = new AlgoOver;
    myOver2 = new AlgoOver;

    myOver1->init(inPin1,outPin1,curWeekday,cycle);
    myOver2->init(inPin2,outPin2,curWeekday,cycle);

    break;

    }
}

void loop()

{

  /*
  loopCounter++;

  if(loopCounter > 800000)
  {
        loopCounter=0;
        printf("metro in \n");

        //gpio_put(inPin1,timeOutLedFlip);
        //timeOutLedFlip=!timeOutLedFlip;
  }
  */

  //this writes the status pins
  //its opposite because of the reverse circuitry
  gpio_put(ledPin1,!gpio_get(outPin1));
  gpio_put(ledPin2,!gpio_get(outPin2));

  if(!timeChecked)
  {

    algoSetup();

    timeChecked=true;
  }


  if(timeChecked)
  {

  	switch(curEpoch)
  	{
  	case 0:

  		myPlain1->tick();

        if(cycle != 0)
        {
  		myPlain2->tick();
        }

     break;

  	case 1:
  		myReich1->tick();
  		myReich2->tick();
     break;

  	case 2:
  		myCulture1->tick();
  		myCulture2->tick();
     break;

  	case 3:
  		mySparse1->tick();
  		mySparse2->tick();
      break;

  	case 4:
  		myBlocks1->tick();
  		myBlocks2->tick();
      break;

  	case 5:
  		myWonk1->tick();
  		myWonk2->tick();
      break;
    case 6:
      myOver1->tick();
      myOver2->tick();
    break;

    }
  }
}

int main(){

    //GPT CODE

    set_sys_clock_khz(1,false);

    // Delay for one second using a busy-wait loop
    const uint32_t delay_time_us = 1000000; // 1 second delay in microseconds
    uint32_t start_time_us = time_us_32();
    while (time_us_32() - start_time_us < delay_time_us) {
        // Busy-wait loop to delay for one second
    }

    // Set system clock back to its original value
    set_sys_clock_khz(125000,false);

    // Continue with your RP2040 initialization code here
    // ...

    //END GPT CODE

/*
    //gpt code 2

    // Set the system clock divider to 250 to slow down the RP2040
    clock_divider_t divider = clock_get_default_divider();
    clock_set_divider(divider, 250);

    // Wait for one second using a busy-wait loop
    const uint32_t delay_time_us = 1000000; // 1 second delay in microseconds
    uint32_t start_time_us = time_us_32();
    while (time_us_32() - start_time_us < delay_time_us) {
        // Busy-wait loop to delay for one second
    }

    // Restore the system clock divider to its original value
    clock_set_divider(divider, clock_get_default_divider_value(divider));

    // Continue with your RP2040 initialization code here
    // ...

    // end gpt code 2
*/
    stdio_init_all();

    if(usbWait)
    {
    while (!tud_cdc_connected()) { sleep_ms(100); }
    }


        //sleep_ms(500);
        setup();

        clockSetup();
        todaySeed=today+curMonth+curYear+seedOffset;

        if(!testVarRandom)
        {
            srand(todaySeed);
        } else {
            srand(testVarSeed);
        }

        myLight.setLights(curWeekday,cycle,curEpoch);


        printf("\n\n");
        printf("hello petrock epoch %d \n",curEpoch);
        printf("hello petrock cycle %d \n",cycle);

        printf("XOSC startup var read: %d \n", PICO_XOSC_STARTUP_DELAY_MULTIPLIER);


    while(true)
    {
    loop();
    }

    //return 0;
}
