#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Solution.cpp"

void printBox(const vector<vector<char>>& box) {
    for (const auto& row : box) {
        cout << "[ ";
        for (char c : row) {
            cout << "'" << c << "' ";
        }
        cout << "]" << endl;
    }
}

int main() {
    Solution sol;

    // Test Case 1
    cout << "--- Test Case 1 ---" << endl;
    vector<vector<char>> box1 = {{'#', '.', '#'}};
    vector<vector<char>> result1 = sol.rotateTheBox(box1);
    printBox(result1);
    // Expected: [[.], [#], [#]]

    // Test Case 2
    cout << "\n--- Test Case 2 ---" << endl;
    vector<vector<char>> box2 = {
        {'#', '.', '*', '.'},
        {'#', '#', '*', '.'}
    };
    vector<vector<char>> result2 = sol.rotateTheBox(box2);
    printBox(result2);
    // Expected: [['#', '.'], ['#', '#'], ['*', '*'], ['.', '.']]

    // Test Case 3
    cout << "\n--- Test Case 3 ---" << endl;
    vector<vector<char>> box3 = {
        {'#', '#', '*', '.', '*', '.'},
        {'#', '#', '#', '*', '.', '.'},
        {'#', '#', '#', '.', '#', '.'}
    };
    vector<vector<char>> result3 = sol.rotateTheBox(box3);
    printBox(result3);

    return 0;
}

/**
 * 🔗 Quick Links
 * [Problem Statement](./Problem.md) | [Solution Code](./Solution.cpp) | [Approach / Logic](./Approach.md)
 */
