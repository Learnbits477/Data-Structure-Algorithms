#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    long long maxProfit(int x, int y, vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> diffs(n);
        long long totalProfit = 0;

        for (int i = 0; i < n; ++i) {
            totalProfit += b[i];
            diffs[i] = a[i] - b[i];
        }

        sort(diffs.begin(), diffs.end(), greater<int>());

        int minA = max(0, n - y);
        int maxA = x;

        int i = 0;
        for (; i < minA; ++i) {
            totalProfit += diffs[i];
        }

        for (; i < maxA && i < n; ++i) {
            if (diffs[i] > 0) {
                totalProfit += diffs[i];
            } else {
                break;
            }
        }

        return totalProfit;
    }
};
