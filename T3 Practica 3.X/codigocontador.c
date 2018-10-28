/*
 * File:   codigocontador.c
 * Author: Travelur
 *
 * Created on 27 de septiembre de 2018, 08:58 PM
 */


#include <xc.h>

#include "config.h"
#define _XTAL_FREQ 32000000
int cont;
void main(void){
    //FRECUENCIA
    OSCFRQbits.HFFRQ=0b110; //32MHz
    //TIMER0
   
    T0CON0bits.T016BIT=0; //8-BITS   
    T0CON0bits.T0OUTPS=0b1001; //Postscaler    1:10 
    T0CON1bits.T0CKPS=0b0000; //Prescaler 1:1 
    T0CON1bits.T0CS=0b000; // CS -----> boton
    T0CON1bits.T0ASYNC=1; //TMR0 INPUT ASYNCHRONIZATION ENABLE BIT --- Fosc/4 
    T0CKIPPS=0x06; // BOTON PPS ENTRADA
    TMR0L=0; //Contador en 0
    T0CON0bits.T0EN=1; //HABILITA TIMER0
    
    PORTA=0;
    TRISA=255;
    ANSELA=0; 
    TMR0H=97;
    
    PORTD=0;
    TRISD=0;
    ANSELD=0;
    PORTC=0;
    TRISC=0;
    ANSELC=0;
    
    unsigned char voltajitos[]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,
    0b01101101,0b01111101,0b00000111,0b01111111,0b01100111,0b00111111};

    while(1){          
         if(TMR0L<10){
        LATD=0b00000110;
        LATC=voltajitos[TMR0L];
        }
         if((TMR0L<20)&&(TMR0L>9)){                
             LATD=0b00000110;
             LATC=voltajitos[TMR0L-10];
             __delay_us(400);
             LATD=0b00000101;
             LATC=voltajitos[1];
              __delay_us(400);
         }
          if((TMR0L<30)&&(TMR0L>19)){
             
             LATD=0b00000110;
             LATC=voltajitos[TMR0L-20];
             __delay_us(400);
             LATD=0b00000101;
             LATC=voltajitos[2];
              __delay_us(400);
         }    
          if((TMR0L<40)&&(TMR0L>29)){
              
             LATD=0b00000110;
             LATC=voltajitos[TMR0L-30];
             __delay_us(400);
             LATD=0b00000101;
             LATC=voltajitos[3];
              __delay_us(400);
         }    
          if((TMR0L<50)&&(TMR0L>39)){
              
             LATD=0b00000110;
             LATC=voltajitos[TMR0L-40];
             __delay_us(400);
             LATD=0b00000101;
             LATC=voltajitos[4];
              __delay_us(400);
         } 
         if((TMR0L<60)&&(TMR0L>49)){
            
             LATD=0b00000110;
             LATC=voltajitos[TMR0L-50];
             __delay_us(400);
             LATD=0b00000101;
             LATC=voltajitos[5];
              __delay_us(400);
         }  
         if((TMR0L<70)&&(TMR0L>59)){
         
             LATD=0b00000110;
             LATC=voltajitos[TMR0L-60];
             __delay_us(400);
             LATD=0b00000101;
             LATC=voltajitos[6];
              __delay_us(400);
         }  
         if((TMR0L<80)&&(TMR0L>69)){
            
             LATD=0b00000110;
             LATC=voltajitos[TMR0L-70];
             __delay_us(400);
             LATD=0b00000101;
             LATC=voltajitos[7];
              __delay_us(400);
         }  
         if((TMR0L<90)&&(TMR0L>79)){
          
             LATD=0b00000110;
             LATC=voltajitos[TMR0L-80];
             __delay_us(400);
             LATD=0b00000101;
             LATC=voltajitos[8];
              __delay_us(400);
         }  
         if((TMR0L<100)&&(TMR0L>89)){
            
             LATD=0b00000110;
             LATC=voltajitos[TMR0L-90];
             __delay_us(400);
             LATD=0b00000101;
             LATC=voltajitos[9];
              __delay_us(400);
         }  
          if(TMR0L==100){
             
             LATD=0b00000110;
             LATC=voltajitos[0];
             __delay_us(400);
             LATD=0b00000101;
             LATC=voltajitos[0];
              __delay_us(400);
             LATD=0b00000011;
             LATC=voltajitos[1];
              __delay_us(400);
         }  
        if(TMR0L>100){
            TMR0L=0;
        }        
    }
    return;
}
