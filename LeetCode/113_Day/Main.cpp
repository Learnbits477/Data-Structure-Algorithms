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

void runTest(int testId, vector<int> A, vector<int> B, vector<int> expected) {
    Solution solver;
    vector<int> actual = solver.findThePrefixCommonArray(A, B);
    
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   A: " << formatVector(A) << "\n";
    cout << "   B: " << formatVector(B) << "\n";
    cout << "   Expected: " << formatVector(expected) << "\n";
    cout << "   Actual:   " << formatVector(actual) << "\n";
    
    if (actual == expected) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
}

int main() {
    cout << "\n🔢 [Day 113] Find the Prefix Common Array of Two Arrays — Test Suite 🚀\n";
    
    // Example 1
    runTest(1, {1, 3, 2, 4}, {3, 1, 2, 4}, {0, 2, 3, 4});
    
    // Example 2
    runTest(2, {2, 3, 1}, {3, 1, 2}, {0, 1, 3});

    // Extra Edge Case 3: Single element
    runTest(3, {1}, {1}, {1});

    // Extra Edge Case 4: Identical permutations
    runTest(4, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5});

    // Extra Edge Case 5: Reverse permutations
    runTest(5, {1, 2, 3}, {3, 2, 1}, {0, 1, 3});

    // Extra Edge Case 6: Shifted permutations
    runTest(6, {1, 2, 3, 4}, {2, 3, 4, 1}, {0, 1, 2, 4});
    
    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
