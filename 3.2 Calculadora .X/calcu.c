/*
 * File:   calcu.c
 * Author: Travelur
 *
 * Created on 24 de septiembre de 2018, 09:53 PM
 */
#include <xc.h>
#include "config.h"
#include <stdio.h>
#define _XTAL_FREQ 32000000 //su usa cuando usamos delays
#include "flex_lcd.h"
int reinicio;
int contadorsuma=0;
int columna;
int numero;
int signo=0;
int cuenta3=0;
int unidad=0;
int decena=0;
int centena=0;
int valorunolcd;   
int valordoslcd;
int resultado;
int uno=1;
int signosecundario=0;
int signoprimario;
void main(void) {
    //Oscilador
    OSCFRQbits.HFFRQ = 0b110; //16MHz
    
    unsigned char buffer1[16];
    unsigned char columna1[]={0b00001000,0b00000100,0b00000010,0b00000001};
    
    //Puertos 
    
   
    PORTA=0;          //Limpia puertos A
    PORTB=0;          //Limpia puertos B
    ANSELA=0;         //Todo digital 
    ANSELB=0;         //Todo digital
    TRISA=0b00001111; //Entradas para las flag
    TRISB=0b00000000; //Salidas para los barrimientos
    WPUB=0b11111111;
    //WPUA=0b11111111;  // parece que no se necesitara...
    ANSELC=0; 
    Lcd_Init();              //Inicializa LCD
    Lcd_Cmd(LCD_CLEAR);
    Lcd_Cmd(LCD_CURSOR_OFF);
  
    
    //IOC
    IOCAPbits.IOCAP0=1; //RA0 flanco de subida
    IOCAFbits.IOCAF0=0; //FLAG DE A0
    
    IOCAPbits.IOCAP1=1; //RA0 flanco de subida
    IOCAFbits.IOCAF1=0; //FLAG DE A0
    
    IOCAPbits.IOCAP2=1; //RA0 flanco de subida
    IOCAFbits.IOCAF2=0; //FLAG DE A0
    
    IOCAPbits.IOCAP3=1; //RA0 flanco de subida
    IOCAFbits.IOCAF3=0; //FLAG DE A0
    
    PIR0bits.IOCIF=0;   //FLAG GENERAL
    PIE0bits.IOCIE=1;   //ENABLE IOC 
    INTCONbits.GIE=1;//Global interrup enable
    //variables
    
    int a;
  

    while(uno){
        
        for(a=0;a<4;a++){
            columna=a;
           LATB=columna1[a];
           __delay_ms(10);
        }
        
        
      //escribimos en la lcd    
    
      if(signo==0){  
           
          
      sprintf(buffer1, "%05d",valorunolcd);
      Lcd_Out2(2, 9, buffer1); 
       sprintf(buffer1, "%05d",valordoslcd);
      Lcd_Out2(1, 9, buffer1);
      
      }
      
       if(signo==222){  
      sprintf(buffer1, "        ");
      Lcd_Out(1, 9, buffer1); 
       sprintf(buffer1, "%05d",resultado);
      Lcd_Out2(2, 9, buffer1);
      
      reinicio=69;
      
      }
     
    
    }

    return;
}

void __interrupt () calculadora (void){
 
    //****************COLUMNA 0//
    signoprimario= signosecundario;
    
    if((columna==0)&&(reinicio==69)){
        uno=0;
    }
    if((columna==1)&&(reinicio==69)){
        uno=0;
    }
    if((columna==2)&&(reinicio==69)){
        uno=0;
    }
    if((columna==3)&&(reinicio==69)){
        uno=0;
    }
    
    
    
     if((IOCAFbits.IOCAF0==1)&&(columna==0)){   //AQUI SERIA EL SIGNO Y LE SIGUE EL 3,2,1 GG ERROR DE DISEÑO
         cuenta3=cuenta3+1;
          __delay_ms(500);//Espera 500ms
         numero=1;
         IOCAFbits.IOCAF0=0;    //Limpia bandera individual
         PIR0bits.IOCIF=0;      //Limpia bandera general
     }
     if((IOCAFbits.IOCAF1==1)&&(columna==0)){
          cuenta3=cuenta3+1;
          __delay_ms(500);//Espera 500ms
         numero=2;
         IOCAFbits.IOCAF1=0;    //Limpia bandera individual
         PIR0bits.IOCIF=0;      //Limpia bandera general
     }
     if((IOCAFbits.IOCAF2==1)&&(columna==0)){
          cuenta3=cuenta3+1;
          __delay_ms(500);//Espera 500ms
         numero=3;
         IOCAFbits.IOCAF2=0;    //Limpia bandera individual
         PIR0bits.IOCIF=0;      //Limpia bandera general
     }
     if((IOCAFbits.IOCAF3==1)&&(columna==0)){ //************Exclusivo para signos....
          __delay_ms(500);//Espera 500ms
         signo=444;
         IOCAFbits.IOCAF3=0;    //Limpia bandera individual
         PIR0bits.IOCIF=0;      //Limpia bandera general
         signosecundario=444;
     }
     
     //****************SIGUIENTE COLUMNA 1//
      if((IOCAFbits.IOCAF0==1)&&(columna==1)){
           cuenta3=cuenta3+1;
          __delay_ms(500);//Espera 500ms
         numero=4;
         IOCAFbits.IOCAF0=0;    //Limpia bandera individual
         PIR0bits.IOCIF=0;      //Limpia bandera general
     }
     if((IOCAFbits.IOCAF1==1)&&(columna==1)){
          cuenta3=cuenta3+1;
          __delay_ms(500);//Espera 500ms
         numero=5;
         IOCAFbits.IOCAF1=0;    //Limpia bandera individual
         PIR0bits.IOCIF=0;      //Limpia bandera general
     }
     if((IOCAFbits.IOCAF2==1)&&(columna==1)){
          cuenta3=cuenta3+1;
          __delay_ms(500);//Espera 500ms
         numero=6;
         IOCAFbits.IOCAF2=0;    //Limpia bandera individual
         PIR0bits.IOCIF=0;      //Limpia bandera general
     }
     if((IOCAFbits.IOCAF3==1)&&(columna==1)){ //************Exclusivo para signos....
          __delay_ms(500);//Espera 500ms
         signo=555;
         IOCAFbits.IOCAF3=0;    //Limpia bandera individual
         PIR0bits.IOCIF=0;      //Limpia bandera general
         signosecundario=555;
         
     }
    
      //****************SIGUIENTE COLUMNA 2//
      if((IOCAFbits.IOCAF0==1)&&(columna==2)){
           cuenta3=cuenta3+1;
          __delay_ms(500);//Espera 500ms
         numero=7;
         IOCAFbits.IOCAF0=0;    //Limpia bandera individual
         PIR0bits.IOCIF=0;      //Limpia bandera general
     }
     if((IOCAFbits.IOCAF1==1)&&(columna==2)){
          cuenta3=cuenta3+1;
          __delay_ms(500);//Espera 500ms
         numero=8;
         IOCAFbits.IOCAF1=0;    //Limpia bandera individual
         PIR0bits.IOCIF=0;      //Limpia bandera general
     }
     if((IOCAFbits.IOCAF2==1)&&(columna==2)){
          cuenta3=cuenta3+1;
          __delay_ms(500);//Espera 500ms
         numero=9;
         IOCAFbits.IOCAF2=0;    //Limpia bandera individual
         PIR0bits.IOCIF=0;      //Limpia bandera general
     }
     if((IOCAFbits.IOCAF3==1)&&(columna==2)){ //************Exclusivo para signos....
          __delay_ms(500);//Espera 500ms
         signo=666;
         IOCAFbits.IOCAF3=0;    //Limpia bandera individual
         PIR0bits.IOCIF=0;      //Limpia bandera general
         signosecundario=666;
       
         
         
     }
     
      //****************SIGUIENTE COLUMNA 3//
      if((IOCAFbits.IOCAF0==1)&&(columna==3)){
           cuenta3=cuenta3+1;
          __delay_ms(500);//Espera 500ms
         numero=0;
         IOCAFbits.IOCAF0=0;    //Limpia bandera individual
         PIR0bits.IOCIF=0;      //Limpia bandera general
     }
     if((IOCAFbits.IOCAF1==1)&&(columna==3)){
         
          __delay_ms(500);//Espera 500ms
        signo=888;
         IOCAFbits.IOCAF1=0;    //Limpia bandera individual
         PIR0bits.IOCIF=0;      //Limpia bandera general
     }
     if((IOCAFbits.IOCAF2==1)&&(columna==3)){
        
          __delay_ms(500);//Espera 500ms
         signo=222;
         IOCAFbits.IOCAF2=0;    //Limpia bandera individual
         PIR0bits.IOCIF=0;      //Limpia bandera general
     }
     if((IOCAFbits.IOCAF3==1)&&(columna==3)){ //************Exclusivo para signos....
          __delay_ms(500);//Espera 500ms
         signo=111;
         IOCAFbits.IOCAF3=0;    //Limpia bandera individual
         PIR0bits.IOCIF=0;      //Limpia bandera general
         signosecundario=111;
     }
     
    
   //Operaciones +,-,*,/...
    if(signo==888){
        uno=0;
    } 
    
    /**************************************************************************************************/
  
    
     if((signoprimario==111)&&(signo==555)){    //solo falta arreglar la sucecion continua..........
            valordoslcd=valordoslcd+valorunolcd;
            cuenta3=0;           
            signo=0;
            contadorsuma=1; 
     }
    if((signoprimario==111)&&(signo==444)){    //solo falta arreglar la sucecion continua..........
            valordoslcd=valordoslcd+valorunolcd;
            cuenta3=0;           
            signo=0;
            contadorsuma=1; 
     }
    if((signoprimario==111)&&(signo==666)){    //solo falta arreglar la sucecion continua..........
            valordoslcd=valordoslcd+valorunolcd;
            cuenta3=0;           
            signo=0;
            contadorsuma=1;
          
     }
    if((signoprimario==666)&&(signo==111)){    //solo falta arreglar la sucecion continua..........
            valordoslcd=valordoslcd-valorunolcd;
            cuenta3=0;           
            signo=0;
            contadorsuma=1; 
     }
     if((signoprimario==666)&&(signo==555)){    //solo falta arreglar la sucecion continua..........
            valordoslcd=valordoslcd-valorunolcd;
            cuenta3=0;           
            signo=0;
            contadorsuma=1; 
     } 
    if((signoprimario==666)&&(signo==444)){    //solo falta arreglar la sucecion continua..........
            valordoslcd=valordoslcd-valorunolcd;
            cuenta3=0;           
            signo=0;
            contadorsuma=1; 
     }
    
     if((signoprimario==555)&&(signo==111)){    //solo falta arreglar la sucecion continua..........
            valordoslcd=valordoslcd*valorunolcd;
            cuenta3=0;           
            signo=0;
            contadorsuma=1; 
     }
     if((signoprimario==555)&&(signo==666)){    //solo falta arreglar la sucecion continua..........
            valordoslcd=valordoslcd*valorunolcd;
            cuenta3=0;           
            signo=0;
            contadorsuma=1; 
     } 
    if((signoprimario==555)&&(signo==444)){    //solo falta arreglar la sucecion continua..........
            valordoslcd=valordoslcd*valorunolcd;
            cuenta3=0;           
            signo=0;
            contadorsuma=1; 
     }
    
      if((signoprimario==444)&&(signo==555)){    //solo falta arreglar la sucecion continua..........
            valordoslcd=valordoslcd/valorunolcd;
            cuenta3=0;           
            signo=0;
            contadorsuma=1; 
     }
     if((signoprimario==444)&&(signo==666)){    //solo falta arreglar la sucecion continua..........
            valordoslcd=valordoslcd/valorunolcd;
            cuenta3=0;           
            signo=0;
            contadorsuma=1; 
     } 
    if((signoprimario==444)&&(signo==111)){    //solo falta arreglar la sucecion continua..........
            valordoslcd=valordoslcd/valorunolcd;
            cuenta3=0;           
            signo=0;
            contadorsuma=1; 
     }
    
    
    /**************************************************************************************************/
    
    
      if((signo==444)&&(contadorsuma==1)){
            valordoslcd=valordoslcd/valorunolcd;
            cuenta3=0;
            contadorsuma=1;
            signo=0;
        }
     if(signo==444){
            valordoslcd=valorunolcd;
            cuenta3=0;
            contadorsuma=1;
            signo=0;
        } 
    
     if((signo==555)&&(contadorsuma==1)){
            valordoslcd=valordoslcd*valorunolcd;
            cuenta3=0;
            contadorsuma=1;
            signo=0;
        }
     if(signo==555){
            valordoslcd=valorunolcd;
            cuenta3=0;
            contadorsuma=1;
            signo=0;
        } 
    
    
    if((signo==666)&&(contadorsuma==1)){
            valordoslcd=valordoslcd-valorunolcd;
            cuenta3=0;
            contadorsuma=1;
            signo=0;
        } 
    
       if(signo==666){
            valordoslcd=valorunolcd;
            cuenta3=0;
            contadorsuma=1;
            signo=0;
        } 
    
       if(signo==111){
            valordoslcd=valordoslcd+valorunolcd;
            cuenta3=0;
            signo=0;
        } 
     //Just for the result :v 
       if(signo==222){
           if(signosecundario==444){
           resultado=valordoslcd/valorunolcd;
           }
            if(signosecundario==555){
           resultado=valorunolcd*valordoslcd;
           }
            if(signosecundario==666){
           resultado=valordoslcd-valorunolcd;
           }
            if(signosecundario==111){
           resultado=valorunolcd+valordoslcd;
           }
       }
         
     
      //Asignacion de datos a unidad,decena,centena...
      if( cuenta3==4){
         cuenta3=0;
     }
        if (cuenta3 == 0){
          unidad=0;
          decena=0;
          centena=0;
        } 
     if (cuenta3 == 1){
           unidad = numero; 
       } 
     if (cuenta3 == 2){
             decena= unidad*10;
             unidad=numero;
       } 
          if (cuenta3 == 3){
              centena= decena*10;
              decena= unidad*10;
              unidad=numero;
          } 
  
     //Resultado
      valorunolcd=unidad+decena+centena;
       
        
}
