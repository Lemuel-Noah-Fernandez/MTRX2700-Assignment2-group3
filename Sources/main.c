#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

<<<<<<< HEAD
#include "serial_command_parser.h"
=======
#include "serial.h"
>>>>>>> e70c888ae231fcc3d348c1f7f95be612584d67bd

void main(void) {
  /* put your own code here */
  SCI1_setup();
  


	EnableInterrupts;


  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
