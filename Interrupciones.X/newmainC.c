/*
 * File:   newmainC.c
 * Author: Travelur
 *
 * Created on 20 de septiembre de 2018, 06:28 PM
 */

#include "config.h"
#include <xc.h>
#define _XTAL_FREQ 32000000
void main(void) {
  
    //Oscilador
    OSCFRQbits.HFFRQ = 0b101; //16MHz
    
    
    //Puertos 
    PORTA=0;
    PORTB=0;
    ANSELA=0;
    ANSELB=0;
    TRISA=0b00000001;
    TRISB=0b00000001;
    WPUBbits.WPUB0=1;
    WPUAbits.WPUA0=1;
    
    //Peripheral Pin Select
    INTPPS=0x08; //INT ----> RB0
    //Interrupción INT
    INTCONbits.INTEDG=1;//Flanco de subida
    //Interrucción
    PIR0bits.INTF=0; //Limpia bandera
    PIE0bits.INTE=1; //Habilita Interrpcion INT
 
    //Ciclo infinito
  
    
    //IOC
     
    IOCBPbits.IOCBP1=1; //RA0 flanco de subida
    IOCBFbits.IOCBF1=0; //FLAG DE A0
    IOCBPbits.IOCBP0=1; //RA0 flanco de subida
    IOCBNbits.IOCBN0=1; //RA0 flanco de subida
    IOCBFbits.IOCBF0=0; //FLAG DE A0
   
    PIE0bits.IOCIE=1;   //ENABLE IOC      
    INTCONbits.GIE=1;//Global interrup enable
    
    //IOCAPbits.
    while(1);
    return;
//teclado matricial interrupcion IOC
    return;
}

void __interrupt () INTERRUPCIONALVBB (void){
    if( PIR0bits.INTF==1){
    LATB7=LATB7+1;  //Cambio estado de led RB0
    __delay_ms(500);//Espera 500ms
    PIR0bits.INTF=0;//Limpia bandera
    }
     if(  IOCAFbits.IOCAF0==1){
    LATA7=LATA7+1;  //Cambio estado de led RA7
    __delay_ms(500);//Espera 500ms
       IOCAFbits.IOCAF0=0;//Limpia bandera
    }
    
    
}
