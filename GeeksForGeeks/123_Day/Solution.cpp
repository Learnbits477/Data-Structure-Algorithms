#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void replaceElements(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Save original first element as left-neighbour sentinel
        int prev = arr[0];

        // Step 2: Update first element (only one neighbour: arr[1])
        arr[0] = arr[0] ^ arr[1];

        // Step 3: Update middle elements using saved prev and untouched arr[i+1]
        for (int i = 1; i <= n - 2; i++) {
            int temp = arr[i];
            arr[i] = prev ^ arr[i + 1];
            prev = temp;
        }

        // Step 4: Update last element (only one neighbour: prev = original arr[n-2])
        arr[n - 1] = prev ^ arr[n - 1];
    }
};
