#include <iostream>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printResult(bool res) {
    cout << (res ? "true" : "false") << endl;
}

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> mat1 = {
        {6, 7, 8},
        {4, 6, 7},
        {1, 4, 6}
    };
    cout << "Example 1 Output: ";
    printResult(sol.isToeplitz(mat1)); // Expected: true

    // Example 2
    vector<vector<int>> mat2 = {
        {6, 3, 8},
        {4, 9, 7},
        {1, 4, 6}
    };
    cout << "Example 2 Output: ";
    printResult(sol.isToeplitz(mat2)); // Expected: false

    return 0;
}
