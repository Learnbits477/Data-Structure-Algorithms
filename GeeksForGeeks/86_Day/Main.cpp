#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Solution.cpp"

using namespace std;

// Function to print the array for better visualization
void printArray(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

// Function to run and display test cases
void runTest(int caseNum, vector<int> arr, bool expected) {
    Solution sol;
    bool result = sol.canSplit(arr);
    
    cout << "Test Case " << caseNum << ": ";
    printArray(arr);
    cout << "\nResult: " << (result ? "true" : "false");
    cout << " | Expected: " << (expected ? "true" : "false");
    
    if (result == expected) {
        cout << " | PASSED" << endl;
    } else {
        cout << " | FAILED" << endl;
    }
    cout << "---------------------------------------------------" << endl;
}

int main() {
    cout << "Split Array into Two Equal Sum Subarrays " << endl << endl;

    // Example 1
    runTest(1, {1, 2, 3, 4, 5, 5}, true);

    // Example 2
    runTest(2, {4, 3, 2, 1}, false);

    // Additional Test Cases
    runTest(3, {1, 1, 1, 1}, true);    // [1, 1] and [1, 1]
    runTest(4, {1, 2, 3, 6}, true);    // [1, 2, 3] and [6]
    runTest(5, {10, 20, 30, 5, 5}, false); 
    runTest(6, {2, 2, 2, 2, 2}, false); // Odd number of same elements, total sum 10 but cannot split? Wait, 10/2=5. 2+2=4, 4+2=6. Impossible. Correct.

    return 0;
}
