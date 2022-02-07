#include <iostream>

using namespace std;

void printBoard(int n, int board[][20]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool canPlace(int board[][20], int n, int i, int j) {
    //along the column
    for (int p = i; p >= 0; p--) {
        if (board[p][j] == 1) return false;
    }

    //along the left diagonal
    int p = i;
    int q = j;
    while (p >= 0 && q >= 0) {
        if (board[p][q] == 1) return false;
        p--;
        q--;
    }

    //along the right diagonal
    p = i;
    q = j;
    while (p >= 0 && q < n) {
        if (board[p][q] == 1) return false;
        p--;
        q++;
    }

    return true;
}

bool solveNQueen(int n, int board[][20], int i) {
    // base case
    if (i == n) {
        printBoard(n, board);
        return true;
    }

    // rec case
    for (int j = 0; j < n; j++) {
        if (canPlace(board, n, i, j)) {


            board[i][j] = 1;
            bool success = solveNQueen(n, board, i+1);
            if (success) {
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}

int main(void) {
    int board[20][20] = {0};
    int n;
    cin >> n;

    solveNQueen(n, board, 0);

    return 0;
}
