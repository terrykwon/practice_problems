#include <iostream>
#include <algorithm>  // lower_bound
#include <list>  // O(1) deletion
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    multiset<int> tickets;  // ordered, equivalent elements allowed

    for (int i = 0; i < n; i++) {
        int ticket_price;
        cin >> ticket_price; 
        tickets.insert(ticket_price);
    }   

    for (int j = 0; j < m; j++) {
        int budget;
        cin >> budget;

        // can use auto, but for pedagogical purposes
        // find first element greater than budget
        multiset<int>::iterator it = tickets.upper_bound(budget);

        if (it == tickets.begin()) {
            cout << -1 << endl;
        } else {
            it--;
            int previous = *it;
            cout << previous << endl;
            tickets.erase(it);
        }
    }

}