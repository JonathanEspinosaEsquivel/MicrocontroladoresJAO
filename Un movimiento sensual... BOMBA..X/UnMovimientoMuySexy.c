#include <xc.h>
#include "config.h"
#include <stdio.h>
#define _XTAL_FREQ 32000000
#include "flex_lcd.h"


void main(void) {
    int seg,seg1,min,min1,hora,hora1,dia,mes,anio;
     unsigned char buffer1[16];
    //Oscilator
    OSCFRQbits.HFFRQ=0b110; 
    //Puertos
    PORTB=0;
    PORTD=0;
    ANSELD=0;
    TRISD=0;
    ANSELB=0;
   // TRISB=0b00000000;
    ANSELC=0; //portc como digital
    SSP1CON1bits.SSPEN=1;    
    SSP1CLKPPS=0x08; //RB0   
    SSP1DATPPS=0x09; //RB1
    SSP1CON1bits.SSPM=0b1000;
    SSP1ADD=19;  
    RB0PPS=0x14;
    RB1PPS=0x15;
    //        SSP1STATbits.
  /*  SSPCON1bits.SSPM3=1 ;
    SSPCON1bits.SSPM2=0;
    SSPCON1bits.SSPM1=0;
    SSPCON1bits.SSPM0=0;*/
    int horaE=10;
    int minuE=40;
    int segE=27;
    //Hora actual...
    unsigned char minutos=0b01000110;
    unsigned char hora3=0b00010010;
    int sono=0;
    Lcd_Init();     //inicializamos el lcd
    Lcd_Cmd(LCD_CLEAR);		//limpiamos lcd
    Lcd_Cmd(LCD_CURSOR_OFF);	//apagamos el cursor
    Lcd_Out(2, 1, "Bombita bb");
  sprintf(buffer1,"BUM! at %02d:%02d:%02d",horaE,minuE,segE);
         Lcd_Out(2, 0, buffer1);
  /* SSP1CON2bits.SEN=1;
        while( SSP1CON2bits.SEN);
        SSP1BUF=0b11010000;
        while(SSP1STATbits.BF);
        while(SSP1STATbits.R_nW); //9no clock
        SSP1BUF=0; //Mandamos la direccion
        while(SSP1STATbits.BF);
        while(SSP1STATbits.R_nW);
        SSP1BUF=0;//Seg
        while(SSP1STATbits.BF);
        while(SSP1STATbits.R_nW);
        SSP1BUF=minutos;//min
        while(SSP1STATbits.BF);
        while(SSP1STATbits.R_nW);
        SSP1BUF=hora3;//hor
        while(SSP1STATbits.BF);
        while(SSP1STATbits.R_nW);
        SSP1BUF=0b00000101;//día
        while(SSP1STATbits.BF);
        while(SSP1STATbits.R_nW);
        SSP1BUF=0b00001000;//fecha
        while(SSP1STATbits.BF);
        while(SSP1STATbits.R_nW);
        SSP1BUF=0b00010001;//mes
        while(SSP1STATbits.BF);
        while(SSP1STATbits.R_nW);
        SSP1BUF=0b00011000;//año
        while(SSP1STATbits.BF);
        while(SSP1STATbits.R_nW);
        SSP1BUF=0b00010000;
        while(SSP1STATbits.BF);
        while(SSP1STATbits.R_nW);
        SSP1CON2bits.PEN=1;
        while(SSP1CON2bits.PEN);
        
        */
    while(1){
        SSP1CON2bits.SEN=1;    //Se genera la señal de Start
        while( SSP1CON2bits.SEN);
        SSP1BUF=0b11010000;
        while(SSP1STATbits.BF);          //espera hasta que se envie el dato
        while(SSP1STATbits.R_nW);        //Espera hasta que llegue el 9o clock
        SSP1BUF=0;           //Se escribe el siguiente dato
        while(SSP1STATbits.BF);          //espera hasta que se envie el dato
        while(SSP1STATbits.R_nW);        //Espera hasta que llegue el 9o clock
        SSP1CON2bits.RSEN=1;             //restart
        while(SSP1CON2bits.RSEN);
        SSP1BUF=0b11010001;
        while(SSP1STATbits.BF);
        while(SSP1STATbits.R_nW)
        SSP1CON2bits.RCEN=1;         //habilita la recepción
        while(SSP1STATbits.BF==0);  // ESPERAR A QUE LLEGUE EL DATO
        seg=SSP1BUF;           //leer dato de SSPBUF
        SSP1CON2bits.ACKDT=0;
        SSP1CON2bits.ACKEN=1;            //Genera ack
        while(SSP1CON2bits.ACKEN);
        SSP1CON2bits.RCEN=1;         //habilita la recepción
        while(SSP1STATbits.BF==0);
        min=SSP1BUF;           //leer dato de SSPBUF
        SSP1CON2bits.ACKDT=0;
        SSP1CON2bits.ACKEN=1;            //Genera ack
        while(SSP1CON2bits.ACKEN);
        SSP1CON2bits.RCEN=1;         //habilita la recepción
        while(SSP1STATbits.BF==0);
        hora=SSP1BUF;           //leer dato de SSPBUF
        SSP1CON2bits.ACKDT=1;
        SSP1CON2bits.ACKEN=1;            //Genera Noack
        while(SSP1CON2bits.ACKEN);
        SSP1CON2bits.PEN=1;
        while(SSP1CON2bits.PEN);
        
        seg1=((0b01110000 & seg)>>4)*10+(0b00001111 & seg);
        min1=((0b01110000 & min)>>4)*10+(0b00001111 & min);
        hora1=((0b01110000 & hora)>>4)*10+(0b00001111 & hora);
        sprintf(buffer1,"   %02d:%02d:%02d",hora1,min1,seg1);
        Lcd_Out2(1, 1, buffer1);
      
        
        
        if(((seg1==segE)&&(min1==minuE)&&(hora1==horaE))||(sono==1)){
            LATDbits.LATD4=LATDbits.LATD4+1;
            sono=1;
        }
        __delay_ms(200);
    }
    return;
}