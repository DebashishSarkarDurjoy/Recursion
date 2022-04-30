#include <iostream>
using namespace std;

bool isSafe(int mat[][9], int i, int j, int no) {
    // check all rows and colums simultaneously
    for (int k = 0; k < 9; k++) {
        if (mat[i][k] == no || mat[k][j] == no) {
            return false;
        }
    }

    // check in subgrid
    int sx = (i/3) * 3;
    int sy = (j/3) * 3;
    for (int x = sx; x < sx + 3; x++) {
        for (int y = sy; y < sy + 3; y++) {
            if (mat[x][y] == no) {
                return false;
            }
        }
    }

    return true;
}

void displayMatrix(int mat[][9], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool sudokuSolver(int mat[][9], int i, int j, int n) {
    // base case
    if (i == n) {
        displayMatrix(mat, n);
        return true;
    }

    // recursive case
    if (j == n) {
        return sudokuSolver(mat, i+1, 0, n);
    }

    if (mat[i][j] != 0) {
        return sudokuSolver(mat, i, j+1, n);
    }

    for (int no = 1; no <= n; no++) {
        if (isSafe(mat, i, j, no)) {
            mat[i][j] = no;
            bool isSolved = sudokuSolver(mat, i, j+1, n);
            if (isSolved) return true;
        }
    }

    mat[i][j] = 0;
    return false;
}

int main(void) {
    int n = 9;
	int mat[9][9] =
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};


        if(!sudokuSolver(mat,0,0,n)){
        	cout<<"No solution exists!";
        }


    return 0;
}
