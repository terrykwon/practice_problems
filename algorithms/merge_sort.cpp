#include <iostream>
#include <vector>
#include <algorithm>  // generate
using namespace std;


/**
 * Merging two sorted lists *in-place* is non-trivial.
 * See https://stackoverflow.com/questions/2571049/how-to-sort-in-place-using-the-merge-sort-algorithm
 * 
 */
vector<int> merge(vector<int>& left, vector<int>& right) {
    int l = 0;
    int r = 0;
    int i = 0;  // i = l + r
    vector<int> result(left.size() + right.size());

    while (l < left.size() && r < right.size()) {
        if (left[l] < right[r]) {
            result[i] = left[l];
            l++;
        } else {
            result[i] = right[r];
            r++;
        }
        i++;
    }

    while (l < left.size()) {
        result[i] = left[l];
        l++;
        i++;
    }

    while (r < right.size()) {
        result[i] = right[r];
        r++;
        i++;
    }

    return result;
}

/**
 * Returns the sorted vector.
 */
vector<int> merge_sort(vector<int>& v) {
    if (v.size() <= 1) {
        return v;
    }
    
    int m = v.size() / 2;
    vector<int> left(v.begin(), v.begin()+m);
    vector<int> right(v.begin()+m, v.end());
    
    left = merge_sort(left);
    right = merge_sort(right);

    vector<int> merged = merge(left, right);

    return merged;
}

int main() {
    vector<int> v = {3,9,5,66,2,3,6,6,13,2,1,2,3,5}; 
    vector<int> r = merge_sort(v);

    for (auto e : r) {
        cout << e << " ";
    }
    cout << endl;
}