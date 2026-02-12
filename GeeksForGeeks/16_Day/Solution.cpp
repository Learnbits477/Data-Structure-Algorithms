#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(long long target, int k, int w, const vector<int>& arr) {
        int n = arr.size();
        vector<long long> diff(n + 1, 0);
        long long current_add = 0;
        int days_needed = 0;

        for (int i = 0; i < n; ++i) {
            current_add += diff[i];
            long long current_height = arr[i] + current_add;

            if (current_height < target) {
                long long needed = target - current_height;
                if (days_needed + needed > k) return false;

                days_needed += needed;
                current_add += needed;
                
                if (i + w < n) {
                    diff[i + w] -= needed;
                } else {
                     if (i + w < n + 1) diff[i + w] -= needed; 
                }
                
                k -= needed; 
            }
        }
        return true;
    }

    // Refined check function
    bool isPossible(long long target, int k, int w, vector<int>& arr) {
        int n = arr.size();
        vector<long long> diff(n + 1, 0); // To store when effects wear off
        long long current_water = 0;
        int used_k = 0; 
                        
        // The checking logic:
        long long water_supply = 0;
        long long k_remaining = k;
        
        for(int i=0; i<n; ++i) {
            water_supply += diff[i];
            long long current_val = arr[i] + water_supply;
            
            if(current_val < target) {
                long long needed = target - current_val;
                if(needed > k_remaining) return false;
                
                water_supply += needed;
                k_remaining -= needed;
                
                if(i + w < n) {
                    diff[i + w] -= needed;
                }
            }
        }
        return true;
    }

    long long maxMinHeight(vector<int>& arr, int k, int w) {
        int n = arr.size();
        long long min_h = *min_element(arr.begin(), arr.end());
        long long max_h = *max_element(arr.begin(), arr.end()) + k;
        long long ans = min_h;

        while (min_h <= max_h) {
            long long mid = min_h + (max_h - min_h) / 2;
            if (isPossible(mid, k, w, arr)) {
                ans = mid;
                min_h = mid + 1;
            } else {
                max_h = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> arr1 = {2, 3, 4, 5, 1};
    int k1 = 2;
    int w1 = 2;
    cout << "Test 1: " << sol.maxMinHeight(arr1, k1, w1) << " Expected: 2" << endl;

    // Example 2
    vector<int> arr2_vec = {5, 8};
    int k2 = 5;
    int w2 = 1;
    cout << "Test 2: " << sol.maxMinHeight(arr2_vec, k2, w2) << " Expected: 9" << endl;

    return 0;
}
