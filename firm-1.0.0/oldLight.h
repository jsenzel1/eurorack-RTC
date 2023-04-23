#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/gpio.h"
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

    int bLED=3;
    int rLED=5;
    //int rLED=4;
    int gLED=5;

	//uint slice_r=0;
	//uint slice_g=0;
	//uint slice_b=0;

			void pwm_init(uint gpio, uint slice_num)
			{
			    gpio_set_function(gpio, GPIO_FUNC_PWM);
			    pwm_set_wrap(slice_num, 100);
                //6k value was 255
			    pwm_set_enabled(slice_num, true);
			}

			// Function to set PWM duty cycle
			void set_pwm_duty(uint slice_num, uint8_t duty)
			{
			    pwm_set_chan_level(slice_num, PWM_CHAN_A, duty);
			}

	void setLights(int dow, int cycle, int epoch)
	{
		/*
        gpio_init(rLED);
        gpio_init(gLED);
        gpio_init(bLED);

        gpio_set_dir(rLED,GPIO_OUT);
        gpio_set_dir(gLED,GPIO_OUT);
        gpio_set_dir(bLED,GPIO_OUT);
		*/

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

		uint slice_r = pwm_gpio_to_slice_num(rLED);
        uint slice_g = pwm_gpio_to_slice_num(gLED);
        uint slice_b = pwm_gpio_to_slice_num(bLED);

		pwm_init(rLED, slice_r);
		pwm_init(gLED, slice_g);
		pwm_init(bLED, slice_b);

		int red_value = 100;
		int green_value = 100;
		int blue_value = 100;

		set_pwm_duty(slice_r, red_value);
	    set_pwm_duty(slice_g, green_value);
		set_pwm_duty(slice_b, blue_value);


//        gpio_init(bLED);

//        gpio_set_dir(bLED,GPIO_OUT);

//        gpio_put(bLED,1);
        //
        //FOR TESTING ONLY BELOW
//        gpio_put(dayLedPins[0],1);
//        gpio_put(moonLedPins[7],1);

        /*
        if(epoch==0)
        {
            printf("set to red \n");
            //red
            gpio_put(rLED,1);
        }

        if(epoch==1)
        {

            printf("set to bluered \n");
            //yellow
            gpio_put(rLED,1);
            gpio_put(gLED,1);
        }

        if(epoch==2)
        {
            //purple
            gpio_put(rLED,1);
            gpio_put(bLED,1);
        }

        if(epoch==3)
        {
            //aqua
            gpio_put(bLED,1);
            gpio_put(gLED,1);
        }

        if(epoch==4)
        {
            //green
            gpio_put(gLED,1);
        }

        if(epoch==5)
        {
            //blue
            gpio_put(bLed,1);
        }
        */

	}
};
