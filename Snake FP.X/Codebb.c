/*
 * File:   Codebb.c
 * Author: Travelur
 *
 * Created on 2 de septiembre de 2018, 01:24 PM
 */


//librerias necesaria para el programa...
#include <pic16f18877.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <xc.h>
#include "config1.h"
#define _XTAL_FREQ 32000000
#define N 8
#define M 8 
 
void main(void) {
   
   OSCFRQbits.HFFRQ = 0b110;
   ANSELD = 0b00000000;
   PORTD = 0b00000000; 
   TRISD = 0b00000000; 
   ANSELC = 0b00000000; 
   PORTC = 0b00000000; 
   TRISC = 0b00000000;
   ANSELA = 0b00000000;
   PORTA = 0b00000000;
   TRISA = 0b11111111;
  
   WPUA= 0b00001111;
   //srand(time(NULL));
     int valor=0;
   int caso2=0;
   
    int caso3=0;
    unsigned char CportC[] = {0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111};
    unsigned char fportd[] = {0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000}; 
    unsigned char bolitac[] = {0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111};  
    unsigned char bolitaf[] = {0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000};
   unsigned char bolita2c[] = {0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111};  
    unsigned char bolita2f[] = {0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000};
    unsigned char bolita3c[] = {0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111};  
    unsigned char bolita3f[] = {0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000};
    unsigned char comidac[] = {0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111};
    unsigned char comidaf1[] = {0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000};
   // unsigned char posactual[] = {0b00000000,0b00000000,0b00010000,0b00010000,0b00010000,0b00000000,0b00000000,0b00000000};
  
    int c=2;
    int f=5;
    unsigned char columnaMsj[]={0b11111111,0b11111111,0b11111111,0b11101111,0b11110111,0b11111011,0b11111111,0b11111111};
    unsigned char filaMsj[]={0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111,0b11111111};
    filaMsj[0]=0b00000001;  
    filaMsj[1]=0b00111001;
    filaMsj[2]=0b01000001;  
    filaMsj[3]=0b00111001; 
    filaMsj[4]=0b00000001;  
    filaMsj[5]=0b01001001; 
    filaMsj[6]=0b00000001;
    filaMsj[7]=0b11111111;
    columnaMsj[0]=0b01111111;
    columnaMsj[1]=0b10111111;
    columnaMsj[2]=0b11011111;
    columnaMsj[3]=0b11101111;
    columnaMsj[4]=0b11110111;
    columnaMsj[5]=0b11111011;
    columnaMsj[6]=0b11111101;
    columnaMsj[7]=0b11111110;
 //   unsigned char borrarf=0b00000000;
  //  unsigned char borrarc= 0b11111111;
    unsigned char cabeza[8][8];
 
   int velocidad; 
   velocidad=100;
    /*
    
            unsigned char fila[8];   
         fila[7]=0b10000000;
         fila[6]=0b01000000;
         fila[5]=0b00100000;
         fila[4]=0b00010000;
         fila[3]=0b00001000;
         fila[2]=0b00000100;
         fila[1]=0b00000010;
         fila[0]=0b00000001;     
         unsigned char columna[8];
         columna[0]=0b11111110;
         columna[1]=0b11111101;
         columna[2]=0b11111011;
         columna[3]=0b11110111;
         columna[4]=0b11101111;
         columna[5]=0b11011111;
         columna[6]=0b10111111;
         columna[7]=0b01111111;
     int numx;
     int numy;
         numx=rand()%7;
          numy=rand()%7;
          LATC = columna[numy];
          LATD = fila[numx];
          __delay_ms(1000);
    
    
    */
    
    
    
    fportd[f]=0b00000100;
    CportC[c]=0b11011111;
    /// b3f;     para calarlo con varibles
    //char b3c;
    int comidaf;   //variable para el random
    
    
   
    
    int boton = 0;
    int contador=1;
    int i;
    int x=1;
    int y=0;
    int j=3;
    int a =0;
  //   unsigned char vec[2]={CportC[i],fportd[x]};
   cabeza[i][x] = (LATC=CportC[i],LATD=fportd[x]);
//    unsigned char columna;
   int numero1;
   unsigned char aaaa;
   aaaa=0;

    
       int valor2=0;
  comidaf= rand () % 7;   //numero al azar  
  
   comidaf1[comidaf]=1<<comidaf;
   if (comidaf==0){
   if (comidaf==7){
            aaaa=0b01111111;
        }
         if (comidaf==6){
            aaaa=0b10111111;
        } 
        if (comidaf==5){
            aaaa=0b11011111;
        }
         if (comidaf==4){
            aaaa=0b11101111;
        }
         if (comidaf==3){
            aaaa=0b11110111;
        }
         if (comidaf==2){
            aaaa=0b11111011;
        }
         if (comidaf==1){
            aaaa=0b11111101;
        }
         if (comidaf==0){
            aaaa=0b11111110;
        }
  }
    if (comidaf==1){
   if (comidaf==6){
            aaaa=0b01111111;
        }
         if (comidaf==5){
            aaaa=0b10111111;
        } 
        if (comidaf==4){
            aaaa=0b11011111;
        }
         if (comidaf==3){
            aaaa=0b11101111;
        }
         if (comidaf==2){
            aaaa=0b11110111;
        }
         if (comidaf==1){
            aaaa=0b11111011;
        }
         if (comidaf==0){
            aaaa=0b11111101;
        }
         if (comidaf==7){
            aaaa=0b11111110;
        }
  }
    if (comidaf==2){
   if (comidaf==5){
            aaaa=0b01111111;
        }
         if (comidaf==4){
            aaaa=0b10111111;
        } 
        if (comidaf==3){
            aaaa=0b11011111;
        }
         if (comidaf==2){
            aaaa=0b11101111;
        }
         if (comidaf==1){
            aaaa=0b11110111;
        }
         if (comidaf==0){
            aaaa=0b11111011;
        }
         if (comidaf==7){
            aaaa=0b11111101;
        }
         if (comidaf==6){
            aaaa=0b11111110;
        }
  }
    if (comidaf==3){
   if (comidaf==4){
            aaaa=0b01111111;
        }
         if (comidaf==3){
            aaaa=0b10111111;
        } 
        if (comidaf==2){
            aaaa=0b11011111;
        }
         if (comidaf==1){
            aaaa=0b11101111;
        }
         if (comidaf==0){
            aaaa=0b11110111;
        }
         if (comidaf==7){
            aaaa=0b11111011;
        }
         if (comidaf==6){
            aaaa=0b11111101;
        }
         if (comidaf==5){
            aaaa=0b11111110;
        }
  }
    if (comidaf==4){
   if (comidaf==3){
            aaaa=0b01111111;
        }
         if (comidaf==2){
            aaaa=0b10111111;
        } 
        if (comidaf==1){
            aaaa=0b11011111;
        }
         if (comidaf==0){
            aaaa=0b11101111;
        }
         if (comidaf==7){
            aaaa=0b11110111;
        }
         if (comidaf==6){
            aaaa=0b11111011;
        }
         if (comidaf==5){
            aaaa=0b11111101;
        }
         if (comidaf==4){
            aaaa=0b11111110;
        }
  }
    if (comidaf==5){
   if (comidaf==2){
            aaaa=0b01111111;
        }
         if (comidaf==1){
            aaaa=0b10111111;
        } 
        if (comidaf==0){
            aaaa=0b11011111;
        }
         if (comidaf==7){
            aaaa=0b11101111;
        }
         if (comidaf==6){
            aaaa=0b11110111;
        }
         if (comidaf==5){
            aaaa=0b11111011;
        }
         if (comidaf==4){
            aaaa=0b11111101;
        }
         if (comidaf==3){
            aaaa=0b11111110;
        }
  }
    if (comidaf==6){
   if (comidaf==1){
            aaaa=0b01111111;
        }
         if (comidaf==1){
            aaaa=0b10111111;
        } 
        if (comidaf==0){
            aaaa=0b11011111;
        }
         if (comidaf==7){
            aaaa=0b11101111;
        }
         if (comidaf==6){
            aaaa=0b11110111;
        }
         if (comidaf==5){
            aaaa=0b11111011;
        }
         if (comidaf==4){
            aaaa=0b11111101;
        }
         if (comidaf==3){
            aaaa=0b11111110;
        }
  }
    if (comidaf==7){
   if (comidaf==0){
            aaaa=0b01111111;
        }
         if (comidaf==7){
            aaaa=0b10111111;
        } 
        if (comidaf==6){
            aaaa=0b11011111;
        }
         if (comidaf==5){
            aaaa=0b11101111;
        }
         if (comidaf==4){
            aaaa=0b11110111;
        }
         if (comidaf==3){
            aaaa=0b11111011;
        }
         if (comidaf==2){
            aaaa=0b11111101;
        }
         if (comidaf==1){
            aaaa=0b11111110;
        }
  }
   
   comidac[comidaf]=aaaa;
   while(contador){
    
     
     //  int num ;      
     //  num = rand();
      // while (num>7){  
      // num=rand();
      // } 
//      fportd[num]=comidaf[num];
  // CportC[num]=comidac[num];                   
    
       
       
        
       
        
          
       
       //Aqui se imprime la cabeza, cuerpo1, cuerpo2, y 3 bb...
       for(y=0;y<velocidad;y++){
           y;
       for(i = 0; i<8; i++){
           for(x =0; x<8; x++){
        LATC=CportC[i];
        LATD=fportd[x];
        __delay_us(25);
                 LATC=bolitac[i];
                 LATD=bolitaf[x];
            __delay_us(25);
             LATC=  bolita2c[i]; 
            LATD=bolita2f[x];
         __delay_us(25);
           LATC=  bolita3c[i]; 
            LATD=bolita3f[x];
         __delay_us(25);
          LATD=comidaf1[i];
            LATC=comidac[x];
              __delay_us(25);
                
      if(PORTAbits.RA0 == 0 && boton!=4){
       //   __delay_ms(150); 
          boton = 1;
       }
       
       if(PORTAbits.RA1 == 0 && boton !=3){
      //    __delay_ms(150);
           boton = 2;
       }
      
      if(PORTAbits.RA2 == 0 && boton !=2){
        //  __delay_ms(150); 
          boton = 3;
      }
       
     if(PORTAbits.RA3 == 0 && boton !=1){
        // __delay_ms(150); 
         boton = 4;
      }
           }
           
           
            __delay_us(50);
        }
       }
     //si la cabeza esta en la comida, esta cambia a cero y se vuelve a generar otra posicion....
        if ((fportd[f]==comidaf1[comidaf])&&(CportC[c]==comidac[comidaf])){
             comidaf1[comidaf]=0;
             comidac[comidaf]=0b11111111; 
            
             if (velocidad<21){
               
                 velocidad=20+10;
                
             } 
           velocidad=velocidad-20;
       }   
       // otra posicion....
   if ((comidaf1[comidaf]==0)){
                 comidaf= rand () % 8;     
  
    comidaf1[comidaf]=1<<comidaf;
  
    if (comidaf==0){
   if (comidaf==7){
            aaaa=0b01111111;
        }
         if (comidaf==6){
            aaaa=0b10111111;
        } 
        if (comidaf==5){
            aaaa=0b11011111;
        }
         if (comidaf==4){
            aaaa=0b11101111;
        }
         if (comidaf==3){
            aaaa=0b11110111;
        }
         if (comidaf==2){
            aaaa=0b11111011;
        }
         if (comidaf==1){
            aaaa=0b11111101;
        }
         if (comidaf==0){
            aaaa=0b11111110;
        }
  }
    if (comidaf==1){
   if (comidaf==6){
            aaaa=0b01111111;
        }
         if (comidaf==5){
            aaaa=0b10111111;
        } 
        if (comidaf==4){
            aaaa=0b11011111;
        }
         if (comidaf==3){
            aaaa=0b11101111;
        }
         if (comidaf==2){
            aaaa=0b11110111;
        }
         if (comidaf==1){
            aaaa=0b11111011;
        }
         if (comidaf==0){
            aaaa=0b11111101;
        }
         if (comidaf==7){
            aaaa=0b11111110;
        }
  }
    if (comidaf==2){
   if (comidaf==5){
            aaaa=0b01111111;
        }
         if (comidaf==4){
            aaaa=0b10111111;
        } 
        if (comidaf==3){
            aaaa=0b11011111;
        }
         if (comidaf==2){
            aaaa=0b11101111;
        }
         if (comidaf==1){
            aaaa=0b11110111;
        }
         if (comidaf==0){
            aaaa=0b11111011;
        }
         if (comidaf==7){
            aaaa=0b11111101;
        }
         if (comidaf==6){
            aaaa=0b11111110;
        }
  }
    if (comidaf==3){
   if (comidaf==4){
            aaaa=0b01111111;
        }
         if (comidaf==3){
            aaaa=0b10111111;
        } 
        if (comidaf==2){
            aaaa=0b11011111;
        }
         if (comidaf==1){
            aaaa=0b11101111;
        }
         if (comidaf==0){
            aaaa=0b11110111;
        }
         if (comidaf==7){
            aaaa=0b11111011;
        }
         if (comidaf==6){
            aaaa=0b11111101;
        }
         if (comidaf==5){
            aaaa=0b11111110;
        }
  }
    if (comidaf==4){
   if (comidaf==3){
            aaaa=0b01111111;
        }
         if (comidaf==2){
            aaaa=0b10111111;
        } 
        if (comidaf==1){
            aaaa=0b11011111;
        }
         if (comidaf==0){
            aaaa=0b11101111;
        }
         if (comidaf==7){
            aaaa=0b11110111;
        }
         if (comidaf==6){
            aaaa=0b11111011;
        }
         if (comidaf==5){
            aaaa=0b11111101;
        }
         if (comidaf==4){
            aaaa=0b11111110;
        }
  }
    if (comidaf==5){
   if (comidaf==2){
            aaaa=0b01111111;
        }
         if (comidaf==1){
            aaaa=0b10111111;
 
         } 
        if (comidaf==0){
            aaaa=0b11011111;
        }
         if (comidaf==7){
            aaaa=0b11101111;
        }
         if (comidaf==6){
            aaaa=0b11110111;
        }
         if (comidaf==5){
            aaaa=0b11111011;
        }
         if (comidaf==4){
            aaaa=0b11111101;
        }
         if (comidaf==3){
            aaaa=0b11111110;
        }
  }
    if (comidaf==6){
   if (comidaf==1){
            aaaa=0b01111111;
        }
         if (comidaf==1){
            aaaa=0b10111111;
        } 
        if (comidaf==0){
            aaaa=0b11011111;
        }
         if (comidaf==7){
            aaaa=0b11101111;
        }
         if (comidaf==6){
            aaaa=0b11110111;
        }
         if (comidaf==5){
            aaaa=0b11111011;
        }
         if (comidaf==4){
            aaaa=0b11111101;
        }
         if (comidaf==3){
            aaaa=0b11111110;
        }
  }
    if (comidaf==7){
   if (comidaf==0){
            aaaa=0b01111111;
        }
         if (comidaf==7){
            aaaa=0b10111111;
        } 
        if (comidaf==6){
            aaaa=0b11011111;
        }
         if (comidaf==5){
            aaaa=0b11101111;
        }
         if (comidaf==4){
            aaaa=0b11110111;
        }
         if (comidaf==3){
            aaaa=0b11111011;
        }
         if (comidaf==2){
            aaaa=0b11111101;
        }
         if (comidaf==1){
            aaaa=0b11111110;
        }
  }
   
  
   comidac[comidaf]=aaaa;
                 
             }
      
       
  /*      if ((( fportd[comidaf]=0b00010000)&&(CportC[comidaf]=0b11101111))){
             comidaf1[comidaf]=0;
             comidac[comidaf]=0b11111111;
             
        }
       */
      
       
      // if (cuartabolita>=2){ 
         ////  Borrar datitos JUST FOR FUN necesario para evitar registros encendidos :v
           for(i = 0; i<8; i++){
           for(x =0; x<8; x++){
      bolita3c[i]=0b11111111; 
     bolita3f[x]=0b00000000;
           }            
        }
         //para tomar los valores anteriores de la bolita 2 en la bolita 3....
         if(caso3==4){
       bolita3f[valor]=bolita2f[valor+1];
      bolita3c[c]=bolita2c[c];
       }
        if(caso3==1){
       bolita3f[valor]=bolita2f[valor-1];
      bolita3c[c]=bolita2c[c];
       }
        if(caso3==2){
      
      bolita3c[valor]=bolita2c[valor+1];
       bolita3f[f]=bolita2f[f];
       }
        if(caso3==3){
       bolita3c[valor]=bolita2c[valor-1];
       bolita3f[f]=bolita2f[f];
       }  
           
        
       
       //borrar bolita 2
       for(i=0;i<8;i++){
           for(x=0;x<8;x++){
           bolita2c[i]=0b11111111;
       bolita2f[x]=0b00000000;
       }
       }
       
       
       
     
      //para tomar los valores anteriores de la bolita 1 en al bolita 2 
       if(caso2==1){
                caso3=1;
       bolita2f[valor]=bolitaf[valor];///change por valor
      bolita2c[c]=bolitac[c];
      valor2=c;
       }
        if(caso2==4){
                 caso3=4;
       bolita2f[valor]=bolitaf[valor];
      bolita2c[c]=bolitac[c];
        valor2=c;
       }
        if(caso2==2){
           caso3=2;
      bolita2c[valor]=bolitac[valor];
       bolita2f[f]=bolitaf[f];
         valor2=c;
       }
        if(caso2==3){
            caso3=3;
       bolita2c[valor]=bolitac[valor];
       bolita2f[f]=bolitaf[f];
         valor2=c;
    
       }
       
       
       
 /*      for(y=0;y<50;y++){
           y;
        for(i = 0; i<8; i++){
           for(x =0; x<8; x++){
         LATC=bolitac[i];
                 LATD=bolitaf[x];
            __delay_us(10);
           } 
            __delay_us(50);
        }
       }   */
      
       
       
      if(PORTAbits.RA0 == 0 && boton!=4){
       //   __delay_ms(150); 
          boton = 1;
       }
       
       if(PORTAbits.RA1 == 0 && boton !=3){
      //    __delay_ms(150);
           boton = 2;
       }
      
      if(PORTAbits.RA2 == 0 && boton !=2){
        //  __delay_ms(150); 
          boton = 3;
      }
       
     if(PORTAbits.RA3 == 0 && boton !=1){
        // __delay_ms(150); 
         boton = 4;
      }
       ///Para borrar el rastro gg :V
          for(i = 0; i<8; i++){
           for(x =0; x<8; x++){
    bolitac[i]=0b11111111; 
     bolitaf[x]=0b00000000;
  
           }            
        }
         
       
       
       //nos da el corrimiento de la cabeza...
        switch(boton){
            case 1:
           
                caso2=1;
                
            f=f+1;
                  
            fportd[f] = fportd[f-1]>>1;
            bolitaf[f-1]=fportd[f-1]; //tomo valor del la cabeza anterior en fila
            
             fportd[f-1] = 0b00000000;
                 valor=f-1; 
            
            //columnas cuerpo
            bolitac[c]=CportC[c];
          
          
          
            
          //  if(bolita=1) {
         //       break;
           // }
          
         //   bolita2f[f]=bolitaf[f-1];
         //   fportd[f-1] = 0b00000000;
           
          
            
           
         ///   bolitaf[f-2]=0b00000000;
            // valorf=f-1;
       
            if(f>7){
                   f=0;
                   contador=0;
               }    
             
            break;
            case 2:
          
                caso2=2;
              
                 c=c-1;
                 
                 if(CportC[c+1]==0b11111110){
                   CportC[c]=0b11111101; 
                     bolitac[c+1]=CportC[c+1];
                   CportC [c+1]=0b11111111;
                   valor=c+1;
            bolitaf[f]=fportd[f];
                 //   bolitac[j+1]=0b11111111;
                   break;
                }
                 if(CportC[c+1]==0b11111101){
                   CportC [c]=0b11111011;  
                    bolitac[c+1]=CportC[c+1];
                   CportC [c+1]=0b11111111;
                   valor=c+1;
                  bolitaf[f]=fportd[f];
                //   bolitac[c+1]=0b11111111;
                   break;
                }
                 if(CportC[c+1]==0b11111011){
                   CportC [c]=0b11110111; 
                    bolitac[c+1]=CportC[c+1];
                   CportC [c+1]=0b11111111;
                   valor=c+1;
                 bolitaf[f]=fportd[f];
             //     bolitac[c+1]=0b11111111;
                   break;
                }
                 if(CportC[c+1]==0b11110111){
                   CportC [c]=0b11101111;  
                    bolitac[c+1]=CportC[c+1];
                   CportC [c+1]=0b11111111;
                   valor=c+1;
                   bolitaf[f]=fportd[f];
              //      bolitac[c+1]=0b11111111;
                    
                   break;
                }
                if(CportC[c+1]==0b11101111){
                    CportC [c]=0b11011111; 
                      bolitac[c+1]=CportC[c+1];
                    CportC [c+1]=0b11111111;
                   valor=c+1;
                
                    bolitaf[f]=fportd[f];
             //      bolitac[c+1]=0b11111111;
                    break;
                }
                 if(CportC[c+1]==0b11011111){
                    CportC [c]=0b10111111; 
                         bolitac[c+1]=CportC[c+1];
                    CportC [c+1]=0b11111111;
                   valor=c+1;
              bolitaf[f]=fportd[f];
              //     bolitac[c+1]=0b11111111;
                    break;
                }
                if(CportC[c+1]==0b10111111){
                   CportC [c]=0b01111111; 
                        bolitac[c+1]=CportC[c+1];
                 CportC [c+1]=0b11111111;
                   valor=c+1;
              bolitaf[f]=fportd[f];
           //        bolitac[c+1]=0b11111111;
                   break;
                }
                  if(CportC[c+1]==0b01111111){
                  
                   contador=0;
               }
            break;   
            case 3:
               
               
                caso2=3;
              c=c+1;
              
                 if(CportC[c-1]==0b01111111){
                   CportC[c]=0b10111111;  
                     bolitac[c-1]=CportC[c-1];
                   CportC [c-1]=0b11111111;
                   valor=c-1;
            bolitaf[f]=fportd[f];
        //              bolitac[c-1]=0b11111111;
                   break;
                }
              
                 if(CportC[c-1]==0b10111111){
                   CportC [c]=0b11011111;
                       bolitac[c-1]=CportC[c-1];
                 CportC[c-1]=0b11111111;
                   valor=c-1;
                 bolitaf[f]=fportd[f];
       //              bolitac[c-1]=0b11111111;
                     
                   break;
                }
                 if(CportC[c-1]==0b11011111){
                   CportC [c]=0b11101111; 
                        bolitac[c-1]=CportC[c-1];
                  CportC [c-1]=0b11111111;
                   valor=c-1;
                 bolitaf[f]=fportd[f];
         //               bolitac[c-1]=0b11111111;
                   break;
                }
                 if(CportC[c-1]==0b11101111){
                   CportC [c]=0b11110111;  
                      bolitac[c-1]=CportC[c-1];
                  CportC [c-1]=0b11111111;
                   valor=c-1;
                  bolitaf[f]=fportd[f];
                   
          //             bolitac[c-1]=0b11111111;
                   break;
                }
              
              
                if(CportC[c-1]==0b11110111){
                    CportC [c]=0b11111011; 
                       bolitac[c-1]=CportC[c-1];
                   CportC [c-1]=0b11111111;
                   valor=c-1;
                    bolitaf[f]=fportd[f];
              
           //         bolitac[c-1]=0b11111111;
                    break;
                }
                 if(CportC[c-1]==0b11111011){
                    CportC [c]=0b11111101; 
                     bolitac[c-1]=CportC[c-1];
                    CportC [c-1]=0b11111111;
                   valor=c-1;
                    bolitaf[f]=fportd[f];
                  
            //          bolitac[c-1]=0b11111111;
                    break;
                }
                if(CportC[c-1]==0b11111101){
                   CportC [c]=0b11111110; 
                    bolitac[c-1]=CportC[c-1];
                   CportC [c-1]=0b11111111;
                   valor=c-1;
                   bolitaf[f]=fportd[f];
      //                 bolitac[c-1]=0b11111111;
                    
                   break;
                }
              
              
                if(CportC[c-1]==0b11111110){
                    
                    contador=0;
                    }
                break; 
          
                               
            break;
            
            case 4:     
              
                caso2=4;
                f=f-1;       
               
            fportd[f] = fportd[f+1]<<1;
               bolitaf[f+1]=fportd[f+1];
           // guardamos la posicion de cabeza 
            fportd[f+1] = 0b00000000;
         ///   bolitaf[f+2]=0b00000000;
            bolitac[c]= CportC[c];
         
              if(f<0){
                contador=0;
              }  
               valor=f+1;
            break;
      
       
        }
        
     
      /*  if (boton !=2 || boton !=3 || boton !=1 ){
           bolitaf[f-1]= fportd[f+1]<<1;
            bolitac[c]= CportC[c];
         
        }
         if (boton !=2 || boton !=3 || boton !=4 ){
           bolitaf[f]= fportd[f-1]>>1;
            bolitac[c]= CportC[c];
        
        }¨*/
   
        
        
        
        
        
       //cuerpo but medio works
        
      
        
        /* if (boton !=4 || boton !=1 ){
            CportC[valor]=bolitac[j];
        
        }*/
      /*
         if (botones !=4 || botones !=1 ){
               columna[valor]=cuerpoc1[j];
             
        }
         */
                    
                   
        }
        
     /*   if (botones==4){
            for (i=0;i<8;i++){   
                    if(i = f+1){
                        fila[i] =cuerpof1[f+1];  
                    }
        } 
        }*/

   
   
    //mensaje cuando se termina el juego por lo menos esto si funciona bien haha (SO SAD):'v
    for(j = 0; j<100; j++){
         for(i = 0; i<8; i++){
          
           LATD=filaMsj[i];
           LATC=columnaMsj[i];
           __delay_ms(1);
          
        } 
          __delay_ms(1);
    }
        return;  
}
    
    
    
 
