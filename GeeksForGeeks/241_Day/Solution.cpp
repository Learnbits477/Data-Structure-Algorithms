#include <bits/stdc++.h>
using namespace std;

// Representation of a box with height, normalized width, and normalized length
struct Box {
    int h; // Height
    int w; // Width  (w <= l)
    int l; // Length (l >= w)
};

class Solution {
public:
    // Core function to find the maximum possible height of the box stack
    int maxHeight(vector<int>& height, vector<int>& width, vector<int>& length) {
        int n = height.size();
        if (n == 0) return 0;

        vector<Box> boxes;
        boxes.reserve(3 * n);

        // Step 1: Generate all 3 valid rotations for each box
        // We normalize the base dimensions so that width <= length
        for (int i = 0; i < n; ++i) {
            // Orientation 1: height[i] as height
            boxes.push_back({height[i], min(width[i], length[i]), max(width[i], length[i])});

            // Orientation 2: width[i] as height
            boxes.push_back({width[i], min(height[i], length[i]), max(height[i], length[i])});

            // Orientation 3: length[i] as height
            boxes.push_back({length[i], min(height[i], width[i]), max(height[i], width[i])});
        }

        // Step 2: Sort boxes in descending order of base area (width * length)
        // Tie-breaking: length descending, then width descending
        sort(boxes.begin(), boxes.end(), [](const Box& a, const Box& b) {
            long long areaA = 1LL * a.w * a.l;
            long long areaB = 1LL * b.w * b.l;
            if (areaA != areaB) {
                return areaA > areaB;
            }
            if (a.l != b.l) {
                return a.l > b.l;
            }
            return a.w > b.w;
        });

        int totalBoxes = boxes.size();
        // dp[i] stores the maximum stack height possible with boxes[i] at the top
        vector<int> dp(totalBoxes);
        int maxStackHeight = 0;

        // Step 3: Compute LIS-based DP transitions
        for (int i = 0; i < totalBoxes; ++i) {
            dp[i] = boxes[i].h; // Base case: box i alone

            for (int j = 0; j < i; ++j) {
                // Box i can be placed on top of Box j if both base dimensions are strictly smaller
                if (boxes[i].w < boxes[j].w && boxes[i].l < boxes[j].l) {
                    dp[i] = max(dp[i], dp[j] + boxes[i].h);
                }
            }

            maxStackHeight = max(maxStackHeight, dp[i]);
        }

        return maxStackHeight;
    }

    // Overload supporting raw array parameters (classic GFG signature)
    int maxHeight(int height[], int width[], int length[], int n) {
        vector<int> h(height, height + n);
        vector<int> w(width, width + n);
        vector<int> l(length, length + n);
        return maxHeight(h, w, l);
    }

    // Platform alias methods
    int maxStackHeight(vector<int>& height, vector<int>& width, vector<int>& length) {
        return maxHeight(height, width, length);
    }

    int boxStacking(vector<int>& height, vector<int>& width, vector<int>& length) {
        return maxHeight(height, width, length);
    }
};
