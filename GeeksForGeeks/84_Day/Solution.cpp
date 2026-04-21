#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int m, int n, int d) {
        if (d > max(m, n)) return -1;
        if (d % gcd(m, n) != 0) return -1;

        // The minimum steps will be the minimum of two strategies:
        // 1. Always fill jug M and pour to jug N.
        // 2. Always fill jug N and pour to jug M.
        return min(solve(m, n, d), solve(n, m, d));
    }

private:
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    int solve(int fillCap, int otherCap, int target) {
        int currFill = fillCap;
        int currOther = 0;
        int steps = 1; // Initially fill the first jug

        while (currFill != target && currOther != target) {
            // Find the amount to pour from fillCap jug to otherCap jug
            int amount = min(currFill, otherCap - currOther);
            
            currOther += amount;
            currFill -= amount;
            steps++; // Pour operation

            if (currFill == target || currOther == target) break;

            // If the fill jug becomes empty, refill it
            if (currFill == 0) {
                currFill = fillCap;
                steps++;
            }
            // If the other jug becomes full, empty it
            else if (currOther == otherCap) {
                currOther = 0;
                steps++;
            }
        }
        return steps;
    }
};
