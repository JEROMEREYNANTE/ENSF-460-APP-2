/*
 * File:   IOs.c
 * Author: Angelo
 *
 * Created on October 10, 2023, 11:31 AM
 */

#include "xc.h"
#include "IOs.h"
#include "delay.h"
#include "UART2.h"

uint8_t MINS;
uint8_t SECS;
uint8_t RESET;
uint8_t ALARM;



int IOinit() {
    //Clock output on REFO pin - pin 18 RB15
    //TRISBbits.TRISB15 = 0;  // Set RB15 as output for REFO
    //REFOCONbits.ROEN = 1; // Ref oscillator is enabled
    //REFOCONbits.ROSSLP = 0; // Ref oscillator is disabled in sleep
    //REFOCONbits.ROSEL = 0; // Output base clk showing clock switching
    //REFOCONbits.RODIV = 0b0000;
    
    //IO Inititalizations
    AD1PCFG = 0xFFFF;  // Turn all analog pins to digital
    
    TRISAbits.TRISA2 = 1; //input PB1
    TRISBbits.TRISB4 = 1; //input PB2
    TRISBbits.TRISB8 = 0; //output
    LATBbits.LATB8 = 0;   // Sets LED OFF
    
    CNPU1bits.CN0PUE = 1; // Enables pull up resistor on RA4/CN0
    CNPU1bits.CN1PUE = 1; // Enables pull up resistor on RB4/CN1

    /*
        RA2 - CN30
        RB4 - CN1
        RA4 - CN0
    */
    
     //Clock output on REFO pin - pin 18 RB15
    
    //Interrupt Inititalizations
    CNEN1bits.CN0IE = 1;
    CNEN1bits.CN1IE = 1;
    IPC4 = IPC4 | 0xF000;
    
    IEC1bits.CNIE = 1;
    IFS1bits.CNIF = 0;
    return;
}

//checks to see what input 
void IOcheck(void) {
    IEC1bits.CNIE = 0;
    delay_ms(400, 1);
    IEC1bits.CNIE = 1;
    
    //If PB1 is pressed, toggle the LED light
    while((PORTAbits.RA4 == 0) && (PORTBbits.RB4 == 1) && (PORTAbits.RA2 ==1))
    {
        LATBbits.LATB8 = LATBbits.LATB8 ^ 1;
    } 
    while((PORTAbits.RA4 == 1) && (PORTBbits.RB4 == 0) && (PORTAbits.RA2 ==1))
    {
        //implement the code afterwards
    }

}


void __attribute__((interrupt, no_auto_pav)) _CNInterrupt(void)
{ 
	IFS1bits.CNIF = 0;		// clear IF flag
    T2CONbits.TON = 0; // Disable timer
    IEC0bits.T2IE = 0; //Disable timer interrupt
    IOcheck();
	Nop();

    return;	
    
    
}