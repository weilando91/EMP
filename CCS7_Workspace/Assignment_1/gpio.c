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
*****************************************************************************/
/* Date    Id    Change
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

/*****************************    Defines    *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void init_gpio(void)
/*****************************************************************************
*   Input    :
*   Output   :
*   Function :
******************************************************************************/
{
    int dummy;

    // Enable the GPIO port that is used for the on-board LEDs and switches.
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

    // Do a dummy read to insert a few cycles after enabling the peripheral.
    dummy = SYSCTL_RCGC2_R;

    // Set the direction as output (PF1 - PF3).
    GPIO_PORTF_DIR_R = 0x0E;

    // Enable the GPIO pins for digital function (PF1 - PF4).
    GPIO_PORTF_DEN_R = 0x1E;

    // Enable internal pull-up (PF4).
    GPIO_PORTF_PUR_R = 0x10;
}
/****************************** End Of Module *******************************/
