#ifndef UNTITLED_FILEINPUT_H
#define UNTITLED_FILEINPUT_H
//Defining the maximum rows and columns for the arrays and the ALPHA constant for the number of letters in the alphabet
//These constants will be used throughout the .C files, so they were put here in one place to make it easier to alter them
#define MAX_ROWS 14
#define MAX_COLS 50
#define ALPHA 26
//Declaring the functions that will be used for the file input and file output
void readsentences(char sentences[MAX_ROWS][MAX_COLS]);
void fileoutput(char sentences[MAX_ROWS][MAX_COLS], int anagrams[10][10], int count1);
void fileoutputMissing(char sentences[MAX_ROWS][MAX_COLS], int i, int j, int total);
#endif
