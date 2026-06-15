#include "Solution.cpp"
#include <iostream>
#include <vector>
using namespace std;

ListNode* build(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur  = head;
    for (int i = 1; i < (int)vals.size(); i++) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

vector<int> toVec(ListNode* head) {
    vector<int> res;
    while (head) { res.push_back(head->val); head = head->next; }
    return res;
}

void freeList(ListNode* head) {
    while (head) { ListNode* t = head->next; delete head; head = t; }
}

void runTest(int testNum, vector<int> input, vector<int> expected) {
    Solution sol;
    ListNode* head   = build(input);
    ListNode* result = sol.deleteMiddle(head);
    vector<int> got  = toVec(result);
    bool passed      = (got == expected);

    cout << "  Test " << testNum << "  |  Input: [";
    for (int i = 0; i < (int)input.size(); i++) {
        cout << input[i];
        if (i + 1 < (int)input.size()) cout << ", ";
    }
    cout << "]  |  Expected: [";
    for (int i = 0; i < (int)expected.size(); i++) {
        cout << expected[i];
        if (i + 1 < (int)expected.size()) cout << ", ";
    }
    cout << "]  |  Got: [";
    for (int i = 0; i < (int)got.size(); i++) {
        cout << got[i];
        if (i + 1 < (int)got.size()) cout << ", ";
    }
    cout << "]  |  " << (passed ? "PASSED" : "FAILED") << "\n";
    freeList(result);
}

int main() {
    cout << "\n";
    cout << "   Delete Middle Node of Linked List - Test Suite\n";
    cout << "                   LeetCode Day 139\n";
    cout << "==========================================================\n\n";

    cout << "  Provided Examples:\n";
    cout << "  " << string(60, '-') << "\n";

    runTest(1, {1, 3, 4, 7, 1, 2, 6}, {1, 3, 4, 1, 2, 6});
    runTest(2, {1, 2, 3, 4},           {1, 2, 4});
    runTest(3, {2, 1},                 {2});

    cout << "\n  Edge Cases:\n";
    cout << "  " << string(60, '-') << "\n";

    runTest(4, {1},                    {});
    runTest(5, {1, 2, 3},             {1, 3});
    runTest(6, {1, 2, 3, 4, 5},       {1, 2, 4, 5});
    runTest(7, {5, 10},               {5});
    runTest(8, {1, 2, 3, 4, 5, 6},   {1, 2, 3, 5, 6});

    cout << "\n==========================================================\n";
    cout << "                  All Tests Complete!\n";
    cout << "==========================================================\n\n";

    return 0;
}
