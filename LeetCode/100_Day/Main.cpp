#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

#include "Solution.cpp"

// Helper function to build a vector from a space-separated string
vector<int> buildArray(string str) {
    vector<int> res;
    stringstream ss(str);
    int temp;
    while (ss >> temp) {
        res.push_back(temp);
    }
    return res;
}

// Helper function to print a vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Test Case 1
    string input1 = "2 1 3";
    vector<int> nums1 = buildArray(input1);
    vector<int> result1 = sol.maxValue(nums1);
    cout << "Test Case 1:\nInput: [2, 1, 3]\nOutput: ";
    printVector(result1);
    cout << "\nExpected: [2, 2, 3]\n\n";

    // Test Case 2
    string input2 = "2 3 1";
    vector<int> nums2 = buildArray(input2);
    vector<int> result2 = sol.maxValue(nums2);
    cout << "Test Case 2:\nInput: [2, 3, 1]\nOutput: ";
    printVector(result2);
    cout << "\nExpected: [3, 3, 3]\n\n";

    // Test Case 3
    string input3 = "10 5 2 15 8";
    vector<int> nums3 = buildArray(input3);
    vector<int> result3 = sol.maxValue(nums3);
    cout << "Test Case 3:\nInput: [10, 5, 2, 15, 8]\nOutput: ";
    printVector(result3);
    cout << "\nExpected: [10, 10, 10, 15, 15]\n";

    return 0;
}
