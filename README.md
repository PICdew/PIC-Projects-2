**I have been using PICs on and off for personal projects and for work since 2010.Here are some personal projects I have done myself using Microchip's PICs:**

**Note:The projects above are written in C or ASM.I love both <3** 


**P1-16F688LM35 - Thermometer with PIC16F688 and LM35 in C:**
One of ADC channels of PIC16F688 was used to convert LM35's (temperature sensor) voltage output into digital.Using this digitized and manipulated data,through a BCD-to-7-segment display converter,current temperature between 0*C to 50*C is displayed on 7-segment displays.


**P2-BLNKYASM16F688 - Blinky LED with PIC16F688 in ASM:**
Like "hello world!" in programming,I think a blinky led project is the "hello world!" in embedded systems :) I'm happy to be back using ASM with PICs.The source code is just for a led in PortA.1 to turn on or off after the delay function has been called.

**P3-TMR016F84 - 8-bit timer(TMR0) use of PIC16F84 in C**
I just wanted to make a reference source code to use in the future.In the sourcecode,the TMR0 is initialized and the prescaler rate is set to 1/2.The overflow bit is cleared and the TMR0 is started again 10 times and this is shown in PORTB as output.
