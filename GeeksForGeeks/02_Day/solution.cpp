#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    string firstNonRepeating(string &s) {
        vector<int> freq(26, 0);
        queue<char> q;
        string result = "";
        
        for (char c : s) {
            freq[c - 'a']++;
            q.push(c);
            
            while (!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }
            
            if (q.empty()) {
                result += '#';
            } else {
                result += q.front();
            }
        }
        
        return result;
    }
};