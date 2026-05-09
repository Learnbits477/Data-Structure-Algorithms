#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int numLayers = min(m, n) / 2;

        for (int layer = 0; layer < numLayers; ++layer) {
            // Boundaries for the current layer
            int r1 = layer, c1 = layer;
            int r2 = m - 1 - layer, c2 = n - 1 - layer;

            // 1. Extract elements of the layer in counter-clockwise order
            vector<int> elements;
            
            // Top row (left to right) - wait, counter-clockwise means:
            // Top row: (r1, c1) to (r1, c2-1)
            // Left col: (r1, c1) to (r2-1, c1)
            // Bottom row: (r2, c1) to (r2, c2-1)
            // Right col: (r1+1, c2) to (r2, c2)
            
            // Standard counter-clockwise path starting from top-left:
            // Top: (r1, c1) -> (r1, c2)
            // Right: (r1+1, c2) -> (r2, c2)
            // Bottom: (r2, c2-1) -> (r2, c1)
            // Left: (r2-1, c1) -> (r1+1, c1)
            
            // Let's use a simpler path:
            for (int j = c1; j < c2; ++j) elements.push_back(grid[r1][j]); // Top
            for (int i = r1; i < r2; ++i) elements.push_back(grid[i][c2]); // Right
            for (int j = c2; j > c1; --j) elements.push_back(grid[r2][j]); // Bottom
            for (int i = r2; i > r1; --i) elements.push_back(grid[i][c1]); // Left

            int len = elements.size();
            int netK = k % len;

            // 2. Rotate elements 1D vector
            // To rotate counter-clockwise by k, the element at index i moves to (i - k + len) % len
            // Or use std::rotate: rotate(elements.begin(), elements.begin() + netK, elements.end())
            rotate(elements.begin(), elements.begin() + netK, elements.end());

            // 3. Put elements back into the grid
            int idx = 0;
            for (int j = c1; j < c2; ++j) grid[r1][j] = elements[idx++];
            for (int i = r1; i < r2; ++i) grid[i][c2] = elements[idx++];
            for (int j = c2; j > c1; --j) grid[r2][j] = elements[idx++];
            for (int i = r2; i > r1; --i) grid[i][c1] = elements[idx++];
        }

        return grid;
    }
};
