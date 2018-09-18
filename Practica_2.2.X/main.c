/*
 * File:   main.c
 * Author: Travelur
 *
 * Created on 3 de septiembre de 2018, 09:55 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000

void main(void) {
    //oscilador
    OSCFRQbits.HFFRQ = 0b110; //32 MHz HFINTFOSC
    //Puertos
    PORTB = 0; //Limpia puerto B
    ANSELB = 0, //Puerto B como digital
    TRISB = 0b00000111; //RB2 ENTRADAS   //RB3-RB7 SALIDAS
    PORTD = 0; //Limpia puerto D
    ANSELD = 0, //Puerto D como digital
    TRISD = 0b00000001; //RD0 ENTRADAS   //RD1-RA7 SALIDAS
   
    while(1){
       if(PORTBbits.RB0 ==0){
            __delay_ms(100);
            LATBbits.LATB3 = LATBbits.LATB3 + 1;
            __delay_ms(10);
        }
         if(PORTDbits.RD0 ==0){
            __delay_ms(100);
            LATDbits.LATD1 = LATDbits.LATD1 + 1;
            __delay_ms(10);
        }
    }
        
    return;
}
