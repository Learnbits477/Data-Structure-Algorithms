#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void runTest(vector<int>& cost, int expected) {
    Solution sol;
    int result = sol.minimumCost(cost);
    
    cout << "Input: cost = [";
    for (size_t i = 0; i < cost.size(); ++i) {
        cout << cost[i] << (i == cost.size() - 1 ? "" : ", ");
    }
    cout << "]\n";
    
    cout << "Expected Output: " << expected << "\n";
    cout << "Actual Output:   " << result << "\n";
    
    if (result == expected) {
        cout << "✅ PASSED\n\n";
    } else {
        cout << "❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🔢 Minimum Cost of Buying Candies With Discount — Test Suite\n\n";
    
    // Example 1
    vector<int> cost1 = {1, 2, 3};
    runTest(cost1, 5);
    
    // Example 2
    vector<int> cost2 = {6, 5, 7, 9, 2, 2};
    runTest(cost2, 23);
    
    // Example 3
    vector<int> cost3 = {5, 5};
    runTest(cost3, 10);
    
    // Additional Edge Cases
    vector<int> cost4 = {10, 10, 10};
    runTest(cost4, 20);
    
    vector<int> cost5 = {1};
    runTest(cost5, 1);
    
    return 0;
}
