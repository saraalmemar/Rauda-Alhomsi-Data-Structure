#include <stdio.h>

int main() {
    int arr[100];
    int size = 0;
    int choice, pos, value, i;

    while (1) {
        printf("\n--- Array Operations ---\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display array\n");
        printf("4. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("Enter value: ");
            scanf("%d", &value);

            if (pos < 0 || pos > size) {
                printf("Invalid position\n");
            } else {
                for (i = size; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = value;
                size++;
                printf("Element inserted\n");
            }

        } else if (choice == 2) {
            printf("Enter position to delete: ");
            scanf("%d", &pos);

            if (pos < 0 || pos >= size) {
                printf("Invalid position\n");
            } else {
                for (i = pos; i < size - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                size--;
                printf("Element deleted\n");
            }

        } else if (choice == 3) {
            if (size == 0) {
                printf("Array is empty\n");
            } else {
                printf("Array elements: ");
                for (i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }

        } else if (choice == 4) {
            break;

        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
