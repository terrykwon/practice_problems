#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Naive solution that scans K lists at each iteration and chooses the minimum.
// Think this is O(N x K^2)? Can be improved by using a min heap structure
// -> O(N x Klog(K)). N here is the length of the longest list.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* merged_head = nullptr;        
        ListNode* current = nullptr;  // IMPORTANT: must initialize to nullptr
                                      // or it will be filled with random value

        vector<ListNode*> heads;  // current heads

        bool traverse_end;

        // use pointer to pointer in order to increment each head in list
        ListNode** min_node = nullptr;
        // ListNode* head = nullptr;

        // int i = 0;
        while(1) {
            traverse_end = true;

            // *** IMPORTANT ***: range-based for loop COPIES the value by 
            // default

            // for (ListNode* head : lists) {
            for (ListNode* &head : lists) {
                if (!head) {
                    continue;
                }
                traverse_end = false;
                // cout << head->val << " " << endl;

                // Entering this loop works as expected
                if (!min_node || !*min_node || head->val < (*min_node)->val) {
                    min_node = &head;
                    // cout << "min_node := " << (*min_node)->val << endl;
                }
            }

            if (traverse_end) {
                break;
            }

            if (!current) {  // first iteration
                current = *min_node;
                merged_head = current;
            } else {
                current->next = *min_node;
                current = current->next;
            }

            *min_node = (*min_node)->next;
            // if (*min_node) {
            //     cout << "min_node := " << (*min_node)->val << endl;
            // }
        }
        return merged_head;
    }
};


int main() {
    ListNode a1 = ListNode(1);
    ListNode a2 = ListNode(2);
    ListNode a3 = ListNode(3);
    ListNode a4 = ListNode(4);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;

    ListNode b1 = ListNode(2);
    ListNode b2 = ListNode(3);
    ListNode b3 = ListNode(5);
    b1.next = &b2;
    b2.next = &b3;

    vector<ListNode*> lists{&a1, &b1, nullptr};

    Solution s;
    ListNode* h = s.mergeKLists(lists);
    while (h) {
        cout << h->val << " ";
        h = h->next;
    }
    cout << endl;
}