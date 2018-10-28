/*
 * File:   distancia.c
 * Author: Travelur
 *
 * Created on 9 de octubre de 2018, 09:59 PM
 */
#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000
#include "flex_lcd.h"
#include <stdio.h>
int a=0;

void main(void) {
    
    unsigned char buffer1[16];
    OSCFRQbits.HFFRQ=0b110; //32MHz
    ANSELC=0;//PUERTOS PARA LCD
    //Inicializar LCD
    Lcd_Init();                 //Inicializa LCD
    Lcd_Cmd(LCD_CLEAR);         //Limpia LCD
    Lcd_Cmd(LCD_CURSOR_OFF);    //Apaga el cursor
    __delay_ms(100);            //Retardo 100ms
     
    PORTA=0;
    ANSELA=0;
    TRISAbits.TRISA0=0;  //Trigger OUTPUT Signal
    TRISAbits.TRISA1=1; //Echo INPUT Signal
    
       
   //Configuracion del TIMER1
    T1CONbits.CKPS = 0b11;  //Prescale value 8
    T1CONbits.nT1SYNC=1;    //No sincronizada
    T1CLKbits.CS= 0b0001;   // FOSC/4
   // T1CONbits.ON=1;  //Abilita el timer 1
     TMR1=0;
     
    //Configuracion de interrucion Timer1   
    PIR4bits.TMR1IF=0;  ///// FLAG
    PIE4bits.TMR1IE=1;  ////  Enable
    INTCONbits.PEIE=1;  //Habilitar interruciones por periferico
    INTCONbits.GIE=1;   //Global interrup enable
    
    float t=0;
    float distancia=0;
    while(1){
      
      LATAbits.LATA0=1;         //Iniciamos el pulso
      __delay_us(10);           //Duracion del pulso
      LATAbits.LATA0=0;         //Desactivamos el pulso
      while(!PORTAbits.RA1);    //Espera el rebote del pulso
      T1CONbits.ON=1;           //Inicia la cuenta
      while(PORTAbits.RA1==1 && PIR4bits.TMR1IF==0);    //Termina el pulso sin desbordarse  
          T1CONbits.ON=0;                               //Finaliza la cuenta
          a=TMR1;                                       //Variable "a" igual al conteo entre la entrada del rebote y el fin del pulso
          TMR1=0;                                       //Reiniciamos timer1
  
        t=(0.000001)*(a)/2;         //Calculo del tiempo
        distancia=(34000*t);        //Calculo de distancia=velocidad*tiempo
        
        sprintf(buffer1,"Measure %03.2f ", distancia); //Guardamos en el string
        Lcd_Out2(1,0,buffer1);                         //Escribimos el string
        Lcd_Out2(1,14,"cm");                           //cm
        __delay_ms(100);                               //delay
    } 
    return;    
}
void __interrupt () INTERRUp (void){
     PIR4bits.TMR1IF=0;
}