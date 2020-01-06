#include <16F628A.h>
#use delay(clock=20000000)
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES HS                       //High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NOBROWNOUT               //No brownout reset
#FUSES MCLR                     //Master Clear pin enabled
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection

//-------------------- PRUEBA 1 -----------------------
#DEFINE SW1 PORTA,0
#DEFINE SW2 PORTA,1
#DEFINE LED PORTB,7
#BYTE PORTB= 6
#BYTE PORTA= 5 

Byte CONST display[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};

float duty=0.10; //
int onTime;

void main(){   
   set_tris_a(0xFF); //TODOS ENTRADAS
   set_tris_b(0x00); // TODOS PINES SALIDAS DIGITALES
   
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);   
   //portb = display[0];// Mostrar ciclo de trabajo
   portb = display[1];
   while(true){   
      onTime = (int)(duty*50);    
      BIT_SET(LED);
      delay_ms(onTime);
      BIT_CLEAR(LED);       
      delay_ms(50-onTime);               
         if(!BIT_TEST(SW1) && duty<=0.90){
           duty+=0.01;  
           //delay_ms(90);
         }
         if(!BIT_TEST(SW2) && duty>0.10){         
            duty-=0.01; 
            //delay_ms(90);
         }
         if(duty>=0.09 && duty<=0.10){
            portb = display[1];
         }
         if(duty>=0.19 && duty<=0.20){
            portb = display[2];
         }
         if(duty>=0.29 && duty<=0.30){
            portb = display[3];
         }
         if(duty>=0.39 && duty<=0.40){
            portb = display[4];
         }
         if(duty>=0.49 && duty<=0.50){
            portb = display[5];
         }
         if(duty>=0.59 && duty<=0.60){
            portb = display[6];
         }
         if(duty>=0.69 && duty<=0.70){
            portb = display[7];
         }
         if(duty>=0.79 && duty<=0.80){
            portb = display[8];
         }
         if(duty>=0.89 && duty<=0.90){
            portb = display[9];
         }     
     
   }
}



