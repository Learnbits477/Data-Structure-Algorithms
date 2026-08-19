#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved;
        
        // Step 1: Bitmask Representation
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                reserved[row] |= (1 << col);
            }
        }
        
        // Step 2: Initial Answer for unreserved rows
        int ans = 2 * (n - (int)reserved.size());
        
        // Step 3: Evaluate each reserved row
        for (const auto& pair : reserved) {
            int mask = pair.second;
            bool left = (mask & 60) == 0;
            bool right = (mask & 960) == 0;
            bool middle = (mask & 240) == 0;
            
            if (left && right) {
                ans += 2;
            } else if (left || right || middle) {
                ans += 1;
            }
        }
        
        // Step 4: Return Result
        return ans;
    }
};
