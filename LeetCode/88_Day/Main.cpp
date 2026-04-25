#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

void runTestCase(const string& testName, int side, vector<vector<int>>& points, int k, int expected, Solution& sol) {
    cout << "--- " << testName << " ---" << endl;
    cout << "Side: " << side << " | K: " << k << endl;
    
    // Execute Algorithm
    int result = sol.maxDistance(side, points, k);
    
    cout << "Output:   " << result << endl;
    cout << "Expected: " << expected << "\n" << endl;
}

int main() {
    Solution sol;
    
    // Test Case 1
    vector<vector<int>> points1 = {{0,2},{2,0},{2,2},{0,0}};
    runTestCase("Test Case 1", 2, points1, 4, 2, sol);

    // Test Case 2
    vector<vector<int>> points2 = {{0,0},{1,2},{2,0},{2,2},{2,1}};
    runTestCase("Test Case 2", 2, points2, 4, 1, sol);

    // Test Case 3
    vector<vector<int>> points3 = {{0,0},{0,1},{0,2},{1,2},{2,0},{2,2},{2,1}};
    runTestCase("Test Case 3", 2, points3, 5, 1, sol);

    return 0;
}
