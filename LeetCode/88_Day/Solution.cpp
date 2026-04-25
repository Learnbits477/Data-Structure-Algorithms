#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    long long mapTo1D(int x, int y, int side) {
        if (y == 0) return x;                                // Bottom edge
        if (x == side) return (long long)side + y;           // Right edge
        if (y == side) return 2LL * side + (side - x);       // Top edge
        if (x == 0) return 3LL * side + (side - y);          // Left edge
        return 0; 
    }

    bool check(long long mid, int k, int N, const vector<long long>& extended_P, long long perimeter) {
        vector<int> next_jump(2 * N, 2 * N);
        int j = 0;
        
        for (int i = 0; i < 2 * N; ++i) {
            while (j < 2 * N && extended_P[j] - extended_P[i] < mid) {
                j++;
            }
            next_jump[i] = j;
        }
        
        for (int i = 0; i < N; ++i) {
            int current = i;
            int count = 1;
            
            while (count < k && current < 2 * N) {
                current = next_jump[current];
                count++;
            }
            
            if (count == k && current < 2 * N) {
                if (extended_P[current] - extended_P[i] <= perimeter - mid) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int N = points.size();
        vector<long long> P(N);
        
        for (int i = 0; i < N; ++i) {
            P[i] = mapTo1D(points[i][0], points[i][1], side);
        }
        
        sort(P.begin(), P.end());
        
        long long perimeter = 4LL * side;
        vector<long long> extended_P(2 * N);
        
        for (int i = 0; i < N; ++i) {
            extended_P[i] = P[i];
            extended_P[i + N] = P[i] + perimeter;
        }
        
        long long low = 1, high = perimeter / k;
        int ans = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (check(mid, k, N, extended_P, perimeter)) {
                ans = mid;
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
        
        return ans;
    }
};
