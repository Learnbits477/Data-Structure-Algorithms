#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> nextPalindrome(vector<int> num) {
        int n = num.size();
        // Case 1: Check if all digits are 9
        bool allNine = true;
        for (int i = 0; i < n; i++) {
            if (num[i] != 9) {
                allNine = false;
                break;
            }
        }

        if (allNine) {
            vector<int> res(n + 1, 0);
            res[0] = 1;
            res[n] = 1;
            return res;
        }

        // Case 2: Not all digits are 9
        vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = num[i];

        int mid = n / 2;
        int i = mid - 1;
        int j = (n % 2 == 0) ? mid : mid + 1;

        // Find the first point of difference from the center outwards
        bool leftSmaller = false;
        while (i >= 0 && res[i] == res[j]) {
            i--;
            j++;
        }

        if (i < 0 || res[i] < res[j]) {
            leftSmaller = true;
        }

        // Mirror the left part to the right part
        int left = mid - 1;
        int right = (n % 2 == 0) ? mid : mid + 1;
        while (left >= 0) {
            res[right] = res[left];
            left--;
            right++;
        }

        // If the mirrored number is smaller or equal, increment the middle
        if (leftSmaller) {
            int carry = 1;
            int i_ptr = mid - 1;
            int j_ptr;

            if (n % 2 == 1) {
                res[mid] += carry;
                carry = res[mid] / 10;
                res[mid] %= 10;
                j_ptr = mid + 1;
            } else {
                j_ptr = mid;
            }

            while (i_ptr >= 0) {
                res[i_ptr] += carry;
                carry = res[i_ptr] / 10;
                res[i_ptr] %= 10;
                res[j_ptr] = res[i_ptr];
                i_ptr--;
                j_ptr++;
            }
        }

        return res;
    }
};