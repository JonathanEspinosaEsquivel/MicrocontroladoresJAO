/*
 * File:   extrapoints.c
 * Author: Travelur
 *
 * Created on 26 de septiembre de 2018, 08:40 PM
 */
#include <xc.h>
#include <pic16f18877.h>
#include "config.h"
#define _XTAL_FREQ 32000000
int cont;
void main(void) {
    //FRECUENCIA
    OSCFRQbits.HFFRQ=0b110; //32MHz
    //TIMER0
   
    T0CON0bits.T016BIT=0; //8-BITS   
    T0CON0bits.T0OUTPS=0b1001; //Postscaler    1:10 
    T0CON1bits.T0CKPS=0b1101; //Prescaler 1:8192 
    T0CON1bits.T0CS=0b001; // CS -----> boton
    T0CKIPPS=0x06;
    T0CON1bits.T0ASYNC=0; //TMR0 INPUT ASYNCHRONIZATION ENABLE BIT --- Fosc/4 
    T0CON0bits.T0EN=1; //HABILITA TIMER0
   // RB7PPS=0x18;
    TMR0H=97;
    PORTB=0;
    TRISB=0;
    ANSELB=0;
    //TMR0L ES EL QUE INCREMENTA LA CUENTA
    PIR0bits.TMR0IF=0;
    PIE0bits.TMR0IE=1;
    INTCONbits.GIE=1;
    
    
    
    //Ciclo infinito
    while(1){
    }
    return;
}   

void __interrupt () isr(void){
    cont++;
    if(cont==10){
        LATB7=LATB7+1;
        cont=0;
    }
    TMR0IF=0;
}


/*
while(1){
    TMR0L=0;
    ****************
    ****************TMR0L AUMENTA Y ESTE SE MANDA A LOS DISPLAYS
    ****************
    ****************PRECARGA 100 Y DEBE REINICIARSE
    ****************
    x=TMR0L;
    tiempo=x*1Tick
}*/