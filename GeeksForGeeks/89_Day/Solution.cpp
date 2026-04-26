#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        vector<int> result;
        int i = 0, j = 0, k = 0;
        int n1 = a.size(), n2 = b.size(), n3 = c.size();
        while (i < n1 && j < n2 && k < n3) {
            if (a[i] == b[j] && b[j] == c[k]) {
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++;
                j++;
                k++;
            } 
            else if (a[i] < b[j]) {
                i++;
            } 
            else if (b[j] < c[k]) {
                j++;
            } 
            else {
                k++;
            }
        }
        return result;
    }
};
