#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

// Struct for DLL
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new Node
struct Node* creteNewNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert at the End
void insertAtEnd(int value, struct Node** head) {
    struct Node* newNode = creteNewNode(value);
    if (*head == NULL) {
        (*head) = newNode;
        return;
    }

    struct Node* current = *head;
    while (current != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}


// Forward traversal
void displayForward(struct Node* head) {
    printf("Forward: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Backward traversal
void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("Backward: List is empty\n");
        return;
    }

    // Go to last node
    while (head->next != NULL)
        head = head->next;

    printf("Backward: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");
}

// Insert at the beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
}

// Delete a node with a given value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;

    // Search for the node
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    // Adjust pointers
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;  // Deleting the head

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted node with value %d\n", key);
    free(temp);
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 1);

    displayForward(head);
    displayBackward(head);

    deleteNode(&head, 20);
    deleteNode(&head, 1);
    displayForward(head);
    displayBackward(head);
    return SUCCESS;
}