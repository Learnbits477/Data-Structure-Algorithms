#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution solution;
    
    // Example 1
    vector<vector<int>> grid1 = {
        {2, 4, 3},
        {6, 5, 2}
    };
    cout << "Example 1 Input: grid = [[2,4,3],[6,5,2]]" << endl;
    cout << "Output: " << (solution.hasValidPath(grid1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;

    // Example 2
    vector<vector<int>> grid2 = {
        {1, 2, 1},
        {1, 2, 1}
    };
    cout << "Example 2 Input: grid = [[1,2,1],[1,2,1]]" << endl;
    cout << "Output: " << (solution.hasValidPath(grid2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;

    // Example 3
    vector<vector<int>> grid3 = {
        {1, 1, 2}
    };
    cout << "Example 3 Input: grid = [[1,1,2]]" << endl;
    cout << "Output: " << (solution.hasValidPath(grid3) ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;

    return 0;
}
