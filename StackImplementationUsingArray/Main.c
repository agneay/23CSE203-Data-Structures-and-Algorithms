#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100 // To define the MAX size of stack
#define FAILURE -1
#define SUCCESS 0

// Stack structure
struct stack
{
    int items[MAX];
    int top;
};

// Function to initialize stack
void init(struct stack* s)
{
    s->top = -1;
}

// Function to check is stack is full
bool isFull(struct stack* s)
{
    return (s->top == MAX - 1);
}

//Function to check if stack is empty
bool isEmpty(struct stack* s) {
    return (s->top == -1);
}

// Function to POP elements
int pop(struct stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow \n Cannot pop\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Function to push items into stack
void push(struct stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! \n Cannot Push\n");
    }
    s->items[++(s->top)] = value;
    printf("Pushed values: %d\n", value);
}

// Function to peek at the top
int peek(struct stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! \n Cannot Peek\n");
        return -1;
    }
    return s->items[s->top];
}

int main()
{
    struct stack s;
    init(&s);

    push(&s, 100);
    push(&s, 100);
    push(&s, 300);

    printf("The top of the stack is %d", peek(&s));

    pop(&s);
    pop(&s);

    printf("The top of the stack after pop is %d", peek(&s));

    pop(&s);
    pop(&s);

    return SUCCESS;
}
