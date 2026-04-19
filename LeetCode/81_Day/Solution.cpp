#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        long long original_n = n;
        long long reverse_n = 0;
        long long temp = n;

        // Reverse the digits of n
        while (temp > 0) {
            reverse_n = reverse_n * 10 + (temp % 10);
            temp /= 10;
        }

        // Return the absolute difference
        return abs(original_n - reverse_n);
    }
};
