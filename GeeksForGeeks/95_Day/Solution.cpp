#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int findPosition(int N) {
        if (N <= 0 || (N & (N - 1)) != 0) {
            return -1;
        }

        return log2(N) + 1;
    }
};
