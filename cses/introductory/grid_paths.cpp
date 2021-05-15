#include <iostream>
#include <string>
using namespace std;

const int N = 7;
bool visited[N][N] = {};  // Initialized as 0
string directions;

int paths = 0;
long long dfs_calls = 0;


bool valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N && !visited[r][c];
}

// Prune
bool early_terminate(int r, int c) {
    // if (r == N-1 && c == 0 && pos < N*N-1) {
    //     return true;
    // }

    // If there are empty squares to the left and right but we cannot go
    // forward or back, then this search can be terminated.
    if (valid(r-1, c) && valid(r+1, c) && 
            !valid(r, c+1) && !valid(r, c-1)) {
        return true;
    } 
    if (valid(r, c-1) && valid(r, c+1) && 
            !valid(r-1, c) && !valid(r+1, c)) {
        return true;
    }
    return false;
}

void print_grid() {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cout << visited[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * Code efficiency here matters--TLE if unlucky.
 * 
 * Checking BEFORE calling the DFS function (as opposed to checking at the
 * start of DFS) is a bit faster? No idea...
 */
void dfs(int r, int c, int pos) {
    // print_grid();
    // if (!valid(r, c)) {
    //     return;
    // }

    // if (early_terminate(r, c, pos)) {
    //     return;
    // }

    if (r == N-1 && c == 0) {
        if (pos == N*N-1) {
            paths += 1;
        }
        return;
    }

    // if (pos == N*N-1) {
    //     if (r == N-1 && c == 0) {
    //         paths += 1;
    //         // cout << paths << endl;
    //     }
    //     return;
    // }

    // dfs_calls++;

    visited[r][c] = true;
    char d = directions[pos];

    if (d == 'U' || d == '?') {
        if (valid(r-1, c) && !early_terminate(r-1, c)) {
            dfs(r-1, c, pos+1);
        }
    }
    if (d == 'D' || d == '?') {
        if (valid(r+1, c) && !early_terminate(r+1, c)) {
            dfs(r+1, c, pos+1);
        }
    }
    if (d == 'L' || d == '?') {
        if (valid(r, c-1) && !early_terminate(r, c-1)) {
            dfs(r, c-1, pos+1);
        }
    }
    if (d == 'R' || d == '?') {
        if (valid(r, c+1) && !early_terminate(r, c+1)) {
            dfs(r, c+1, pos+1);
        }
    }
    visited[r][c] = false;
}


// ????????????????????????????????????????????????
// DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD
// ??????R??????U??????????????????????????LD????D?

int main() {
    cin >> directions;

    dfs(0, 0, 0);
    
    cout << paths << endl;
    // cout << dfs_calls << endl;
}