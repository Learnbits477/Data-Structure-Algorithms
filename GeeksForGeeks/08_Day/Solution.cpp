#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        
        // Ants moving to the left take 'pos' time to reach the left end (0)
        for (int pos : left) {
            ans = max(ans, pos);
        }
        
        // Ants moving to the right take 'n - pos' time to reach the right end (n)
        for (int pos : right) {
            ans = max(ans, n - pos);
        }
        
        return ans;
    }
};
