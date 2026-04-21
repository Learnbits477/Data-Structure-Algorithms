#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void test(vector<int> source, vector<int> target, vector<vector<int>> swaps, int expected) {
    Solution sol;
    int result = sol.minimumHammingDistance(source, target, swaps);
    cout << "Expected: " << expected << ", Result: " << result;
    if (result == expected) {
        cout << " [PASSED]" << endl;
    } else {
        cout << " [FAILED]" << endl;
    }
}

int main() {
    cout << "Running Tests..." << endl;
    
    // Example 1
    test({1,2,3,4}, {2,1,4,5}, {{0,1},{2,3}}, 1);
    
    // Example 2
    test({1,2,3,4}, {1,3,2,4}, {}, 2);
    
    // Example 3
    test({5,1,2,4,3}, {1,5,4,2,3}, {{0,4},{4,2},{1,3},{1,4}}, 0);
    
    return 0;
}
