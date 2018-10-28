/*
 * File:   timer1.c
 * Author: Travelur
 *
 * Created on 8 de octubre de 2018, 10:54 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000
int a=0;
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
   ////////////////////////////////////////////////////////////////////////////
    PIR4bits.TMR1IF=0;/////
    PIE4bits.TMR1IE=1;////
    INTCONbits.PEIE=1;/////
    INTCONbits.GIE=1;//Global interrup enable
     TMR1=500;
   
    T1CONbits.CKPS = 0b11; //Prescale value 8
    //T1CONbits.RD16= 0;
    T1CONbits.nT1SYNC=1;
    T1CLKbits.T1CS1= 0b0001; // Seleccion de relog Fosc

    
    // T1GCONbits.GE=1;
      T1CONbits.ON=1;  /////
      
    //  PIR5bits.TMR1GIF=1;
   
    while(1){
        
    }
    return;
}

void __interrupt () INTERRUPCIONALVBB (void){
    
    
        LATB7=LATB7+1; 
       //TMR1H=15536;
   
      TMR1H=500;
  
  /*  if( PIR0bits.INTF==1){
        a=a+1;
        if (a==3){
            a=1;
        }
        
        if (a==1){
    T1CONbits.CKPS = 0b11; //Prescale value 8
    //T1CONbits.RD16= 0;
     T1CONbits.ON =1;
    T1CLKbits.T1CS1= 0b0010; // Seleccion de relog Fosc
    TMR1H=15536;
    TMR1L=0;
    
        }
       if (a==2){
    T1CONbits.CKPS = 0b11; //Prescale
    //T1CONbits.RD16= 0;
    T1CONbits.ON =1; 
    T1CLKbits.T1CS1= 0b0010; // Seleccion de relog Fosc
    
  
  //  TMR1H=60536;
    
        }
        
      
        
        
        
     
        
   // LATB7=LATB7+1;  //Cambio estado de led RB0
    __delay_ms(500);//Espera 500ms
    PIR0bits.INTF=0;//Limpia bandera
   
    }
     if(PIR4bits.TMR1IF==1){
          LATB7=LATB7+1;  //Cambio estado de led RB0
    __delay_ms(500);//Espera 500ms
       TMR1H=15536;
    
      }  
     PIR4bits.TMR1IF=0;
     
     
     
     */
  
     PIR4bits.TMR1IF=0;
}