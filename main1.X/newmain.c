/*
 * File:   newmain.c
 * Author: Travelur
 *
 * Created on 22 de agosto de 2018, 06:30 PM
 */

#include "hacks.h"
#include <xc.h>

void main(void) {
    OSCCON1bits.NOSC= 0b001; 
    OSCCON1bits.NDIV=0b0001;
    OSCFRQbits.HFFRQ=0b110;
    PORTB= 0;
    ANSELC= 0;
    TRISB = 0;
    TRISC = 0B11010110;
    
    return;
}
