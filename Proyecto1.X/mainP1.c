/*
 * File:   mainP1.c
 * Author: Travelur
 *
 * Created on 22 de agosto de 2018, 05:59 PM
 */


#include <xc.h>
#include <pic16f18877.h>
#include "configuracionalv.h"

void main(void) {
    //Configuración del oscilador
    OSCCON1bits.NDIV=0b0001;  //Divisor 1:2   
    OSCFRQbits.HFFRQ=0b110; //HFINT 32MHz
    
    return;
}
