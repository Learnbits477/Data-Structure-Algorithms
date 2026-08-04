#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int count = 0;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            while (arr[right] - arr[left] >= k) {
                left++;
            }
            count += (right - left);
        }
        
        return count;
    }
};
