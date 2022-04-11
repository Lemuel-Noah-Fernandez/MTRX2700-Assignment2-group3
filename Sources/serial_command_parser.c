#include <stdio.h>
#include <stdlib.h>

#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#include "serial_command_parser.h"

//Declaring Functions 
const char *convert_string_to_lower_case(char *serial_in);
int command_syntax_identifier(char *serial_in);


/*DETERMINATING OPERATION*/
void serial_parser(char *serial_in, char **function_names) {
  /*
   1 - operator does not exist
   3 - run command (runs a function)
   4 - say commands, replays a message back to serial 
  */  

  /*check which command is being called by the serial*/
  volatile int com_mode = command_syntax_identifier(serial_in);

  /*Types of commands put here**/
  switch(com_mode){
    case 0:
      /*send out serial output that the command does not exist*/
      no_operand();
    break;
    case 1:
      /*A say command has been called, which will output what is in serial after the command*/
      say_operation(serial_in, function_names);
    break;
    case 2:
      /*A run command has been called to run a function*/
      run_operation(serial_in);
    break;
    
    default:
    break; 

    //add more commands here 
  }
}

const char *convert_string_to_lower_case(char *serial_in){
    int i;
    
    for(i = 0; i < strlen(serial_in); i++){                           
        if(serial_in[i] >= 56 && serial_in[i] <= 90){
            serial_in[i] += 32;
        }
    }
    return serial_in;
}

int command_syntax_identifier(char *serial_in){
    /*The Commands that can be run on the system are defined by their string in this array of strings*/
    const char commands[2][15] = {"run","say"};
    
    /*Convert whole serial input into lowercase*/
    const char* command_in = convert_string_to_lower_case(serial_in);

    char *command_test;
    int com_mode;
    int i;

    for(i = 0; i < 2; i++){
        command_test = strstr(command_in, commands[i]);
        if(command_test != NULL){
            com_mode = i+1;
            break;
        }
    }
    return com_mode;
  }


/*OPERATION INIT*/

void run_operation(char *serial_in, char **function_names){
  const char* operand = operand_distiller(serial_in);
  int i;
  
  /*A simple check if no function to be called was intputted*/
  if(operand == NULL){
    no_operand();
  }
  
  for(i = 0; i < 2; i++){
    if(strcmp(function_names[i], operand) == 0){
      function_selector(i);
    }
  }
}

void say_operation(char *serial_in){
  /*some_function(serial_in)*/
}

/*MISC FUNCTIONS*/
const char * operand_distiller(char *command){
  char *token;
  char *operand;
  const char s[2] = " ";
  
  token = strtok(command, s);
  
  token = strok(NULL, s);
  
  strcpy(operand, token);
  
  return operand;
  
}

void no_operand(){
  /*some_function("ERROR! No operand inputted")*/
}

void incorrect_operation() {
  /*some_function("ERROR! Operation does not exist")*/
}
