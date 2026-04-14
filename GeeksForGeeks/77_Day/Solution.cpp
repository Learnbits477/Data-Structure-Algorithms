#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        return s;
    }
};