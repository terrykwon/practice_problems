#include <iostream>
#include <vector>
using namespace std;


/**
 * Keep track of the number of inversions.
 */ 
const int MAX_N = 20005;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n+2);  // actual array, 1-indexed, default value = 0
    vector<int> pos(n+2);  // position array
    pos[n+1] = MAX_N;  // buffer in positions 0 and N+1
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        arr[i] = x; 
        pos[x] = i;
    }

    int inversions = 0;
    for (int i = 1 ; i <= n; i++) {
        if (pos[i-1] > pos[i]) {
            inversions++;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        int x = arr[a];
        int y = arr[b];

        if (x > y) {
            swap(x, y);
        }
        
        if (y - x == 1) {  // x and y are adjacent, so only consider 3 pairs
            // previously no inversion but now there is one
            inversions += 
                (pos[x] > pos[x-1] && pos[y] < pos[x-1]) + 
                (pos[y+1] > pos[y] && pos[y+1] < pos[x]) +
                (pos[y] > pos[x]);

            // previously an inversion but now there isn't
            inversions -= 
                (pos[x] < pos[x-1] && pos[y] > pos[x-1]) +
                (pos[y+1] < pos[y] && pos[y+1] > pos[x]) +
                (pos[y] < pos[x]);
        } else {
            // previously no inversion but now there is one
            inversions += 
                (pos[x] > pos[x-1] && pos[y] < pos[x-1]) + 
                (pos[x+1] > pos[x] && pos[x+1] < pos[y]) + 
                (pos[y+1] > pos[y] && pos[y+1] < pos[x]) +
                (pos[y] > pos[y-1] && pos[x] < pos[y-1]);

            // previously an inversion but now there isn't
            inversions -= 
                (pos[x] < pos[x-1] && pos[y] > pos[x-1]) +
                (pos[x+1] < pos[x] && pos[x+1] > pos[y]) + 
                (pos[y+1] < pos[y] && pos[y+1] > pos[x]) +
                (pos[y] < pos[y-1] && pos[x] > pos[y-1]);
        }

        swap(arr[a], arr[b]);
        swap(pos[x], pos[y]);

        cout << inversions+1 << endl;
    }
}