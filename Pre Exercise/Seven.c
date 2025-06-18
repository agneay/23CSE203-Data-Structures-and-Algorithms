#include <stdio.h>

#define MAX_SIZE 100

void insertElement(int arr[], int *size, int element, int position);
void deleteElement(int arr[], int *size, int position);
int searchElement(int arr[], int size, int element);
void displayArray(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position, result;

    while (1) {
        printf("\nArray Operations Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert (0 to %d): ", size);
                scanf("%d", &position);
                if (position >= 0 && position <= size) {
                    insertElement(arr, &size, element, position);
                } else {
                    printf("Invalid position!\n");
                }
                break;

            case 2:
                if (size == 0) {
                    printf("Array is empty! Nothing to delete.\n");
                    break;
                }
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                if (position >= 0 && position < size) {
                    deleteElement(arr, &size, position);
                } else {
                    printf("Invalid position!\n");
                }
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &element);
                result = searchElement(arr, size, element);
                if (result != -1) {
                    printf("Element %d found at position %d\n", element, result);
                } else {
                    printf("Element %d not found in the array\n", element);
                }
                break;

            case 4:
                displayArray(arr, size);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void insertElement(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Array is full! Cannot insert more elements.\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
    printf("Element %d inserted at position %d\n", element, position);
}

void deleteElement(int arr[], int *size, int position) {
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element at position %d deleted\n", position);
}

int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

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
