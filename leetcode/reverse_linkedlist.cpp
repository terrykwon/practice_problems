#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Is there a way to do this with just two pointers?
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main() {
    ListNode n1 = ListNode(1);
    ListNode n2 = ListNode(2);
    ListNode n3 = ListNode(3);
    ListNode n4 = ListNode(4);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    Solution s;

    ListNode* p = s.reverseList(&n1);
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}