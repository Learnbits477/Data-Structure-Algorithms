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

void runTest(int testId, vector<int> arr1, vector<int> arr2, int expected) {
    Solution solver;
    int actual = solver.longestCommonPrefix(arr1, arr2);
    
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   arr1: " << formatVector(arr1) << "\n";
    cout << "   arr2: " << formatVector(arr2) << "\n";
    cout << "   Expected: " << expected << "\n";
    cout << "   Actual:   " << actual << "\n";
    
    if (actual == expected) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
}

int main() {
    cout << "\n🔢 [Day 114] Find the Length of the Longest Common Prefix — Test Suite 🚀\n";
    
    // Example 1
    runTest(1, {1, 10, 100}, {1000}, 3);
    
    // Example 2
    runTest(2, {1, 2, 3}, {4, 4, 4}, 0);

    // Extra Edge Case 3: Complete match
    runTest(3, {12345}, {12345}, 5);

    // Extra Edge Case 4: No match at all
    runTest(4, {987}, {123, 456}, 0);

    // Extra Edge Case 5: Multiple prefixes matching with different lengths
    runTest(5, {123, 12, 1}, {12345, 129, 99}, 3);

    // Extra Edge Case 6: Single digits
    runTest(6, {5}, {5}, 1);

    // Extra Edge Case 7: Large numbers
    runTest(7, {99999999}, {99999999}, 8);
    
    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
