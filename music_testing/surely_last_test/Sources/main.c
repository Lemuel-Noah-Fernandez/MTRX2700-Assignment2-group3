#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "making_music.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// All notes are in the 4th octave
#define A 3409
#define B 3037
#define C 5733
#define D 5108
#define E 4551
#define F 4295
#define G 3827

#define Z 20 // Definition for a rest
#define toggle 0x04

/*
unsigned int crazy[] = {
 D4 754, F4 504, D4 254, D4 104, G4 254, D4 254, C4 254, D4 754, A4 504, D4 754, D4 104, A4 254, A4 254, F4 254, D4 254, A4 254, D4 255, D4 104, C4 254,
 C4 104, A4 253, E4 254, D4 504 
 }; 

 
unsigned long int score[] = {
51084075, 42954050, 51084025, 51084010, 38274025, 51084025, 57334025, 51084075, 34094050, 51084075, 51084010, 34094025, 34094025, 42954025, 51084025, 34094025, 51085025,
51084010, 57334025, 57334010, 34093025, 45514025, 51084050 
};                                                               
*/

// Score is in the form (note, time, octave)
unsigned int score[] = {
 E, 40, 4, D, 75, 4, F, 50, 4, D, 25, 4, D, 10, 4, G, 25, 4, D, 25, 4, C, 25, 4, D, 50, 4, A, 50, 4, D, 50, 4, A, 25, 4, A, 25, 4, F, 25, 4, A, 25, 4,
 A, 25, 4, D, 25, 5, D, 10, 4, C, 25, 4, C, 10, 4, A, 25, 3, E, 25, 4, D, 50, 4, Z, 50, 4, C, 50, 8, C, 50, 1
};

int time;
char time_string[10];

void main(void) {
  
  time = music_runtime(score); // The song will take this many ms to play
  sprintf(&time_string[0], "%dx", time); // Converts the time integer to a string for serial output
  making_music(score);
  flag = 4;

}







