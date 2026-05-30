#include "Solution.cpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Pretty-print a vector as [a, b, c, ...]
string vecToStr(const vector<int>& v) {
    string s = "[";
    for (int i = 0; i < (int)v.size(); i++) {
        s += to_string(v[i]);
        if (i + 1 < (int)v.size()) s += ", ";
    }
    return s + "]";
}

void runTest(int testNum,
             vector<int> input,
             const vector<int>& expected)
{
    Solution sol;

    vector<int> original = input;          // keep for display
    sol.replaceElements(input);             // mutates 'input' in-place

    bool passed = (input == expected);

    cout << "─────────────────────────────────────────────────\n";
    cout << "  Test #" << testNum << "\n";
    cout << "  Input    : " << vecToStr(original) << "\n";
    cout << "  Expected : " << vecToStr(expected)  << "\n";
    cout << "  Got      : " << vecToStr(input)     << "\n";
    cout << "  Result   : " << (passed ? "✅ PASSED" : "❌ FAILED") << "\n";
}

int main() {
    cout << "\n";
    cout << "╔═════════════════════════════════════════════════╗\n";
    cout << "║    Replace with XOR of Adjacent — Test Suite    ║\n";
    cout << "║         Day 123  |  GeeksForGeeks  |  Easy      ║\n";
    cout << "╚═════════════════════════════════════════════════╝\n\n";

  
    // Example 1 from problem statement
    runTest(1,
        {2, 1, 4, 7},
        {3, 6, 6, 3});

    // Example 2 from problem statement
    runTest(2,
        {5, 9, 2, 6, 7},
        {12, 7, 15, 5, 1});

  
    // Minimum size array (n = 2)
    // arr[0] = 3^8 = 11, arr[1] = 3^8 = 11
    runTest(3,
        {3, 8},
        {11, 11});

    // All identical elements — XOR of equal values is 0
    // arr = [5,5,5,5] => [0, 0, 0, 0]
    runTest(4,
        {5, 5, 5, 5},
        {0, 0, 0, 0});

    // Powers of 2 — no overlapping bits, XOR == bitwise OR
    // arr = [1, 2, 4, 8]
    // idx0: 1^2=3, idx1: 1^4=5, idx2: 2^8=10, idx3: 4^8=12
    runTest(5,
        {1, 2, 4, 8},
        {3, 5, 10, 12});

    // Larger values near constraint boundary
    // arr = [10000000, 9999999, 1]
    // idx0: 10000000^9999999, idx1: 10000000^1, idx2: 9999999^1
    runTest(6,
        {10000000, 9999999, 1},
        {10000000 ^ 9999999,
         10000000 ^ 1,
         9999999  ^ 1});

    cout << "─────────────────────────────────────────────────\n";
    cout << "\n  🏁  All tests completed.\n\n";

    return 0;
}
