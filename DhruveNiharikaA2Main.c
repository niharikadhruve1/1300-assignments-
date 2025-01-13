#include <stdio.h>
#include <string.h>
#include "givenA2.h"

int main(){

    // all var for main
    char ipAddress [16] = "0.0.0.0";
    char task3;
    int numDigits = 0;
    int lengthIPAddr = 0;

    // task one
    printf("Testing Task 1 in main \n\n");
    readIPAddress(ipAddress); // call for task#1
    printf("IP Addr: ");
    // printing the ipaddress
    for(int i = 0; i < 16; i++)
    {
        printf("%c", ipAddress[i]);
    }
    printf("\n\nTask 1 ends \n\n");
    // task 2

    printf("Testing Task 2 in main\n\n");

    //find length of the ipAddress
    for (int i = 0; i < 16; i++){
        if (ipAddress[i] != '.' && ipAddress[i] != '\0'){
            lengthIPAddr += 1;
        }
    }
    // printing things for task 2
    long task2numDigits = convertIPToLongNumber(ipAddress, lengthIPAddr, &numDigits);
    printf("Number of digits = %ld\n",task2numDigits);
    printf("Task 2 ends\n");
    printf("\n");

    // task 3
    printf("Testing Task 3 in main \n\n");
    task3 = classifyIPAddress(ipAddress);
    // printing ip and class
    printf("Class for %s = %c \n", ipAddress, task3);

    printf("Task 3 ends \n ");

    return 0;
}