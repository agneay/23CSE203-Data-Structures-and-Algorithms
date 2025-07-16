#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

#define MAX 100 // Defining the Max capacity of the Queue

// Queue Structure
struct Queue {
    int items[MAX];
    int rear;
    int front;
};

// Function to intialise the Queue
void init(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if queue is Full
int isFull(struct Queue* Q) {
    return Q->rear == MAX - 1;
}

// Function to check if queue is empty
int isEmpty(struct Queue* Q) {
    return Q->front == -1 || Q->front > Q->rear;
}

// Function to enqueue an element
void enqueue(struct Queue* Q, int x) {
    if (isFull(Q)) {
        printf("Queue Overflow\n Cannot EnQueue");return;
    }

    if (Q->front == -1)Q->front = 0;
    Q->rear++;
    Q->items[Q->rear] = x;
    printf("Enqueued Value: %d", x);
}

// Function to dequeue an element
int dequeue(struct Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue Underflow\nCannot DeQueue");
        return -1;
    }
    int temp = Q->items[Q->front];
    Q->front++;
    // reset Queue if all elements are deleted
    if (Q->front > Q->rear) {
        Q->rear = -1;
        Q->front = -1;
    }
    printf("Dequeued Value %d", temp);
    return temp;
}

// get Front
int getFront(struct Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue is Empty! No front Elements!");
        return -1;
    }
    return Q->items[Q->front];
}

// get rear
int getRear(struct Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue Empty! No rear Element!");
        return -1;
    }
    return Q->items[Q->rear];

}

// function to display Queue
void display(struct Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = Q->front; i <= Q->rear; i++) {
        printf("%d ", Q->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    init(&q);

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

    printf("Front element: %d\n", getFront(&q));
    printf("Rear element: %d\n", getRear(&q));
    return SUCCESS;
}