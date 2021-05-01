#include <iostream>
using namespace std;


const int N = 8;
char board[N][N];
bool row_taken[N];
bool col_taken[N];
bool diag1_taken[2*N-1];
bool diag2_taken[2*N-1];
int successes = 0;  // global "count" is a taken name

bool place(int r, int c) {
    if (board[r][c] != '*' && 
            !row_taken[r] && 
            !col_taken[c] &&
            !diag1_taken[r+c] &&
            !diag2_taken[N-r+c-1]) {
        board[r][c] = 'Q';
        row_taken[r] = true;
        col_taken[c] = true;
        diag1_taken[r+c] = true;
        diag2_taken[N-r+c-1] = true;

        return true;
    } else {
        return false;
    }
}

// searches over rows
void search(int row) {
    if (row == N) {
        successes += 1;
        return;
    }

    for (int col = 0; col < N; col++) {
        if (place(row, col)) {
            search(row+1);

            // backtrack
            board[row][col] = '.';
            row_taken[row] = false;
            col_taken[col] = false;
            diag1_taken[row+col] = false;
            diag2_taken[N-row+col-1] = false;
        } else {
            // queen can't be placed here; continue
        }
    }
}

/**
 * The n-queens problem.
 */
int main() {

    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            cin >> board[r][c];
        }
    }

    search(0);
    cout << successes << endl;
}