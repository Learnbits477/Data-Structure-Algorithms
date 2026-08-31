#include <bits/stdc++.h>
using namespace std;

#ifndef LISTNODE_DEF
#define LISTNODE_DEF
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Step 1: Base validation - Need at least 3 nodes to have any critical point
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        // Step 2: Initialize tracking variables
        int first_critical_idx = -1;
        int prev_critical_idx = -1;
        int min_dist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 2; // 1-based index of 'curr'

        // Step 3: Traverse the linked list
        while (curr->next != nullptr) {
            bool is_local_max = (curr->val > prev->val && curr->val > curr->next->val);
            bool is_local_min = (curr->val < prev->val && curr->val < curr->next->val);

            if (is_local_max || is_local_min) {
                if (first_critical_idx == -1) {
                    first_critical_idx = idx;
                } else {
                    min_dist = min(min_dist, idx - prev_critical_idx);
                }
                prev_critical_idx = idx;
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }

        // Step 4: Validate if at least two critical points were found
        if (first_critical_idx == -1 || prev_critical_idx == first_critical_idx) {
            return {-1, -1};
        }

        // Step 5: Compute max distance and return
        int max_dist = prev_critical_idx - first_critical_idx;
        return {min_dist, max_dist};
    }
};
