#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string firstNonRepeating(string s) {
        vector<int> freq(26, 0);
        queue<char> q;
        string result = "";
        
        for (char c : s) {
            // Increase frequency of the current character
            freq[c - 'a']++;
            
            // Push the character to the queue
            q.push(c);
            
            // Remove characters from the front of the queue if they are repeating
            while (!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }
            
            // If the queue is empty, there is no non-repeating character
            if (q.empty()) {
                result += '#';
            } else {
                // The front of the queue is the first non-repeating character
                result += q.front();
            }
        }
        
        return result;
    }
};
