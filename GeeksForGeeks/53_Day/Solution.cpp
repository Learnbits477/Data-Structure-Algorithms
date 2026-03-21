#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        // Catalan numbers up to N=6 (max elements in array is 6)
        vector<int> cat = {1, 1, 2, 5, 14, 42, 132};
        vector<int> res;
        for (int i = 0; i < arr.size(); ++i) {
            int L = 0, R = 0;
            for (int j = 0; j < arr.size(); ++j) {
                if (arr[j] < arr[i]) L++;
                else if (arr[j] > arr[i]) R++;
            }
            res.push_back(cat[L] * cat[R]);
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        Solution obj;
        vector<int> res = obj.countBSTs(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
