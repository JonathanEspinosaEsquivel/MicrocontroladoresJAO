/*
 * File:   main3.c
 * Author: Travelur
 *
 * Created on 5 de septiembre de 2018, 05:28 PM
 */
#include <xc.h>
#include "config.h"
#include <stdio.h>
#define _XTAL_FREQ 32000000
#include "flex_lcd.h"


void main(void) {
    unsigned char i,j;
    unsigned char buffer1[16];
    //OSC****************************
    OSCFRQbits.HFFRQ=0b110; //32MHz
    //Puertos************************
    //ANSELD=0;//Puerto D como digital
    ANSELC=0;//Puerto E como digital
    //¨*********Inicialización LCD
    Lcd_Init(void);//Inicializa LCD
    Lcd_Cmd(LCD_CLEAR);//Limpia LCD
    Lcd_Cmd(LCD_CURSOR_OFF);//Apaga el cursor
    __delay_ms(100);//Retardo 100ms
    
    
    for(i=10;i>0; i--)
    {
        sprintf(buffer1,"cuenta %03d", i); //guardamos en el string
        Lcd_Out2(1,1,buffer1); //escribamos
        __delay_ms(100); //
    }
    
     Lcd_Out(2,1, "Mecatronica");//escribimos en la lcd
    __delay_ms(600); // esperamos 600ms
    Lcd_Cmd(LCD_BLINK_CURSOR_ON);
    __delay_ms(1000);
    Lcd_Cmd(LCD_UNDERLINE_ON);
    __delay_ms(1000);
    Lcd_Cmd(LCD_CURSOR_OFF);
    __delay_ms(1000);
    Lcd_Cmd(LCD_CLEAR);  
    Lcd_Out(1, 4, "Gracias");
    Lcd_Out(2, 4, "Thank you");
    
  
    
    
    //Clico infinito        
    while(1){
         
    }
    
    return;
}
