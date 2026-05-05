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
   
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // 1. Compute the length of the list and find the tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // 2. Adjust k and handle cases where rotation is not needed
        k = k % length;
        if (k == 0) return head;

        // 3. Connect tail to head to form a circular list
        tail->next = head;

        // 4. Find the new tail (length - k steps from the old head)
        int stepsToNewTail = length - k;
        ListNode* newTail = tail; 
        while (stepsToNewTail--) {
            newTail = newTail->next;
        }

        // 5. Break the circle and set new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
