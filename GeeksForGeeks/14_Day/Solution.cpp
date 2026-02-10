#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int kokoEat(vector<int>& piles, int H) {
        int low = 1;
        int high = 0;
        for(int p : piles) high = max(high, p);
        
        int ans = high;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = 0;
            
            for(int p : piles) {
                // ceil(p / mid) is calculated as (p + mid - 1) / mid
                hours += (long long)(p + mid - 1) / mid;
            }
            
            if(hours <= H) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> piles1 = {5, 10, 3};
    int k1 = 4;
    cout << "Example 1: " << sol.kokoEat(piles1, k1) << " Expected: 5" << endl;
    
    // Example 2
    vector<int> piles2 = {5, 10, 15, 20};
    int k2 = 7;
    cout << "Example 2: " << sol.kokoEat(piles2, k2) << " Expected: 10" << endl;
    
    return 0;
}
