#ifndef UNTITLED_QUICKSORT_H
#define UNTITLED_QUICKSORT_H
//Declaring the quicksort functions
void swap(char replica[MAX_ROWS][MAX_COLS], char sentences[MAX_ROWS][MAX_COLS], int i, int j);
int partition(char replica[MAX_ROWS][MAX_COLS], char sentences[MAX_ROWS][MAX_COLS], int first, int last);
void quicksortChar(char replica[MAX_ROWS][MAX_COLS], char sentences[MAX_ROWS][MAX_COLS], int first, int last);
#endif //UNTITLED_QUICKSORT_H

