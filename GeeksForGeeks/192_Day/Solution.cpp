#include <vector>

using namespace std;

class Solution {
public:
    int countFriendsPairings(int n) {
        if (n <= 2) return n;
        
        long long a = 1; // f(n-2)
        long long b = 2; // f(n-1)
        long long mod = 1e9 + 7;
        
        for (int i = 3; i <= n; i++) {
            long long current = (b + (i - 1) * a) % mod;
            a = b;
            b = current;
        }
        return b;
    }
};
