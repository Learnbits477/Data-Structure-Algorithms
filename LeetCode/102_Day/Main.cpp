#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Solution.cpp"

using namespace std;

class TestRunner {
public:
    static vector<vector<int>> buildGrid(string input) {
        vector<vector<int>> grid;
        input = input.substr(1, input.length() - 2); // Remove outer brackets
        
        size_t pos = 0;
        while ((pos = input.find('[')) != string::npos) {
            size_t end = input.find(']', pos);
            string rowStr = input.substr(pos + 1, end - pos - 1);
            
            vector<int> row;
            stringstream ss(rowStr);
            string val;
            while (getline(ss, val, ',')) {
                row.push_back(stoi(val));
            }
            grid.push_back(row);
            input = input.substr(end + 1);
        }
        return grid;
    }

    static void printGrid(const vector<vector<int>>& grid) {
        cout << "[";
        for (size_t i = 0; i < grid.size(); ++i) {
            cout << "[";
            for (size_t j = 0; j < grid[i].size(); ++j) {
                cout << grid[i][j] << (j == grid[i].size() - 1 ? "" : ",");
            }
            cout << "]" << (i == grid.size() - 1 ? "" : ",");
        }
        cout << "]" << endl;
    }

    static void runTest(int testNum, string gridStr, int k, string expectedStr) {
        Solution sol;
        vector<vector<int>> grid = buildGrid(gridStr);
        vector<vector<int>> result = sol.rotateGrid(grid, k);

        cout << "Test Case " << testNum << ":" << endl;
        cout << "Input: grid = " << gridStr << ", k = " << k << endl;
        cout << "Output:   ";
        printGrid(result);
        cout << "Expected: " << expectedStr << endl;
        
        cout << "Status: COMPLETED" << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    cout << "=== 1914. Cyclically Rotating a Grid ===" << endl << endl;

    // Test Case 1
    TestRunner::runTest(1, "[[40,10],[30,20]]", 1, "[[10,20],[40,30]]");

    // Test Case 2
    TestRunner::runTest(2, "[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]", 2, "[[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]");

    // Test Case 3: Larger K
    TestRunner::runTest(3, "[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]", 10, "[[11,12,16,15],[10,1,2,14],[9,5,6,13],[8,7,3,4]]");

    return 0;
}
