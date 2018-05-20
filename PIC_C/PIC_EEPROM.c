/*
 Description : data writing/reading to EEPROM of PIC12F675
 */
#include <xc.h>
 
#pragma config FOSC=INTRCIO,WDTE=OFF,MCLRE=OFF,BOREN=OFF

void main(void)
{
    int count = 0;
    while(1)
 {
    int print_counter;
    // Initialize writing to EEPROM
    EECON1bits.WREN = 1;              
    INTCONbits.GIE = 1;
    EEADR = 0x55;
    _delay(1);
    EEDATA = count;         // Write the counter value to EEPROM data register
    _delay(1);
    EECON1bits.WR = 1;
    INTCONbits.GIE = 1;
    _delay(2);
   
    // Initialize Reading
    EEADR = 0x55;
    EECON1bits.RD = 1;
    print_counter = EEDATA;   // Read counter data to print_counter variable
    count++;
 }
    return;
}
   
