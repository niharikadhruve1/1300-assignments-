#include <stdio.h>
#include <string.h>
#include "givenA3.h"


/************************dhruveNiharikaA3.c**************
Student Name: Niharika Dhruve  Email Id: ndhruve
Due Date: November ... Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity. 2) I
have completed the Computing with Integrity Tutorial on Moodle; and 3) I have
achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and
all material that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for
this course.


Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall
compiling:
gcc -std=c99 -Wall dhruveNiharikaA3.c dhruveNiharikaA3Main.c
Running: ./a.out data.txt
********************************************************/


// data to array function
int readFromFile(char fName[30], char playerNames[NUMBER_PLAYERS][MAX_LEN_PNAME],
                 char countryNames[NUMBER_PLAYERS][MAX_LEN_CNAME], int data[NUMBER_PLAYERS][6])
{
    // vars
    FILE *file;
    char line[128];
    int i = 0;

    file = fopen(fName, "r");
    if (!file)
    // if not data.txt
    {
        return -1;
    }


    while (fgets(line, sizeof(line), file))
    {
        // var inside loop
        int whiteSpaceCounter = 0;
        int nameIndex = 0, countryIndex = 0, dataIndex = 0;
        int lineIndex = 0;
        int number = 0; // For accumulating numbers

        // will be seperating data by white spaces
        while (line[lineIndex] != '\0' && line[lineIndex] != '\n')
        {
    
            if (line[lineIndex] == ' ' || line[lineIndex] == '\t')
            {
                // add to whitespace counter for each separator
                whiteSpaceCounter++;
                if (whiteSpaceCounter >= 3 && number != 0)
                {
                    // Store the number
                    data[i][dataIndex++] = number;
                    number = 0; // Reset for the next number
                }
                // Skip mulitiple spaces or tabs
                while (line[lineIndex + 1] == ' ' || line[lineIndex + 1] == '\t')
                {
                    lineIndex++;
                }
                // Add a space between first and last name 
                if (whiteSpaceCounter == 1)
                {
                    playerNames[i][nameIndex++] = ' ';
                }
            }

            else
            {
                // adds data to its array
                if (whiteSpaceCounter < 2)
                {
                    // Adds to player name array
                    playerNames[i][nameIndex++] = line[lineIndex];
                }
                else if (whiteSpaceCounter == 2)
                {
                    // Adds to country name array
                    countryNames[i][countryIndex++] = line[lineIndex];
                }
                else if (whiteSpaceCounter >= 3)
                {
                    // adds to data array
                    if (line[lineIndex] >= '0' && line[lineIndex] <= '9')
                    {
                        number = number * 10 + (line[lineIndex] - '0');
                    }
                }
            }
            lineIndex++;
        }

        // Store the last accumulated number, if any
        if (number != 0)
        {
            data[i][dataIndex++] = number;
        }

        // end strings
        playerNames[i][nameIndex] = '\0';
        countryNames[i][countryIndex] = '\0';

        i++; // Move to the next player
    }
    // close file once done task
    fclose(file);
    return 1;
}

// function to find how many people per country 
int howManyFromCountryX(char playerNames[NUMBER_PLAYERS][MAX_LEN_PNAME], char countryNames[NUMBER_PLAYERS][MAX_LEN_CNAME], int data[NUMBER_PLAYERS][6], char whichCountry[MAX_LEN_CNAME])
{
    // var
    int count = 0;
    // loop goes through list of players info
    for (int i = 0; i < 30; i++)
    {
        // strcmp compares the two strings
        if ((strcmp(whichCountry, countryNames[i])) == 0)
        {
            // prints output
            printf("\n%s, %s, (Rank %d) \n", playerNames[i], whichCountry, data[i][0]);
            count++;
        }
    }
    // number of people in that country
    return count;
}

//function for old or young
int oldOrYoung(int data[NUMBER_PLAYERS][6], int whichOne, int *howMany)
{

    int age = data[0][1];
    *howMany = 0;
    // loop which compares ages, until done all 30, in the end we will be left with the oldest person
    if (whichOne == 1)
    {
        for (int i = 0; i < 30; i++)
        {
            if ((data[i][1]) > age)
            {
                age = data[i][1];
            }
        }
    }
    // loop which compares ages, until done all 30, in the end we will be left with the youngest person
    if (whichOne == 0)
    {
        for (int i = 0; i < 30; i++)
        {
            if ((data[i][1]) < age)
            {
                age = data[i][1];
            }
        }
    }
    // finds how many people for either to oldest or youngest age
    for (int i = 0; i < 30; i++)
    {
        if ((data[i][1]) == age)
        {
            (*howMany)++;
        }
    }
    // retuns age to main
    return age;
}

// avg number of aces function
float avgNumberAcesRanksXToY(int data[NUMBER_PLAYERS][6], int lower, int upper)
{
    // var
    float avg = 0;
    int sum = 0;
    int count = 0;

    // 
    // finds all aces between lower and upper, including the lower and upper
    for (int i = 0; i < 30; i++)
    {
        if (data[i][0] >= lower && data[i][0] <= upper)
        {
            
            sum += data[i][3];
            count++;
        }
    }
    // finds avg
    avg = (float)sum / count;

    
    // if valid will return avg to main, otherwise -1 will be returned
    if (lower > upper)
    {
        return -1;
    }

    else
    {
        return avg;
    }
}

// function to print the histogram
void printVerticalHistogramMatches(int data[NUMBER_PLAYERS][6])
{
    // var
    int numBlank = 0;
    int numStars;
    // loop that prints the first row of numbers
    for (int i = 0; i < 30; i++)
    {
        printf("%d  ", data[i][2]);
    }
    printf("\n");
    // printng histogram
    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            numStars = data[j][2] - 21;
            numBlank = 23 - numStars;
            if (i >= numBlank)
            {
                printf(" *  ");
            }
            else
            {
                printf("    ");
            }
            
        }
        printf("\n");
    }
    // spacing for the bottom numbers
    for (int i = 0; i < 30; i++)
    {
        if (i < 9)
        {
            printf(" %d  ", i + 1);
        }
        else if (i == 8)
        {
            printf(" %d ", i + 1);
        }
        else if (i == 9)
        {
            printf(" %d  ", i + 1);
        }
        else
        {
            printf("%d  ", i + 1);
        }
    }
}

// function to print the ranks based on input
void rankTopN(char playerNames[NUMBER_PLAYERS][MAX_LEN_PNAME], char countryNames[NUMBER_PLAYERS][MAX_LEN_CNAME], int data[NUMBER_PLAYERS][6], int whichOne, int n)
{
    // var
    int order[30][2];
    int choice = whichOne + 2;
    int i, j;
    // adds all data to order array, depending on which choice user gave
    for (int a = 0; a < NUMBER_PLAYERS; a++){
        // 
        order[a][0] = data[a][choice];
        // rank
        order[a][1] = data[a][0];
    }

    
    // now orders the the order array 
    for (i = 0; i < 30 - 1; i++)
    {
        for (j = 0; j < 30 - i - 1; j++)
        {
            if (order[j][0] < order[j + 1][0])
            {
                int score = order[j][0];
                order[j][0] = order[j + 1][0];
                order[j + 1][0] = score;

                // adds rank to the order array aswell
                int rank = order[j][1];
                order[j][1] = order[j + 1][1];
                order[j + 1][1] = rank;
            }
        }
    }


    // prints output
    printf("Top %d players ranked on ", n);
    switch (whichOne)
    {
    case 1:
        printf("Aces\n\n");
        break;
    case 2:
        printf("Double Faults\n\n");
        break;
    case 3:
        printf("Service Games Won\n\n");
        break;
    }

    // prints for only the amount of players the user wants to see
    for (int b = 0; b < n; b++){
        int index = order[b][1] - 1;
        printf("%s, %s, %d, (Rank %d)\n", playerNames[index],countryNames[index], order[b][0], order[b][1]);
    }


}
