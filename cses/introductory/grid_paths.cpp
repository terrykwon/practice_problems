#include <iostream>
#include <string>
using namespace std;

const int N = 7;
bool grid[N][N] = {};  // Initialized as 0
string directions;

int paths = 0;


// TODO
bool early_terminate(int r, int c, int direction) {

}


bool movable(int r, int c, int direction) {
    if (direction == 'L') {
        return c >= 1 && !grid[r][c-1];
    } else if (direction == 'R') {
        return c <= N-2 && !grid[r][c+1]; 
    } else if (direction == 'U') {
        return r >= 1 && !grid[r-1][c];
    } else {  // direction == 'D'
        return r <= N-2 && !grid[r+1][c];
    }
}

void print_grid() {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


// Marking *current* position is easier than marking next!
void dfs(int r, int c, int pos) {
    if (pos == N*N - 1) {
        if (r == N-1 && c == 0) {  // arrived at bottom left
            paths += 1;
            cout << paths << endl;
        } 
        return;
    }

}

void search(int r, int c, int pos) {
    // print_grid();

    if (pos == N*N - 1) {
        if (r == N-1 && c == 0) {  // arrived at bottom left
            paths += 1;
            cout << paths << endl;
        } 
        return;
    }

    char direction = directions[pos];
        
    if (direction == 'D'|| direction == '?') {
        if (movable(r, c, 'D')) {
            grid[r+1][c] = true;
            search(r+1, c, pos+1);
            grid[r+1][c] = false;
        }
    } 
    if (direction == 'U' || direction == '?') {
        if (movable(r, c, 'U')) {
            grid[r-1][c] = true;
            search(r-1, c, pos+1);
            grid[r-1][c] = false;
        }
    }
    if (direction == 'L' || direction == '?') {
        if (movable(r, c, 'L')) {
            grid[r][c-1] = true;
            search(r, c-1, pos+1);
            grid[r][c-1] = false;
        }
    } 
    if (direction == 'R' || direction == '?') {
        if (movable(r, c, 'R')) {
            grid[r][c+1] = true;
            search(r, c+1, pos+1);
            grid[r][c+1] = false;
        }
    }
}


// ????????????????????????????????????????????????
// DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD
// ??????R??????U??????????????????????????LD????D?

int main() {
    cin >> directions;

    grid[0][0] = true;
    search(0, 0, 0);
    
    cout << paths << endl;
}