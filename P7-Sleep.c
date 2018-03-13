/*
    Burak Koryan | http://koryan.ca
    Description: This code below makes PIC24F128GB202 sleep 4 seconds 
    Date : March 7 2018
    e-mail : burak@koryan.ca
*/


#pragma config WDTPS = 12
#pragma config FWPSA = 0
#pragma config FWDTEN = SWON            /* Watchdog Timer Enable (WDT controlled with the SWDTEN bit) */
#include "xc.h"

void delay()                            /* Some delay for LED blinking */
{
    int i;
    for(i=0;i<10000;i++);
    return; 
}

void Gosleep(){                         /* initialization of SLEEP */
    RCONbits.VREGS = 1;
    RCONbits.SWDTEN = 1;
    RCONbits.RETEN = 1;
    Sleep();
}

void main()
{
    
__builtin_write_OSCCONL(OSCCON | 0x40);
int count;

TRISBbits.TRISB0 = 0;
PORTBbits.RB0 = 1;
    
         if (RCONbits.SLEEP)            /* check if the pic has been in sleep */
        {
             RCONbits.SLEEP = 0;        /* clear the SLEEP bit */
             RCONbits.SWDTEN = 0;   

            while(1)                    /* blink the led */
            {
                 PORTBbits.RB0 = 1;
                 delay();
                 PORTBbits.RB0 = 0;
                 delay();    
            }     
        }
Gosleep();                              /* go to sleep */
}

