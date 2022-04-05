/*
//#include "c:\cwHCS12\include\hcs12.h"  // Stuff from the textbook that isn't here 
//#include "c:\cwHCS12\include\delay.h"
#include "derivative.h"
//#include <delay.h>
#define HiFreq 1250
#define LoFreq 5000

int dlycnt; // delay count for OC5 operation
void oc5ISR(void);
void music_setup(void) 
{
   TSCR1 = 0x90; // enable TCNT and fast timer flag clear
   TSCR2 = 0x03; // set prescaler to TCNT to 1:8
   TIOS |= 32; // enable OC5
   TCTL1 = 0x04; // select toggle for OC5 pin action
   dlycnt = HiFreq; // use high-frequency delay count first
   TC5 = TCNT + dlycnt; // start an OC5 operation
   TIE |= 32; // enable TC5 interrupt
   asm(cli);
   
   while(1) {
   delayby100ms(5); // wait for half a second 
   dlycnt = LoFreq; // switch to low-frequency tone
   delayby100ms(5); // wait for half a second
   dlycnt = HiFreq; // switch to high-frequency tone
   }
}

interrupt void oc5ISR(void)
{
 TC5 15 dlycnt;
}                       

*/

// Alternative thingy
//#include "c:\cwHCS12\include\hcs12.h"
//#include "c:\cwHCS12\include\SetClk.h"
#include <hidef.h>      /* common defines and macros */
#include "derivative.h"
#define G3 7653
#define B3 6074
#define C4 5733
#define C4S 5412
#define D4 5108
#define E4 4551
#define F4 4295
#define F4S 4054
#define G4 3827
#define A4 3409
#define B4F 3218
#define B4 3037
#define C5 2867
#define D5 2554
#define E5 2275
#define F5 2148
#define ZZ 20 // delay count to create an inaudible sound
#define toggle 0x04 // value to toggle OC5 pin
int delay;
unsigned int score[] = {
 D4,B3,G3,B3,D4,G4,B4,A4,G4,B3,C4S,
 D4,ZZ,D4,ZZ,D4,B4,A4,G4,F4S,E4,F4S,G4,ZZ,G4,D4,B3,G3,
 D4,B3,G3,B3,D4,G4,B4,A4,G4,B3,C4S,D4,ZZ,D4,ZZ,D4,
 B4,A4,G4,F4S,E4,F4S,G4,ZZ,G4,D4,B3,G3,B4,ZZ,B4,
 B4,C5,D5,ZZ,D5,C5,B4,A4,B4,C5,ZZ,C5,ZZ,C5,B4,A4,G4,
 F4S,E4,F4S,G4,B3,C4S,D4,ZZ,D4,G4,ZZ,G4,ZZ,G4,F4S,
 E4,ZZ,E4,ZZ,E4,A4,C5,B4,A4,G4,ZZ,G4,F4S,D4,ZZ,D4,
 G4,A4,B4,C5,D5,G4,A4,B4,C5,A4,G4,0};
unsigned int dur[] = {
 30,10,40,40,40,80,30,10,40,40,40,
 80,3,20,3,20,60,20,40,80,20,20,40,3,40,40,40,40,
 30,10,40,40,40,80,30,10,40,40,40,80,3,20,3,20,
 60,20,40,80,20,20,40,3,40,40,40,60,20,3,20,
 40,40,40,3,80,20,20,40,40,40,3,80,3,40,60,20,40,
 80,20,20,40,40,40,80,3,40,40,3,40,3,20,20,
 40,3,40,3,40,40,20,20,20,20,3,40,40,20,3,20,
 60,20,20,20,80,20,20,60,20,40,80};
void delayby10ms(int kk);
void yeet(void) {
 int j;
 //SetClk8(); // set E-clock to 24 MHz
 TSCR1 = 0x90; // enable TCNT to fast timer flag clear
 TSCR2 = 0x03; // set TCNT clock prescaler to 8
 TIOS = 32; // enable OC5
 TCTL1 = toggle; // set OC5 pin action to toggle
 delay = score[0];
 j = 0;
 TC0 = TCNT + delay; //start an OC0 operation
 //TIE = 32;//C5I; //enable TC5 interrupt
 EnableInterrupts;
 while(score[j]){
 delay = score[j];
 delayby10ms(dur[j]);
 j++;
 }
 //TIOS &= 0xDF; //disable OC5
 while(1);
}
void delayby10ms(int kk) {
 char ix;
 TIOS |= 0x40; //enable OC6
 TC6 = TCNT + 30000; //start OC6 operation with 20-ms delay
 for(ix = 0; ix < kk; ix++){
 while(!(TFLG1 & 0x40));
 TC6 += 30000; 
 }
 TIOS &= 0xBF; //disable OC6
}
interrupt void tc5ISR(void) {
 TC5 += delay; 
}