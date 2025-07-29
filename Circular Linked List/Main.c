#include <stdio.h>
#include <stdlib.h>

// Program Written By Agneay B Nair
// Roll No: CH.SC.U4CSE24102

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new Node
struct Node* createNewNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display Circular Linked List
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Insert at end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNewNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // circular link
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

// Insert at beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNewNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}

// Delete a node with a given key
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head, * prev = NULL;

    // If head node contains key
    if (temp->data == key) {
        if (temp->next == *head) {
            // Only one node
            free(temp);
            *head = NULL;
            return;
        }
        // Find last node
        struct Node* last = *head;
        while (last->next != *head)
            last = last->next;
        last->next = temp->next;
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the node to delete
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != *head && temp->data != key);

    if (temp->data == key) {
        prev->next = temp->next;
        free(temp);
    }
    else {
        printf("Node with value %d not found.\n", key);
    }
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);

    display(head);

    deleteNode(&head, 10);
    display(head);

    deleteNode(&head, 5);
    display(head);

    deleteNode(&head, 30);
    display(head);

    deleteNode(&head, 20);
    display(head);

    return 0;
}
