#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, tm;
        cin >> n;

        vector<int> arrivals;
        vector<int> departures;
        vector<int> delays;

        departures.push_back(0);
        arrivals.push_back(0);
        delays.push_back(0);

        for (int i = 0; i < n; i++) {
            cin >> a;
            cin >> b;
            arrivals.push_back(a);
            departures.push_back(b);
        }
        for (int i = 0; i < n; i++) {
            cin >> tm;
            delays.push_back(tm);  
        }

        int x = 0;
        int y = 0;
        for (int i = 1; i < n+1; i++) {
            int duration = arrivals[i] - departures[i-1] + delays[i];
            x = y + duration;
            y = max(x + (int)ceil(((double)departures[i] - arrivals[i]) / 2.0),
                    departures[i]);
        }        
        cout << x << endl;
    }
}