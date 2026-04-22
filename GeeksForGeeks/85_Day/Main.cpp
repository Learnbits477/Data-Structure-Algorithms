#include <iostream>
#include <vector>
#include <iomanip>
#include "Solution.cpp"

using namespace std;

void printArray(const vector<int>& res) {
    cout << "[";
    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i] << (i == res.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    cout << "========================================" << endl;
    cout << "   Mean of Range in Array - Test Suite" << endl;
    cout << "========================================" << endl;

    // Test Case 1
    cout << "\nTest Case 1:" << endl;
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<vector<int>> queries1 = {{0, 2}, {1, 3}, {0, 4}};
    cout << "Input: arr = [1, 2, 3, 4, 5], queries = [[0, 2], [1, 3], [0, 4]]" << endl;
    vector<int> res1 = sol.findMean(arr1, queries1);
    cout << "Output: ";
    printArray(res1);
    cout << "Expected: [2, 3, 3]" << endl;

    // Test Case 2
    cout << "\nTest Case 2:" << endl;
    vector<int> arr2 = {6, 7, 8, 10};
    vector<vector<int>> queries2 = {{0, 3}, {1, 2}};
    cout << "Input: arr = [6, 7, 8, 10], queries = [[0, 3], [1, 2]]" << endl;
    vector<int> res2 = sol.findMean(arr2, queries2);
    cout << "Output: ";
    printArray(res2);
    cout << "Expected: [7, 7]" << endl;

    cout << "\n========================================" << endl;
    return 0;
}
