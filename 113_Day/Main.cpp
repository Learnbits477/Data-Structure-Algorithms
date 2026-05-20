#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

// Helper to format a vector as string
string formatVector(const vector<int>& v) {
    string res = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        res += to_string(v[i]);
        if (i + 1 < v.size()) res += ", ";
    }
    res += "]";
    return res;
}

void runTest(int testId, vector<int> arr, long long target, bool expected) {
    Solution solver;
    bool actual = solver.isProduct(arr, target);
    
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   Input array: " << formatVector(arr) << "\n";
    cout << "   Target: " << target << "\n";
    cout << "   Expected: " << (expected ? "true" : "false") << "\n";
    cout << "   Actual:   " << (actual ? "true" : "false") << "\n";
    
    if (actual == expected) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
}

int main() {
    cout << "\n🔢 [Day 113] Product Pair — Test Suite 🚀\n";
    
    // Example 1
    runTest(1, {10, 20, 9, 40}, 400, true);
    
    // Example 2
    runTest(2, {-10, 20, 9, -40}, 30, false);
    
    // Example 3
    runTest(3, {-10, 0, 9, -40}, 0, true);

    // Extra Edge Cases
    runTest(4, {5, 5}, 25, true);
    runTest(5, {0, 0}, 0, true);
    runTest(6, {5, 0}, 0, true);
    runTest(7, {3, 7}, 21, true);
    runTest(8, {3, 7}, 20, false);
    runTest(9, {-5, 6}, -30, true);
    
    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
