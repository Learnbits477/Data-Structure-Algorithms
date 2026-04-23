#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void printVector(const vector<long long>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

void runTest(int caseNum, vector<int> nums, vector<long long> expected) {
    Solution sol;
    vector<long long> result = sol.distance(nums);
    
    cout << "Test Case " << caseNum << ": ";
    cout << "Input: ";
    for(int x : nums) cout << x << " ";
    cout << "\nResult:   ";
    printVector(result);
    cout << "\nExpected: ";
    printVector(expected);
    
    bool passed = (result == expected);
    cout << "\nStatus: " << (passed ? "PASSED" : "FAILED") << endl;
    cout << "---------------------------------------------------" << endl;
}

int main() {
    cout << "=== 2615. Sum of Distances Test Harness ===" << endl << endl;

    // Example 1
    runTest(1, {1, 3, 1, 1, 2}, {5, 0, 3, 4, 0});

    // Example 2
    runTest(2, {0, 5, 3}, {0, 0, 0});

    // Custom Test: All same
    runTest(3, {1, 1, 1}, {3, 2, 3}); 
    // i=0: |0-1|+|0-2| = 1+2=3
    // i=1: |1-0|+|1-2| = 1+1=2
    // i=2: |2-0|+|2-1| = 2+1=3

    return 0;
}
