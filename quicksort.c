#include <string.h>
#include "fileinput.h"
//Function that will swap strings so that they will be sorted alphabetically and then printed in the output.txt file
void swap(char replica[MAX_ROWS][MAX_COLS], char sentences[MAX_ROWS][MAX_COLS], int i, int j)
{
    //Declaring a temporary character array that will be used in the sort function
    char temp[MAX_COLS];
    //Every swap made on the lowercase array is duplicated for the original array, because we want to print out the
    //sorted original array
    strcpy(temp, replica[j]);
    strcpy(replica[j], replica[i]);
    strcpy(replica[i], temp);
    strcpy(temp, sentences[j]);
    strcpy(sentences[j], sentences[i]);
    strcpy(sentences[i], temp);
}
//Function that will partition the lowercase array into two sub arrays
int partition(char replica[MAX_ROWS][MAX_COLS], char sentences[MAX_ROWS][MAX_COLS], int first, int last)
{
    //Calling the swap function that will swap the middle value into the first position
    swap(replica, sentences, first, (first + last) / 2);
    //Declaring the pivot variable
    char *pivot = replica[first];
    //Index of first unknown value
    int index1 = first + 1;
    //Index of last unknown value
    int index2 = last;
    //While some values are still unknown, strcmp the line with the pivot and move accordingly
    while (index1 <= index2) {
        if (strcmp(replica[index1], pivot) < 0)
            index1++;
        else if (strcmp(replica[index2],  pivot) > 0)
            index2--;
        else {
            //Calling the swap function
            swap(replica, sentences, index1, index2);
            index1++;
            index2--;
        }
    }
    //Calling the swap function that will place the pivot value in between the two sub arrays and return its index
    swap(replica, sentences, first, index2);
    return index2;
}
//Quicksort character function
void quicksortChar(char replica[MAX_ROWS][MAX_COLS], char sentences[MAX_ROWS][MAX_COLS], int first, int last)
{
    //if the size of the array is equal to 0 or 1, the array is sorted by definition, we don't need to do any sorting
    if(first < last)
    {
        int pivotindex = partition(replica, sentences, first, last);
        quicksortChar(replica, sentences, first, pivotindex-1);
        quicksortChar(replica, sentences, pivotindex+1, last);
    }
}