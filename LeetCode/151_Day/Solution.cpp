#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // Step 1: Compute Frequency Map
        unordered_map<long long, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        int max_len = 0;
        
        // Step 2: Handle Edge Case of Ones
        if (freq.count(1)) {
            int count1 = freq[1];
            max_len = count1 % 2 == 0 ? count1 - 1 : count1;
        }
        
        // Step 3: Simulate Chain for Elements > 1
        for (auto& pair : freq) {
            long long x = pair.first;
            if (x == 1) continue;
            
            long long temp = x;
            int current_length = 0;
            while (true) {
                // If we have >= 2 of temp, and its square is in freq, we can continue the chain
                if (temp <= 100000 && freq[temp] >= 2 && freq.count(temp * temp)) {
                    current_length += 2;
                    temp = temp * temp;
                } else {
                    // Otherwise, temp must be the peak of the chain (requires only 1 copy)
                    current_length += 1;
                    break;
                }
            }
            max_len = max(max_len, current_length);
        }
        
        // Step 4: Return Result
        return max_len;
    }
};
