#include <iostream>
using namespace std;

bool isSafeValue(int mat[][9], int i, int j, int no, int n) {
    // check col and row
    for (int k = 0; k < n; k++) {
        if (mat[k][j] == no || mat[i][k] == no) {
            return false;
        }
    }

    // check in the sub-grid
    int si = (i/3) * 3;
    int sj = (j/3) * 3;
    for (int temp_i = si; temp_i < si + 3; temp_i++) {
        for (int temp_j = sj; temp_j < sj + 3; temp_j++) {
            if (mat[temp_i][temp_j] == no) {
                return false;
            }
        }
    }

    return true;
}

void showMat(int mat[][9], int n) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool solveSudoku(int mat[][9], int i, int j, int n) {
    // base case
    if (i == n) {
        showMat(mat, n);
        return true;
    }

    // other base case
    if (j == n) {
        return solveSudoku(mat, i+1, 0, n);
    }

    // if already filled then skip
    if (mat[i][j] != 0) {
        return solveSudoku(mat, i, j+1, n);
    }

    // actual work
    for (int no = 1; no <= 9; no++) {
        if (isSafeValue(mat, i, j, no, n)) {
            mat[i][j] = no;
            bool success = solveSudoku(mat, i, j+1, n);
            if (success) {
                return true;
            }
        }
    }

    mat[i][j] = 0;
    return false;
}


int main(){
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


        if(!solveSudoku(mat,0,0,n)){
        	cout<<"No solution exists!";
        }


}
