#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int minWorker = workerTimes[0];
        for (int w : workerTimes) {
            if (w < minWorker) minWorker = w;
        }
        
        long long low = 0;
        long long high = (long long)minWorker * mountainHeight * (mountainHeight + 1) / 2;
        long long ans = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long total = 0;
            
            for (int w : workerTimes) {
                long long val = mid / w;
                // If this worker can do all the work alone
                if (val >= (long long)mountainHeight * (mountainHeight + 1) / 2) {
                    total += mountainHeight;
                } else {
                    // Quadratic formula to find max x: x(x+1)/2 <= mid/w  =>  x(x+1) <= 2*val
                    long long x = (sqrt(1.0 + 8.0 * val) - 1.0) / 2.0;
                    
                    // Fine tune to prevent any floating point precision errors
                    while (x * (x + 1) / 2 > val) {
                        x--;
                    }
                    while ((x + 1) * (x + 2) / 2 <= val) {
                        x++;
                    }
                    total += x;
                }
                
                // Early break if the goal is met
                if (total >= mountainHeight) {
                    break;
                }
            }
            
            if (total >= mountainHeight) {
                ans = mid;
                high = mid - 1; // Try to find a smaller feasible time
            } else {
                low = mid + 1;  // Not feasible, require more time
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> workerTimes = {2, 1, 1};
    cout << sol.minNumberOfSeconds(4, workerTimes) << endl; // Output should be 3
    
    vector<int> workerTimes2 = {3, 2, 2, 4};
    cout << sol.minNumberOfSeconds(10, workerTimes2) << endl; // Output should be 12
    
    vector<int> workerTimes3 = {1};
    cout << sol.minNumberOfSeconds(5, workerTimes3) << endl; // Output should be 15
    return 0;
}
