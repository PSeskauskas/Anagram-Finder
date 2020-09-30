#ifndef UNTITLED_ANAGRAMS_H
#define UNTITLED_ANAGRAMS_H
//Declaring the functions that will be used to identify the anagrams and missing anagrams
void lettercount(char replica[MAX_ROWS][MAX_COLS], int lettercounter[MAX_ROWS][ALPHA]);
void comparison(char replica[MAX_ROWS][MAX_COLS], int lettercounter[MAX_ROWS][ALPHA], char sentences[MAX_ROWS][MAX_COLS]);
int check(int i, int j, int lettercounter[MAX_ROWS][ALPHA]);
int missing(int i, int j, int lettercounter[MAX_ROWS][ALPHA]);
#endif
