#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> result;
        deque<int> dq;
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            // Remove elements out of the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove elements smaller than the current element from the back
            // as they will not be the maximum anymore
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            // Add current element's index
            dq.push_back(i);

            // Add maximum element of current window to result
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }

        return result;
    }
};
