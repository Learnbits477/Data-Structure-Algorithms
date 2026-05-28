#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

// Test runner function
void runTest(int testId, vector<string> wordsContainer, vector<string> wordsQuery, vector<int> expected) {
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   wordsContainer: [ ";
    for (auto const& w : wordsContainer) {
        cout << "\"" << w << "\" ";
    }
    cout << "]\n";
    cout << "   wordsQuery:     [ ";
    for (auto const& q : wordsQuery) {
        cout << "\"" << q << "\" ";
    }
    cout << "]\n";

    Solution solver;
    vector<int> actual = solver.stringIndices(wordsContainer, wordsQuery);

    cout << "   Expected:       [ ";
    for (int x : expected) {
        cout << x << " ";
    }
    cout << "]\n";

    cout << "   Actual:         [ ";
    for (int x : actual) {
        cout << x << " ";
    }
    cout << "]\n";

    if (actual == expected) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
}

int main() {
    cout << "\n🔢 [Day 121] Longest Common Suffix Queries — Test Suite 🚀\n";

    // Example 1: Standard suffix matching and length tie-break
    runTest(1, 
            {"abcd", "bcd", "xbcd"}, 
            {"cd", "bcd", "xyz"}, 
            {1, 1, 1});

    // Example 2: Matching long suffixes and length comparison
    runTest(2, 
            {"abcdefgh", "poiuygh", "ghghgh"}, 
            {"gh", "acbfgh", "acbfegh"}, 
            {2, 0, 2});

    // Test Case 3: No suffix match, falling back to global best (shortest length, then earliest index)
    runTest(3, 
            {"abcdef", "gh", "ij"}, 
            {"xyz"}, 
            {1});

    // Test Case 4: Precise full suffix match
    runTest(4, 
            {"apple", "orange", "banana"}, 
            {"apple", "orange", "banana"}, 
            {0, 1, 2});

    // Test Case 5: Duplicate words in container (tie-breaker index)
    runTest(5, 
            {"ab", "ab", "ab"}, 
            {"b"}, 
            {0});

    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
