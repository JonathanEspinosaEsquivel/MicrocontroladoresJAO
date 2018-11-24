/*
 * File:   newmain.c
 * Author: Travelur
 *
 * Created on 22 de agosto de 2018, 06:30 PM
 */

#include "hacks.h"
#include <xc.h>

void main(void) {
    //oscilador
    OSCFRQbits.HFFRQ=0b110;
    //Puertos
    PORTB=0; //Limpia puerto B
    ANSELB=0; //Puerto B como digital
    TRISB=0; //Puerto B como salida
    //PPS
    RB7PPS=0x18; // RB0<----- T0_out
    //Timer 
    return;
}
