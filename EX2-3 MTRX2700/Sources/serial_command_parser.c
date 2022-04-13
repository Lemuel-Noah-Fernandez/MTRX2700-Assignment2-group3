#include "serial_command_parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

//*Declaring Functions 

//DETERMINATING OPERATIONS
const char *convert_string_to_lower_case(char *serial_in);
int command_syntax_identifier(char *serial_in);

//OPERATION INIT
void run_operation(char *serial_in, char **function_names);
void say_operation(char *serial_in);

//MISC FUNCTIONS
char * operand_distiller(char *command);
void no_operand(void);
void incorrect_operation(void);

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
      say_operation(serial_in);
    break;
    case 2:
      /*A run command has been called to run a function*/
      run_operation(serial_in, function_names);
    break;
    
    default:
    break; 

    //add more commands here 
  } 
  
  return;
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
    const char commands[2][15] = {"say","run"};
    
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
  int i;
  char* operand = operand_distiller(serial_in);
  char* parameters =  operand_distiller(operand);
  
  
  /*A simple check if no function to be called was intputted*/
  if(operand == NULL){
    no_operand();
  }
  
  /*determine functcion name by index number in array and return to main*/
  for(i = 0; i < 2; i++){
    if(strcmp(function_names[i], operand) == 0){
      function_selector(i, parameters);
    }
  }
}

void say_operation(char *serial_in){
  volatile const char* string = operand_distiller(serial_in);
  //SCI1_ISR(&SCI1, &SCI1,"x", string);
}

/*MISC FUNCTIONS*/
char * operand_distiller(char *command){
  char *operand;
  
  char *token = strtok(command, " ");
  
  token = strtok(NULL, " ");
  
  operand = token;
  
  return operand;
  
}

void no_operand(void){
  //SCI1_ISR(&SCI1, &SCI1,"x","ERROR! NO OPERAND FOUND");
}

void incorrect_operation(void) {
  //SCI1_ISR(&SCI1, &SCI1,"x","ERROR! Operation does not exist");
}





