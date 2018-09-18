/*
 * File:   main.c
 * Author: Travelur
 *
 * Created on 13 de septiembre de 2018, 12:08 AM
 */

#include "config.h"
#include <xc.h>
#include <stdio.h>
#define _XTAL_FREQ 32000000
#include "flex_lcd.h"
void main(void) {
    double volt1;
    double volt2;
    double ref;
    float sensor;
    double hister, x,y,z, tol, menor, mayor;//tol = +-3, menor=25 mayor=80grados
    int adc1=0, adc2=0, adc3=0;
    unsigned char buffer1[16];
    OSCFRQbits.HFFRQ = 0b110;//oscilador a 32 MHz
    ANSELC = 0;
    PORTA =0;
    PORTB=0;
    PORTD=0;
    ANSELBbits.ANSB0 =1; //LM35
    TRISBbits.TRISB0 =1;
    ANSELAbits.ANSA0 =1;  //potenciometro
    TRISAbits.TRISA0 = 1;
    ANSELDbits.ANSD7 = 0;//Ventilador
    TRISDbits.TRISD7 = 0;
    ANSELDbits.ANSD6 = 0;//foco
    TRISDbits.TRISD6 = 0;
    
     //Convertidor Analogico-Digital
    
    ADCON0bits.ADON=1; //activar ADC
    ADCON0bits.ADCS=1;//Justificar derecha
    ADREFbits.ADNREF=0;//Vref neg. = GND
    ADREFbits.ADPREF=0b00;//Vref pos. = VDD
    ADCON0bits.ADFRM=1;//Justificar derecha
   __delay_ms(200);
    
   
    
    //Init LCD
    Lcd_Init();
    Lcd_Cmd(LCD_CLEAR);
    Lcd_Cmd(LCD_CURSOR_OFF);
    __delay_ms(100);
    
    
     //ciclo infinito
    while(1){
      
        ADPCH=0b000000; // Potenciometro A0 /*Revisar si es el puerto correcto en binario*/
      __delay_ms(50);
      ADCON0bits.GO=1;//Inicia la converción
      while(ADCON0bits.GO);
      adc1 = ADRESH;
      adc1 = adc1<<8;
      adc1 = adc1+ADRESL;
      volt1=(5.0*adc1)/1023.0;//voltaje
      sensor = volt1*100.0;
      
   
     sprintf(buffer1,"Ref=%0.2f",sensor);
     Lcd_Out2(1,0,buffer1);
     __delay_ms(2);
     
      
   
      __delay_ms(300);
      
      ADPCH = 0b001000; //Sensor Lm35
      __delay_ms(50);
      ADCON0bits.GO=1;
      while(ADCON0bits.GO);
      adc2 = ADRESH;
      adc2 = adc2<<8;
      adc2 = adc2+ADRESL;
   
      volt1=5.0*adc2/1023.0;
      ref=volt1*100.0;
      sprintf(buffer1, "Lm=%04.2f C", ref);
      Lcd_Out2(2,0, buffer1);
       __delay_ms(300);
       
       x = 5;
    
       
       
       if(sensor>(ref + x)){
           LATDbits.LATD6=1;
           LATDbits.LATD7=0;
           
       }
       
       __delay_ms(300);
       if(sensor<(ref - x)){
           LATDbits.LATD6=0;
           LATDbits.LATD7=1;
           
       }
       if (ref< 25 || ref>80){
           sprintf(buffer1, "OUT");
           Lcd_Out2(2,14,buffer1);
           __delay_ms(300);
       }else{
           sprintf(buffer1,"   ");
           Lcd_Out2(2,14,buffer1);
           __delay_ms(300);
       }
       
  
       }
      return;
}