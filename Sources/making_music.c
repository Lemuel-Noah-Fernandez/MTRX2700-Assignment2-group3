#include <hidef.h>       /* common defines and macros */
#include <math.h>
#include <stdlib.h>
#include "derivative.h"      /* derivative-specific definitions */
#include "making_music.h"

int note;
int i = 0;
int j;
int k;


void making_music(unsigned int score[]) {
  
  timer_setup();
  play(score);
  for(;;);
  
}

// Initialises timer
void timer_setup(void) {
  
  TSCR1 = 0x90; // Enable TCNT to fast timer flag clear
  TSCR2 = 0x03; // Set TCNT clock prescaler to 8
  TIOS = 0x20;  // Output compare to chanel 5
  TCTL1 = 0x04; // Toggles on successful output compare

}


// Play music
void play(unsigned int score[]) {
  int x = 0;
  while(score[x]) {
    if(x == 0) {
      int letter = score[0];
      int time = score[1];
      int octave = score[2];
      letter = octave_check(octave, letter);
      note = letter; 
      delay(time);
      note = 20;
      delay(10);
      TIE = 0x20;   // Enable interrupts for timer 5
     
      // First output compare
      TC5 = TCNT + note;
    	EnableInterrupts;            
    }else if(x % 3 == 0) {
      int letter = score[x];
      int time = score[x+1];
      int octave = score[x+2];      
      letter = octave_check(octave, letter);
      note = letter;
      delay(time); 
      note = 20;
      delay(10);    
    }
    x++;
      
  }
  /*
  note = 20;
  delay(10);
  */
}
 

// Octave check
int octave_check(int octave, int letter){
  switch (octave)
  {
      case 5:
      letter /= 2;
      break;
      case 6:
      letter /= 4;
      break;
      case 7:
      letter /= 8;
      break;
      case 8:
      letter /= 16;
      break;
      case 3:
      letter *= 2;
      break;
      case 2:
      letter *= 4;
      break;
      case 1:
      letter *= 8;
      break;
      case 0:
      letter *= 16;
      break;
  }
  return letter;
}

// Delay function
void delay(unsigned int time) {
      
    // Delay of time in ms x 10
    //time *= 10;
    time *= 5;
    for(j=0;j<time;j++)
      for(k=0;k<4000;k++);
}


// Interrupt vector
#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void musicISR()
{
	TC5 = TC5 + note;
}