#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#include <stdio.h>
#include <stdlib.h>

#include "serial_command_parser.h"

void serial_parser(char *serial_in, char **function_names) {

  int com_mode;
  
  /*check which command is being called by the serial*/
  strcpy(command_syntax_identifier(*serial_in, *com_mode));

  switch(com_mode){
    case 0:
      /*send out serial output that the command does not exist*/
    break;
    case 1:
      /*A say command has been called, which will output what is in serial after the command*/
    break;
    case 2:
      /*A run command has been called to run a function*/
    break; 
  }
}


char *command_syntax_identifiier(char *serial_in, int *com_mode){
   char opperator[12]
   char opperand[64]

   for(int i = 0; i < strlen(serial_in); i++){
      if (serial_in[i] == ' '){
        strncpy(opperator, serial_in,i-1)
        strc
   }
}