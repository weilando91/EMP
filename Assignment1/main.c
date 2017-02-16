/*
 * main.c
 */

#include<stdint.h>
#include "tm4c123gh6pm.h"


int main(void) {

    int dummy;

    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

    dummy = SYSCTL_RCGC2_R;

    GPIO_PORTF_DIR_R = 0x0E;

    GPIO_PORTF_DEN_R = 0x1E;

    GPIO_PORTF_PUR_R = 0x10;
    while(1) {
        if( GPIO_PORTF_DATA_R & 0x10 )
            GPIO_PORTF_DATA_R &= ~( 0x04 );
        else
            GPIO_PORTF_DATA_R |= 0x04;
    }

    return 0;
}