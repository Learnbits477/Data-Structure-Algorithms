#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kokoEat(vector<int>& piles, int H) {
        int low = 1;
        int high = 0;
        
        // The maximum possible eating speed we would ever need is the largest pile.
        // Eating any faster wouldn't save any hours, since Koko can only eat from one pile per hour.
        for (int p : piles) {
            high = max(high, p);
        }
        
        int ans = high;
        
        // Binary search for the minimum viable eating speed
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = 0;
            
            // Calculate total hours required if Koko eats 'mid' bananas per hour
            for (int p : piles) {
                // Equivalent to ceil((double)p / mid) but done cleanly with integers
                hours += (long long)(p + mid - 1) / mid;
            }
            
            // If Koko can finish within H hours, this is a valid speed.
            // Try to find a smaller valid speed by searching the left half.
            if (hours <= H) {
                ans = mid;
                high = mid - 1;
            } 
            // If it takes too long, Koko needs to eat faster. Search the right half.
            else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
