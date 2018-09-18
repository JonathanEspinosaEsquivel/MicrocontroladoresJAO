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
#include "config1.h"
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
                           
   
    int a=6;
    int b=2;
 
    cabesaC[a]=64;
    cabesaf[b]=251;
    int contador=1;
    int c;
     int controll = 0;
    
    //unsigned char columna;
   while(contador){
   
    
     
     //  int num ;      
     //  num = rand();
     //  while (num>7){  
     // num=rand();
     // } 
//      fportd[num]=comidaf[num];
  // CportC[num]=comidac[num];                   
       
       //Aqui se imprime la cabeza...
        for(c = 0; c<8; c++){
           for(y=0; y<8; y++){
           LATC=cabesaC[c];
           LATD=cabesaf[y];
           __delay_ms(2);
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
               
            a=a+1;
                  
            cabesaf[a] = cabesaf[a-1]>>1;
            cabesaf[a-1] = 0;
              if(a>7){
                   a=0;
                   contador=0;
            }    
             
            break;
            case 2:
            a=a-1;       
               
            cabesaf[a] = cabesaf[a+1]<<1;
            cabesaf[f+1] =0 ;
            if(a<0){
            contador=0;
            } 
               
            break;   
            case 3:
                b=b+1;              
                 if(cabesaC[b-1]==0b01111111){
                   cabesaC [b]=0b10111111;  
                   cabesaC [b-1]=0b11111111;
                   break;
                }
              
                 if(cabesaC[b-1]==0b10111111){
                   cabesaC [b]=0b11011111;  
                   cabesaC[b-1]=0b11111111;
                   break;
                }
                 if(cabesaC[b-1]==0b11011111){
                   cabesaC [b]=0b11101111;  
                  cabesaC [b-1]=0b11111111;
                   break;
                }
                 if(cabesaC[b-1]==0b11101111){
                   cabesaC [b]=0b11110111;  
                  cabesaC [b-1]=0b11111111;
                   break;
                }
              
              
                if(cabesaC[b-1]==0b11110111){
                    cabesaC [b]=0b11111011; 
                   cabesaC [b-1]=0b11111111;
     
                    break;
                }
                 if(cabesaC[b-1]==0b11111011){
                    cabesaC [b]=0b11111101; 
                    cabesaC [b-1]=0b11111111;
                    break;
                }
                if(cabesaC [b-1]==0b11111101){
                   cabesaC [b]=0b11111110; 
                   cabesaC [b-1]=0b11111111;
                   break;
                }
              
              
                if(cabesaC[b-1]==0b11111110){
                    
                    contador=0;
                    break;
                }
               
          
                               
            break;
            
            case 4:         
            b=b-1;
                 
                 if(cabesaC[b+1]==0b11111110){
                   cabesaC [b]=0b11111101;  
                   cabesaC [b+1]=0b11111111;
                   break;
                }
                 if(cabesaC[b+1]==0b11111101){
                   cabesaC [b]=0b11111011;  
                   cabesaC [b+1]=0b11111111;
                  
                   break;
                }
                 if(cabesaC[b+1]==0b11111011){
                   cabesaC [b]=0b11110111;  
                   cabesaC [b+1]=0b11111111;
                   break;
                }
                 if(cabesaC[b+1]==0b11110111){
                   cabesaC [b]=0b11101111;  
                   cabesaC [b+1]=0b11111111;
                   break;
                }
                if(cabesaC[b+1]==0b11101111){
                    cabesaC [b]=0b11011111; 
                    cabesaC [b+1]=0b11111111;
                    break;
                }
                 if(cabesaC[b+1]==0b11011111){
                    cabesaC [b]=0b10111111; 
                    cabesaC [b+1]=0b11111111;
                    break;
                }
                if(cabesaC[b+1]==0b10111111){
                   cabesaC[b]=0b01111111; 
                 cabesaC[b+1]=0b11111111;
                   break;
                }
                  if(cabesaC[b+1]==0b01111111){                  
                   contador=0;
               }
                
                
            break;
            }                   
        }    
        return;  
}
    








  a=a-1;       
               
            cabesaf[a] = cabesaf[a+1]<<1;
            cabesaf[f+1] =0 ;
              if(a<0){
                contador=0;
              } 