#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution sol;
    
    // Example 1
    int n1 = 4;
    vector<int> left1 = {4, 3};
    vector<int> right1 = {0, 1};
    cout << "Example 1:\n";
    cout << "Input: n = 4, left = [4, 3], right = [0, 1]\n";
    cout << "Output: " << sol.getLastMoment(n1, left1, right1) << "\n";
    cout << "Expected: 4\n\n";

    // Example 2
    int n2 = 7;
    vector<int> left2 = {};
    vector<int> right2 = {0, 1, 2, 3, 4, 5, 6, 7};
    cout << "Example 2:\n";
    cout << "Input: n = 7, left = [], right = [0, 1, 2, 3, 4, 5, 6, 7]\n";
    cout << "Output: " << sol.getLastMoment(n2, left2, right2) << "\n";
    cout << "Expected: 7\n\n";

    return 0;
}
