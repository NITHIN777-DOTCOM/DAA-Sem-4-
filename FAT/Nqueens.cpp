#include <iostream>
using namespace std;

int n;
int board[20];   // board[i] = column of queen in row i

// check if safe
bool isSafe(int row, int col) {
    for(int i = 0; i < row; i++) {
        if(board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

// backtracking
void solve(int row) {
    if(row == n) {
        for(int i = 0; i < n; i++)
            cout << board[i] << " ";
        cout << endl;
        return;
    }

    for(int col = 0; col < n; col++) {
        if(isSafe(row, col)) {
            board[row] = col;   // place
            solve(row + 1);     // recurse
        }
    }
}

int main() {
    cin >> n;
    solve(0);
    return 0;
}