#include <stdio.h>
#include <stdlib.h>

// Structure definition for a doubly linked list node
typedef struct list {
    int info;
    struct list *next;
    struct list *prev;
} node;

node *start = NULL; // Global pointer to track the beginning of the list

// Function prototypes
void insertfirst();
void insertspecificposition();
void deletenodefromspecificposition();
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
                insertfirst();
                break;
            case 2:
                insertspecificposition();
                break;
            case 3:
                deletenodefromspecificposition();
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
void insertfirst() {
    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL) {
        printf("\nMemory allocation failed.");
        return;
    }

    printf("\nEnter the data to insert: ");
    if (scanf("%d", &ptr->info) != 1) {
        printf("\nInvalid input! Please enter a number.");
        free(ptr);
        return;
    }

    ptr->prev = NULL;
    ptr->next = start;

    if (start != NULL)
        start->prev = ptr;

    start = ptr;
    printf("\nData inserted at the first position.");
}

// Function to insert at a specific position
void insertspecificposition() {
    int pos, count = 1;
    printf("\nEnter the position to insert at: ");
    if (scanf("%d", &pos) != 1 || pos < 1) {
        printf("\nInvalid input! Enter a positive integer.");
        return;
    }

    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL) {
        printf("\nMemory allocation failed.");
        return;
    }

    printf("\nEnter the data to insert: ");
    if (scanf("%d", &ptr->info) != 1) {
        printf("\nInvalid input! Please enter a number.");
        free(ptr);
        return;
    }

    if (pos == 1) {  // Insert at the beginning
        ptr->prev = NULL;
        ptr->next = start;
        if (start != NULL)
            start->prev = ptr;
        start = ptr;
        printf("\nData inserted at position %d.", pos);
        return;
    }

    node *temp = start;
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("\nPosition out of range.");
        free(ptr);
        return;
    }

    ptr->next = temp->next;
    ptr->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = ptr;
    temp->next = ptr;
    
    printf("\nData inserted at position %d.", pos);
}

// Function to delete a node from a specific position
void deletenodefromspecificposition() {
    int pos, count = 1;
    printf("\nEnter the position to delete from: ");
    if (scanf("%d", &pos) != 1 || pos < 1) {
        printf("\nInvalid input! Enter a positive integer.");
        return;
    }

    if (start == NULL) {
        printf("\nThe list is empty. No node to delete.");
        return;
    }

    node *temp = start;

    if (pos == 1) { // Delete first node
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        printf("\nDeleted node with value %d.", temp->info);
        free(temp);
        return;
    }

    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("\nPosition out of range.");
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("\nDeleted node with value %d.", temp->info);
    free(temp);
}

// Function to traverse and display the linked list
void traverse() {
    if (start == NULL) {
        printf("\nThe list is empty.");
        return;
    }

    node *temp = start;
    printf("\nThe data in the list:");
    while (temp != NULL) {
        printf(" %d", temp->info);
        temp = temp->next;
    }
    printf("\n"); // New line for better readability
}

// Function to search for an element in the linked list
void search() {
    int key, pos = 1, found = 0;
    printf("\nEnter the value to search: ");
    if (scanf("%d", &key) != 1) {
        printf("\nInvalid input! Please enter a number.");
        return;
    }

    node *temp = start;
    while (temp != NULL) {
        if (temp->info == key) {
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (found) {
        printf("\nElement %d found at position %d.", key, pos);
    } else {
        printf("\nElement %d not found in the list.", key);
    }
}