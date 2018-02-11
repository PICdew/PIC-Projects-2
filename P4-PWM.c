/*
 Burak Koryan - web: http://koryan.ca
 February 10 2018 - Simple PWM setup with PIC16F677
 e-mail: burak@koryan.ca
 
 */

// Configuration bits:
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit 
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit 
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits 
#pragma config CP = OFF         // Flash Program Memory Code Protection bit 

#define XTAL_FREQ 20000000      // Crystal frequency
#define TMR2Prescale 4          // TMR2 Prescale value

#include <xc.h>

long PWMFreq = 5000;            // PWM Frequency

void PWM_Init()
{
    PR2 = (XTAL_FREQ/(PWMFreq*4*TMR2Prescale))-1;  // PR2 register value
    CCP1M3 = 1;             // CCP1CON register - CCP1M3 register set
    CCP1M2 = 1;             // CCP1CON register - CCP1M2 register set
    T2CKPS0 = 2;            // Timer 2 prescale setup
    T2CKPS1 = 0;            // Timer 2 prescale setup
    TMR2ON = 1;             // Timer 2 on/off bit
    TRISC2 = 0;             // PortC.2 bit set output  
    return;
    
}

void PWM_DCycle(unsigned int duty_cycle)
{
        if (duty_cycle<1023)
        {    
          duty_cycle = ((float)duty_cycle/1023)*(XTAL_FREQ/(PWMFreq*TMR2Prescale));  
          CCP1X = duty_cycle & 1;       // CCP1CON register - store CCP1X bit
          CCP1Y = duty_cycle & 2;       // CCP1CON register - store CCP1Y bit
          CCPR1L = duty_cycle >> 2;     // store the remanining bits
        }
        return;
}

void delay(int x)
{
    int i;
    for(i=0;i<x;i++);
    return;
}

void main()
{
    TRISC = 0x00;                   // Set PortC as output
    PWM_Init();                     // initialize PWM
    
    do{
        PWM_DCycle(100);           // duty cycle width 100 = 100uS 
        delay(50);
    }while(1);
}
