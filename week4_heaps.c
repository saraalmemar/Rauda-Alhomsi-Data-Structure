#include <stdio.h>

#define MAX 100

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void maxHeapifyDown(int a[], int n, int i) {
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;

        if (left < n && a[left] > a[largest]) largest = left;
        if (right < n && a[right] > a[largest]) largest = right;

        if (largest != i) {
            swap(&a[i], &a[largest]);
            i = largest;
        } else break;
    }
}

void minHeapifyDown(int a[], int n, int i) {
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < n && a[left] < a[smallest]) smallest = left;
        if (right < n && a[right] < a[smallest]) smallest = right;

        if (smallest != i) {
            swap(&a[i], &a[smallest]);
            i = smallest;
        } else break;
    }
}

void buildMaxHeap(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        maxHeapifyDown(a, n, i);
    }
}

void buildMinHeap(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        minHeapifyDown(a, n, i);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n;
    int input[MAX], maxH[MAX], minH[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
        maxH[i] = input[i];
        minH[i] = input[i];
    }

    buildMaxHeap(maxH, n);
    buildMinHeap(minH, n);

    printf("\nMax Heap array representation:\n");
    printArray(maxH, n);

    printf("\nMin Heap array representation:\n");
    printArray(minH, n);

    return 0;
}
