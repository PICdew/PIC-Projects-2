
// Burak Koryan | http://koryan.ca
// Feb 14 2018
// SPI communication with PIC24FJ128GA010 and external memory chip 25LC256
// CODE NOT COMPLETED YET- TO BE UPDATED
//-------------------------------------------------------------------------------
    
#include <xc.h>

// Definitions
#define SPI_MASTER 0x0120  // select 8-bit master mode CKE=1 CKP=0
#define SPI_ENABLE 0x8000   // SPI Enable
#define CSEE _RD12          // RD12 pin connected to CS of memory
#define TCSEE _TRISD12      // TRISD12 (Pin 12 in PortD)

// 25LC256 Memory chip commands:
#define SEE_WRSR 1 // write status register
#define SEE_WRITE 2 // write command
#define SEE_READ 3 // read command
#define SEE_WDI 4 // write disable
#define SEE_STAT 5 // read status register
#define SEE_WEN 6 // write enable
//-----------------------------------------------------------------------

/// SPI Write function
int writeSPIdata(int data)
{
    SPI2BUF = data;
    while(!SPI2STATbits.SPIRBF);
    return SPI2BUF;
}

void main(void)
{
   int temp;
   int data;                    // variable "data" to read data into
   int data2 = 9;               // data to be written to the memory
   int ADDR8High = 0x15;
   int ADDR8Low = 0xFF;
 
 // PORT/Pin initialization
 TRISF = 0;                     // set PORTF as output
 TCSEE = 0;                     // make SSEE pin output
 CSEE = 1;                      // toggle serial EEPROM
 SPI2CON1 = SPI_MASTER;         // select mode
 SPI2STAT = SPI_ENABLE;         // enable the peripheral
 CSEE = 0;                      // toggle serial EEPROM
 writeSPIdata(SEE_WEN);         // send command
 CSEE = 1;                      
//------------------------------------------------------------------
 // Communicating with the external memory
CSEE = 0;  
    writeSPIdata( SEE_STAT);          // read status register 
    temp = writeSPIdata(0);      
CSEE = 1; 
//-----------------------------------------------------------------
// Writing data to the external memory
CSEE = 0; 
    writeSPIdata( SEE_WRITE);     // send command
    writeSPIdata( ADDR8High);      // high 8-bit of memory address
    writeSPIdata( ADDR8Low);      // low 8-bit of memory address
    writeSPIdata(data2);          // send data2 to be written
CSEE = 1;                         // write to the external memory
//-----------------------------------------------------------------
CSEE = 0; // select the Serial EEPROM
    writeSPIdata( SEE_READ); 
    writeSPIdata(ADDR8High);        // high 8-bit of memory address
    writeSPIdata(ADDR8Low);         // low 8-bit of memory address
    data = writeSPIdata(0);         // read data from memory into "data"
CSEE = 1; 

PORTF = data;                       // print read data to PORTF
while(1);
}
