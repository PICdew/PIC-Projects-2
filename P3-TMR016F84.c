/*
 Project:  Basic 0 to 10 counter with TMR0 of PIC16F84 in C language
 Student : Burak Koryan | web : http://koryan.ca | e-mail : b.fk@unb.ca
 Date : January 17 2018
 Notes: 
       -> if the prescaler rate in the option_reg is increased,it takes longer for overflow to occur as expected.
 */


#include <xc.h>

void main(void)
{
    int count = 0;
    TRISA = 0;             // set portA as output
    TRISB = 0;             // set portB as output
    PORTA = 0;
    PORTB = 0;
    OPTION_REG = 0;        // set Option_reg to zero.
    INTCON = 0;            // set intcon register to zero
    OPTION_REG = 0xC0;     // set option register to 0b11000000
    INTCON = 0b00000100;   // start the 8-bit timer
    
    while(count!= 10)
    {
        do
        {
          PORTA = 0x2;       // PORTA = 2 if timer overflow bit isn't set.
        }while(T0IF != 1);   // check timer flag
    
          T0IF = 0;          // set overflow flag to zero
          count++;           // increment counter
          PORTB = count;     // print in PORTB
    }
    while(1);
}
