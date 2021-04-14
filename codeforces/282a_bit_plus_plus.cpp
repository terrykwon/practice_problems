#include <iostream>
using namespace std;

int main() {
    int x = 0;
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s[1] == '+') x++; 
        else x--;
    }
    cout << x << endl;
}