#include <stdio.h>
#include "pico/stdlib.h"
#include "jfunc.h" 
class Light
{
	public:
		int dow;
		int cycle;
		int epoch;
        //first is 7
        int dayLedPins[7]={7,1,0,2,11,9,8};
        int moonLedPins[8]={26,27,28,29,25,24,18,23};

        int bLed=3;
        int rLed=4;
        int gLed=5;

	void setLights(int dow, int cycle, int epoch)
	{
        gpio_init(rLed);
        gpio_init(gLed);
        gpio_init(bLed);

        gpio_set_dir(rLed,GPIO_OUT);
        gpio_set_dir(gLed,GPIO_OUT);
        gpio_set_dir(bLed,GPIO_OUT);

        
        for(int i=0; i<7; i++)
        {
            gpio_init(dayLedPins[i]);
            gpio_set_dir(dayLedPins[i],GPIO_OUT);
        }
        
        for(int i=0; i<8; i++)
        {
            gpio_init(moonLedPins[i]);
            gpio_set_dir(moonLedPins[i],GPIO_OUT);
        }
        
        gpio_put(dayLedPins[dow],1);
        gpio_put(moonLedPins[cycle],1);

        //FOR TESTING ONLY BELOW
//        gpio_put(dayLedPins[0],1);
//        gpio_put(moonLedPins[7],1);

        if(epoch==0)
        {
            printf("set to red \n");
            //red
            gpio_put(rLed,1);
        }

        if(epoch==1)
        {
            
            printf("set to bluered \n");
            //yellow
            gpio_put(rLed,1);
            gpio_put(gLed,1);
        }

        if(epoch==2)
        {
            //purple
            gpio_put(rLed,1);
            gpio_put(bLed,1);
        }

        if(epoch==3)
        {
            //aqua
            gpio_put(bLed,1);
            gpio_put(gLed,1);
        }

        if(epoch==4)
        {
            //green
            gpio_put(gLed,1);
        }

        if(epoch==5)
        {
            //blue
            gpio_put(bLed,1);
        }
        
	}
	
};
