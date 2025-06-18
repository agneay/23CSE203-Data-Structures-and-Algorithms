// PROGRAM TO PRINT SUM OF VALUE IN ARRAY
// CH.SC.U4CSE24102
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("This program prints SUM OF VALUE IN ARRAY\n");
    printf("Done by CH.SC.U4CSE24102\n");

    int n;

    //prompt user for size of array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    //validate input
    if(n <= 0){
        printf("Please enter a positive integer greater than 0.\n");
        return 1; // exit program with an error code
    }
    int array[n]; // declare array of size n
    int sum = 0; // variable to hold the sum of array elements

    //prompt user to enter array elements
    printf("Enter %d elements of the array:\n", n);
    for(int i = 0; i < n; i++){
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
        sum += array[i]; // add each element to sum
    }
    printf("The sum of the array elements is: %d\n", sum);
    return 0; // Exit program successfully
}