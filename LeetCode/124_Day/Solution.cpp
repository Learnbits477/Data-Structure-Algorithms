#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // Step 1: Initialize Variables
        long long current_mass = mass;
        
        // Step 2: Sort the Asteroids
        sort(asteroids.begin(), asteroids.end());
        
        // Step 3: Simulate Collisions
        for (int asteroid : asteroids) {
            if (current_mass >= asteroid) {
                current_mass += asteroid;
            } else {
                return false;
            }
        }
        
        // Step 4: Return Result
        return true;
    }
};
