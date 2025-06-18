// To find the second largest element in an array

#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("This program finds the second largest element in an array of N natural numbers.\n");
    printf("Done by CH.SC.U4CSE24102\n");
    int n;
    // Prompt user for size of array
    printf("Enter the size of the array: ");
    scanf("%d", &n);   

    if(n<=0){
        printf("Please enter a positive integer greater than 0.\n");
        return 1; // Exit program with an error code
    }
    int array[n]; // Declare array of size n
    int max = 0, second_max = 0; // Variables to hold the maximum and second maximum values
    // Prompt user to enter array elements
    printf("Enter %d elements of the array:\n", n);
    for(int i = 0; i < n; i++){
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
        if(array[i] > max) {
            second_max = max; // Update second max before changing max
            max = array[i]; // Update max if current element is greater
        } else if(array[i] > second_max && array[i] < max) {
            second_max = array[i]; // Update second max if current element is less than max but greater than second max
        }
    }

    if(second_max == 0) {
        printf("There is no second largest element in the array.\n");
    } else {
        printf("The second largest element in the array is: %d\n", second_max);
    }

    return 0; // Exit program successfully
}