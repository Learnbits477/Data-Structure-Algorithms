#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSeatAllPeople(int k, vector<int>& seats) {
        // Step 1: Check if k <= 0
        if (k <= 0) {
            return true;
        }

        int m = seats.size();
        // Step 2: Traverse the Seat Array
        for (int i = 0; i < m; ++i) {
            if (seats[i] == 0) {
                // Check left and right neighbor constraints
                bool left_empty = (i == 0 || seats[i - 1] == 0);
                bool right_empty = (i == m - 1 || seats[i + 1] == 0);

                if (left_empty && right_empty) {
                    seats[i] = 1; // Place the person here
                    k--;          // Decrement remaining count of people

                    if (k == 0) {
                        return true; // Return true early if everyone is seated
                    }

                    i++; // Skip the next seat since it cannot be used
                }
            }
        }

        // Step 3: Return Result
        return k <= 0;
    }
};
