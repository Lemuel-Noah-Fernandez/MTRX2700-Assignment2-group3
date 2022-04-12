#ifndef MUSIC_HEADER
#define MUSIC_HEADER


void timer_setup(void);
void delay(unsigned int time);
void play(unsigned int score[]);
int octave_check(int octave, int letter);
void making_music(unsigned int score[]);
__interrupt void musicISR();

#endif