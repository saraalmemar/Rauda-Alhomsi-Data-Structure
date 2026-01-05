#include <stdio.h>

#define MAX 100

int tree[MAX];
int n;


void preorder(int i) {
    if (i >= n) return;
    printf("%d ", tree[i]);
    preorder(2*i + 1);
    preorder(2*i + 2);
}

void inorder(int i) {
    if (i >= n) return;
    inorder(2*i + 1);
    printf("%d ", tree[i]);
    inorder(2*i + 2);
}

void postorder(int i) {
    if (i >= n) return;
    postorder(2*i + 1);
    postorder(2*i + 2);
    printf("%d ", tree[i]);
}

int main() {
    int i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements of tree in array form:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
    }

    printf("\nPreorder: ");
    preorder(0);

    printf("\nInorder: ");
    inorder(0);

    printf("\nPostorder: ");
    postorder(0);

    printf("\n");
    return 0;
}
