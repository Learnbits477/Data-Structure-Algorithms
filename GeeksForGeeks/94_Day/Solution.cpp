#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result(n);

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < n; i++) {
            minHeap.push(arr[i]);

            if ((int)minHeap.size() > k)
                minHeap.pop();

            if ((int)minHeap.size() < k)
                result[i] = -1;
            else
                result[i] = minHeap.top();
        }

        return result;
    }
};
