/*
 * File:   recepcion.c
 * Author: Travelur
 *
 * Created on 11 de octubre de 2018, 05:59 PM
 */


#include <xc.h>
#include "config.h"
char dato;
void main(void) {
    //Ocilador
    OSCFRQbits.HFFRQ=0b110;                 //32MHz
    //Puertos
    PORTB=0;                                //Limpia puerto B
    ANSELB=0;                               //Puerto B como digital
    TRISB=0;                                //Puerto B como salidas
    PORTC=0;                                //Limpia Puerto C
    ANSELC=0;                               //Puerto C como digital
    TRISC=0b10000000;                       //RC7 como entrada RC0-6 como salidas
    //PPS
    RXPPS=0x17; //Rx---->RC7
    //Puerto Serie
    RC1STAbits.SPEN=1; //Habilita puerto serie
    TX1STAbits.BRGH=0; //Low speed
    TX1STAbits.SYNC=0; //Asíncrono
    RC1STAbits.CREN=1; //Recepción continua
    //BAUD rate
    BAUD1CONbits.BRG16 =0; //Timer USART 8 bits
    SPBRG=51; //9600 BAUDS
    //Interrupción 
    PIR3bits.RCIF=0;//Limpia bandera INT RX
    PIE3bits.RCIE=1;//Habilita INT RX
    INTCONbits.PEIE=1;//Int Periférico
    INTCONbits.GIE=1; //INT GLOBAL
    
    while(1);
    
    
    return;
}
void __interrupt() recepciones(void){
    dato =RC1REG; //Lee el dato recibido
    if (dato == 65)
        LATB0=1;
    if (dato == 80)
        LATB0=0;
    
    PIR3bits.RCIF=0; //Limpia bandera
}
