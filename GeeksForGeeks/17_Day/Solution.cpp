#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    long long sumDigits(long long n) {
        long long sum = 0;
        long long temp = n;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        return sum;
    }

public:
    long long getCount(long long n, long long d) {
        long long low = 1, high = n;
        long long ans = -1;

        // Binary Search
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid - sumDigits(mid) >= d) {
                ans = mid;
                high = mid - 1; // Try smaller value
            } else {
                low = mid + 1; // Need larger value
            }
        }

        if (ans != -1) {
            return n - ans + 1;
        } else {
            return 0;
        }
    }
};

int main() {
    Solution sol;
    
    // Example 1
    long long n1 = 13, d1 = 2;
    cout << "Input: n = " << n1 << ", d = " << d1 << " | Output: " << sol.getCount(n1, d1) << " | Expected: 4" << endl;

    // Example 2
    long long n2 = 14, d2 = 3;
    cout << "Input: n = " << n2 << ", d = " << d2 << " | Output: " << sol.getCount(n2, d2) << " | Expected: 5" << endl;

    // Edge Case: d > n
    long long n3 = 10, d3 = 20;
    cout << "Input: n = " << n3 << ", d = " << d3 << " | Output: " << sol.getCount(n3, d3) << " | Expected: 0" << endl;
    
    // Large N check (correctness not easily manually verified but ensures no crash)
    // 100 - sum(100) = 100 - 1 = 99. If d=90, then 100 should be counted.
    long long n4 = 100, d4 = 90;
    cout << "Input: n = " << n4 << ", d = " << d4 << " | Output: " << sol.getCount(n4, d4) << " | Expected: " << (100 - 100 + 1) << " (Wait, 99 is 99-18=81 < 90. 100 is 100-1=99 >= 90. So only 100 works?)" << endl;
    // Let's manually check 99: 99 - (9+9) = 99 - 18 = 81. < 90.
    // 100: 100 - 1 = 99 >= 90.
    // So for range [1, 100], only 100 works? No, let's verify monotonicity assumption.
    // 100: 99
    // 101: 101-2 = 99
    // Wait... 99 gives 81. 98 gives 98 - 17 = 81.
    // The function is monotonic.
    // So yes, answer should be 1.

    return 0;

}
