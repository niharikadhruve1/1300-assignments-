#include "givenA3.h"
/************************dhruveNiharikaA3Main.c**************
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
********************************************************/
int main(int argc, char *argv[])
{

    // declare all variables here
    //  arrays with names, and data
    char playerNames[NUMBER_PLAYERS][MAX_LEN_PNAME];
    char countryNames[NUMBER_PLAYERS][MAX_LEN_CNAME];
    int data[NUMBER_PLAYERS][6];
    // rest of var
    char whichCountry[100];
    char whichOne[10];
    int intWhichOne;
    int howMany = 0;
    int countryCount;
    int lower = 0;
    int upper = 0;
    int lowerBound = 0;
    int upperBound = 0;
    int taskSixChoice = 0;
    int taskSixNum = 0;
    //int run = 1;
    int choice = 0;
    char *fileName = argv[1];

    // call task 1 (readFile) here
    // task 1
    // converts data to arrays
    readFromFile(fileName, playerNames, countryNames, data);
    do
    {
        // printing the menu
        printf("\nHere is the menu - enter a number between 1 and 6 \n\n");
        printf("1.   Given a country name, find the total number of players from that country \n");
        printf("2.   Based on user’s choice, find the age and count of the youngest or oldest player (s) \n");
        printf("3.   Find the average number of aces among players ranked from x to y \n");
        printf("4.   Print a vertical histogram of the number of matches played \n");
        printf("5.   Rank the top N players based on the number of aces, double faults or Service Games Won \n");
        printf("6.   Exit \n");
        // getting choice from menu
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // make sure you add statements to validate the user's choice here - should be a number between 1 and 6

        
        switch (choice)
        {
        // task 2 which country
        case 1:
            printf("Which Country?: ");
            scanf("%s", whichCountry);
            // calling function
            countryCount = howManyFromCountryX(playerNames, countryNames, data, whichCountry);
            // printing the output
            printf("\n%s has %d ranked players", whichCountry, countryCount);
            break;
        // task 3 old or young
        case 2:
            printf("\nType old for oldest or young for youngest:");
            scanf("%s", whichOne);
            if ((strcmp(whichOne, "old")) == 0)
            {
                intWhichOne = 1;
            }
            if ((strcmp(whichOne, "young")) == 0)
            {
                intWhichOne = 0;
            }
            // calling function
            int age = oldOrYoung(data, intWhichOne, &howMany);

            // printing output
            if (intWhichOne == 1)
            {
                printf("\nThere is %d player(s) who is the oldest, and their age is %d\n", howMany, age);
            }
            if (intWhichOne == 0)
            {
                printf("\nThere is %d player(s) who is the youngest, and their age is %d\n", howMany, age);
            }

            break;
            // task 4
        case 3:
            // inputs
            printf("Enter lower bound: ");
            scanf("%d", &lower);
            if (lower > 30 || lower < 1)
            {
                lowerBound = 0;
            }
            else
            {
                lowerBound = 1;
            }

            while (lowerBound == 0)
            {
                printf("Enter upper bound: ");
                scanf("%d", &lower);
                if (lower > 30 || lower < 1)
                {
                    lowerBound = 0;
                }
                else
                {
                    lowerBound = 1;
                }
            }
            printf("Enter upper bound: ");
            scanf("%d", &upper);
            if (upper > 30 || upper < 1)
            {
                upperBound = 0;
            }
            else
            {
                upperBound = 1;
            }
            while (upperBound == 0)
            {
                printf("Enter upper bound: ");
                scanf("%d", &upper);
                if (upper > 30 || upper < 1)
                {
                    upperBound = 0;
                }
                else
                {
                    upperBound = 1;
                }
            }
            // calling function
            float avg = avgNumberAcesRanksXToY(data, lower, upper);
            // printing output
            printf("\nAverage of aces for all the players ranked %d to %d = %.2f", lower, upper, avg);
            break;
            // task 5
        case 4:
            // calling function
            printVerticalHistogramMatches(data);

            break;
            // task 6
        case 5:
            // taking inputs
            printf("Enter 1 if you want to rank top N players based on the number of aces, 2 for number of double faults, 3 for number of service games won: ");
            scanf("%d", &taskSixChoice);
            printf("How many players data do you want to see? ");
            scanf("%d", &taskSixNum);
            // calling function
            rankTopN(playerNames, countryNames, data, taskSixChoice, taskSixNum);
            break;
        // if they want to close the program
        case 6:
            printf("Goodbye\n");
            break;
        }

    } while (choice != 6);

    return 0;
}

