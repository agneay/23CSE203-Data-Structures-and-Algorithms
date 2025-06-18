// A program to reverse a integer
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("This program reverses an integer.\n");
    printf("Done by CH.SC.U4CSE24102\n");

    int number, reversedNumber = 0, remainder;

    // Prompt user for input
    printf("Enter an integer: ");
    scanf("%d", &number);

    // Reverse the integer
    while (number != 0) {
        remainder = number % 10; // Get the last digit
        reversedNumber = reversedNumber * 10 + remainder; // Build the reversed number
        number /= 10; // Remove the last digit from the original number
    }

    // Output the result
    printf("Reversed Number: %d\n", reversedNumber);
    
    return 0; // Exit program successfully
}
