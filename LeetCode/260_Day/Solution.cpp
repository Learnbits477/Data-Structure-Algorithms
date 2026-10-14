#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // Step: 01 - Verify if the target digit sum is mathematically achievable
        if (1LL * num * 9 < sum) {
            return "";
        }

        // Step: 02 - Compute count of full nines and remaining digit
        int nines = sum / 9;
        int rem = sum % 9;

        // Step: 03 - Construct canonical string with pre-allocated buffer
        string ans = "";
        ans.reserve(num);
        ans.append(nines, '9');

        // Step: 04 - Append remainder digit if non-zero
        if (rem > 0) {
            ans.push_back(static_cast<char>('0' + rem));
        }

        // Step: 05 - Pad trailing zeros to reach length num
        if (static_cast<int>(ans.size()) < num) {
            ans.append(num - static_cast<int>(ans.size()), '0');
        }

        // Step: 06 - Return constructed maximum good integer string
        return ans;
    }

    string maxSumOfSquaresSimulation(int num, int sum) {
        // Step: 01 - Check feasibility against maximum possible digit sum
        if (1LL * num * 9 < sum) {
            return "";
        }

        // Step: 02 - Greedily construct digits position by position
        string ans = "";
        ans.reserve(num);
        int currentSum = sum;

        for (int i = 0; i < num; i++) {
            int digit = min(9, currentSum);
            ans.push_back(static_cast<char>('0' + digit));
            currentSum -= digit;
        }

        // Step: 03 - Return simulated result string
        return ans;
    }

    string maximizeSumOfSquares(int num, int sum) {
        // Step: 01 - Delegate to primary solver
        return maxSumOfSquares(num, sum);
    }
};
