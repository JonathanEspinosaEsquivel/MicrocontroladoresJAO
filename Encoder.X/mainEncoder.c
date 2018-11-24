/*
 * 
 * File:   mainEncoder.c
 * Author: Travelur
 *
 * Created on 14 de noviembre de 2018, 08:44 PM
 */

#include "cofig.h"
#include <xc.h>
#include <stdio.h>
#define _XTAL_FREQ 32000000
#include "flex_lcd.h"
int x=0;
unsigned char bitActual=0;
  unsigned char bitPasado=0;
  unsigned char bitTotal=0;
  int cambio=0;
  float distancia=0;
void main(void) {
    
      //Oscilador
    OSCFRQbits.HFFRQ = 0b110; //16MHz
      unsigned char buffer1[16];
    //Puertos 
    ANSELC=0;
    PORTB=0;
    ANSELB=0;  
  TRISB=0b00000111;
  WPUBbits.WPUB2=1;
  //   WPUB=0b00000111;
  
   //IOC
  
    IOCBNbits.IOCBN1=1; //RB1 flanco de subida
  
    IOCBFbits.IOCBF1=0; //FLAG DE B1 ///A
    
   
    IOCBNbits.IOCBN0=1;  //RB0 flanco de subida
    IOCBFbits.IOCBF0=0; //FLAG DE BO ///B*///////////////////////////////
    
/*    IOCBPbits.IOCBP2=1; //RB2 flanco de BAJADA
    IOCBFbits.IOCBF2=0; //FLAG DE B2 ///B*/
    
   PIE0bits.IOCIE=1;   //ENABLE IOC  
      INTCONbits.PEIE=1;
    INTCONbits.GIE=1;//Global interrup enable
  
    
    Lcd_Init();
    Lcd_Cmd(LCD_CLEAR);
    Lcd_Cmd(LCD_CURSOR_OFF);
    
    
    
    while(1){
        if(PORTBbits.RB2==0){
            cambio=cambio+1;
            if(cambio==3){
                cambio=1;
            }
            __delay_ms(300);
            
        }
       
      distancia=(21.5*x)/20;
        
      sprintf(buffer1, "%03.2f cm",distancia);
      Lcd_Out2(2, 9, buffer1);
      
    
        
    }
    //Cuando gira a la izaquierda se produce flanco de subida en A y bajada en B;
    //Cuando gira a la derecha               flanco de subida en A y subida en A;
    
    return;
}

void __interrupt () INTERRUPCIONALVBB (void){
    
    
    if(cambio==1){
        
        
     if(IOCBFbits.IOCBF1==0&&IOCBFbits.IOCBF0==1){
        if( PORTBbits.RB1==1){
            if(PORTBbits.RB0==0){
            x=x-1;
            __delay_ms(3);
            }
        }
    }
        
        
        
        
        
        
        
    
  /*  if(IOCBFbits.IOCBF1==1&&IOCBFbits.IOCBF0==0){
        if( PORTBbits.RB1==0){
            if(PORTBbits.RB0==1){
            x=x+1;
            __delay_ms(3);
            }
        }
    }
    
     if(IOCBFbits.IOCBF1==0&&IOCBFbits.IOCBF0==1){
        if( PORTBbits.RB1==1){
            if(PORTBbits.RB0==0){
            x=x-1;
            __delay_ms(3);
            }
        }
    }*/
    
    }
    
     if(cambio==2){
    
    if(IOCBFbits.IOCBF1==1&&IOCBFbits.IOCBF0==0){
        if( PORTBbits.RB1==0){
            if(PORTBbits.RB0==1){
            x=x+1;
            __delay_ms(10);
            }
        }
    }
    
    }
    
    
  /*   if(PORTBbits.RB0==1){
        if( IOCBFbits.IOCBF0==0){
            x=x-1;
            __delay_ms(3);
        }
    }
    */
    
    
    
    
    
  /*  if(  IOCBFbits.IOCBF1==1){
    bitActual=(PORTBbits.RB1<<1) | PORTBbits.RB0;
    bitTotal=(bitPasado<<2)|bitActual;

     
    if((bitTotal==13) ||(bitTotal==4) ||(bitTotal==2) ||(bitTotal==11) ) {
        x=x+1;
        
    }
     if((bitTotal==14) ||(bitTotal==7) ||(bitTotal==1) ||(bitTotal==8) ) {
         x=x-1;
        
    }
    }
    bitPasado=bitActual;
    */
    IOCBFbits.IOCBF1=0;

     IOCBFbits.IOCBF0=0;
   
}