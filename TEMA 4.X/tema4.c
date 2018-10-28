/*
 * File:   tema4.c
 * Author: Travelur
 *
 * Created on 10 de octubre de 2018, 06:24 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000

void main(void) {
    int x;
    //Oscilador
    OSCFRQ=0b110; //32MHz
    //Puertos
    PORTC=0;//Limpia puerto C
    ANSELC=0;//Puerto C como digital
    TRISC=0;//Puerto C como salida
    //PPS
    RC6PPS=0x10; //TX---->RC6
    //Puerto Serie
    RC1STAbits.SPEN=1;//Puerto Serie On
    TX1STAbits.TXEN=1;//Habilita Tx
    TX1STAbits.SYNC=0;//Asincrono
    TX1STAbits.BRGH=0;//Low speed
    //Baud rate
    BAUD1CONbits.BRG16=0;//Timer USART 8-bits                                                                                                                     //bits para seleciconar la polaridad, sincrono: saber si esta disponible el hilo de datos para mandar mensajes
    SPBRG=51;
    //Ciclo infinito
    while(1){
        for(x=65;x<91;x++){
            TX1REG=x; //Trasmite valor de x
            while(TX1STAbits.TRMT==0);
            __delay_ms(300);            //terminador de cadena en string
        }
    }
            
    return;
}
