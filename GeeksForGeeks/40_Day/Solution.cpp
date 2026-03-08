#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {
        unordered_set<long long> squares;
        
        for (int x : arr)
            squares.insert((long long)x * x);
        
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long sum = (long long)arr[i] * arr[i] 
                              + (long long)arr[j] * arr[j];
                if (squares.count(sum))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        cout << (obj.pythagoreanTriplet(arr) ? "true" : "false") << "\n";
    }
    return 0;
}