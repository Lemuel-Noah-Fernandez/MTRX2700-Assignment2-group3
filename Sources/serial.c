 #include "derivative.h"
 #include "serial.h"
 
 #define BAUD_RATE 9600
 
 void SCI1_setup(void){
 
 SCI1CR1 = 0;
 SCI1CR2 = 12;
 SCI1BDL = 0x9C;
 SCI1BDH = 0;
  
 /*asm{
            clr SCI1CR1
            movb #mSCI1CR2_RE | mSCI1CR2_TE, SCI1CR2 ; Enables TX and RX signals for the serial port
            ldy #$0016
            ldd #$E360
            ldx 2, SP
            ediv
            
            sty SCI1BDH
            
            rts  
 }*/
 }