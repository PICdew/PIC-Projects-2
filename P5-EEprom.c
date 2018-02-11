/*
    Burak Koryan - Web : http://koryan.ca
    February 10 2018 - Data read/write from/to PIC16F877A EEPROM
    E-mail : burak@koryan.ca
*/

// Configuration bits:

#pragma config FOSC = HS           // Osc selection bis : HS oscillator
#pragma config WDTE = OFF          // Watchdog timer enable bit : OFF
#pragma config PWRTE = ON          // Power-up timer enable bit : ON
#pragma config BOREN = OFF         // Brown-out reset enable bit : OFF
#pragma config LVP = ON            // Low-voltage in cct
#pragma config CPD = OFF           // Data Eeprom memory code protection bit : OFF
#pragma config WRT = OFF           // Flash program memory enable bits : OFF
#pragma config CP = OFF            // Flash memory code protection bit : OFF

#include <xc.h>

void EEP_Write(unsigned char eAddr,unsigned char eData)
{
    unsigned char gie_status;
    EEADR = eAddr;                // EEPROM address register
    EEDATA = eData;               // EEPROM data register
    WREN = 1;                     // EEPROM write-enable bit in EECON1 register
    gie_status = GIE;             // Global Interrupt Enable bit in INTCON Register
    GIE = 0;                      
    EECON2 = 0x55;                // Required sequence by PIC
    EECON2 = 0xaa;                // Required sequence by PIC
    WR = 1;                       
    GIE = gie_status;   
    WREN = 0;
    return;
}

unsigned char EERead(unsigned char EEAddr)
{ 
    while(RD||WR);                // Check if RD or WR is in progress;
    EEADR = EEAddr;               // Write the address
    RD = 1;                       // Set RD,the read bit to start read progress
    return(EEDATA);               // return the read data
}

void main()
{
    unsigned char eep_addr = 0,read_charac;
    TRISB = 0;                          // set PORTB as output
    EEP_Write(eep_addr,'A')             // write 'A' character to EEPROM Address
    read_charac = EERead(eep_addr);     // read the char in the eep_addr address
    PORTB = read_char;                  // push read_char to PORTB (optional)
    
    while(1);
}

