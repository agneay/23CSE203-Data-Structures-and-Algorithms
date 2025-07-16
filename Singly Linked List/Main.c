#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

struct Node {
    int val;
    struct Node* next;
};

// Function to create a new Node
struct Node* createNewNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

// Function to dispaly the list
void display(struct Node* head) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("\n");
}

void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNewNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNewNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Insert a node at a given Index(1-based)
void insertAtPos(struct Node** head, int value, int pos) {
    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(head, value);
        return;
    }

    struct Node* newNode = createNode(value);
    struct Node* temp = *head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete from beginning
void deleteFromBeginning(struct Node** head) {
    if (!head) printf("The list is empty, nothing to delete");

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);

}

// Function to delete from the end
void delteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty\n So nothing to delete!");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
}

// Delete At a given position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Deleted: %d\n", toDelete->val);
    free(toDelete);
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    display(head);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    display(head);

    insertAtPosition(&head, 25, 3);
    display(head);

    deleteFromBeginning(&head);
    display(head);

    deleteFromEnd(&head);
    display(head);

    deleteAtPosition(&head, 2);
    display(head);

    return SUCCESS;
}