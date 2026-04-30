#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isMaxHeap(vector<int>& arr) {
        int n = arr.size();

        if (n <= 1) return true;

        for (int i = 0; i <= (n / 2) - 1; i++) {
            int left  = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[i] < arr[left])
                return false;

            if (right < n && arr[i] < arr[right])
                return false;
        }

        return true;   
    }
};

