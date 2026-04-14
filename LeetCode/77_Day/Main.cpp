#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution solution;

    // Example 1
    vector<int> robot1 = {0, 4, 6};
    vector<vector<int>> factory1 = {{2, 2}, {6, 2}};
    cout << "Example 1 Output: " << solution.minimumTotalDistance(robot1, factory1) << " (Expected: 4)" << endl;

    // Example 2
    vector<int> robot2 = {1, -1};
    vector<vector<int>> factory2 = {{-2, 1}, {2, 1}};
    cout << "Example 2 Output: " << solution.minimumTotalDistance(robot2, factory2) << " (Expected: 2)" << endl;

    return 0;
}
