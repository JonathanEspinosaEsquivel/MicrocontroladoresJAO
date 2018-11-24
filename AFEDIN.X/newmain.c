/*
 * File:   newmain.c
 * Author: Travelur
 *
 * Created on 12 de septiembre de 2018, 05:58 PM
 */
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <xc.h>
#include "congif.h"
#define _XTAL_FREQ 32000000


void main(void) {
    
   OSCFRQbits.HFFRQ = 0b110;
   ANSELD = 0;
   PORTD = 0; 
   TRISD = 0; 
   ANSELC = 0; 
   PORTC = 0; 
   TRISC = 0;
   ANSELB = 0;
   PORTB = 0;
   TRISB = 0b00001111;
   WPUB= 0b00001111;
  
   
   
   
    unsigned char cabesaC[] = {255,255,255,255,
                                255,255,255,255};
    unsigned char cabesaf[] = {0,0,0,0,0,0,0,0}; 
                           
   
    int a=7;
    int b=7;
 
    cabesaC[b]=0b11111110;
    cabesaf[a]=0b00000001;
    int contador=1;
    int c;
    int y;
    int controll = 0;
    
   while(contador){
   
        for(c = 0; c<8; c++){
           for(y=0; y<8; y++){
           LATC=cabesaC[c];
           LATD=cabesaf[y];
           __delay_ms(6);
           } 
        }  
        
   
     
   if(PORTBbits.RB0 == 0){
      __delay_ms(100); 
     controll = 1;
     }
       
  if(PORTBbits.RB1 == 0){
    __delay_ms(100);
    controll = 2;
     }
      
  if(PORTBbits.RB2 == 0){
  __delay_ms(100); 
     controll = 3;
     }
      
  if(PORTBbits.RB3 == 0){
   __delay_ms(100); 
  controll = 4;
     }
       
        switch(controll){
            case 1:
            b=b-1;
                 
                 if(cabesaC[b+1]==254){
                   cabesaC [b]=253;  
                   cabesaC [b+1]=255;
                   break;
                }
                 if(cabesaC[b+1]==253){
                   cabesaC [b]=251;  
                   cabesaC [b+1]=255;
                  
                   break;
                }
                 if(cabesaC[b+1]==251){
                   cabesaC [b]=247;  
                   cabesaC [b+1]=255;
                   break;
                }
                 if(cabesaC[b+1]==247){
                   cabesaC [b]=239;  
                   cabesaC [b+1]=255;
                   break;
                }
                if(cabesaC[b+1]==239){
                    cabesaC [b]=223; 
                    cabesaC [b+1]=255;
                    break;
                }
                 if(cabesaC[b+1]==223){
                    cabesaC [b]=191; 
                    cabesaC [b+1]=255;
                    break;
                }
                if(cabesaC[b+1]==191){
                   cabesaC[b]=127; 
                 cabesaC[b+1]=255;
                   break;
                }
                  if(cabesaC[b+1]==127){                  
                   contador=0;
               }
                
                
         
            break;
            case 2:
            a=a-1;       
               
            cabesaf[a] = cabesaf[a+1]<<1;
            cabesaf[a+1] =0 ;
            if(a<0){
            contador=0;
            } 
               
            break;   
            case 3:
                  
            a=a+1;
                  
            cabesaf[a] = cabesaf[a-1]>>1;
            cabesaf[a-1] = 0;
              if(a>7){
                   a=0;
                   contador=0;
            }                         
            break;
            
            case 4:         
          b=b+1;              
                 if(cabesaC[b-1]==127){
                   cabesaC [b]=191;  
                   cabesaC [b-1]=255;
                   break;
                }
              
                 if(cabesaC[b-1]==191){
                   cabesaC [b]=223;  
                   cabesaC[b-1]=255;
                   break;
                }
                 if(cabesaC[b-1]==223){
                   cabesaC [b]=239;  
                  cabesaC [b-1]=255;
                   break;
                }
                 if(cabesaC[b-1]==239){
                   cabesaC [b]=247;  
                  cabesaC [b-1]=255;
                   break;
                }
              
              
                if(cabesaC[b-1]==247){
                    cabesaC [b]=251; 
                   cabesaC [b-1]=255;
     
                    break;
                }
                 if(cabesaC[b-1]==251){
                    cabesaC [b]=253; 
                    cabesaC [b-1]=255;
                    break;
                }
                if(cabesaC [b-1]==253){
                   cabesaC [b]=254; 
                   cabesaC [b-1]=255;
                   break;
                }
              
              
                if(cabesaC[b-1]==254){
                    
                    contador=0;
                    break;
                }                                                        
            break;
            }                   
        }    
        return;  
}
    
