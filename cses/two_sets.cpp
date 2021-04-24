#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;    

    if (n % 4 == 0) {
        cout << "YES" << endl;
        cout << n/2 << endl;
        for (int i = 1; i <= n/4; i++) {
            cout << i << " " << n-i+1 << " "; 
        }
        cout << endl;
        cout << n/2 << endl;
        for (int j = n/4 + 1; j <= n/2; j++) {
            cout << j << " " << n-j+1 << " ";
        }
    } else if (n % 4 == 3) {
        cout << "YES" << endl;
        cout << (n+1)/2 - 1 << endl;
        for (int i = 1; i <= n/4; i++) {
            cout << i << " " << n-i << " ";
        }
        cout << n << endl;
        cout << (n+1)/2 << endl;
        for (int j = (n+1)/4; j < (n+1)/2; j++) {
            cout << j << " " << n-j << " ";
        }
    } else {
        cout << "NO" << endl;
    }
    cout << endl;
}