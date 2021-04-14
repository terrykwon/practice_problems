#include <iostream>
using namespace std;

int main() {
    unsigned long long n, m, a;
    cin >> n >> m >> a;

    cout << ((unsigned long long)ceil((double)n / (double)a) * 
            (unsigned long long)ceil((double)m / (double)a)) << endl;
}