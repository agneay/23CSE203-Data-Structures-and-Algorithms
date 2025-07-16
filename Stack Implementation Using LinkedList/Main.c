#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new Node
struct Node* createNewNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation Failed!");
        exit(1); // Stop program if memory allocation Fails
    }
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Function to push a value to the stack
void push(struct Node** top, int x) {
    struct Node* newNode = createNewNode(x);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d", x);

}

// Function to check is Stack is Empty
void isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to pop a value from the stack
int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow!\nCannot Pop\n");
        return -1;
    }

    struct Node* temp = *top;
    int popedValue = temp->data;
    *top = temp->next;
    free(temp);
    printf("Poped Value %d", popedValue);
    return popedValue;
}

// Function to peek at the top of the stack
int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty! Cannot peek.\n");
        return -1;
    }
    return top->data;
}

// Function to display Stack elements
void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is Empty!");
        return;
    }
    printf("Stack Elements: ");
    struct Node* current = top;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to demonstrate memory efficiency
void memoryEfficiency(int nodesCreated) {
    printf("Approximate Memory Used: %d bytes (for %d nodes)\n", (int)(nodesCreated * sizeof(struct Node)), nodesCreated);
}

int main() {
    struct Node* top = NULL;
    int nodeCount = 0;

    // Stack operations
    push(&top, 10); nodeCount++;
    push(&top, 20); nodeCount++;
    push(&top, 30); nodeCount++;

    display(top);
    printf("Top element: %d\n", peek(top));

    pop(&top); nodeCount--;
    pop(&top); nodeCount--;

    display(top);
    printf("Top element after pops: %d\n", peek(top));

    // Demonstrate memory usage
    memoryEfficiencyDemo(nodeCount);

    // Free remaining nodes (good practice)
    while (!isEmpty(top)) {
        pop(&top);
        nodeCount--;
    }
    return SUCCESS;
}