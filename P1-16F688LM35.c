/*
        Project: ADC with PIC16F688 and LM35
        Designer : Burak Koryan | web : http://www.koryan.ca
        E-mail : b.fk@unb.ca
        Date : January 06 2018
        Description: This code is basically used to read data from ADC module
        of PIC16F688 and the digitized LM35 output as 8-bit value is printed on
        two 7-segment displays with 74LS48 BCD-to-7-seg decoder.
*/

/* Global Variables */
int adc;
int disp1 = 16;
int disp2 = 32;


/* Delay function to use when necessary */
void delay_ms(int x)
{
     int dat;
     for(dat=0;dat<x;dat++);
}

/* Data print to 7-seg displays done here*/

void print_data(int data1)
{
     int data2 = 32;
     if (data1>0 && data1 < 10 )
     {
        PORTC = 16;
        delay_ms(5);
        PORTC = data2+data1;
        delay_ms(5);
        return;
     }
     else if(data1>9 && data1<20)
     {
          data1 = data1 - 10;
          PORTC = 17;
          delay_ms(5);
          PORTC = data2+data1;
          delay_ms(5);
      return;
     }
     else if (data1>19 && data1<30)
     {
          data1 = data1-20;
          PORTC = 18;
          delay_ms(5);
          PORTC = data2+data1;
          delay_ms(5);
          return;
     }
     else if (data1>29 && data1<40)
     {
          data1 = data1-30;
          PORTC = 19;
          delay_ms(5);
          PORTC = data2+data1;
          delay_ms(5);
          return;
     }
     else if (data1>39 && data1<50)
     {
          data1 = data1-40;
          PORTC = 20;
          delay_ms(5);
          PORTC = data2+data1;
          delay_ms(5);
          return;
     }
     else
     {
          PORTC = 16;
          delay_ms(5);
          PORTC = 32;
          delay_ms(5);
          return;
     
     }
}
/* Main program */
void main() {
     ADCON1 = 0x80;      // ADC Setup
     TRISA = 0xFF;
     TRISC = 0;
do
{    adc = ADC_Read(1);  // ADC Read
     adc = adc >> 1;
     if(adc>25)
     {
       adc = adc-1;
     }
     print_data(adc);
}while(1);


}