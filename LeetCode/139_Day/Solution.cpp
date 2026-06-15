#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Step 1: Single-node edge case — the only node is its own middle.
        if (!head->next) return nullptr;

        // Step 2: Dummy node lets slow start one step behind the list.
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = head;

        // Step 3: Advance fast 2x, slow 1x until fast falls off the end.
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 4: Unlink the middle node.
        slow->next = slow->next->next;

        // Step 5: Return the modified list head.
        return dummy.next;
    }
};
