#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Signature expected by GFG Driver: isPossible(arr, s, x)
    int isPossible(vector<int>& arr, long long s, long long x) {
        vector<long long> P;
        P.push_back(s);
        long long current_sum = s;

        for (int val : arr) {
            if (current_sum > x) break;
            long long next_val = current_sum + val;
            if (next_val > x) break;
            P.push_back(next_val);
            current_sum += next_val;
        }

        for (int i = (int)P.size() - 1; i >= 0; --i) {
            if (x >= P[i]) {
                x -= P[i];
            }
        }

        return x == 0 ? 1 : 0;
    }

    // Signature with s first: isPossible(s, arr, x)
    int isPossible(long long s, const vector<long long>& arr, long long x) {
        vector<long long> P;
        P.push_back(s);
        long long current_sum = s;

        for (size_t i = 0; i < arr.size(); ++i) {
            if (current_sum > x) break;
            long long next_val = current_sum + arr[i];
            if (next_val > x) break;
            P.push_back(next_val);
            current_sum += next_val;
        }

        for (int i = (int)P.size() - 1; i >= 0; --i) {
            if (x >= P[i]) {
                x -= P[i];
            }
        }

        return x == 0 ? 1 : 0;
    }

    // Legacy signature: isPossible(s, N, arr[], x)
    int isPossible(long long s, long long N, long long arr[], long long x) {
        vector<long long> P;
        P.push_back(s);
        long long current_sum = s;

        for (long long i = 0; i < N; ++i) {
            if (current_sum > x) break;
            long long next_val = current_sum + arr[i];
            if (next_val > x) break;
            P.push_back(next_val);
            current_sum += next_val;
        }

        for (int i = (int)P.size() - 1; i >= 0; --i) {
            if (x >= P[i]) {
                x -= P[i];
            }
        }

        return x == 0 ? 1 : 0;
    }
};
