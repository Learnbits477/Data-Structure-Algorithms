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

void runTest(int id, vector<int> arr, int k, int expected) {
    Solution sol;
    int got = sol.countSubset(arr, k);

    cout << "── Test Case " << id << " ──────────────────────────────────\n";
    cout << "  arr[]    : "; printVec(arr); cout << "\n";
    cout << "  k        : " << k << "\n";
    cout << "  Expected : " << expected << "\n";
    cout << "  Got      : " << got << "\n";
    cout << "  Result   : " << (got == expected ? "✅ PASS" : "❌ FAIL")
         << "\n\n";
}

// ── main ─────────────────────────────────────────────────────────────────────

int main() {
    cout << "╔══════════════════════════════════════════════════════╗\n";
    cout << "║   Count Subset With Target Sum II — Test Runner      ║\n";
    cout << "╚══════════════════════════════════════════════════════╝\n\n";

    // Test 1 — GFG Example 1
    runTest(1, {1, 3, 2}, 3, 2);

    // Test 2 — GFG Example 2
    runTest(2, {4, 2, 3, 1, 2}, 4, 3);

    // Test 3 — GFG Example 3
    runTest(3, {10, 20, 30}, 25, 0);

    // Test 4 — Zeroes with Target 0
    runTest(4, {0, 0, 0, 0}, 0, 16); // 2^4 = 16 empty or zeroes subsets

    // Test 5 — Negative Numbers
    runTest(5, {1, -1, 1, -1}, 0, 6);

    return 0;
}
