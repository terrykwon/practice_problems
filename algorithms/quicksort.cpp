#include <iostream>
#include <vector>
using namespace std;


/**
 * A variation of partition where [<x][=x][>x].
 * 
 * i holds the next position of the first partition, while j holds the next
 * position of the second partition. 
 */
pair<int, int> three_way_partition(vector<int> &a, int l, int r) {
    int pivot = a[r];
    int i = l;
    int j = l;
    int k = r;

    while (j <= k) {
        if (a[j] < pivot) {
            swap(a[i], a[j]);
            i++;
            j++;
        } else if (a[j] == pivot) {
            j++;
        } else {
            swap(a[j], a[k]);
            k--;
        }
    }

    // We don't need to swap pivot because it's already part of the algorithm.

    return {i-1, k+1};
}

/**
 * [l, r] inclusive.
 * 
 * At the end of each loop iteration, i is the first element greater than pivot.
 * j is the first element not looked at yet.
 * 
 * But this doesn't hold before the start of the first iteration! Is this why
 * CLRS starts i at l-1, and increments i before the swap? Functionally they are
 * equivalent.
 *  
 * @return The index of the pivot.
 */
int partition(vector<int> &a, int l, int r) {
    int pivot = a[r];
    int i = l;
    int j = l;
    
    while (j < r) {
        if (a[j] < pivot) {
            swap(a[i], a[j]);
            i++;
            j++;
        } else {
            j++;
        }
    }

    swap(a[i], a[r]);

    return i;
}

/**
 * Sorts an array in place. 
 */
void quicksort(vector<int> &a, int l, int r) {
    int n = r - l + 1;
    if (n <= 1) {
        return;
    }

    int q = partition(a, l, r);
    quicksort(a, l, q-1);
    quicksort(a, q+1, r);
}

void quicksort(vector<int> &a) {
    quicksort(a, 0, a.size()-1);
}


void print_v(vector<int> &a) {
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> a = {-5, -12, -99, 7, 7, 23, -100, 1, 2, 5};
    vector<int> b = {2,1};
    vector<int> c = {0};
    vector<int> d = {3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,2,2,2,2,2,2};
    vector<int> e = {3,2,1};
    quicksort(a);
    quicksort(b);
    quicksort(c);
    quicksort(d);
    quicksort(e);
    print_v(a);
    print_v(b);
    print_v(c);
    print_v(d);
    print_v(e);

    vector<int> f = {1,2,3,3,2,1,1,2,3,2,1,3,2};
    three_way_partition(f, 0, f.size()-1);
    print_v(f);
}