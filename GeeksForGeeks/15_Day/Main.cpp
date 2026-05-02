#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution sol;
    
    // Example 1
    vector<int> h1 = {1, 2, 3};
    vector<int> cost1 = {10, 100, 1000};
    cout << "Example 1:\n";
    cout << "Input: heights = [1, 2, 3], cost = [10, 100, 1000]\n";
    cout << "Output: " << sol.minCost(h1, cost1) << "\n";
    cout << "Expected: 120\n\n";

    // Example 2
    vector<int> h2 = {7, 1, 5};
    vector<int> cost2 = {1, 1, 1};
    cout << "Example 2:\n";
    cout << "Input: heights = [7, 1, 5], cost = [1, 1, 1]\n";
    cout << "Output: " << sol.minCost(h2, cost2) << "\n";
    cout << "Expected: 6\n\n";

    return 0;
}
