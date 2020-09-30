#include <string.h>
#include "fileinput.h"
#include "quicksort.h"
#include "anagrams.h"
//Declaring the function that will convert the copy of the original 2D array to lowercase
void convert(char replica[MAX_ROWS][MAX_COLS], char sentences[MAX_ROWS][MAX_COLS]);
//Declaring the function main
int main(void) {
    //Declaring the sentences array
    char sentences[MAX_ROWS][MAX_COLS];
    //Calling the file input function to read the strings from the input.txt file
    readsentences(sentences);
    //Declaring the replica array that will store the lowercase strings
    char replica[MAX_ROWS][MAX_COLS];
    //Calling the function to copy the original array to the copy array and change the uppercase characters to lowercase
    convert(replica, sentences);
    //Calling the quicksort function to sort the lowercase and original array in alphabetical order
    quicksortChar(replica, sentences, 0, MAX_ROWS - 1);
    //Declaring the lettercounter array that will contain the occurrences of each character in each line
    int lettercounter[MAX_ROWS][ALPHA];
    //Calling the function that will count the occurrences of each character in each string
    lettercount(replica, lettercounter);
    //Calling the function that will compare strings to see if they're anagrams or not, and find missing anagrams
    comparison(replica, lettercounter, sentences);
    return 0;
}
//Function to convert the uppercase characters of the copy array to lowercase
void convert(char replica[MAX_ROWS][MAX_COLS], char sentences[MAX_ROWS][MAX_COLS])
{
    //Declaring the variables i and j that will be used in the loop parameters
    int i, j;
    //For loop to copy the strings of the original array to the copy array using strcpy
    for (i = 0; i < MAX_ROWS; i++) {
        strcpy(replica[i], sentences[i]);
    }
    //Nested for loop to convert uppercase characters to lowercase in the copy array
    for (i = 0; i < MAX_ROWS && replica[i] != '\0'; i++) {
        for (j = 0; j < MAX_COLS && replica[i][j] != '\0'; j++) {
            if (replica[i][j] >= 'A' && replica[i][j] <= 'Z') {
                replica[i][j] += 32;
            }
        }
    }
}