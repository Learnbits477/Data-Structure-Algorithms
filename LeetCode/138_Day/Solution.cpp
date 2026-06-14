#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {

        // Step 1: Find the middle via slow & fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half in-place
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr != nullptr) {
            ListNode* nxt = curr->next;
            curr->next   = prev;
            prev         = curr;
            curr         = nxt;
        }

        // Step 3: Two-pointer sweep — compute max twin sum
        int maxSum = 0;
        ListNode* left  = head;
        ListNode* right = prev;
        while (right != nullptr) {
            maxSum = max(maxSum, left->val + right->val);
            left   = left->next;
            right  = right->next;
        }

        // Step 4: Return result
        return maxSum;
    }
};
