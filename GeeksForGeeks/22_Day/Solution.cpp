#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to count inversions in the array.
    long long int inversionCount(vector<int> &arr) {
        long long int count = 0;
        int n = arr.size();
        if (n <= 1) return 0;
        
        vector<int> temp(n);
        count = mergeSort(arr, temp, 0, n - 1);
        return count;
    }

private:
    long long int merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right) {
        long long int count = 0;
        int i = left;    // Index for left subarray
        int j = mid + 1; // Index for right subarray
        int k = left;    // Index for temp array

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                // arr[i] > arr[j], so (mid - i + 1) inversions
                temp[k++] = arr[j++];
                count += (mid - i + 1);
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }

        return count;
    }

    long long int mergeSort(vector<int> &arr, vector<int> &temp, int left, int right) {
        long long int count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            count += mergeSort(arr, temp, left, mid);
            count += mergeSort(arr, temp, mid + 1, right);
            count += merge(arr, temp, left, mid, right);
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {2, 4, 1, 3, 5};
    cout << "Example 1 Input: [2, 4, 1, 3, 5]" << endl;
    cout << "Example 1 Output: " << sol.inversionCount(arr1) << endl; 
    // Expected: 3

    // Example 2
    vector<int> arr2 = {2, 3, 4, 5, 6};
    cout << "Example 2 Input: [2, 3, 4, 5, 6]" << endl;
    cout << "Example 2 Output: " << sol.inversionCount(arr2) << endl;
    // Expected: 0

    // Example 3
    vector<int> arr3 = {10, 10, 10};
    cout << "Example 3 Input: [10, 10, 10]" << endl;
    cout << "Example 3 Output: " << sol.inversionCount(arr3) << endl;
    // Expected: 0

    return 0;
}
