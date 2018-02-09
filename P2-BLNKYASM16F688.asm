; BLINKY LED WITH PIC16F688 IN ASM
; BURAK KORYAN - JAN 15 2018 	
; WEB : KORYAN.CA | E-MAIL: BURAK@KORYAN.CA
; DESCRIPTION : JUST A SIMPLE BLINKY LED PROJECT IN ASSEMBLY WITH 0.5 SEC DELAY 

	    

list		p=16f688		
#include	<P16F688.inc>		
	
__CONFIG    _CP_OFF & _CPD_OFF & _BOD_OFF & _PWRTE_ON & _WDT_OFF & _INTRC_OSC_NOCLKOUT & _MCLRE_ON & _FCMEN_OFF & _IESO_OFF
;-------------------------------------------------------------------------------------------------	
	
	    CBLOCK 0x20	     ; define variables in the memory space
	COUNT0		    
	COUNT1
	    ENDC
	
ORG 0x00
	    BSF STATUS,RP0   ; select bank 1
	    CLRF TRISA	     ; make port A output
	    BCF STATUS,RP0   ; select bank 0
	    
MAIN:
	    BCF PORTA,1      ; clear portA.1 
	    CALL DELAY
	    BSF PORTA,1      ; set portA.1
	    CALL DELAY
GOTO MAIN
	 
; some delay here:
	    
DELAY:
	MOVLW 0xFF
	MOVWF COUNT0
	MOVWF COUNT1
D0:
	DECFSZ COUNT0
	GOTO D0
D1:
	DECFSZ COUNT1
	GOTO D0
	
    RETURN
 
	END 
