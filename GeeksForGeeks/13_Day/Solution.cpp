#include <vector>

using namespace std;

class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;
        
        // If the array is not rotated at all
        if (arr[low] <= arr[high]) return 0;

        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // If mid element is strictly greater than the high element,
            // the minimum element must be in the right half.
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                // Otherwise, the minimum element is in the left half,
                // or mid itself is the minimum.
                high = mid;
            }
        }
        
        // The index of the minimum element corresponds to the number of right rotations
        return low;
    }
};
