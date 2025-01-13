#include "givenA2.h"

#include <stdio.h>
#include <string.h>

#define MAX 16

void readIPAddress (char ipAddress []){
    // var for storing the octets:
    int octetOne = 300;
    int octetTwo = 300;
    int octetThree = 300;
    int octetFour = 300;
    // var to store octets when breaking them up:
    int one[3];
    int two[3];
    int three[3];
    int four[3];
    //indexs for each octet array
    int oneIndex = 0;
    int twoIndex = 0;
    int threeIndex = 0;
    int fourIndex = 0;
    //
    int pos = 0;

      // while loop for entering in the numbers and assiging it to the vars
    while(octetOne > 127 || octetOne < 0 ){
        printf("Octet#1 - Enter a number - must be between 0 and 127: ");
        scanf("%d",&octetOne);
    }
    while(octetTwo > 255 || octetTwo < 0 ){
        printf("Octet#2 - Enter a number - must be between 0 and 255: ");
        scanf("%d",&octetTwo);
    }
    while(octetThree > 255 || octetThree < 0 ){
        printf("Octet#3 - Enter a number - must be between 0 and 255: ");
        scanf("%d",&octetThree);
    }
    while(octetFour > 255 || octetFour < 0 ){
        printf("Octet#4 - Enter a number - must be between 0 and 255: ");
        scanf("%d",&octetFour);
    }

    // if the octets are = to 0:
    if (octetOne == 0){
        one[oneIndex++] = '0';
    }
    if (octetTwo == 0){
        two[twoIndex++] = '0';
    }
    if (octetThree == 0){
        three[threeIndex++] = '0';
    }
    if (octetFour == 0){
        four[fourIndex++] = '0';
    }

    // spliting each octet into ints and adding to seprate array
    while(octetOne > 0){
        one[oneIndex++] = (octetOne % 10) + '0';
        octetOne = octetOne/10;
    }
    while(octetTwo > 0){
        two[twoIndex++] = (octetTwo % 10) + '0';
        octetTwo = octetTwo/10;
    }
    while(octetThree > 0){
        three[threeIndex++] =  (octetThree % 10) + '0';
        octetThree = octetThree/10;
    }
    while(octetFour > 0){
        four[fourIndex++] = (octetFour % 10) + '0';
        octetFour = octetFour/10;
    }
        //adding all octets to the ipAddress array, and seperating them with>

    for (int i = oneIndex -1; i >= 0; i--){
        ipAddress[pos] = one[i];
        pos++;
    }
    ipAddress[pos] = '.';
    pos++;
    for (int i = twoIndex -1; i >= 0; i--){
        ipAddress[pos] = two[i];
        pos++;
    }
    ipAddress[pos] = '.';
    pos++;
    for (int i = threeIndex -1; i >= 0; i--){
        ipAddress[pos] = three[i];
        pos++;
    }
    ipAddress[pos] = '.';
    pos++;
    for (int i = fourIndex -1; i >= 0; i--){
        ipAddress[pos] = four[i];
        pos++;
    }
    // ending the array
    ipAddress[pos] = '\0';

}

// Task 2
long int convertIPToLongNumber ( char ipAddress [], int lengthIPAddr, int * numDigits){
// all var for task 2
    // var for each octets binary
    int octetBinary1 [8];
    int octetBinary2 [8];
    int octetBinary3 [8];
    int octetBinary4 [8];
    int octet1 = 0;
    int octet2 = 0;
    int octet3 = 0;
    int octet4 = 0;
    int numberOctet = 0;
    int i = 0;
    int binaryAllOctets[32];

    // seperating the char ipAddress into each octet and making it into 
    while (ipAddress[i] != '\0'){
        if(ipAddress[i] == '.'){
            // everytime '.' is found the octet number increases
            numberOctet++;
        }
        else{

            if (numberOctet == 0){
                octet1 = octet1 * 10 + (ipAddress[i] - '0');
            }
            else if (numberOctet == 1) {
                octet2 = octet2 * 10 + (ipAddress[i] - '0');
            }
            else if (numberOctet == 2) {
                octet3 = octet3 * 10 + (ipAddress[i] - '0');
            }
            else if (numberOctet == 3) {
                octet4 = octet4 * 10 + (ipAddress[i] - '0');
            }

        }
        i++;
    }

    // use convertToBinary to convert to binary for EACH octet
    convertToBinary (octet1, octetBinary1);// convert to binary(8bit)
    convertToBinary (octet2, octetBinary2);
    convertToBinary (octet3, octetBinary3);
    convertToBinary (octet4, octetBinary4);
    // calling function to combine the octets
    combineAllOctets(octetBinary1, 0, binaryAllOctets);
    combineAllOctets(octetBinary2, 8, binaryAllOctets);
    combineAllOctets(octetBinary3, 16, binaryAllOctets);
    combineAllOctets(octetBinary4, 24, binaryAllOctets);

    // finding long int of the decimal number
    long int numDecimal = convertBinaryToDecimal (binaryAllOctets);
    printf("ipDecimal = %ld \n", numDecimal);
    int task2numDigits = countDig(numDecimal);

    return task2numDigits;
    }

// Task 3
char classifyIPAddress (char ipAddress []){
    // all var for task 3
    int pos[2];
    int j = 0;
    int index = 0;
    char secondOctet[3];
    int intSecondOctet[3];
    int intOctet = 0;
    //
    for(int i = 0; i < 16; i++){
        if (ipAddress[i] == '.'){
            pos[j] = i;
            j++;
            if (j == 2){
                break;
            }
        }
    }
    pos[j] = '\0';

    // adding numbers in between to an char array

    for(int i = pos[0] + 1; i < pos[1]; i++){
        secondOctet[index] = ipAddress[i];
        index++;
    }
    secondOctet[index] = '\0';

    //changing char array to an int array
    // turning the array into an int
    for (int k = 0; k < index; k++){
        intSecondOctet[k] = secondOctet[k] - '0';

    }

    for (int m = 0; m < index; m++) {
        intOctet = intOctet * 10 + intSecondOctet[m];
    }
    // finding the class of the second octet
    if (intOctet <= 127){
        return 'A';
    }
    if (intOctet >= 128 && intOctet <= 191){
        return 'B';
    }
    if (intOctet >= 192 && intOctet <= 223){
        return 'C';
    }
    if (intOctet >= 224 && intOctet <= 239){
        return 'D';
    }
    if (intOctet >= 240 && intOctet <= 255){
        return 'E';
    }
    else{
        return 'F';

    }

}


// helper functions

void convertToBinary (int octet, int octetBinary [8]){
    //converts an octet into an binary
    for (int i = 7; i >= 0; i--) {
        octetBinary[i] = octet % 2;
        octet = octet/2;
    }

}

int countDig(int num){
    int counter = 0;
    // if num is 0 then number of digits is one
    if (num == 0){
        return 1;
    }
    // finding number of digits
    while (num != 0){
        num = num / 10;
        counter++;
    }
    return counter;
}

void combineAllOctets (int octetBinary[8], int pos,int binaryAllOctets [32]){
    // combining all octets
    for (int i = 0; i < 8; i++){
        binaryAllOctets[pos + i] = octetBinary[i];
    }

}

long int convertBinaryToDecimal (int binaryAllOctets [32]){
    // converting the binary numbers to 32 bit
    long numDecimal = 0;
    for (int i = 0; i < 32; i++){
        numDecimal = numDecimal * 2 + binaryAllOctets[i];
    } 

    return numDecimal;
}