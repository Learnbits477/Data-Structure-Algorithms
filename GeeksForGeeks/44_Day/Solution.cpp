#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        int flipped = 0, res = 0;
        vector<int> isFlipped(n, 0);

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flipped ^= isFlipped[i - k];
            }
            if (arr[i] == flipped) {
                if (i + k > n) {
                    return -1;
                }
                isFlipped[i] = 1;
                flipped ^= 1;
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1};
    int k1 = 2;
    cout << "Output: " << sol.kBitFlips(arr1, k1) << endl; // Expected: 4
    
    vector<int> arr2 = {0, 0, 1, 1, 1, 0, 0};
    int k2 = 3;
    cout << "Output: " << sol.kBitFlips(arr2, k2) << endl; // Expected: -1
    
    return 0;
}
