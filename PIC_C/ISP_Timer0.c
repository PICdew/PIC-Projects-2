/*
 Description : TIMER0 interrupt use with ISP using PIC12F675
 */
#include <xc.h>

#pragma config FOSC=INTRCIO,WDTE=OFF,MCLRE=OFF,BOREN=OFF

void init(void)
{
OPTION_REG = 0B00001000;
T0IE = 1;                       //enable TMR0 overflow interrupts
INTCONbits.GIE = 1;             //enable Global interrupts
    return;
}

void interrupt Timer0_ISR(void)
{
if (T0IE && T0IF)               //TMR0 interrupts enabled
{
                                // Do whatever  in the ISP here.
}
T0IF = 0;
return;
}

void main(void) {

    TRISIO = 0b11011011;        // GP2 is set as output
    init();
    while(1);
    return;
}

   
