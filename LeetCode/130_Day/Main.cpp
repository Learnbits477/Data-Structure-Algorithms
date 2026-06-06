#include <iostream>
#include <vector>
#include <cmath>
#include "Solution.cpp"

using namespace std;

// Utility function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << (i < vec.size() - 1 ? "," : "");
    }
    cout << "]";
}

// Utility function to check equality of two vectors
bool isVectorEqual(const vector<int>& v1, const vector<int>& v2) {
    if (v1.size() != v2.size()) return false;
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

void runTest(vector<int> nums, const vector<int>& expected) {
    Solution sol;
    
    cout << "Input: nums = ";
    printVector(nums);
    cout << "\n";
    
    vector<int> result = sol.leftRightDifference(nums);
    
    cout << "Expected: ";
    printVector(expected);
    cout << " | Output: ";
    printVector(result);
    cout << "\n";
    
    if (isVectorEqual(result, expected)) {
        cout << "✅ PASSED\n\n";
    } else {
        cout << "❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🔢 Left and Right Sum Differences — Test Suite\n";
    cout << "--------------------------------------------------------\n" << endl;
    
    // Test Case 1
    runTest({10, 4, 8, 3}, {15, 1, 11, 22});
    
    // Test Case 2
    runTest({1}, {0});
    
    return 0;
}
