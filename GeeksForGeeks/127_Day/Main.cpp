#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

// Utility function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i < vec.size() - 1 ? ", " : "");
    }
    cout << "]";
}

// Utility function to check equality of two vectors
bool areEqual(const vector<int>& v1, const vector<int>& v2) {
    if (v1.size() != v2.size()) return false;
    for (size_t i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

// Utility function to run a test
void runTest(int testCase, vector<int> arr, vector<vector<int>> queries, const vector<int>& expected) {
    Solution sol;
    vector<int> result = sol.freqInRange(arr, queries);
    
    cout << "Test Case " << testCase << ": ";
    if (areEqual(result, expected)) {
        cout << "✅ PASSED\n";
    } else {
        cout << "❌ FAILED\n";
        cout << "   Expected: ";
        printVector(expected);
        cout << "\n   Got:      ";
        printVector(result);
        cout << "\n";
    }
}

int main() {
    cout << "\n🔢 Subarray Frequency Count Queries — Test Suite\n";
    cout << "=================================================\n\n";

    // Example 1
    vector<int> arr1 = {1, 2, 1, 3, 1, 2, 3};
    vector<vector<int>> queries1 = {{0, 4, 1}, {2, 5, 2}, {1, 6, 3}, {0, 6, 5}};
    vector<int> expected1 = {3, 1, 2, 0};
    runTest(1, arr1, queries1, expected1);

    // Example 2
    vector<int> arr2 = {11, 21, 51, 101, 11, 51};
    vector<vector<int>> queries2 = {{0, 4, 11}, {2, 5, 51}};
    vector<int> expected2 = {2, 2};
    runTest(2, arr2, queries2, expected2);

    cout << "\n=================================================\n";
    cout << "🎉 All tests completed!\n\n";

    return 0;
}
