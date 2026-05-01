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

void runTest(int id, vector<int> nums, int expected) {
    Solution sol;
    int got = sol.maxRotateFunction(nums);

    cout << "── Test Case " << id << " ──────────────────────────────────\n";
    cout << "  nums[]   : "; printVec(nums); cout << "\n";
    cout << "  Expected : " << expected      << "\n";
    cout << "  Got      : " << got           << "\n";
    cout << "  Result   : " << (got == expected ? "✅ PASS" : "❌ FAIL") << "\n\n";
}

// ── main ─────────────────────────────────────────────────────────────────────

int main() {
    cout << "╔══════════════════════════════════════════════════════╗\n";
    cout << "║   LeetCode 396 — Rotate Function — Test Runner       ║\n";
    cout << "╚══════════════════════════════════════════════════════╝\n\n";

    // Test 1 — LeetCode Example 1
    // F(3) = 0*3 + 1*2 + 2*6 + 3*4 = 0+2+12+12 = 26
    runTest(1, {4, 3, 2, 6}, 26);

    // Test 2 — LeetCode Example 2 (single element)
    // F(0) = 0*100 = 0
    runTest(2, {100}, 0);

    // Test 3 — All same elements (all F(k) are equal)
    // F(k) = 0*5+1*5+2*5+3*5 = 0+5+10+15 = 30 for any k
    runTest(3, {5, 5, 5, 5}, 30);

    // Test 4 — Ascending sequence
    // sum=10, F(0)=0*1+1*2+2*3+3*4=0+2+6+12=20
    // F(1)=20+10-4*4=20+10-16=14; F(2)=14+10-4*3=12; F(3)=12+10-4*2=14
    // max = 20
    runTest(4, {1, 2, 3, 4}, 20);

    // Test 5 — Negative elements
    runTest(5, {-1, -2, -3, -4}, -12);

    return 0;
}
