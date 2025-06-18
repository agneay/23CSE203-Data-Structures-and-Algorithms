#include <stdio.h>
#include <stdlib.h> 

// Function prototypes
void initializeArray(int arr[], int size);
void insertElement(int arr[], int *size, int element, int position);
void deleteElement(int arr[], int *size, int position);
int searchElement(int arr[], int size, int element);
void displayArray(int arr[], int size);

int main(){
    printf("This program performs basic array operations.\n"); 
    printf("Done by CH.SC.U4CSE24102\n");

    int arr[100], size = 0, choice, element, pos, result;

    initializeArray(arr, 100);

    while(1){
        // Display menu
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");       
        printf("3. Search for an element\n");
        printf("4. Display the array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);   

        switch(choice){
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert (0 to %d): ", size);
                scanf("%d", &pos);
                if(pos < 0 || pos > size){
                    printf("Invalid position!\n");
                } else {
                    insertElement(arr, &size, element, pos);
                    printf("Element inserted successfully.\n");
                }
                break;
            case 2:
                printf("Enter the position of the element to delete (0 to %d): ", size - 1);
                scanf("%d", &pos);
                if(pos < 0 || pos >= size){
                    printf("Invalid position!\n");
                } else {
                    deleteElement(arr, &size, pos);
                }
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                result = searchElement(arr, size, element);
                if(result != -1){
                    printf("Element found at index: %d\n", result);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 4:
                displayArray(arr, size);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Initialize array with 0 (optional)
void initializeArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

// Insert an element at a specified position
void insertElement(int arr[], int *size, int element, int pos) {
    if(*size >= 100) {
        printf("Array is full, cannot insert element.\n");
        return;
    }
    for(int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    (*size)++;
}

// Delete an element at a specified position
void deleteElement(int arr[], int *size, int position){
    for(int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element at position %d deleted.\n", position);
}

// Search for an element
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

// Display all elements in the array
void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
