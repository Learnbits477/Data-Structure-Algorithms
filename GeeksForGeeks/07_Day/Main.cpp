#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution sol;
    
    // Example 1
    vector<int> prices1 = {7, 10, 1, 3, 6, 9, 2};
    cout << "Example 1:\n";
    cout << "Input: prices = [7, 10, 1, 3, 6, 9, 2]\n";
    cout << "Output: " << sol.maxProfit(prices1) << "\n";
    cout << "Expected: 8\n\n";

    // Example 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Example 2:\n";
    cout << "Input: prices = [7, 6, 4, 3, 1]\n";
    cout << "Output: " << sol.maxProfit(prices2) << "\n";
    cout << "Expected: 0\n\n";

    // Example 3
    vector<int> prices3 = {1, 3, 6, 9, 11};
    cout << "Example 3:\n";
    cout << "Input: prices = [1, 3, 6, 9, 11]\n";
    cout << "Output: " << sol.maxProfit(prices3) << "\n";
    cout << "Expected: 10\n\n";

    return 0;
}
