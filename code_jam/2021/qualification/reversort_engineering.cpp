#include <iostream>
#include <algorithm>
using namespace std;


void fill(int* placements, int* L, int i, int N, int C) {
    if (C <= N-2 || C >= (N*N + N)/2) {
        cout << "IMPOSSIBLE" << endl;
        return;
    } else if (C == N-1) {  // base case; all we need to do is fill the rest
                            // in order
        for (int j = 0; j < N; j++) {
            L[i+j] = i+j+1;
            placements[i+j] = 1;
        }

        int ans[i+N];
        for (int k = 0; k < i+N; k++) {
            ans[k] = k+1;
        }

        // really naive... there must be a better solution
        for (int l = i+N-1; l >= 0; l--) {
            reverse(ans+l, ans+l+placements[l]);
        }

        for (int l = 0; l < i+N; l++) {  // print answer
            cout << ans[l] << " ";
        }
        cout << endl;
        return;
    }

    int placement = min(N, C-N+2);

    L[i+placement] = i+1;
    reverse(L+i, L+i+placement+1);

    placements[i] = placement;

    fill(placements, L, i+1, N-1, C-placement);
}

void test_case(int t) {
    int N, C;
    cin >> N >> C;
    int L[N];
    int placements[N];

    cout << "Case #" << t << ": ";
    fill(placements, L, 0, N, C);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        test_case(t);
    }
}