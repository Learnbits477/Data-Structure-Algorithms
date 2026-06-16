#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructList(vector<vector<int>>& queries) {
        // Step 1 — Initialize variables
        int cumulativeXor = 0;
        vector<int> result;
        
        // Step 2 — Process queries in reverse
        for (int i = (int)queries.size() - 1; i >= 0; --i) {
            if (queries[i][0] == 0) {
                result.push_back(queries[i][1] ^ cumulativeXor);
            } else {
                cumulativeXor ^= queries[i][1];
            }
        }
        
        // Step 3 — Process initial element
        result.push_back(cumulativeXor);
        
        // Step 4 — Sort and return
        sort(result.begin(), result.end());
        return result;
    }
};
