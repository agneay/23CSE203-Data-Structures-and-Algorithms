#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

// Node structure for LinkedList
struct Node {
    int val;
    struct Node* next;
};

// Queue Structure with front and rear pointers
struct Queue {
    struct Node* front;
    struct Node* rear;
};
// Function to initialize the Queue
void initQueue(struct Queue* Q) {
    Q->rear = Q->front = NULL;
}

// Function to check if Queue is Empty
int isEmpty(struct Queue* Q) {
    return (Q->front == NULL);
}

// Function to enqueue an element (insert)
void enqueue(struct Queue* Q, int value) {
    if (isFull(Q)) {
        printf("The Queue is Full\nCannot Enqueue\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    if (!newNode) {
        printf("Memory allocation Failed");
        exit(1);// exit program if memory allocation failed
    }
    newNode->next = NULL;
    newNode->val = value;
    if (Q->rear == NULL) {
        Q->front = Q->rear = newNode;
    }
    else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
    printf("Enqueued  Value: %d", value);
}

// Function to Dequeue an element
void dequeue(struct Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue Underflow\nCannot Dequeue");
        return;
    }
    struct Node* tmp = Q->front;
    int temp = Q->front->val;
    Q->front = Q->front->next;
    if (Q->front == NULL)Q->rear = NULL;
    free(tmp);
    printf("Dequeued Value: %d", temp);
    return temp;
}

// Function to get the front element
int getFront(struct Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue Underflow\nCannot get Front");
        return -1;
    }
    return Q->front->val;
}

// Function to get the rear element
int getRear(struct Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue Underflow\nCannot get Front");
        return -1;
    }
    return Q->rear->val;
}

// Function to display the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    struct Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    printf("Front element: %d\n", getFront(&q));
    printf("Rear element: %d\n", getRear(&q));

    dequeue(&q);
    display(&q);

    enqueue(&q, 40);
    display(&q);

    // Clean up memory (important in real applications)
    while (!isEmpty(&q)) {
        dequeue(&q);
    }
    return SUCCESS;
}