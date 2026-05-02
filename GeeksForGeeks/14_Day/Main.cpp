#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution sol;
    
    // Example 1
    vector<int> piles1 = {5, 10, 3};
    int k1 = 4;
    cout << "Example 1:\n";
    cout << "Input: arr = [5, 10, 3], k = 4\n";
    cout << "Output: " << sol.kokoEat(piles1, k1) << "\n";
    cout << "Expected: 5\n\n";
    
    // Example 2
    vector<int> piles2 = {5, 10, 15, 20};
    int k2 = 7;
    cout << "Example 2:\n";
    cout << "Input: arr = [5, 10, 15, 20], k = 7\n";
    cout << "Output: " << sol.kokoEat(piles2, k2) << "\n";
    cout << "Expected: 10\n\n";

    return 0;
}
