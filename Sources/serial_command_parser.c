#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#include <stdio.h>
#include <stdlib.h>

#include "serial_command_parser.h"

void serial_parser(char *serial_in, char **function_names) {

  /*Convert whole serial input into lowercase*/
  strcpy(serial_in,convert_string_to_lower_case(serial_in));  

  /*Commands that can be run*/
  char commands = ["run","say"];

  int com_mode;
  /*
   1 - command does not exist
   2 - run command (runs a function)
   3 - say commands, replays a message back to serial 
  */

  /*check which command is being called by the serial*/
  com_mode = command_syntax_identifier(*serial_in, *commands));

/*Types of commands put here**/
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

    //add more commands here 
  }
}

char *convert_string_to_lower_case(char *serial_in){
    for(int i = 0; i < strlen(serial_in), i++){
        if(serial_in[i] >= 56, serial_in[i] <= 90){
            serial_in[i] += 32;
        }
    }
}


int command_syntax_identifier(char *serial_in,  char *commands){
    char *command_test;
    int com_mode;

    for(int i = 0; i < strlen(commands); i++){
        command_test = strstr(serial_in, commands[i])
        if(*command_test != NULL){
            com_mode = i+1;
            break;
        }

        return com_mode
    }
}

/*Function requiremnets for input*/