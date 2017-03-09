/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: emp.c
*
* PROJECT....: EMP
*
* DESCRIPTION: See module specification file (.h-file).
*
* Change Log:
*****************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 050128  KA    Module created.
*
*****************************************************************************/


/***************************** Include files *******************************/
#include<stdint.h>
#include"tm4c123gh6pm.h"
#include"emp_type.h"
#include"gpio.h"
#include"systick.h"


/*****************************    Defines    *******************************/
#define TIM_100_MSEC   20
#define TIM_200_MSEC   40
#define TIM_500_MSEC  100
#define TIM_1_SEC     200
#define TIM_2_SEC     400

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/
INT8U           counter_value = 1;
INT8U           direction = 1;
extern INT16S   ticks;

INT16U           counter = 0;

int main(void) {
/*****************************************************************************
*   Input    :
*   Output   :
*   Function :
******************************************************************************/


    SYSCTL_RCGCSSI_R = SYSCTL_RCGCSSI_R0; // Enable and provide a clock to SSI module 0 in Run mode.
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R0; // Enable and provide a clock to GPIO Port A in Run mode.
    GPIO_PORTA_AFSEL_R = 0;
    GPIO_PORTA_PCTL_R = 0x2;

    GPIO_PORTA_DEN_R=0;


 //   SSICR1 = 0;



    //Initialization
    disable_global_int();
    init_gpio();
    init_systick();
    enable_global_int();

    // Loop forever.
    while(1)
    {
        while(!ticks);

        ticks--;

    }
    return 0;
}
//0 0x00 off
//1 0x08 green
//2 0x04 blue
//3 0x0C Cyan
//4 0x02 Red
//5 0x0A Yellow
//6 0x06 Magenta
//7 0x0E White



//        GPIO_PORTF_DATA_R |= 0x02;


        /*
        if( GPIO_PORTF_DATA_R & 0x10 )         //if PF4 er high
        {
            GPIO_PORTF_DATA_R &= ~(0x02);
        }
        else
        {
            GPIO_PORTF_DATA_R |= 0x02;
        }

*/

//Code
/*
        if(counter = TIM_200_MSEC)

        {
            counter = 0;

            if(direction = 1)
            {
                if(counter_value >= 7)
                {
                    counter_value = 0;
                }
                else
                {
                    counter_value++;
                }
            }
            else
            {
                if(counter_value <=0)
                {
                    counter_value = 7;
                }
                else
                {
                    counter_value--;
                }
            }
        }
        else
        {
            counter++;
        }


        if(counter_value & 0x01)
        {
            GPIO_PORTF_DATA_R |= 0x08;          //bit 0
        }
        else
        {
            GPIO_PORTF_DATA_R &= ~(0x08);
        }

        if(counter_value & 0x02)
        {
            GPIO_PORTF_DATA_R |= 0x04;          //bit 1
        }
        else
        {
            GPIO_PORTF_DATA_R &= ~(0x04);
        }

        if(counter_value & 0x04)
        {
            GPIO_PORTF_DATA_R |= 0x02;          //bit 2
        }
        else
        {
            GPIO_PORTF_DATA_R &= ~(0x02);
        }

*/





/*
if( GPIO_PORTF_DATA_R & 0x10 )         //if PF4 er high
{
    GPIO_PORTF_DATA_R &= ~(0x02);
}
else
{
    GPIO_PORTF_DATA_R |= 0x02;
}
*/



/*
if(counter > 200)
    counter++;
else
    counter = 0;
    if(counter_value <= 7)
    {
        counter_value++;
    }
    else
    {
        counter_value=0;
    }

if(counter_value & 0x01)
   GPIO_PORTF_DATA_R |= 0x08;          //bit 0
else
   GPIO_PORTF_DATA_R &= ~(0x08);

if(counter_value & 0x02)
   GPIO_PORTF_DATA_R |= 0x04;          //bit 1
else
   GPIO_PORTF_DATA_R &= ~(0x04);

if(counter_value & 0x04)
   GPIO_PORTF_DATA_R |= 0x02;          //bit 2
else
   GPIO_PORTF_DATA_R &= ~(0x02);

*/
