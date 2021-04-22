#include <iostream>
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* first = head;
        ListNode* second;
        ListNode* new_head;
        ListNode* temp;

        if (!head || !head->next) {
            new_head = head;
        } else {
            new_head = head->next;
        }

        while (first && first->next) {
            second = first->next;

            if (second && second->next) {
                first->next = second->next->next;
            } else if (second) {
                first->next = second->next;
            }

            temp = first;
            first = second->next;
            second->next = temp;
        }
        return new_head;
    }
};