/* 
 * File:   IOs.h
 * Author: Jerome Reynante
 *
 * Created on November 3, 2023, 6:08 PM
 */

#ifndef IOS_H
#define	IOS_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

void InitUART2(void);
void XmitUART2(char CharNum, unsigned int repeatNo);
void __attribute__ ((interrupt, no_auto_psv)) _U2RXInterrupt(void);
void __attribute__ ((interrupt, no_auto_psv)) _U2TXInterrupt(void);
void Disp2Hex(unsigned int DispData);
void Disp2Hex32(unsigned long int DispData32);
void Disp2Dec(uint16_t Dec_num);
void Disp2String(char *str);

#endif	/* IOS_H */

