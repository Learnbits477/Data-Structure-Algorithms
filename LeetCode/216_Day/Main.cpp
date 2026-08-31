#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < values.size(); ++i) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    return head;
}

void deleteLinkedList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

string formatVector(const vector<int>& v, int maxItems = 6) {
    ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (static_cast<int>(i) >= maxItems) {
            oss << "...";
            break;
        }
        oss << v[i];
        if (i + 1 < v.size() && static_cast<int>(i + 1) < maxItems) {
            oss << ",";
        }
    }
    oss << "]";
    return oss.str();
}

void runTest(int testNum, const vector<int>& listValues, const vector<int>& expected) {
    ListNode* head = createLinkedList(listValues);
    Solution sol;
    vector<int> result = sol.nodesBetweenCriticalPoints(head);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(26) << formatVector(listValues)
         << setw(16) << formatVector(result)
         << setw(16) << formatVector(expected)
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input:    " << formatVector(listValues, 50) << "\n"
             << "     Expected: " << formatVector(expected) << "\n"
             << "     Got:      " << formatVector(result) << "\n";
    }

    deleteLinkedList(head);
}

int main() {
    cout << "\n🎯 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points — Test Suite\n";
    cout << "※ ======================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(26) << "Input List"
         << setw(16) << "Result"
         << setw(16) << "Expected"
         << "Status\n";
    cout << string(75, '-') << "\n";

    // Test 1: Example 1 (No critical points, 2 nodes)
    runTest(1, {3, 1}, {-1, -1});

    // Test 2: Example 2 (Three critical points)
    runTest(2, {5, 3, 1, 2, 5, 1, 2}, {1, 3});

    // Test 3: Example 3 (Two critical points)
    runTest(3, {1, 3, 2, 2, 3, 2, 2, 2, 7}, {3, 3});

    // Test 4: Monotonically strictly increasing (No critical points)
    runTest(4, {1, 2, 3, 4, 5, 6}, {-1, -1});

    // Test 5: Monotonically strictly decreasing (No critical points)
    runTest(5, {6, 5, 4, 3, 2, 1}, {-1, -1});

    // Test 6: All elements identical (No critical points)
    runTest(6, {2, 2, 2, 2, 2}, {-1, -1});

    // Test 7: Exactly one critical point
    runTest(7, {1, 5, 2}, {-1, -1});

    // Test 8: Alternating peak-valley pattern
    runTest(8, {1, 10, 1, 10, 1, 10, 1}, {1, 4});

    cout << "※ ======================================================================================== ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
