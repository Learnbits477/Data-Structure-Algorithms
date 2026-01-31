#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
         int left = 0;
        int right = letters.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // If left exceeds the array bounds, return the first character
        if (left >= letters.size()) {
            return letters[0];
        } else {
            return letters[left];
        }
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<char> letters1 = {'c', 'f', 'j'};
    char target1 = 'a';
    cout << "Test Case 1: " << sol.nextGreatestLetter(letters1, target1) << " (Expected: c)" << endl;

    // Test Case 2
    vector<char> letters2 = {'c', 'f', 'j'};
    char target2 = 'c';
    cout << "Test Case 2: " << sol.nextGreatestLetter(letters2, target2) << " (Expected: f)" << endl;

    // Test Case 3
    vector<char> letters3 = {'x', 'x', 'y', 'y'};
    char target3 = 'z';
    cout << "Test Case 3: " << sol.nextGreatestLetter(letters3, target3) << " (Expected: x)" << endl;

    return 0;
}
