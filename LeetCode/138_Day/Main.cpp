#include "Solution.cpp"
#include <iostream>
#include <vector>
using namespace std;

ListNode* buildList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < (int)vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

void printList(const vector<int>& vals) {
    cout << "[";
    for (int i = 0; i < (int)vals.size(); ++i) {
        cout << vals[i];
        if (i + 1 < (int)vals.size()) cout << " → ";
    }
    cout << "]";
}

void runTest(int no, const vector<int>& vals, int expected) {
    Solution sol;
    ListNode* head = buildList(vals);
    int result     = sol.pairSum(head);

    cout << "  Test " << no << "  │  Input    : ";
    printList(vals);
    cout << "\n"
         << "         │  Expected : " << expected << "\n"
         << "         │  Result   : " << result   << "\n"
         << "         │  Status   : " << (result == expected ? "✅ PASSED" : "❌ FAILED")
         << "\n\n";
}

int main() {
    cout << "\n";
    cout << "╔══════════════════════════════════════════════════════════╗\n";
    cout << "║      Maximum Twin Sum of a Linked List — Test Suite      ║\n";
    cout << "║        LeetCode 2130  │  Difficulty : Medium             ║\n";
    cout << "╚══════════════════════════════════════════════════════════╝\n";
    cout << "\n";

    runTest(1, {5, 4, 2, 1},                    6);
    runTest(2, {4, 2, 2, 3},                    7);
    runTest(3, {1, 100000},                 100001);
    runTest(4, {3, 3, 3, 3},                    6);
    runTest(5, {1, 2, 3, 4, 5, 6},              7);
    runTest(6, vector<int>(10, 100000),     200000);

    cout << "══════════════════════════════════════════════════════════\n";
    cout << "  🏁  All tests completed!\n";
    cout << "══════════════════════════════════════════════════════════\n\n";

    return 0;
}
