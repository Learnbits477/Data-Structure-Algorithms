#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int computeDigitSum(int val) {
        int sum = 0;
        while (val > 0) {
            sum += val % 10;
            val /= 10;
        }
        return sum;
    }

    struct Element {
        int digitSum;
        int value;
        int origIndex;
    };

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }

        // Step: 01 - Compute digit sums and associate each element with its original index
        vector<Element> items(n);
        for (int i = 0; i < n; ++i) {
            items[i] = {computeDigitSum(nums[i]), nums[i], i};
        }

        // Step: 02 - Sort elements by digit sum ascending, breaking ties by numeric value
        sort(items.begin(), items.end(), [](const Element& a, const Element& b) {
            if (a.digitSum != b.digitSum) {
                return a.digitSum < b.digitSum;
            }
            return a.value < b.value;
        });

        // Step: 03 - Trace disjoint permutation cycles using a visited tracking array
        vector<bool> visited(n, false);
        int totalSwaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || items[i].origIndex == i) {
                continue;
            }

            int cycleSize = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = items[curr].origIndex;
                cycleSize++;
            }

            // Step: 04 - Accumulate required swaps for each cycle of length L
            if (cycleSize > 1) {
                totalSwaps += (cycleSize - 1);
            }
        }

        // Step: 05 - Return minimal swap count to achieve sorted order
        return totalSwaps;
    }

    int minSwapsSimulation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }

        // Step: 01 - Compute digit sums and build destination mapping
        vector<Element> items(n);
        for (int i = 0; i < n; ++i) {
            items[i] = {computeDigitSum(nums[i]), nums[i], i};
        }

        sort(items.begin(), items.end(), [](const Element& a, const Element& b) {
            if (a.digitSum != b.digitSum) {
                return a.digitSum < b.digitSum;
            }
            return a.value < b.value;
        });

        vector<int> targetPos(n);
        for (int i = 0; i < n; ++i) {
            targetPos[items[i].origIndex] = i;
        }

        // Step: 02 - Simulate in-place swaps to count operations directly
        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            while (targetPos[i] != i) {
                int nextIdx = targetPos[i];
                swap(targetPos[i], targetPos[nextIdx]);
                swaps++;
            }
        }

        // Step: 03 - Return simulated swap count
        return swaps;
    }
};
