#include<iostream>
#include<iomanip>           // For setw(), see below
using namespace std;        // Fuck the "good practices"!

int main() {
    int matrix[100][100] = { 0 };
    int row = 0;
    int col = -1;
    char direction = 'R';
    int i = 1;

    unsigned n;
    cin >> n;

    while (i <= n*n) {
        switch (direction) {
        case 'U':
            row--;
            if (matrix[row][col] != 0) {
                row++;
                col--;
                direction = 'L';
            }
            break;
        case 'D':
            row++;
            if (row == n) {
                row--;
                col--;
                direction = 'U';
            }
            break;
        case 'L':
            col--;
            if (col == -1) {
                row++;
                col++;
                direction = 'R';
            }
            break;
        case 'R':
            col++;
            if (col == n || matrix[row][col] != 0) {
                row++;
                col--;
                direction = 'D';
            }
        }
        matrix[row][col] = i;
        i++;
    }

    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++) {
            cout << setw(5) << matrix[row][col] << ' ';     // setw() - for the alignment
        }                                                   // We won't use it a lot.
        cout << '\n';
    }
    return 0;
}