#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#include <stdio.h> 
#include <stdlib.h>

// #define for the serial port
#include "serial.h"

const int NUMBER_OF_SHAPES = 16;


void main(void) {
  
  int counter = 0;
  char string_buffer[8], string_input[8];
  sprintf(&string_buffer[0], "Why?\n\r");

  SerialInitialise(BAUD_9600, &SCI0);
  SerialInitialise(BAUD_9600, &SCI1);
  
  SerialOutputString(&string_buffer[0], &SCI0);
  

	EnableInterrupts;
   SerialInputString(&SCI1, &string_input[0]);

  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  
  
  /* please make sure that you never leave main */
}
