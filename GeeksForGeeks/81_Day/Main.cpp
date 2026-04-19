#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void testFlipBits() {
    Solution sol;
    
    // Example 1
    vector<int> arr1 = {1, 0, 0, 1, 0};
    cout << "Test Case 1: arr[] = [1, 0, 0, 1, 0]" << endl;
    cout << "Expected: 4, Got: " << sol.maxOnes(arr1) << endl;

    // Example 2
    vector<int> arr2 = {1, 0, 0, 1, 0, 0, 1};
    cout << "Test Case 2: arr[] = [1, 0, 0, 1, 0, 0, 1]" << endl;
    cout << "Expected: 6, Got: " << sol.maxOnes(arr2) << endl;

    // Edge Case: All 1s
    vector<int> arr3 = {1, 1, 1, 1};
    cout << "Test Case 3 (All 1s): arr[] = [1, 1, 1, 1]" << endl;
    cout << "Expected: 4, Got: " << sol.maxOnes(arr3) << endl;

    // Edge Case: All 0s
    vector<int> arr4 = {0, 0, 0, 0};
    cout << "Test Case 4 (All 0s): arr[] = [0, 0, 0, 0]" << endl;
    cout << "Expected: 4, Got: " << sol.maxOnes(arr4) << endl;
}

int main() {
    testFlipBits();
    return 0;
}
