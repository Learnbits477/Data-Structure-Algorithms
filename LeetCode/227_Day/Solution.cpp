#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Step 1: Enumerate all distinct index triplets and collect unique even 3-digit numbers
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> uniqueNumbers;
        int n = digits.size();

        // Iterate through all possible hundreds digits
        for (int i = 0; i < n; i++) {
            // Step 1.1: Leading zero is not permitted for a 3-digit number
            if (digits[i] == 0) continue;

            // Iterate through all possible tens digits
            for (int j = 0; j < n; j++) {
                if (j == i) continue; // Each digit element can only be used once

                // Iterate through all possible units digits
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue; // Distinct indices

                    // Step 1.2: Units digit must be even
                    if (digits[k] % 2 != 0) continue;

                    // Form the 3-digit number and insert into set
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    uniqueNumbers.insert(num);
                }
            }
        }

        // Step 2: Return the total count of distinct valid numbers
        return uniqueNumbers.size();
    }

    // Aliases for compatibility
    int countUniqueEvenNumbers(vector<int>& digits) {
        return totalNumbers(digits);
    }

    int unique3DigitEvenNumbers(vector<int>& digits) {
        return totalNumbers(digits);
    }

    int findEvenNumbers(vector<int>& digits) {
        return totalNumbers(digits);
    }
};
