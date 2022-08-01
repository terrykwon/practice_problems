#include <iostream>
#include <list>
using namespace std;


// TODO: unsolved

void test_case(int N, int Q) {
    list<int> result;
    int median;

    cout << 0 << 1 << 2 << endl;
    cin >> median;

    if (median == 0) {
        result.push_back(1);
        result.push_back(0);
        result.push_back(2);
    } else if (median == 1) {
        result.push_back(0);
        result.push_back(1);
        result.push_back(2);
    } else { // median == 2
        result.push_back(0);
        result.push_back(2);
        result.push_back(1);
    }

    for (int i = 1; i < N-2; i++) {
        cout << i << i+1 << i+2 << endl;
        cin >> median;

        // i, i+1 are already in list
        // all we have to do is insert i+2 where appropriate
        int i_index, ip1_index;
        int current_index = 0;
        list<int>::iterator iter = result.begin();
        while (iter != result.end()) {
            if (*iter == i) {
                i_index = current_index;
            } else if (*iter == i+1) {
                ip1_index = current_index;
            } 
            iter++;
            current_index++;
        }

        if (median == i) {
            // can be i+1, i, i+2 OR i+2, i, i+1
            if (i_index < ip1_index) {
                result.insert(advance(result, 2), i+2);
            } else {

            }
        } else if (median == i+1) {
            // can be i, i+1, i+2 OR i+2, i+1, i 

        } else {

        }
    }
}

int main() {
    int T, N, Q;
    cin >> T >> N >> Q;
    for (int t = 1; t <= T; t++) {
        test_case(N, Q);
    }
}