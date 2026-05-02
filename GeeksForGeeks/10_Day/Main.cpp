#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]\n";
}

int main() {
    Solution sol;
    
    // Example 1
    vector<int> a1 = {5, 2, 8};
    vector<int> b1 = {10, 7, 12};
    vector<int> c1 = {9, 14, 6};
    
    cout << "Example 1:\n";
    cout << "Input: a = [5, 2, 8], b = [10, 7, 12], c = [9, 14, 6]\n";
    cout << "Output: ";
    printVector(sol.smallestDiff(a1, b1, c1));
    cout << "Expected: [7, 6, 5]\n\n";

    // Example 2
    vector<int> a2 = {15, 12, 18, 9};
    vector<int> b2 = {10, 17, 13, 8};
    vector<int> c2 = {14, 16, 11, 5};
    
    cout << "Example 2:\n";
    cout << "Input: a = [15, 12, 18, 9], b = [10, 17, 13, 8], c = [14, 16, 11, 5]\n";
    cout << "Output: ";
    printVector(sol.smallestDiff(a2, b2, c2));
    cout << "Expected: [11, 10, 9]\n\n";

    return 0;
}
