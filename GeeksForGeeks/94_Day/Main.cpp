#include <iostream>
#include <vector>

#include "Solution.cpp"

using namespace std;

// ── Helpers ──────────────────────────────────────────────────────────────────

void printVec(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i + 1 < (int)v.size()) cout << ", ";
    }
    cout << "]";
}

bool vecEqual(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < (int)a.size(); i++)
        if (a[i] != b[i]) return false;
    return true;
}

void runTest(int id, int k, vector<int> arr,
             const vector<int>& expected) {
    Solution sol;
    vector<int> got = sol.kthLargest(arr, k);

    cout << "── Test Case " << id << " ──────────────────────────────────\n";
    cout << "  arr[]    : "; printVec(arr);    cout << "\n";
    cout << "  k        : " << k               << "\n";
    cout << "  Expected : "; printVec(expected);cout << "\n";
    cout << "  Got      : "; printVec(got);     cout << "\n";
    cout << "  Result   : " << (vecEqual(got, expected) ? "✅ PASS" : "❌ FAIL")
         << "\n\n";
}

// ── main ─────────────────────────────────────────────────────────────────────

int main() {
    cout << "╔══════════════════════════════════════════════════════╗\n";
    cout << "║   Kth Largest Element in a Stream — Test Runner      ║\n";
    cout << "╚══════════════════════════════════════════════════════╝\n\n";

    // Test 1 — GFG Example 1
    runTest(1, 4,
            {1, 2, 3, 4, 5, 6},
            {-1, -1, -1, 1, 2, 3});

    // Test 2 — GFG Example 2
    runTest(2, 2,
            {3, 2, 1, 3, 3},
            {-1, 2, 2, 3, 3});

    // Test 3 — k = 1  (always the current maximum)
    runTest(3, 1,
            {5, 3, 8, 2, 10},
            {5, 5, 8, 8, 10});

    // Test 4 — all same elements
    runTest(4, 3,
            {7, 7, 7, 7, 7},
            {-1, -1, 7, 7, 7});

    // Test 5 — k equals n  (last element is the minimum)
    runTest(5, 5,
            {10, 9, 8, 7, 6},
            {-1, -1, -1, -1, 6});

    return 0;
}
