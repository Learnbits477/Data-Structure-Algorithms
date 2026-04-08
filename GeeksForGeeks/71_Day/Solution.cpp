#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int n = arr.size();
        int left = 0, right = n - 1;

        while (left < right) {
            // Increment left index while we see 0 at left
            while (arr[left] == 0 && left < right) {
                left++;
            }

            // Decrement right index while we see 1 at right
            while (arr[right] == 1 && left < right) {
                right--;
            }

            // If left is smaller than right then there is a 1 at left
            // and a 0 at right. Exchange arr[left] and arr[right]
            if (left < right) {
                arr[left] = 0;
                arr[right] = 1;
                left++;
                right--;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    sol.segregate0and1(arr);
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
