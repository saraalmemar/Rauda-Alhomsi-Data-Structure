#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Traversal
void traverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

// Insert after a given key
void insertAfter(int key, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;
    do {
        if (temp->data == key) {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Key not found\n");
}

// Delete a node
void deleteValue(int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head needs to be deleted
    if (head->data == value) {
        if (head->next == head) {
            free(head);
            head = NULL;
            return;
        }

        while (temp->next != head)
            temp = temp->next;

        temp->next = head->next;
        free(head);
        head = temp->next;
        return;
    }

    prev = head;
    temp = head->next;

    while (temp != head) {
        if (temp->data == value) {
            prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Value not found\n");
}

// Main
int main() {
    int choice, key, value;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insertAfter(key, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                break;

            case 3:
                traverse();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
