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

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> stack;
        // When should we use dynamic allocation?
        // ListNode* p = new ListNode()
        // The difference between this and ListNode p = *head
        // is that in the latter case, the object is deleted automatically at
        // the end of the block.
        // 
        // Best practice is to minimize using dynamic allocation and raw
        // pointers.

        ListNode* p = head;  // This isn't dynamic allocation, just a pointer.
        int n = 0;

        while (p != nullptr) {
            n++;
            p = p->next;
        }

        p = head;
        for (int i = 0; i < n / 2; i++) {
            stack.push_back(p->val);
            p = p->next;
        }

        if (n % 2 != 0) {
            p = p->next;  // ignore middle element
        }

        for (int i = (n+1)/2 ; i < n; i++) {
            // cout << p->val << stack.back() << endl;
            if (p->val != stack.back()) {
                return false;
            }
            stack.pop_back();
            p = p->next;
        }

        return true;
    }
};


// Solution reversing the first half of the list
// This allows O(1) memory.
// n = 1 ... 10^5
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* next;

        while (fast && fast->next) {
            // cout << slow->val << " ";

            fast = fast->next->next;

            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // prev is the head of the reversed list,
        // slow is the head of the remaining list

        if (fast) {  // odd length -> ignore middle element
            slow = slow->next;
        }

        while (prev) {  // while slow would cause nullptr in length 1 case
            if (slow->val != prev->val) {
                return false;
            }
            slow = slow->next;
            prev = prev->next;
        }
        return true;
    }
};


int main() {
    ListNode n1 = ListNode(1);
    ListNode n2 = ListNode(2);
    ListNode n3 = ListNode(2);
    ListNode n4 = ListNode(1);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    Solution2 s;

    cout << s.isPalindrome(&n1) << endl;

}