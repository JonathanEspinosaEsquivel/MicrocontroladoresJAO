/*
 * File:   newmain.c
 * Author: Travelur
 *
 * Created on 9 de octubre de 2018, 03:15 PM
 */


#include <xc.h>
#include "confi.h"
#define _XTAL_FREQ 32000000
int a=15536;
int c=0;
void main(void) {
    
    OSCFRQbits.HFFRQ = 0b110; //32 MHz
    //Puertos 
    PORTA=0;
    PORTB=0;
    ANSELA=0;
    ANSELB=0;
    TRISA=0b00000001;
    TRISB=0b00000001;
    WPUBbits.WPUB0=1;
     //Peripheral Pin Select
    INTPPS=0x08; //INT ----> RB0
    //Interrupción INT
    INTCONbits.INTEDG=1;//Flanco de subida
    //Interrucción
    PIR0bits.INTF=0; //Limpia bandera
    PIE0bits.INTE=1; //Habilita Interrpcion INT
    
    
    
   //Configuracion del TIMER1
    T1CONbits.CKPS = 0b11; //Prescale value 8
    T1CONbits.RD16=1;
    T1CLKbits.CS= 0b0001;  // FOSC/4
    T1CONbits.ON=1;  //Abilita el timer 1
     TMR1=a;
        
        
     //Configuracion de interrucion Timer1   
        
    PIR4bits.TMR1IF=0;  ///// FLAG
    PIE4bits.TMR1IE=1;  ////  Enable
    INTCONbits.PEIE=1;  //Habilitar interruciones por periferico
    INTCONbits.GIE=1;   //Global interrup enable
  
    
    
    while(1);
    
    return;
}

void __interrupt () INTERRUp (void){
  
    LATB7=LATB7+1;
     TMR1=a;
     if (PIR0bits.INTF==1){
         c=c+1;
          __delay_ms(300);
     }
     if (c==3){
         c=1;
     }
       if(c==1){
             a=60536;
         }
     if(c==2){
         a=15536;
     }
     PIR0bits.INTF=0;
     PIR4bits.TMR1IF=0;
}