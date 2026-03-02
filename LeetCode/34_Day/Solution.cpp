#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n, 0);
        
        // Count trailing zeros for each row
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) {
                    count++;
                } else {
                    break;
                }
            }
            zeros[i] = count;
        }

        int swaps = 0;
        
        // Find and swap rows to satisfy the condition
        for (int i = 0; i < n; ++i) {
            int target = n - 1 - i;
            int j = i;
            
            // Find the first row that has enough trailing zeros
            while (j < n && zeros[j] < target) {
                j++;
            }
            
            // If no such row is found, it's impossible
            if (j == n) {
                return -1;
            }
            
            // Bubble the found row up to the i-th position
            while (j > i) {
                swap(zeros[j], zeros[j - 1]);
                swaps++;
                j--;
            }
        }
        
        return swaps;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid1 = {{0,0,1},{1,1,0},{1,0,0}};
    cout << "Example 1 Output: " << sol.minSwaps(grid1) << endl;
    
    vector<vector<int>> grid2 = {{0,1,1,0},{0,1,1,0},{0,1,1,0},{0,1,1,0}};
    cout << "Example 2 Output: " << sol.minSwaps(grid2) << endl;
    
    vector<vector<int>> grid3 = {{1,0,0},{1,1,0},{1,1,1}};
    cout << "Example 3 Output: " << sol.minSwaps(grid3) << endl;

    return 0;
}
