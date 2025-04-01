#include <stdio.h>
#include <stdlib.h>

// Structure definition for a singly linked list node
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL; // Global pointer to track the beginning of the list

// Function prototypes
void insertFirst();
void insertAtPosition();
void deleteFromPosition();
void traverse();
void search();

int main() {
    int choice;
    while (1) {
        printf("\n\nMENU:");
        printf("\n1. Insert at the beginning");
        printf("\n2. Insert at a specific position");
        printf("\n3. Delete a node from a specific position");
        printf("\n4. Traverse and display");
        printf("\n5. Search for an element");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                insertFirst();
                break;
            case 2:
                insertAtPosition();
                break;
            case 3:
                deleteFromPosition();
                break;
            case 4:
                traverse();
                break;
            case 5:
                search();
                break;
            case 6:
                printf("\nExiting the program.\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}

// Function to insert a node at the beginning
void insertFirst() {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("\nMemory allocation failed.");
        return;
    }

    printf("\nEnter the data to insert: ");
    if (scanf("%d", &newNode->data) != 1) {
        printf("\nInvalid input! Please enter a number.");
        free(newNode);
        return;
    }

    newNode->next = head;
    head = newNode;
    printf("\nData inserted at the first position.");
}

// Function to insert a node at a specific position
void insertAtPosition() {
    int pos, count = 1;
    printf("\nEnter the position to insert at: ");
    if (scanf("%d", &pos) != 1 || pos < 1) {
        printf("\nInvalid input! Enter a positive integer.");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("\nMemory allocation failed.");
        return;
    }

    printf("\nEnter the data to insert: ");
    if (scanf("%d", &newNode->data) != 1) {
        printf("\nInvalid input! Please enter a number.");
        free(newNode);
        return;
    }

    if (pos == 1) {  // Insert at the beginning
        newNode->next = head;
        head = newNode;
        printf("\nData inserted at position %d.", pos);
        return;
    }

    Node *temp = head;
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("\nPosition out of range.");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    
    printf("\nData inserted at position %d.", pos);
}

// Function to delete a node from a specific position
void deleteFromPosition() {
    int pos, count = 1;
    printf("\nEnter the position to delete from: ");
    if (scanf("%d", &pos) != 1 || pos < 1) {
        printf("\nInvalid input! Enter a positive integer.");
        return;
    }

    if (head == NULL) {
        printf("\nThe list is empty. No node to delete.");
        return;
    }

    Node *temp = head;

    if (pos == 1) { // Delete first node
        head = head->next;
        printf("\nDeleted node with value %d.", temp->data);
        free(temp);
        return;
    }

    Node *prev = NULL;
    while (temp != NULL && count < pos) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("\nPosition out of range.");
        return;
    }

    prev->next = temp->next;
    printf("\nDeleted node with value %d.", temp->data);
    free(temp);
}

// Function to traverse and display the linked list
void traverse() {
    if (head == NULL) {
        printf("\nThe list is empty.");
        return;
    }

    Node *temp = head;
    printf("\nThe data in the list:");
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
}

// Function to search for an element in the linked list
void search() {
    int key, pos = 1, found = 0;
    printf("\nEnter the value to search: ");
    if (scanf("%d", &key) != 1) {
        printf("\nInvalid input! Please enter a number.");
        return;
    }

    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("\nValue %d found at position %d.", key, pos);
            found = 1;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
        printf("\nValue %d not found in the list.", key);
}
