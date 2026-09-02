#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, string s) {
        // Step 1: Initialize state array for 26 uppercase English letters
        // state[i] = 0: not arrived yet
        // state[i] = 1: currently using a computer
        // state[i] = 2: arrived but rejected (no computer was available)
        vector<int> state(26, 0);
        int occupied = 0;
        int rejected = 0;

        // Step 2: Iterate through each event character in string s
        for (char ch : s) {
            int idx = ch - 'A';

            // Arrival (first occurrence)
            if (state[idx] == 0) {
                if (occupied < n) {
                    // Computer available -> assign and mark as using
                    occupied++;
                    state[idx] = 1;
                } else {
                    // All computers full -> reject customer
                    rejected++;
                    state[idx] = 2;
                }
            } 
            // Departure (second occurrence)
            else if (state[idx] == 1) {
                // Customer was using computer -> free up computer
                occupied--;
            }
            // If state[idx] == 2 (rejected previously), do nothing on departure
        }

        // Step 3: Return total rejected customers count
        return rejected;
    }

    // Aliases for driver/platform function name compatibility
    int unoccupiedComputers(int n, string s) {
        return solve(n, s);
    }
};
