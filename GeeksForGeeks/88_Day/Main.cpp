#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

void runTestCase(const string& testName, vector<int>& input, const string& expected, Solution& sol) {
    cout << "--- " << testName << " ---" << endl;
    
    cout << "Input:    ";
    printVector(input);
    cout << endl;
    
    // Execute algorithm
    vector<int> result = sol.reducePairs(input);
    
    cout << "Output:   ";
    printVector(result);
    cout << endl;
    
    cout << "Expected: " << expected << "\n" << endl;
}

int main() {
    Solution sol;
    
    // Test Case 1: Multiple collisions leading to a single surviving element
    vector<int> arr1 = {10, -5, -8, 2, -5};
    runTestCase("Test Case 1", arr1, "[10]", sol);

    // Test Case 2: Equal magnitude pairs destroying each other
    vector<int> arr2 = {5, -5, -2, -10};
    runTestCase("Test Case 2", arr2, "[-2, -10]", sol);

    // Test Case 3: Complete annihilation with larger opposite elements
    vector<int> arr3 = {-20, 1, 20};
    runTestCase("Test Case 3", arr3, "[]", sol);

    return 0;
}
