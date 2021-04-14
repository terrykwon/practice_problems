#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (char& c: s) {
        switch(c) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'Y':
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'y':
                continue;
            default:
                cout << ".";
                if (isupper(c)) {
                    cout << (char)tolower(c);
                } else {
                    cout << c;
                }
        }
    }

    cout << endl;
}