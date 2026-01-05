#include <iostream>
using namespace std;

struct Triple {
    int row;
    int col;
    int val;
};

int main() {
    const int MAXR = 100, MAXC = 100, MAXNZ = 10000;
    int a[MAXR][MAXC];
    Triple sparse[MAXNZ];

    int r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of cols: ";
    cin >> c;

    cout << "Enter matrix elements (" << r << "x" << c << "):\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    
    int k = 0; // index for sparse[]
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].val = a[i][j];
                k++;
            }
        }
    }

    
    cout << "\nSparse Matrix (3-tuple form):\n";
    cout << "Row Col Val\n";
    cout << r << " " << c << " " << k << "\n";
    for (int i = 0; i < k; i++) {
        cout << sparse[i].row << " " << sparse[i].col << " " << sparse[i].val << "\n";
    }

    return 0;
}
