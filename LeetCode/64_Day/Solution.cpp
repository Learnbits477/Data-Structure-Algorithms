#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

/**
 * Problem: 2751. Robot Collisions
 * Source: https://leetcode.com/problems/robot-collisions/description/
 * 
 * Approach: Stack & Sorting
 * 
 * 1. Store robot details (position, health, direction, original index) in a list.
 * 2. Sort robots by their initial positions to process them in order along the line.
 * 3. Use a stack to track robots moving right ('R').
 * 4. When a robot is moving left ('L'):
 *    - Check for collisions with robots on the stack (which are moving right).
 *    - Compare health:
 *      - If 'L' has more health: Top 'R' is destroyed, 'L' health decreases by 1, and 'L' continues checking the next 'R' on the stack.
 *      - If 'L' has less health: Bottom 'R' health decreases by 1, and 'L' is destroyed.
 *      - If health is equal: Both are destroyed.
 * 5. After processing all robots, sort survivors back to their original index order.
 * 
 * Time Complexity: O(n log n) - sorting
 * Space Complexity: O(n) - storing robot details and stack
 */

struct Robot {
    int position;
    int health;
    char direction;
    int index;
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots(n);
        
        for (int i = 0; i < n; i++) {
            robots[i] = {positions[i], healths[i], directions[i], i};
        }
        
        // Sort robots by position
        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.position < b.position;
        });
        
        stack<Robot> s;
        for (int i = 0; i < n; i++) {
            if (robots[i].direction == 'R') {
                s.push(robots[i]);
            } else {
                // Current robot is moving 'L'
                bool destroyed = false;
                while (!s.empty() && s.top().direction == 'R') {
                    if (s.top().health > robots[i].health) {
                        // Stack robot survives, current 'L' robot destroyed
                        s.top().health -= 1;
                        destroyed = true;
                        break;
                    } else if (s.top().health < robots[i].health) {
                        // Stack robot destroyed, current 'L' robot continues
                        s.pop();
                        robots[i].health -= 1;
                    } else {
                        // Both destroyed
                        s.pop();
                        destroyed = true;
                        break;
                    }
                }
                
                if (!destroyed) {
                    s.push(robots[i]);
                }
            }
        }
        
        // Collect survivors
        vector<Robot> survivors;
        while (!s.empty()) {
            survivors.push_back(s.top());
            s.pop();
        }
        
        // Sort by original index
        sort(survivors.begin(), survivors.end(), [](const Robot& a, const Robot& b) {
            return a.index < b.index;
        });
        
        vector<int> result;
        for (const auto& robot : survivors) {
            result.push_back(robot.health);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> p1 = {5,4,3,2,1};
    vector<int> h1 = {2,17,9,15,10};
    string d1 = "RRRRR";
    vector<int> res1 = sol.survivedRobotsHealths(p1, h1, d1);
    cout << "Example 1 Output: ";
    for(int h : res1) cout << h << " ";
    cout << endl;

    // Example 2
    vector<int> p2 = {3,5,2,6};
    vector<int> h2 = {10,10,15,12};
    string d2 = "RLRL";
    vector<int> res2 = sol.survivedRobotsHealths(p2, h2, d2);
    cout << "Example 2 Output: ";
    for(int h : res2) cout << h << " ";
    cout << endl;

    return 0;
}
