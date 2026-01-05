#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node* head = NULL;

Node* createNode(int value) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = value;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void insertEnd(int value) {
    Node* n = createNode(value);

    if (head == NULL) {
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}
void deleteValue(int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    
    if (temp == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return;
    }

    
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    temp->prev->next = temp->next;

    free(temp);
}


void displayForward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void displayBackward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Doubly Linked List ---\n");
        printf("1) Insert (End)\n");
        printf("2) Delete (By Value)\n");
        printf("3) Display Forward\n");
        printf("4) Display Backward\n");
        printf("5) Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            insertEnd(value);
        }
        else if (choice == 2) {
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteValue(value);
        }
        else if (choice == 3) {
            displayForward();
        }
        else if (choice == 4) {
            displayBackward();
        }
        else if (choice == 5) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
