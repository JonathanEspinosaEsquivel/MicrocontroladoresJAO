/*
 * File:   rompiendoFronteras.c
 * Author: Travelur
 *
 * Created on 10 de octubre de 2018, 10:47 PM
 */
#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000
void main(void) {    
    OSCFRQbits.HFFRQ=0b110; // 32MHz
    //Puertos
    PORTC=0;
    TRISC=0; 
    PORTB=0;
    TRISB=0b00011111; //TRIS =1 ENTRADA
    ANSELB=0;
    
    //SENSORES
    //B0-S1
    //B1-S2
    //B2-S3
    //B3-S4
    //B4-S5

    //Configuracion  CCP1  pwm
   
    RC4PPS=0x09; //Salida CCP1 ----> RCO
    CCP1CONbits.EN=1; //Habilita CCP1
    CCP1CONbits.MODE=0b1111; //PWM mode
    //PR2=255;
  
     //Configuracion  CCP2  pwm
   
    RC5PPS=0x0A; //Salida CCP2 ----> RC1
    CCP2CONbits.EN=1; //Habilita CCP1
    CCP2CONbits.MODE=0b1111; //PWM mode
    PR2=255;
    



    
    CCPTMRS0bits.C1TSEL=0b01; //Seleccion timer TMR2 CCP1
    CCPTMRS0bits.C2TSEL=0b01; //Seleccion timer TMR2 CCP2
    //TIMER2
    T2CLKCONbits.CS= 0b0001;  // FOSC
    T2CONbits.OUTPS=0; //Porstcaler 1:1
    T2CONbits.T2CKPS=0b100; // Prescaler 1:16
    T2CONbits.ON=1; //INICIALIZA timer2
  /*  PIR4bits.TMR2IF=0;
    PIE4bits.TMR2IE=1;
    INTCONbits.GIE=1;//Global interrup enable*/
  
    while(1){
         //Adelante S3 a full
     /* 
        if(PORTBbits.RB2==1){
            CCPR2=1022; 
            CCPR1=1022;
        }
        
         //Adelante S3,S2,S4 a full
       if(PORTBbits.RB2==1&&PORTBbits.RB1==1&&PORTBbits.RB3==1){
            CCPR2=1022; 
            CCPR1=1022;
       } 
        
         //GIRO IZQUIERDA
         if(PORTBbits.RB1==1&&PORTBbits.RB2==1){
            CCPR2=1022; 
            CCPR1=600; 
        }
         if(PORTBbits.RB1==1){
            CCPR2=1022; 
            CCPR1=600; 
         
            
        }
         //GIRO DERECHA
         if(PORTBbits.RB3==1&&PORTBbits.RB2==1){
            CCPR2=600; 
            CCPR1=1022;   
          
        }
             if(PORTBbits.RB3==1){
            CCPR2=600; 
            CCPR1=1022;   
          
        }
         //CURVA IZQUIERDA
        if(PORTBbits.RB0==1&&PORTBbits.RB1==1){
            CCPR2=1023; 
            CCPR1=200;
          
        }
        if(PORTBbits.RB0==1){
            CCPR2=1023; 
            CCPR1=200;
          
        }
         //CURVA DERECHA
        if(PORTBbits.RB4==1&&PORTBbits.RB3==1){
            CCPR2=200;
            CCPR1=1023; 
        }
             if(PORTBbits.RB4==1){
            CCPR2=200;
            CCPR1=1023; 
        }
 */
        
         CCPR2=0;
    
    CCPR1=800;
    
    __delay_ms(2000);
        
         CCPR2=800;
    
    CCPR1=0;
    
    __delay_ms(2000);
        
        
}
     return;
}

void __interrupt () INTERRUPCIONALVBB (void){
       PIR4bits.TMR2IF=0; 
}
