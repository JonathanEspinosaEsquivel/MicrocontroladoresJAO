/*
 * File:   P2.c
 * Author: Travelur
 *
 * Created on 30 de agosto de 2018, 06:13 PM
 */

#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000
void main(void) {
    //Osciador 32MHz OSC=hfint div 1:1
    OSCFRQbits.HFFRQ=0b110; //HFINTOSC 32MH
    //Configuración de puertos
    
    PORTD=0; //Limpia puerto D    
    ANSELD=0; //Todos los puertos como pin digital digital      
    TRISD=0; //TRISB=0b00000000; TRISB=0xFF; Todos los puertos D como salidas  
    
    //Ciclo infinito
    while(1){      
        LATDbits.LATD1 = LATDbits.LATD1 + 1; //Toggle RD1
        __delay_ms(500); //Retardo 500ms    
        
    }
 //   for(;;){
 //     
 //    }
    return;
}
