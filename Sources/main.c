#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#include <stdio.h> 
#include <stdlib.h>

// #define for the serial port
#include "serial.h"
#include "music.h"


void main(void) {
  
  int counter = 0;
  char *string_buffer[256];
  char *print_string = "Dudes be like 'Subway Sucks', my brother in Christ, you made the sandwich!x";
  
  SerialInitialise(BAUD_9600, &SCI0);
  SerialInitialise(BAUD_9600, &SCI1);
  //set function parameters
  //&print_string[0], to also &string_buffer[0] to see result of input pushed to terminal
  SCI1_ISR(&SCI1, &SCI1, &string_buffer[0], &print_string[0]);

	EnableInterrupts;
  
  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  
  
  /* please make sure that you never leave main */
}


