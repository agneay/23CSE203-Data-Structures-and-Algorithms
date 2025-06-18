// To find the maximum number in an array of N natural numbers

#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("This program finds the maximum number in an array of N natural numbers.\n");
    printf("Done by CH.SC.U4CSE24102\n");

    int n;
    // Prompt user for size of array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Validate input
    if(n <= 0){
        printf("Please enter a positive integer greater than 0.\n");
        return 1; // Exit program with an error code
    }

    int array[n]; // Declare array of size n
    int max; // Variable to hold the maximum value

    // Prompt user to enter array elements
    printf("Enter %d elements of the array:\n", n);
    for(int i = 0; i < n; i++){
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
        if(i == 0 || array[i] > max) {
            max = array[i]; // Update max if current element is greater
        }
    }

    printf("The maximum value in the array is: %d\n", max);
    return 0; // Exit program successfully
}