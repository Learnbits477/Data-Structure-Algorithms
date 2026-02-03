#include <iostream>
#include <vector>
#include <cassert>
#define SKIP_SOLUTION_MAIN // Tell Solution.cpp to skip its main function
#include "Solution.cpp"

using namespace std;

void runTest(vector<int> prices, int expected) {
    Solution sol;
    int result = sol.maxProfit(prices);
    cout << "Prices: {";
    for (size_t i = 0; i < prices.size(); ++i) {
        cout << prices[i] << (i < prices.size() - 1 ? ", " : "");
    }
    cout << "} -> Expected: " << expected << ", Got: " << result << endl;
    assert(result == expected);
}

int main() {
    // Example 1
    runTest({7, 10, 1, 3, 6, 9, 2}, 8);

    // Example 2
    runTest({7, 6, 4, 3, 1}, 0);

    // Example 3
    runTest({1, 3, 6, 9, 11}, 10);
    
    // Additional test cases
    runTest({2, 4, 1}, 2); // Buy at 2, sell at 4 (profit 2). Buying at 1 comes after.
    runTest({3, 2, 6, 5, 0, 3}, 4); // Buy at 2, sell at 6 (profit 4).

    cout << "All tests passed!" << endl;
    return 0;
}
