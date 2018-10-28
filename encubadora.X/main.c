#include "config.h"
#include <xc.h>
#include <stdio.h>
#define _XTAL_FREQ 32000000
#include "flex_lcd.h"

void main(void) {
    int adc1=0; //declarar variables tipo int
    int adc2=0;
    float volt1=0,temp=0,volt2=0;
    unsigned char buffer1[16];
    //Oscilator
    OSCFRQbits.HFFRQ=0b110; 
    //Puertos
    ANSELC=0; //portc como digital
    ANSELBbits.ANSB0=1;//B0 como Analógico  LM35
    TRISBbits.TRISB0=1;//B0 como Entrada    LM35
    ANSELAbits.ANSA0=1;
    TRISAbits.TRISA0=1;
    ANSELBbits.ANSB6=1;//B6 como digital
    TRISBbits.TRISB6=0; //B6 como salida transistor
    //****Convertidor Analógico-Digital
    ADCON0bits.ADON=1;
    ADCON0bits.ADCS=1;  
    ADREFbits.ADNREF=0;
    ADREFbits.ADPREF=0b00;
    ADCON0bits.ADFRM=1; //justificacion Derecha
    //Canal ANA4
    //Init LCD
    Lcd_Init();
    Lcd_Cmd(LCD_CLEAR);
    Lcd_Cmd(LCD_CURSOR_OFF);
    __delay_ms(100);
    while(1){
        
        ADPCH=0b000000; 
        __delay_ms(50);
        ADCON0bits.GO=1;
        while(ADCON0bits.GO);
        adc2= ADRESH;
        adc2= adc2<<8;
        adc2=adc2+ADRESL;
        volt1=((0.8)*adc2)/1023.0;//Voltaje
        sprintf(buffer1,"volt=%02.2f", volt1);
        Lcd_Out2(1,0,buffer1);
        __delay_ms(300);
         ADREFbits.ADNREF=0.25;
         ADREFbits.ADPREF=0.8;
         ADPCH=0b001000;
        __delay_ms(50);
        ADCON0bits.GO=1;
        while(ADCON0bits.GO);
        adc2= ADRESH;
        adc2= adc2<<8;
        adc2=adc2+ADRESL;
        volt2=5.0*adc2/1023.0;
        
       /* sprintf(buffer1,"ADC=%04d", adc);
        Lcd_Out2(1,0,buffer1);*/
        temp= volt2*100;
        sprintf(buffer1,"temp=%04.2f", temp);
        Lcd_Out2(2,0,buffer1);
        
        
        __delay_ms(300);
                   
        
    }
    
    return;
}