#include <iostream>
using namespace std;


/**
 * Count the number of components in a graph.
 */

char plan[1000][1000];  // as in "floor plan"
int n, m;

void dfs(int r, int c) {
    plan[r][c] = 'v';
    if (r >= 1 && plan[r-1][c] == '.') {
        dfs(r-1, c);
    }
    if (r <= n-2 && plan[r+1][c] == '.') {
        dfs(r+1, c);
    }
    if (c >= 1 && plan[r][c-1] == '.') {
        dfs(r, c-1);
    }
    if (c <= m-2 && plan[r][c+1] == '.') {
        dfs(r, c+1);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> plan[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (plan[i][j] == '.') {
                count += 1;
                dfs(i, j);
            }
        }
    }
    
    cout << count << endl;
}