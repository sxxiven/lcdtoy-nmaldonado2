// Nichole Maldonado and Previous Commits
// This is the header file for buzzer.h
// which has functions to initialize the
// buzzer and set the frequency of the buzzer.

#ifndef buzzer_included
#define buzzer_included

#define NOTE_E 3033
#define NOTE_E_FLAT 3214
#define NOTE_B 4049
#define NOTE_D 3405
#define NOTE_C 3822
#define NOTE_A 4545

// Initialize the buzzer.
void buzzer_init();

// Set the period based on the number of
// cycles.
void buzzer_set_period(short cycles);

#endif // included
