#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Defining functions
unsigned int conver_string_to_brinary_to_int(char *string);
unsigned int *Music_input_converter(char *input);

#include "serial_command_parser.h"
#include "making_music.h"

// All notes are in the 4th octave
#define A 3409
#define B 3037
#define C 5733
#define D 5108
#define E 4551
#define F 4295
#define G 3827

#define Z 20 // Rest 
// Score is in the form (note, time, octave)
unsigned int score[] = {
 E, 10, 4, D, 75, 4, F, 50, 4, D, 25, 4, D, 10, 4, G, 25, 4, D, 25, 4, C, 25, 4, D, 50, 4, A, 50, 4, D, 50, 4, A, 25, 4, A, 25, 4, F, 25, 4, A, 25, 4,
 A, 25, 4, D, 25, 5, D, 10, 4, C, 25, 4, C, 10, 4, A, 25, 3, E, 25, 4, D, 50, 4
};


char *function_names[2] = {
  "musicbox", "other"
};

void main(void) {
  /* put your own code here */
  
  char *teststring = "say I like turtles!!!";
  char *teststring2 = "run musicbox";

  serial_parser(teststring, function_names);
 
  serial_parser(teststring2, function_names);
 
	
	//EnableInterrupts;
	
	
  for(;;) {
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  
  
  /* please make sure that you never leave main */
}


void function_selector(int func_num, char * parameters){
  switch(func_num){
    case(0):
    making_music(Music_input_converter(parameters));
    break;
    case(1):
    break;
    default:
    break;
  }
}


/*MUSIC SCORE GENERATOR FROM SERIAL INPUT*/
unsigned int *Music_input_converter(char *input){
  int i = 0;  
  unsigned int music_score[256];
  
  char * token = strtok(input, ",");
  
  while(token != NULL){
    music_score[i] = conver_string_to_brinary_to_int(token);
    
    i++;
    token = strtok(NULL, ",");
  }
 
  music_score[i-1] = 0;
  
  return music_score; 
}

unsigned int conver_string_to_brinary_to_int(char *string){

  int binarynum = atoi(string);

  int num = 0, temp = 0, remainder;
    while (binarynum!=0)
    {
        remainder = binarynum % 10;
        binarynum = binarynum / 10;
        num = num + (remainder*remainder);
        temp++;
    }
    return num;
}   