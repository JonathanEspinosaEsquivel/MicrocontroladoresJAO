/*
 * File:   adcmain.c
 * Author: Travelur
 *
 * Created on 6 de septiembre de 2018, 06:10 PM
 */
#include "config.h"
#include <xc.h>
#include <stdio.h>
#define _XTAL_FREQ 32000000 //su usa cuando usamos delays
#include "flex_lcd.h"

void main(void) {
    int adc=0;
    float volt=0;
    unsigned char buffer1[16];   
    //Oscilator
    OSCFRQbits.HFFRQ=0b110;
    //Puertos
     //Puerto D como digital
     ANSELC=0; //Puerto E como digital
     ANSELAbits.ANSA4=1;
     TRISAbits.TRISA4=1;
     //****Convertidor Analógico-Digital
     ADCON0bits.ADON=1;//ADC ON
     ADCON0bits.ADCS=1;//FCR
     ADREFbits.ADNREF=0;//Vref--->AVss
     ADREFbits.ADPREF=0b00;//Vref+---->Vdd
     ADCON0bits.ADFRM=1;//Justificacion Derecha
     //Canal ANA5
     //Init LCD
     Lcd_Init(); //Inicializa LCD
     Lcd_Cmd(LCD_CLEAR);
     Lcd_Cmd(LCD_CURSOR_OFF);
     __delay_ms(100);//Esperar a que el capacitor se cargue
     while(1){
         ADPCH=0b000100; 
         ADCON0bits.GO=1; //Inicia la converción
         while(ADCON0bits.GO==1);
         adc= ADRESH;
         adc=adc<<8;
         adc=adc+ADRESL;
         //adc=(adresch<<8)+adresl:
         volt=(adc*3.3)/1023.0;//Voltaje
         sprintf(buffer1,"adc=%04d",adc);
         Lcd_Out2(1,1,buffer1);
         sprintf(buffer1,"Volt=%04d",volt); //ESTO ESTA MAL PERRO :V
         Lcd_Out2(2,1,buffer1);
         __delay_ms(500);
         
     }
          
    return;
}
