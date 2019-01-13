/*
 * File:   newmain.c
 * Author: brk-ksk
 *
 * Created on January 9, 2019, 10:58 PM
 */
#include <xc.h>
#pragma config FOSC = INTRCIO,WDTE=ON,MCLRE=OFF,BOREN=OFF
void main(void) {
    int i = 0;
    TRISIO = 0b11111011;
    while(1)
    {
        GP2 = 1;
        CLRWDT();
        STATUSbits.nPD = 0;
        STATUSbits.nTO = 1;
        GP2 = 0;
        for(i=0;i<20000;i++);
    }
    return;
}
