/************************dhruveNiharikanameA1.c**************
Student Name: Niharika Dhruve Email Id: ndhruve
Due Date: ............ Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic
integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self
Test.
I assert that this work is my own. I have appropriately acknowledged any
and all material that I have used, whether directly quoted or
paraphrased. Furthermore, I certify that this assignment was prepared by
me specifically for this course.
********************************************************/
/*********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall
compiling:
gcc lastnameFirstnameA2.c -std=c99 -Wall
OR
gcc lastnameFirstnameA1.c -std=c99 -Wall -o assn1
Running the Program
Running: ./a.out
OR
Running: ./assn1
*********************************************************/
#include <stdio.h>
#include <string.h>
int main()
{
    // USING FORMATTING IN SCENARIO 1 OF THE ASSIGNMENT1 INFO PAGE
    // declare all vars
    // all var involving time
    int timeFormat;
    int hours;
    int mins;
    int twelveHourConversion;
    int twentyfourHourConversion;
    char AmPm;
    // all var involving hotal 
    int hotel;
    int hotelDays;
    int hotelChoice;
    float hotelCost;
    // all var involving rides and flight fees
    int ride;
    float rideCost;
    float flightCost;
    // all var involving discounts in task 6
    int dayOfBirth;
    float discountOne;
    float discountTwo;
    int birthFirstDigit;
    int birthSecondDigit;
    // all var involving total costs
    float totalCost;
    float totalTaxCost;


    // TASK ONE
    // task one finding 12 hour or 24 hour format
    printf("Would you like to enter the time in 12-hour format (enter 1) or 24-hour format (enter2)? ");
    scanf("%d", &timeFormat);
    
    switch (timeFormat)
    {
    // using case to see if user inputed 12 hour format
    case 1:
        // outputs tailored to 12 hour format
        printf("\nEnter time in 12 hour format\n");
        // taking hours and minutes and storing them
        printf("\nEnter a value between 0 and 12 for hour: ");
        scanf("%d", &hours);
        printf("Enter a value between 0 and 60 for minutes: ");
        scanf("%d", &mins);
        // finding if in am or pm
        printf("Enter a for am or p for pm: ");
        scanf(" %c", &AmPm);
        // outputing their time and their time in 24 hour format
        printf("-\n--------------------------\n");
        // am outputs
        if (AmPm == 'a')
        {
            if (hours < 10 && mins < 10)
            {
                twelveHourConversion = hours;
                twentyfourHourConversion = hours;
                printf("You entered 0%d:0%d am\n", hours, mins);
                printf("In 24 hour format - you entered 0%d:0%d", hours, mins);
            }
            else if (hours >= 10 && mins < 10)
            {
                twelveHourConversion = hours;
                twentyfourHourConversion = hours;
                printf("You entered 0%d:%d am\n", hours, mins);
                printf("In 24 hour format - you entered %d:0%d", hours, mins);
            }
            else if (hours >= 10 && mins >= 10)
            {
                twelveHourConversion = hours;
                twentyfourHourConversion = hours;
                printf("You entered %d:%d am\n", hours, mins);
                printf("In 24 hour format - you entered %d:%d", hours, mins);
            }
            else if (hours < 10 && mins >= 10)
            {
                twelveHourConversion = hours;
                twentyfourHourConversion = hours;
                printf("You entered 0%d:%d am\n", hours, mins);
                printf("In 24 hour format - you entered 0%d:%d", hours, mins);
            }
        }
        // pm outputs
        // outputs their time along with their time in 24 hour format
        else if (AmPm == 'p')
        {

            if (hours >= 10 && mins < 10)
            {
                twelveHourConversion = hours;
                twentyfourHourConversion = hours += 12;
                printf("You entered %d:%d pm\n", hours, mins);
                hours += 12;
                printf("In 24 hour format - you entered %d:0%d", hours, mins);
            }
            else if (hours >= 10 && mins >= 10)
            {
                twelveHourConversion = hours;
                twentyfourHourConversion = hours += 12;
                printf("You entered %d:%d pm\n", hours, mins);
                hours += 12;
                printf("In 24 hour format - you entered %d:%d", hours, mins);
            }
            else if (hours < 10 && mins < 10)
            {
                twelveHourConversion = hours;
                twentyfourHourConversion = hours += 12;
                printf("You entered 0%d:0%d pm\n", hours, mins);
                hours += 12;
                printf("In 24 hour format - you entered %d:0%d", hours, mins);
            }
            else if (hours < 10 && mins >= 10)
            {
                twelveHourConversion = hours;
                twentyfourHourConversion = hours += 12;
                printf("You entered 0%d:%d pm\n", hours, mins);
                hours += 12;
                printf("In 24 hour format - you entered %d:%d", hours, mins);
            }
        }

        printf("\n---------------------------\n");

        break;
    // using case to see if user inputed 24 hour format
    case 2:
        // outputs with 24 hour format
        printf("\nEnter time in 24 hour format \n");
        // taking hours and minutes in 24 hour format
        printf("\nEnter a value between 0 and 24 for hour: ");
        scanf("%d", &hours);
        printf("Enter a value between 0 and 60 for minutes: ");
        scanf("%d", &mins);
        // outputing their time and their time in 14 hour format
        printf("---------------------------\n");
        twentyfourHourConversion = hours;
        if (hours > 10 && mins < 10){
                printf("You entered 0%d:%d\n", hours, mins);
                twelveHourConversion = hours - 12;
                if (hours > 12){
                    printf("In 12 hour format - you entered %d:%d pm", twelveHourConversion, mins);
                }
                else{
                    printf("In 12 hour format - you entered %d:%d am", twelveHourConversion, mins);
                }
            }
        else if (hours > 10 && mins > 10){
                printf("You entered %d:%d\n", hours, mins);
                twelveHourConversion = hours - 12;
                if (hours > 12){
                    printf("In 12 hour format - you entered %d:%d pm", twelveHourConversion, mins);
                }
                else{
                    printf("In 12 hour format - you entered %d:%d am", twelveHourConversion, mins);
                }
                }
                
         else if (hours < 10 && mins < 10){
                twelveHourConversion = hours;
                printf("You entered 0%d:0%d am\n", hours, mins);
                printf("In 12 hour format - you entered 0%d:0%d", hours, mins);
            }
        else if (hours < 10 && mins > 10)
            {
                printf("You entered 0%d:%d am\n", hours, mins);
                printf("In 12 hour format - you entered 0%d:%d", hours, mins);
            }
        
        printf("\n---------------------------\n");
    // end of case
    default:
        break;
    }

    // End of task one
    // TASK TWO
    // task two find closest times 
    // close to 7:15?
    if (twentyfourHourConversion <= 7 && (AmPm == 'a'))
    {
        // making sure fits within the time frame 
        // outputing closest time and arriving time
        // setting flight cost = to cost based on time slot
        if (twentyfourHourConversion == 7 && mins < 15)
        {
            printf("Closest departure times is 7:15 a.m., arriving at 8:25 a.m.\n");
            flightCost = 231;
        }
        if (twentyfourHourConversion < 7)
        {
            printf("Closest departure times is 7:15 a.m., arriving at 8:25 a.m.\n");
            flightCost = 231;
        }
    }
    // close to 8:15?
    if (twentyfourHourConversion >= 7 && twentyfourHourConversion <= 8)
    {
        // making sure fits within the time frame 
        // outputing closest time and arriving time
        // setting flight cost = to cost based on time slot
        if (twentyfourHourConversion == 7 && mins > 15)
        {
            printf("Closest departure times is 8:15 a.m., arriving at 9:25 a.m.\n");
            flightCost = 226;
        }
        if (twentyfourHourConversion == 8 && mins < 15)
        {
            printf("Closest departure times is 8:15 a.m., arriving at 9:25 a.m.\n");
            flightCost = 226;
        }
    }
    // close to 9:15?
    if (twentyfourHourConversion >= 8 && twentyfourHourConversion <= 9)
    {   
        // making sure fits within the time frame 
        // outputing closest time and arriving time
        // setting flight cost = to cost based on time slot
        if (twentyfourHourConversion == 8 && mins > 15)
        {
            printf("Closest departure times is 9:15 a.m., arriving at 10:25 a.m.\n");
            flightCost = 226;
        }
        if (twentyfourHourConversion == 9 && mins < 15)
        {
            printf("Closest departure times is 9:15 a.m., arriving at 10:25 a.m.\n");
            flightCost = 226;
        }
    }
    // close to 10:15?
    if (twentyfourHourConversion >= 9 && twentyfourHourConversion <= 10)
    {   
        // making sure fits within the time frame 
        // outputing closest time and arriving time
        // setting flight cost = to cost based on time slot
        if (twentyfourHourConversion == 9 && mins > 15)
        {
            printf("Closest departure times is 10:15 a.m., arriving at 11:25 a.m.\n");
            flightCost = 283;
        }
        if (twentyfourHourConversion == 10 && mins < 15)
        {
            printf("Closest departure times is 10:15 a.m., arriving at 11:25 a.m.\n");
            flightCost = 283;
        }
    }
    // close to 11:15?
    if (twentyfourHourConversion >= 10 && twentyfourHourConversion <= 11)
    {
        // making sure fits within the time frame 
        // outputing closest time and arriving time
        // setting flight cost = to cost based on time slot
        if (twentyfourHourConversion == 10 && mins > 15)
        {
            printf("Closest departure times is 11:15 a.m., arriving at 12:25 p.m.\n");
            flightCost = 283;
        }
        if (twentyfourHourConversion == 11 && mins < 15)
        {
            printf("Closest departure times is 11:15 a.m., arriving at 12:25 p.m.\n");
            flightCost = 283;
        }
    }
    // close to 3:15?
    if (twentyfourHourConversion >= 11 && twentyfourHourConversion <= 15)
    {
        // making sure fits within the time frame 
        // outputing closest time and arriving time
        // setting flight cost = to cost based on time slot
        if (twelveHourConversion == 11 && mins > 15)
        {
            printf("Closest departure times is 3:15 p.m., arriving at 4:25 p.m.\n");
            flightCost = 226;
        }
        else if (twentyfourHourConversion == 15 && mins < 15)
        {
            printf("Closest departure times is 3:15 p.m., arriving at 4:25 p.m.\n");
            flightCost = 226;
        }
        else if (twentyfourHourConversion > 11 && twentyfourHourConversion < 15)
        {
            printf("Closest departure times is 3:15 p.m., arriving at 4:25 p.m.\n");
            flightCost = 226;
        }
    }
    // close to 4:15?
    if (twentyfourHourConversion >= 15 && twentyfourHourConversion <= 16)
    {
        // making sure fits within the time frame 
        // outputing closest time and arriving time
        // setting flight cost = to cost based on time slot
        if (twentyfourHourConversion == 15 && mins > 15)
        {
            printf("Closest departure times is 4:15 p.m., arriving at 5:25 p.m.\n");
            flightCost = 226;
        }
        if (twentyfourHourConversion == 16 && mins < 15)
        {
            printf("Closest departure times is 4:15 p.m., arriving at 5:25 p.m.\n");
            flightCost = 226;
        }
    }
    // close to 5:15?
    if (twentyfourHourConversion >= 16 && twentyfourHourConversion <= 17)
    {
        // making sure fits within the time frame 
        // outputing closest time and arriving time
        // setting flight cost = to cost based on time slot
        if (twentyfourHourConversion == 16 && mins > 15)
        {
            printf("Closest departure times is 5:15 p.m., arriving at 6:25 p.m.\n");
            flightCost = 401;
        }
        if (twentyfourHourConversion == 17 && mins < 15)
        {
            printf("Closest departure times is 5:15 p.m., arriving at 6:25 p.m.\n");
            flightCost = 401;
        }
    }
    // end of task two
    // TASK THREE and FOUR 
    // asking if need hotel or not, and assiging a var to their choice
    printf("\nWould you like a hotel in Montreal - enter 0 for no; 1 for yes? "); // task three
    scanf("%d", &hotel);
    switch (hotel)
    {
    // using var hotel to see if they need a hotel or not
    // case: 1 = hotel 0 = no hotel
    case 1:
        // outputs if they need hotel
        printf("\nThere are 3 hotels:\n1. Marriott: $248 per night\n2. Sheraton: $90 per night\n3. Double tree: $128 per night\n");
        printf("\nYour choice?:");
        scanf("%d", &hotelChoice);
        // assigning each hotel choice to a numer: marriot = 1 shearton = 2 double tree = 3
        printf("How many days in Montreal?");
        // taking user input for # of hotel staying days 
        scanf("%d", &hotelDays);
        printf("\nWould you like a ride from airport to hotel? - enter 0 for no; 1 for yes ");// task four
        scanf("%d", &ride);
        // using var ride to store if needing a ride or not (1 = yes, 0 = no)     
        // finding ride cost based on hotel
        // using var rideCost to store cost of ride
        if (ride == 1)
        {
            if (hotelChoice == 1)// ride cost for marriot hotel
            {
                rideCost = 0;
            }
            else if (hotelChoice == 2)// ride cost for shearton hotel
            {
                rideCost = 25;
            }
            else if (hotelChoice == 3)// ride cost for double tree hotel
            {
                rideCost = 20;
            }
        }
        // ride cost if no ride
        if (ride == 0)
        {
            rideCost = 0;
        }
        // now finding total hotelCost, using # of hotel days stayed to find this
        if (hotelChoice == 1)// marriot hotel
        {
            hotelCost = 248 * hotelDays;
        }
        else if (hotelChoice == 2)// shearton hotel
        {
            hotelCost = 90 * hotelDays;
        }
        else if (hotelChoice == 3)// double tree hotel
        {
            hotelCost = 128 * hotelDays;
        }

        break;
    // if no hotel and no ride:
    case 0:
        hotelCost = 0;
        rideCost = 0;
    default:
        break;
    // end of switch
    // end of tasks three and four
    }
    // TASK FIVE
    printf("\nNow enter your day of birth to qualify for discount2: ");
    // needed for task six
    scanf("%d", &dayOfBirth);
    // day of birth needed to see if they qualify for discount
    // Outputing all costs
    printf("\nYour total cost comes to:\n");
    printf("\nCost of closest departure flight: $ %.2f", flightCost);
    printf("\nCost of Hotel for %d days: $ %.2f", hotelDays, hotelCost);
    printf("\nCost of ride: $ %.2f", rideCost);
    // calc total cost
    totalCost = rideCost + hotelCost + flightCost;
    printf("\n\nTotal cost before tax: %.2f\n", totalCost);
    // Task SIX:
    // discount1:
    // if totalcosts/11 remainder is 0 then we know it is an multiple of 11
    if((int)totalCost%11 == 0){ // using that logic with mod
        discountOne = totalCost * 0.05;
        printf("You get a 5%% discount because the total cost was a multiple of 11 :)\n");
    }
    else{// if not a multiple, no discount :(
        printf("\nSorry - you missed out on 5%% discount becasue the total cost was not a multiple of 11\n");
        discountOne = 0;
    }
    // Discount 2
    // finding the 2 digits of the birthday
    birthFirstDigit = dayOfBirth/10; // will find first digit
    birthSecondDigit = dayOfBirth % 10; // will find second
    // adding to birthday digits and seeing if the cost is a multiple of it
    if(((int)totalCost)%(birthFirstDigit + birthSecondDigit)== 0){ // same logic as discount one with mod
        discountTwo = totalCost * 0.05;
        printf("You get an additional 5%% discount because the total cost after discount1 was a multiple of the sum of digits in your day of birth :)\n");
    }
    else{// not multiple, no discount :()
            printf("Sorry - you missed out on the additional 5%% discount becasue the total cost after discount1 was not a multiple of the sum of digits in your day of birth\n");
            discountTwo = 0;
        }
    // end of task 6
    // reusing var totalcost
    // recalculating total cost, by applying discounts
    totalCost = totalCost - discountOne - discountTwo;
    printf("\nTotal cost after discounts 1 and 2: $ %.2f", totalCost);
    // TASK 7
    // Finding tax of the total cost, using new var totalTaxCost for this
    totalTaxCost = (totalCost * 0.13) + totalCost;
    printf("\n\nFinally, your total cost  after taxes: %.2f", totalTaxCost);
    // end of task 7

    return 0;
}
// end of code :)