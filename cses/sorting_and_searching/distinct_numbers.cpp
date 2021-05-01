#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int prev = arr[0];
    int count = 1;
    for (int j = 0; j < n; j++) {
        if (arr[j] != prev) {
            prev = arr[j];
            count += 1; 
        }
    }
    cout << count << endl;
}