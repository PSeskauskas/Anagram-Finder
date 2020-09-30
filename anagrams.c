#include <stdio.h>
#include <stdbool.h>
#include "fileinput.h"
//Function that will count the occurrence of each character in each string of the copy array and
//store those values in a 2D integer array
void lettercount(char replica[MAX_ROWS][MAX_COLS], int lettercounter[MAX_ROWS][ALPHA])
{
    //Declaring the variables that will be used for the loops
    int i, j;
    int total = 0;
    //Nested for loops to initialize each cell of the letter counter array to 0
    for(i = 0; i < MAX_ROWS; i++)
    {
        for(j = 0; j < ALPHA; j++)
        {
            lettercounter[i][j] = 0;
        }
    }
    //Nested for loops to increment each cell with the corresponding occurrences of each character in each line of the copy array
    //The copy array is used because all the characters are lowercase, so less code is needed because we don't need to
    //consider uppercase characters
    for(i = 0; i < MAX_ROWS; i++)
    {
        for(j = 0; j < MAX_COLS && replica[i][j] != '\0'; j++)
        {
            if(replica[i][j] >= 'a' && replica[i][j] <= 'z')
            {
                //Total contains the ASCII value of the current letter minus the ASCII value of the character a
                //for example if the character is a, then a - a, the character a has the array index of 0
                total = replica[i][j] - 'a';
                lettercounter[i][total]++;
            }
        }
    }
}
//Check function that will compare if two strings are anagrams
int check(int i, int j, int lettercounter[MAX_ROWS][ALPHA])
{
    //Declaring the variable used in the loop parameter and the integer variable that will be returned by the function
    int k = 0;
    int count1 = 0;
    //For loop for counting the difference in character values of the two strings
    for(k = 0; k < ALPHA; k++) {
        //If there are different letters in the lines, then count is incremented before the break statement
        //so that it returns a nonzero value
        count1 += lettercounter[i][k] - lettercounter[j][k];
        //In the case that there are different characters, then the break statement exits the loop and returns
        //the nonzero value
        if(lettercounter[i][k] != lettercounter[j][k])
        {
            break;
        }
    }
    //If the frequency of letters is found to be the same, then the function returns 0, meaning they're anagrams
    return count1;
}
//Function to calculate the number of characters that would need to be removed from one line so that it would be
//an anagram of another line, the value must be less than 3 for this input array
int missing(int i, int j, int lettercounter[MAX_ROWS][ALPHA])
{
    //Declaring the variables used in the function
    int k = 0;
    int count2 = 0;
    //For loop for counting the difference in character values of the two strings
    for(k = 0; k < ALPHA; k++) {
        if(lettercounter[i][k] != lettercounter[j][k])
        {
            //Count is incremented every time there is a different letter from one line to the other sent to the
            //function, if this value is less than 3, then we take the strings to be missing anagrams of each other
            //and return the difference in character frequency
            count2++;
        }
    }
    //Return the value of count 2 to the comparison function in which the missing function was called
    return count2;
}
//Function that will compare the sizes of each line, and then send them to the check function or the missing anagrams
//function depending on the difference in size of the lines
void comparison(char replica[MAX_ROWS][MAX_COLS], int lettercounter[MAX_ROWS][ALPHA], char sentences[MAX_ROWS][MAX_COLS]) {
    //Declaring the variables used and the arrays used in the function
    int i, j;
    int count = 0;
    int count1 = 0;
    int temp = 0;
    int k = 0;
    int l = 0;
    int t = 1;
    int total = 0;
    int anagrams[10][10] = {0};
    int sizeOfStrings[MAX_ROWS];
    //A Boolean array is used to keep a record of which lines we have already found to have an anagram of another line
    //So we avoid duplication
    _Bool already[MAX_ROWS] = {false};
    //Nested for loop to store the size of each string in a 1D character array
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS && replica[i][j] != '\0'; j++) {
            if (replica[i][j] >= 'a' && replica[i][j] <= 'z') {
                count++;
            }
        }
        sizeOfStrings[i] = count;
        count = 0;
    }
    //Nested for loops to check if the sizes of strings are the same and if they are, send them to the check function
    //to see if they're anagrams or not
    for(i = 0; i < MAX_ROWS; i++)
    {
        for(j = 0; j < MAX_ROWS - 1; j++)
        {
            //If the size of string i equals size of string j and i doesn't equal to j, the two strings are sent to the
            //check function
            if((sizeOfStrings[i] == sizeOfStrings[j]) && (i != j))
            {
                //If the check function returns a value of 0, then the two strings are anagrams, otherwise they aren't
                //anagrams
                if(check(i, j, lettercounter) == 0 && already[j] == false)
                {
                    //If they're anagrams, then the indexes of the two lines are stored in the 2D integer array
                    //and the index of i in the boolean array is changed to true
                    anagrams[k][l] = i;
                    anagrams[k][l + 1] = j;
                    k++;
                    //Count keeps a record of how many anagrams we have found
                    count1++;
                    already[i] = true;
                }
            }
        }
        //Incrementing the value of i
        i++;
    }
    //Nested for loops to check if the first element of each row of the index array is the same as another
    for(i = 0; i < count1; i++) {
        for (j = 0; j < count1; j++) {
            //If this is the case, then the values after the duplicate will be sent to the previous row. E.G.
            //if we have 0, 5 on the first row and 0, 9, on the second row, then it will become 0, 5, 9 on the first row
            //in the index array and the second row will be an all zero row afterwards in this example case
            if(anagrams[i][j] == anagrams[i + 1][j]) {
                anagrams[i][j + 2] = anagrams[i + 1][j + 1];
                anagrams[i + 1][j] = 0;
                anagrams[i + 1][j + 1] = 0;
            }
        }
    }
    //Nested for loop to sort the index array so that any all zero rows will be put to the bottom of the 2D array
    //and avoided once the printing of the anagrams has commenced
    for(i = 0; i < count1;i++)
    {
        for(j = 0; j < count1; j++)
        {
            if(anagrams[i][j] == 0 && anagrams[i][j + 1] == 0)
            {
                temp = anagrams[i][j];
                anagrams[i][j] = anagrams[i + 1][j];
                anagrams[i + 1][j] = temp;
            }
        }
    }
    //Every zero value that isn't in the first row will be changed to a minus value, because the first row is the only
    //row that can contain the index of 0, and then the minus values will be ignored during printing because there
    //are no minus indexes for the lines, this is all done to make it easier to print out the anagrams
    for(i = 0; i < count1; i++)
    {
        for(j = t; j < count1; j++)
        {
            if(anagrams[i][j] == 0)
            {
                anagrams[i][j] = -1;

            }
        }
        t = 0;
    }
    //Calling the function that will print out the sorted list of strings and the subsequent anagrams
    fileoutput(sentences, anagrams, count1);
    //Opening the output.txt file to print out the precursor to the missing anagrams
    FILE *fp = fopen("../output.txt", "a");
    fprintf(fp,"The missing anagrams found in the array are as follows: ");
    fclose(fp);
    //Nested for loops to check the difference in size of two lines in the input array, if the difference is greater
    //than 0 and less than or equal to 3, the two lines are sent to the missing anagram array to check if they are
    //really missing anagrams of each other, if a certain number of characters were to be removed
    for(i = 0; i < MAX_ROWS - 1; i++)
    {
        for (j = 1; j < MAX_ROWS; j++)
        {
            if(i != j)
            {
                //temp stores the difference between the two lines it has iterated over
                temp = sizeOfStrings[i] - sizeOfStrings[j];
                //If temp is within the range of 0 and less than or equal to 3, then either one of the if statements is executed
                //in turn, calling the missing anagram function to see if they're missing anagrams of each other, and return
                //the character difference if they're missing anagrams, and then send them to the second output function in fileinput.c
                if(temp <= 3 && temp > 0)
                {
                    if(missing(i, j, lettercounter) == 1)
                    {
                        total = missing(i, j, lettercounter);
                        //Calling the function to print out the missing anagrams if the return value equals 1
                        fileoutputMissing(sentences, i, j, total);
                    }
                    else if(missing(i, j, lettercounter) > 1 && missing(i, j, lettercounter) <= 3)
                    {
                        total = missing(i, j, lettercounter);
                        //Calling the function to print out the missing anagrams if the return value is greater than 1
                        fileoutputMissing(sentences, i, j, total);
                    }
                    //I used separate if statements because of the number of characters that could be removed would yield
                    //a different sentence e.g. 1 character was to be removed vs 2 characters were to be removed
                }
            }
        }
    }
}