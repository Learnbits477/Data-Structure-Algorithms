#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    void addVal(int v, int& top1, int& top2, int& top3) {
        if (v == top1 || v == top2 || v == top3) return;
        if (v > top1) {
            top3 = top2;
            top2 = top1;
            top1 = v;
        } else if (v > top2) {
            top3 = top2;
            top2 = v;
        } else if (v > top3) {
            top3 = v;
        }
    }

public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // d1: Top-Left to Bottom-Right (\)
        // d1[i][j] = grid[i][j] + (i>0 && j>0 ? d1[i-1][j-1] : 0)
        vector<vector<int>> d1(m, vector<int>(n, 0));
        // d2: Top-Right to Bottom-Left (/)
        // d2[i][j] = grid[i][j] + (i>0 && j+1<n ? d2[i-1][j+1] : 0)
        vector<vector<int>> d2(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                d1[i][j] = grid[i][j] + (i > 0 && j > 0 ? d1[i - 1][j - 1] : 0);
                d2[i][j] = grid[i][j] + (i > 0 && j + 1 < n ? d2[i - 1][j + 1] : 0);
            }
        }
        
        int top1 = 0, top2 = 0, top3 = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                addVal(grid[i][j], top1, top2, top3);
                
                for (int L = 1; i - L >= 0 && i + L < m && j - L >= 0 && j + L < n; ++L) {
                    
                    // The 4 corners are:
                    // Top: (i-L, j)
                    // Right: (i, j+L)
                    // Bottom: (i+L, j)
                    // Left: (i, j-L)
                    
                    // 1. Top to Right (d1). Endpoint at (i, j+L). Starts at (i-L+1, j+1).
                    // Length = L.
                    int top_right = d1[i][j + L] - (i - L >= 0 && j > 0 ? d1[i - L][j] : 0);
                    
                    // 2. Right to Bottom (d2). Endpoint at (i+L, j). Starts at (i+1, j+L-1).
                    // Length = L.
                    int right_bottom = d2[i + L][j] - (i >= 0 && j + L < n ? d2[i][j + L] : 0);
                    
                    // 3. Bottom to Left (d1). Endpoint at (i+L-1, j-1). Starts at (i, j-L).
                    // Length = L.
                    int bottom_left = d1[i + L - 1][j - 1] - (i - 1 >= 0 && j - L - 1 >= 0 ? d1[i - 1][j - L - 1] : 0);
                    
                    // 4. Left to Top (d2). Endpoint at (i-1, j-L+1). Starts at (i-L, j).
                    // Length = L.
                    int left_top = d2[i - 1][j - L + 1] - (i - L - 1 >= 0 && j + 1 < n ? d2[i - L - 1][j + 1] : 0);
                    
                    int current_sum = top_right + right_bottom + bottom_left + left_top;
                    
                    addVal(current_sum, top1, top2, top3);
                }
            }
        }
        
        vector<int> result;
        if (top1 > 0) result.push_back(top1);
        if (top2 > 0) result.push_back(top2);
        if (top3 > 0) result.push_back(top3);
        return result;
    }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i == vec.size() - 1 ? "" : ",");
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    vector<vector<int>> grid1 = {
        {3, 4, 5, 1, 3},
        {3, 3, 4, 2, 3},
        {20, 30, 200, 40, 10},
        {1, 5, 5, 4, 1},
        {4, 3, 2, 2, 5}
    };
    cout << "Example 1 Output: ";
    printVector(sol.getBiggestThree(grid1));
    
    vector<vector<int>> grid2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Example 2 Output: ";
    printVector(sol.getBiggestThree(grid2));
    
    vector<vector<int>> grid3 = {
        {7, 7, 7}
    };
    cout << "Example 3 Output: ";
    printVector(sol.getBiggestThree(grid3));
    
    return 0;
}
