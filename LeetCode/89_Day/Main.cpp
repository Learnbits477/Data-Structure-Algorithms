#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

void printGrid(const vector<vector<char>>& grid) {
    for (const auto& row : grid) {
        cout << "[";
        for (size_t i = 0; i < row.size(); ++i) {
            cout << "'" << row[i] << "'" << (i == row.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }
}

int main() {
    Solution solution;
    
    vector<vector<char>> grid1 = {
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'}
    };
    cout << "Test Case 1 Grid:" << endl;
    printGrid(grid1);
    cout << "Output: " << (solution.containsCycle(grid1) ? "true" : "false") << "\n\n";

    vector<vector<char>> grid2 = {
        {'c', 'c', 'c', 'a'},
        {'c', 'd', 'c', 'c'},
        {'c', 'c', 'e', 'c'},
        {'f', 'c', 'c', 'c'}
    };
    cout << "Test Case 2 Grid:" << endl;
    printGrid(grid2);
    cout << "Output: " << (solution.containsCycle(grid2) ? "true" : "false") << "\n\n";

    vector<vector<char>> grid3 = {
        {'a', 'b', 'b'},
        {'b', 'z', 'b'},
        {'b', 'b', 'a'}
    };
    cout << "Test Case 3 Grid:" << endl;
    printGrid(grid3);
    cout << "Output: " << (solution.containsCycle(grid3) ? "true" : "false") << "\n\n";

    return 0;
}
