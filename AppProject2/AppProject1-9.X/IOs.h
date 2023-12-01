/* 
 * File:   ChangeClk.h
 * Author: rvyas
 *
 * Created on November 19, 2016, 8:05 PM
 */
#include "xc.h"
#ifndef CHANGECLK_H
#define	CHANGECLK_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

int IOinit();
void setTimer(char t);
void __attribute__((interrupt, no_auto_pav)) _CNInterrupt(void);


#endif	/* CHANGECLK_H */


