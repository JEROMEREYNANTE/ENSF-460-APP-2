/* 
 * File:   delay.h
 * Author: jj
 *
 * Created on December 1, 2023, 3:10 PM
 */

#ifndef DELAY_H
#define	DELAY_H

#ifdef	__cplusplus
extern "C" {
#endif

extern unsigned int TMR2flag;

void delay_ms(uint16_t, uint8_t);
void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void);


#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */

