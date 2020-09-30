#include <stdio.h>
#include "fileinput.h"
//Declaring pointers to the input.txt and output.txt files
const char* INPUT_TEXT_FILE_PATH = "../input.txt";
const char* OUTPUT_TEXT_FILE_PATH = "../output.txt";
//Function to open the input.txt file and read in each line and subsequently store each string in a 2D character array
void readsentences(char sentences[MAX_ROWS][MAX_COLS])
{
    //Declaring the variables used for reading in the sentences
    int line = 0;
    int i, j;
    //Opening the file and declaring that we will be reading the input file
    FILE *fp = fopen(INPUT_TEXT_FILE_PATH, "r");
    //If pointer fp == NULL then the file hasn't been opened correctly and the program will return an error
    if(fp == NULL)
    {
        printf("Error");
        return -1;
    }
    //If the file has been opened correctly, then the while loop will iterate over each line and store each line in the
    //2D character array
    else
    {
        while(fgets(sentences[line], sizeof(sentences[line]), fp))
        {
            line++;
        }
        //Closing the file after taking in the final line of the file
        fclose(fp);
    }
    //Nested for loop to convert newline characters to null terminators in the 2D character array
    for(i = 0; i < MAX_ROWS; i++)
    {
        for(j = 0; j < MAX_COLS; j++)
        {
            if(sentences[i][j] == '\n')
            {
                sentences[i][j] = '\0';
            }
        }
    }
}
//Function to output the alphabetically sorted strings to the file output.txt
void fileoutput(char sentences[MAX_ROWS][MAX_COLS], int anagrams[10][10], int count1)
{
    //Declaring the variable i and j that will be used for the parameters of the loop
    int i, j;
    //Opening the output file and declaring that we will be writing to it
    FILE *fp = fopen(OUTPUT_TEXT_FILE_PATH, "w");
    //If the file hasn't been opened correctly then the program will return an error
    if(fp == NULL)
    {
        printf("Error");
        return -1;
    }
    //For loop to print the sorted 2D array to the output.txt file
    fprintf(fp,"The sorted array of strings is as follows: \n");
    for(i = 0; i < MAX_ROWS; i++)
    {
        fprintf(fp,"%s\n", sentences[i]);
    }
    fprintf(fp, "\n");
    //Nested for loops to print out the anagrams that were found
    fprintf(fp, "These are the anagrams that were found in the array:\n");
    for(i = 0; i < count1 - 1; i++)
    {
        fprintf(fp, "Anagram %d: ", i + 1);
        for(j = 0; j < count1; j++)
        {
            //if anagrams[i][j] != -1, means that for every value in the array that isn't minus 1, these are anagrams
            //that need to be printed out.
            if(anagrams[i][j] != -1) {
                fprintf(fp, "\'%s\' ", sentences[anagrams[i][j]]);
            }
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n");
    //Closing the output.txt file after printing out the final anagram
    fclose(fp);
}
//Function to output the missing anagrams that were found to the output.txt file
void fileoutputMissing(char sentences[MAX_ROWS][MAX_COLS], int i, int j, int total)
{
    //Opening the output file and declaring that we will be appending the output.txt file
    FILE *fp = fopen(OUTPUT_TEXT_FILE_PATH, "a");
    //If the file hasn't been opened correctly then the program will return an error
    if(fp == NULL)
    {
        printf("Error");
        return -1;
    }
    fprintf(fp, "\n");
    //Print statement for if the value returned is 1, separate statements are used because if more than one character is
    //removed, then characters (plural) are removed as opposed to just 1 character
    if(total == 1)
    {
        fprintf(fp, "\'%s\' is an anagram of \'%s\' if %d character was to be removed", sentences[i], sentences[j], total);
    }
    //Print statement if the difference in characters is greater than 1 and less than or equal to 3
    else if(total > 1 && total <= 3)
    {
        fprintf(fp, "\'%s\' is an anagram of \'%s\' if %d characters were to be removed", sentences[i], sentences[j], total);
    }
    //Closing the output.txt file after printing out the final missing anagram
    fclose(fp);
}