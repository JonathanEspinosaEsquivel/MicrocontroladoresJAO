/*
 * File:   Resuelve.c
 * Author: Travelur
 *
 * Created on 21 de octubre de 2018, 10:53 AM
 */


#include <pic16f18877.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "config.h"
#include <xc.h>
#define _XTAL_FREQ 32000000
int a=0;
int distancia1(void);
int distancia2(void);
int distancia3(void);

int ref1=0;
int ref2=0;
int ref3=0;
int velocidad=950;
void main(void) {
     OSCFRQbits.HFFRQ=0b110; // 32MHz
     //Puertos
    PORTA=0;            //Limpiamos puertos A
    ANSELA=0;           //Puerto a como digital
    TRISAbits.TRISA0=0;  //Trigger OUTPUT Signal
    TRISAbits.TRISA1=1; //Echo INPUT Signal --------> S1
    TRISAbits.TRISA2=0;  //Trigger OUTPUT Signal
    TRISAbits.TRISA3=1; //Echo INPUT Signal---------> S2
    TRISAbits.TRISA4=0;  //Trigger OUTPUT Signal
    TRISAbits.TRISA5=1; //Echo INPUT Signal---------> S3
    PORTC=0;
    ANSELCbits.ANSC2=0;
    ANSELCbits.ANSC3=0;
    ANSELCbits.ANSC4=0;
    ANSELCbits.ANSC5=0;
    TRISC=0;
       
   //Configuracion del TIMER1
    T1CONbits.CKPS = 0b11;  //Prescale value 8
    T1CONbits.nT1SYNC=1;    //No sincronizada
    T1CLKbits.CS= 0b0001;   // FOSC/4
   // T1CONbits.ON=1;  //Abilita el timer 1
     TMR1=0;
     
     
     
       //Configuracion  CCP1  pwm
   
    RC0PPS=0x09; //Salida CCP1 ----> RCO
    CCP1CONbits.EN=1; //Habilita CCP1
    CCP1CONbits.MODE=0b1111; //PWM mode
    //PR2=255;
  
     //Configuracion  CCP2  pwm
   
    RC1PPS=0x0A; //Salida CCP2 ----> RC1
    CCP2CONbits.EN=1; //Habilita CCP1
    CCP2CONbits.MODE=0b1111; //PWM mode
    PR2=255;
    
    CCPR2=900;
    CCPR1=900;


    
    CCPTMRS0bits.C1TSEL=0b01; //Seleccion timer TMR2 CCP1
    CCPTMRS0bits.C2TSEL=0b01; //Seleccion timer TMR2 CCP2
     
    //Configuracion de interrucion Timer1   
    PIR4bits.TMR1IF=0;  ///// FLAG
    PIE4bits.TMR1IE=1;  ////  Enable
    INTCONbits.PEIE=1;  //Habilitar interruciones por periferico
     //TIMER2
    T2CLKCONbits.CS= 0b0010;  // FOSC
    T2CONbits.OUTPS=0; //Porstcaler 1:1
    T2CONbits.T2CKPS=0b100; // Prescaler 1:16
    T2CONbits.ON=1; //INICIALIZA timer2
    PIR4bits.TMR2IF=0;
    PIE4bits.TMR2IE=1;
    //ENABLE TIMER
    INTCONbits.GIE=1;   //Global interrup enable
    
    int error=0;
      int d=0; //Veces que gira a la derecha
      int i=0; //Veces que gira a la izquierda
     int privilegio=0; //privilegio 1 derecha primero ;privilegio 2 izquierda primero; privilegio=0 desactiva todo...
     int logicaRight=0; //logicaRight = 1 activa la logica 
     int logicaLeft=1; //logicaLeft = 1 activa la logica 
     int logicaAlAzar=0; //logicaAlAzar=1 activa la logica
     int contadorLogicas;
     int D1=0;
     int D2=0;
     int D3=0;
     int d1;
     int i1;
     int cortador;
     int cortadorPrivilegio=0;////// 0 si queremos activar una logica
     int contador;
     int azar;
     __delay_ms(1000);
     ref1=distancia1();
     ref2=distancia2();
     ref3=distancia3();
     __delay_ms(2000);
     
     while(1){
         while(cortadorPrivilegio){
             
         if(privilegio==1){
             for(d1=0;d1<d;d1++){
                 cortador=1;
                 while(cortador){
                     //Capturas de distancias
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   if(D2>10){
                       LATCbits.LATC4=1;//avanzas 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(300);
                        D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if(D1<3){
                       CCPR1=1023;
                       CCPR2=900;
                   }
                   if(D3<3){
                       CCPR1=900;
                       CCPR2=1023;
                   }
                   
                   if(D3==D1){
                       CCPR1=1023;
                       CCPR2=1023;
                   }
                   if(D1>10&&D2<7&&D3<7){
                      __delay_ms(500); //Checar ya en las pruebas para que avance poquito despues de seguir adelante
                       LATCbits.LATC4=1;//giro izquierda forzado unico camino... 
                       LATCbits.LATC5=1;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                        __delay_ms(1000); //Checar ya en las pruebas que de bien la vuelta
                       LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(500); //Checar ya en las pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if(D1<7&&D2<7&&D3<7){
                       LATCbits.LATC4=0;//giro
                       LATCbits.LATC5=1;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(1000);//Checar en pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                    if(D3>10){
                       __delay_ms(500); //Checar ya en las pruebas para que avance poquito despues de seguir adelante
                       LATCbits.LATC4=1;//giro derecha 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=1;
                       __delay_ms(1000); //Checar ya en las pruebas
                        LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(500); //Checar ya en las pruebas
                       cortador=0;
                   } 
                     
                 }         
              
             }
             privilegio=2;
             contador=contador+1;
         }
         
         if(contador==2){
             cortadorPrivilegio=0;
             privilegio=0;
         }
         
          if(privilegio==2){
             for(i1=0;i1<i;i1++){
                 cortador=1;
                 while(cortador){
                     //Capturas de distancias
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   if(D2>10){
                       LATCbits.LATC4=1;//avanzas 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                   __delay_ms(300);
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if(D1<3){
                       CCPR1=1023;
                       CCPR2=900;
                   }
                   if(D3<3){
                       CCPR1=900;
                       CCPR2=1023;
                   }
                   
                   if(D3==D1){
                       CCPR1=1023;
                       CCPR2=1023;
                   }
                   if(D1<7&&D2<7&&D3>10){
                      __delay_ms(500); //Checar ya en las pruebas para que avance poquito despues de seguir adelante
                       LATCbits.LATC4=1;//giro derecha forzado unico camino... 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=1;
                        __delay_ms(1000); //Checar ya en las pruebas que de bien la vuelta
                       LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(500); //Checar ya en las pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if(D1<7&&D2<7&&D3<7){
                       LATCbits.LATC4=0;//giro
                       LATCbits.LATC5=1;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(1000);//Checar en pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                    if(D1>10){
                       __delay_ms(500); //Checar ya en las pruebas para que avance poquito despues de seguir adelante
                       LATCbits.LATC4=1;//giro izquierda 
                       LATCbits.LATC5=1;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(1000); //Checar ya en las pruebas
                       LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(500); //Checar ya en las pruebas
                       cortador=0;
                   } 
                     
                 }         
              
             }
             privilegio=1;
             contador=contador+1;
         }
         
         if(contador==2){
             cortadorPrivilegio=0;
         }
         }
         
         
         if(logicaRight==1){
             
                contadorLogicas=0;
                 azar= rand () % 7;
             while(1){
                 
                   if(azar==0){
                   azar=1;
                   }
                    //Capturas de distancias
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   if(D2>15){
                       LATCbits.LATC4=1;//avanzas 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(300);
                        D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if(D1<8){
                       CCPR1=900;
                       CCPR2=800;
                   }
                   if(D3<8){
                       CCPR1=800;
                       CCPR2=900;
                   }
                   
                   if(D3==D1){
                       CCPR1=900;
                       CCPR2=900;
                   }
                   if(D1>15&&D2<15&&D3<15){
                         CCPR1=900;
                       CCPR2=900;
                      __delay_ms(150); //Checar ya en las pruebas para que avance poquito despues de seguir adelante
                       LATCbits.LATC4=1;//giro izquierda forzado unico camino... 
                       LATCbits.LATC5=1;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                        __delay_ms(750); //Checar ya en las pruebas que de bien la vuelta
                       LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(300); //Checar ya en las pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if(D1<15&&D2<15&&D3<15){
                         CCPR1=900;
                       CCPR2=900;
                       LATCbits.LATC4=0;//giro
                       LATCbits.LATC5=1;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(950);//Checar en pruebas
                       LATCbits.LATC4=1;//Avanzar poquito para volver a medir
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(300);//checar en pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                    if(D3>15){
                         CCPR1=900;
                       CCPR2=900;
                       __delay_ms(250); //Checar ya en las pruebas para que avance poquito despues de seguir adelante
                       LATCbits.LATC4=1;//giro derecha 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=1;
                       __delay_ms(750); //Checar ya en las pruebas
                        LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(300); //Checar ya en las pruebas
                       contadorLogicas=contadorLogicas+1;
                       if(contadorLogicas>=azar){
                            azar= rand () % 7;
                            contadorLogicas=0;
                             cortador=1;
                                 while(cortador){
                                     
                                     if(azar==0){
                                         azar=1;
                                     }
                                     
                                     
                     //Capturas de distancias
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   if(D2>15){
                       LATCbits.LATC4=1;//avanzas 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if(D1<8){
                       CCPR1=900;
                       CCPR2=800;
                   }
                   if(D3<8){
                       CCPR1=800;
                       CCPR2=900;
                   }
                   
                   if(D3==D1){
                       CCPR1=900;
                       CCPR2=900;
                   }
                   if(D1<15&&D2<15&&D3>15){
                        CCPR1=900;
                       CCPR2=900;
                      __delay_ms(150); //Checar ya en las pruebas para que avance poquito despues de seguir adelante
                       LATCbits.LATC4=1;//giro derecha forzado unico camino... 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=1;
                        __delay_ms(750); //Checar ya en las pruebas que de bien la vuelta
                       LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(300); //Checar ya en las pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if(D1<15&&D2<15&&D3<15){
                       CCPR1=900;
                       CCPR2=900;
                       LATCbits.LATC4=0;//giro
                       LATCbits.LATC5=1;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(950);//Checar en pruebas
                        
                       LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                        __delay_ms(300);
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                    if(D1>15){
                        
                        CCPR1=900;
                        CCPR2=900;
                        
                       __delay_ms(250); //Checar ya en las pruebas para que avance poquito despues de seguir adelante
                       LATCbits.LATC4=1;//giro izquierda 
                       LATCbits.LATC5=1;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(750); //Checar ya en las pruebas
                       LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(300); //Checar ya en las pruebas
                       cortador=0;
                   } 
                     
                 } 
                             
                             
                             
                             
                             
                             
                       }
                   
                   }
                 
                 
             }            
         }
         
         
       if(logicaLeft==1){
             
              
               contadorLogicas=0;
               
                 azar= rand () % 7;
             while(1){
                 
               
               if(azar==0){
                   azar=1;
               }
                 
                   //Capturas de distancias
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   if(D2>ref2){
                       if(D1==D3){
                           CCPR2=velocidad;
                           CCPR1=velocidad;
                       LATCbits.LATC4=1;//avanzas 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       
                       }else{
                        LATCbits.LATC4=1;//avanzas 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                           if(((D3<ref3)&&(D1<10))||((D1>10)&&(D3<ref3))||((D1<10)&&(D3>ref3))){
                               error=ref3-D3;
                               CCPR2=velocidad+(error*10);
                               CCPR1=velocidad-(error*10);
                               //peindiente cambio de correccion lenta.....
                               
                           }
                            if(((D1<ref1)&&(D3<10))||((D3>10)&&(D1<ref1))||((D3<10)&&(D1>ref1))){
                               error=ref1-D1;
                               CCPR2=velocidad-(error*10);
                               CCPR1=velocidad+(error*10);
                           }
                       
                       }
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                  
                   
                   
                   if((D1<ref1+1)&&(D2<ref2+1)&&(D3>ref3+1)){
                        CCPR1=1000;
                       CCPR2=1000;
                       LATCbits.LATC4=1;//giro derecha forzado unico camino... 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=1;
                        __delay_ms(610); //Checar ya en las pruebas que de bien la vuelta
                       LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(80); //Checar ya en las pruebasEl que se mueve gggg  // tenia 110;
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if((D1<ref1+1)&&(D2<ref2+1)&&(D3<ref3)){
                        CCPR1=1000;
                       CCPR2=1000;
                       LATCbits.LATC4=1;//giro
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=0;
                       LATCbits.LATC3=1;
                       __delay_ms(700);//Checar en pruebas
                          LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(100); //Checar ya en las pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                    if((D1>ref1+5)&&(D2<ref2+2)){
                         CCPR1=1000;
                       CCPR2=1000;
                   ///          por si quiero que solamente gire cuando D1>REF+5    __delay_ms(138); //Checar ya en las pruebas para que avance poquito despues de seguir adelante
                       LATCbits.LATC4=1;//giro izquierda 
                       LATCbits.LATC5=1;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(690); //Checar ya en las pruebas
                       LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(95); //Checar ya en las pruebas/////////////////////////////////////////
                      contadorLogicas= contadorLogicas+1;
          if(contadorLogicas>=azar){
             
                            contadorLogicas=0;
                             cortador=1;
                              azar= rand () % 7;
                 while(cortador){
                  
               
               if(azar==0){
                   azar=1;
               }
                     
                     
                     //Capturas de distancias
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                 if(D2>ref2){
                       if(D1==D3){
                           CCPR2=velocidad;
                           CCPR1=velocidad;
                       LATCbits.LATC4=1;//avanzas 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       
                       }else{
                        LATCbits.LATC4=1;//avanzas 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                           if(((D3<ref3)&&(D1<10))||((D1>10)&&(D3<ref3))||((D1<10)&&(D3>ref3))){
                               error=ref3-D3;
                               CCPR2=velocidad+(error*10);
                               CCPR1=velocidad-(error*10);
                               //peindiente cambio de correccion lenta.....
                               
                           }
                            if(((D1<ref1)&&(D3<10))||((D3>10)&&(D1<ref1))||((D3<10)&&(D1>ref1))){
                               error=ref1-D1;
                               CCPR2=velocidad-(error*10);
                               CCPR1=velocidad+(error*10);
                           }
                       
                       }
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if(D1>15&&D2<15&&D3<15){
                        CCPR1=900;
                       CCPR2=900;
                    //  __delay_ms(115); //Checar ya en las pruebas para que avance poquito despues de seguir adelante
                       LATCbits.LATC4=1;//giro izquierda forzado unico camino... 
                       LATCbits.LATC5=1;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                        __delay_ms(710); //Checar ya en las pruebas que de bien la vuelta
                       LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(110); //Checar ya en las pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if(D1<15&&D2<8&&D3<15){
                        CCPR1=900;
                       CCPR2=900;
                       LATCbits.LATC4=1;//giro /////PENDIENTE POSIBLE CAMBIO
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=0;
                       LATCbits.LATC3=1;
                       __delay_ms(700);//Checar en pruebas
                          LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(100); //Checar ya en las pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                    if(D3>20){
                         CCPR1=900;
                       CCPR2=900;
                       __delay_ms(138); //Checar ya en las pruebas para que avance poquito despues de seguir adelante/////
                       LATCbits.LATC4=1;//giro derecha 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=1;
                       __delay_ms(610); //Checar ya en las pruebas
                        LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(95); //Checar ya en las pruebas/////////////////////
                       cortador=0;
                   } 
                     
                 } 
                          
                   
                   } 
                 
             }
             
           }
         
         
         
         
         if(logicaAlAzar==1){
             
             while(1){
             azar= rand () % 2;//generar random
            
             
             
              if(azar==0){  //para el frente
             while(cortador){
                     //Capturas de distancias
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   if(D2>10){
                       LATCbits.LATC4=1;//avanzas 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                   __delay_ms(300);
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if(D1<3){
                       CCPR1=1023;
                       CCPR2=900;
                   }
                   if(D3<3){
                       CCPR1=900;
                       CCPR2=1023;
                   }
                   
                   if(D3==D1){
                       CCPR1=1023;
                       CCPR2=1023;
                   }
                    if(D1>10&&D2<7&&D3<7){
                      __delay_ms(500); //Checar ya en las pruebas para que avance poquito despues de seguir adelante
                       LATCbits.LATC4=1;//giro izquierda forzado unico camino... 
                       LATCbits.LATC5=1;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                        __delay_ms(1000); //Checar ya en las pruebas que de bien la vuelta
                       LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(500); //Checar ya en las pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   
                   
                   if(D3<7&&D2<7&&D3>10){
                      __delay_ms(500); //Checar ya en las pruebas para que avance poquito despues de seguir adelante
                       LATCbits.LATC4=1;//giro derecha forzado unico camino... 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=1;
                        __delay_ms(1000); //Checar ya en las pruebas que de bien la vuelta
                       LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(500); //Checar ya en las pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if(D1<7&&D2<7&&D3<7){
                       LATCbits.LATC4=0;//giro
                       LATCbits.LATC5=1;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(1000);//Checar en pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                    if((D2>10&&D1<7&&D3<7)||(D2>10&&D1>10&&D3>10)||(D2>10&&D1<7&&D3>7)||(D2>10&&D1>7&&D3<7)){
                       LATCbits.LATC4=1;//DE FRENTE
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(2000); //Checar ya en las pruebas
                       cortador=0;
                   }
                  azar= rand () % 2;//generar random   
                 } 

             }
             
              
             
             
             
             if(azar==1){ //para la izquierda
             while(cortador){
                     //Capturas de distancias
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   if(D2>10){
                       LATCbits.LATC4=1;//avanzas 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                   __delay_ms(300);
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if(D1<3){
                       CCPR1=1023;
                       CCPR2=900;
                   }
                   if(D3<3){
                       CCPR1=900;
                       CCPR2=1023;
                   }
                   
                   if(D3==D1){
                       CCPR1=1023;
                       CCPR2=1023;
                   }
                   if(D1<7&&D2<7&&D3>10){
                      __delay_ms(500); //Checar ya en las pruebas para que avance poquito despues de seguir adelante
                       LATCbits.LATC4=1;//giro derecha forzado unico camino... 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=1;
                        __delay_ms(1000); //Checar ya en las pruebas que de bien la vuelta
                       LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(500); //Checar ya en las pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if(D1<7&&D2<7&&D3<7){
                       LATCbits.LATC4=0;//giro
                       LATCbits.LATC5=1;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(1000);//Checar en pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                    if(D1>10){
                       __delay_ms(500); //Checar ya en las pruebas para que avance poquito despues de seguir adelante
                       LATCbits.LATC4=1;//giro izquierda 
                       LATCbits.LATC5=1;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(1000); //Checar ya en las pruebas
                       LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(500); //Checar ya en las pruebas
                       cortador=0;
                   }
                    azar= rand () % 2;//generar random  
                     
                 } 

             }
             
           
             
             
             
             
          if(azar==2){       //giro derecha
              while(cortador){
                    //Capturas de distancias
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   if(D2>10){
                       LATCbits.LATC4=1;//avanzas 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(300);
                        D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if(D1<3){
                       CCPR1=1023;
                       CCPR2=900;
                   }
                   if(D3<3){
                       CCPR1=900;
                       CCPR2=1023;
                   }
                   
                   if(D3==D1){
                       CCPR1=1023;
                       CCPR2=1023;
                   }
                   if(D1>10&&D2<7&&D3<7){
                      __delay_ms(500); //Checar ya en las pruebas para que avance poquito despues de seguir adelante
                       LATCbits.LATC4=1;//giro izquierda forzado unico camino... 
                       LATCbits.LATC5=1;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                        __delay_ms(1000); //Checar ya en las pruebas que de bien la vuelta
                       LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(500); //Checar ya en las pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                   if(D1<7&&D2<7&&D3<7){
                       LATCbits.LATC4=0;//giro
                       LATCbits.LATC5=1;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(1000);//Checar en pruebas
                   D1=distancia1();
                   D2=distancia2();
                   D3=distancia3(); 
                   }
                    if(D3>10){
                       __delay_ms(500); //Checar ya en las pruebas para que avance poquito despues de seguir adelante
                       LATCbits.LATC4=1;//giro derecha 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=1;
                       __delay_ms(1000); //Checar ya en las pruebas
                        LATCbits.LATC4=1;//Avanzar poquito para volver a medir 
                       LATCbits.LATC5=0;
                       LATCbits.LATC2=1;
                       LATCbits.LATC3=0;
                       __delay_ms(500); //Checar ya en las pruebas
                    cortador=0;
                   }
                  azar= rand () % 2;//generar random  
                 
             }           
             
             
          }
             
             
             
             
             }
         }
         
         
         
         
         
     }
     
    return;
}
}
void __interrupt () INTERRUp (void){
     PIR4bits.TMR1IF=0;
     PIR4bits.TMR2IF=0; 
}
int distancia1(void){
    int distancia1=0;
    float t=0;
      ///////////Lecturas de distancia D1
         LATAbits.LATA0=1;         //Iniciamos el pulso
      __delay_us(10);           //Duracion del pulso
      LATAbits.LATA0=0;         //Desactivamos el pulso
      while(!PORTAbits.RA1);    //Espera el rebote del pulso
      T1CONbits.ON=1;           //Inicia la cuenta
      while((PORTAbits.RA1==1) && (PIR4bits.TMR1IF==0));    //Termina el pulso sin desbordarse  
          T1CONbits.ON=0;                               //Finaliza la cuenta
          a=TMR1;                                       //Variable "a" igual al conteo entre la entrada del rebote y el fin del pulso
          TMR1=0; 
        t=(0.000001)*(a)/2;         //Calculo del tiempo
        distancia1=(34000*t);        //Calculo de distancia=velocidad*tiempo
    
    
    return distancia1;
}
int distancia2(void){
       int distancia2=0;
    float t=0;
    ///////////Lecturas de distancia D2
         LATAbits.LATA2=1;         //Iniciamos el pulso
      __delay_us(10);           //Duracion del pulso
      LATAbits.LATA2=0;         //Desactivamos el pulso
      while(!PORTAbits.RA3);    //Espera el rebote del pulso
      T1CONbits.ON=1;           //Inicia la cuenta
      while(PORTAbits.RA3==1 && PIR4bits.TMR1IF==0);    //Termina el pulso sin desbordarse  
          T1CONbits.ON=0;                               //Finaliza la cuenta
          a=TMR1;                                       //Variable "a" igual al conteo entre la entrada del rebote y el fin del pulso
          TMR1=0; 
        t=(0.000001)*(a)/2;         //Calculo del tiempo
        distancia2=(34000*t);        //Calculo de distancia=velocidad*tiempo
        
    
    
    return distancia2;
}
int distancia3(void){
      int distancia3=0;
      float t=0;
     ///////////Lecturas de distancia D3
         LATAbits.LATA4=1;         //Iniciamos el pulso
      __delay_us(10);           //Duracion del pulso
      LATAbits.LATA4=0;         //Desactivamos el pulso
      while(!PORTAbits.RA5);    //Espera el rebote del pulso
      T1CONbits.ON=1;           //Inicia la cuenta
      while(PORTAbits.RA5==1 && PIR4bits.TMR1IF==0);    //Termina el pulso sin desbordarse  
          T1CONbits.ON=0;                               //Finaliza la cuenta
          a=TMR1;                                       //Variable "a" igual al conteo entre la entrada del rebote y el fin del pulso
          TMR1=0; 
        t=(0.000001)*(a)/2;         //Calculo del tiempo
        distancia3=(34000*t);        //Calculo de distancia=velocidad*tiempo
    return distancia3;
}
