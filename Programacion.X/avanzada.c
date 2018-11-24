#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000

void main(void) {
    int x=0;
    OSCFRQbits.HFFRQ = 0b110;
    PORTC = 0;
    ANSELC =0;
    TRISC=0;
    
    PORTA=0;
    ANSELA=0;
    TRISA=255;
    WPUAbits.WPUA1=1;
    WPUAbits.WPUA2=1;
    WPUAbits.WPUA3=1;
    
 //pps
    RC6PPS= 0x10;
    //puerto serie
    RC1STAbits.SPEN =1;
    TX1STAbits.TXEN = 1;
    TX1STAbits.SYNC = 0;
    TX1STAbits.BRGH =0;
    //BAUD rate
    BAUD1CONbits.BRG16 =0;
    SPBRG=51;
    int p=0;
    while(1){
        if ((PORTAbits.RA1==0&&x==0)||(PORTAbits.RA1==0&&x==2)){
            TX1REG = 65;
            x=1;
              while(TX1STAbits.TRMT==0);
           __delay_ms(50);
           p=1;
        }
        if ((PORTAbits.RA3==0&&x==0)||(PORTAbits.RA3==0&&x==1)){
            TX1REG = 68;
            x=2;
              while(TX1STAbits.TRMT==0);
           __delay_ms(50);
            p=1;
        }  
         if ((PORTAbits.RA2==0&&p==1)){
             p=0;
             x=0;
             TX1REG = 83;
              while(TX1STAbits.TRMT==0);
           __delay_ms(50);
           
        }
        
 }
   return;
}
