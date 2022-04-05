#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

//<<<<<<< HEAD
//#include "serial_command_parser.h"
//=======
#include "serial.h"
#include "music.h"
//>>>>>>> e70c888ae231fcc3d348c1f7f95be612584d67bd

void main(void) {
  /* put your own code here */
  
  int counter = 0;
  //char string_buffer[8], string_input[8];
  
  SerialInitialise(BAUD_9600, &SCI0);
  SerialInitialise(BAUD_9600, &SCI1);
  
  //SerialOutputString(&string_buffer[0], &SCI0);
  

	EnableInterrupts;
  //SerialInputString(&SCI1, &string_input[0]);;
  yeet();
  


	//EnableInterrupts;


  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
