#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

#define ll long long int
class Solution {
private:
    multiset<int> l, r;
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll n = nums.size();
        k--;
        ll curr = nums[0];
        for(int i=1; i<=dist+1 && i < n; i++){
            curr += nums[i];
            l.insert(nums[i]);
        }
        while(l.size() > k){
            curr -= *l.rbegin();
            r.insert(*l.rbegin());
            l.erase(l.find(*l.rbegin()));
        }

        ll ans = curr;
        for(int i=dist+2; i<n; i++){
            if(l.find(nums[i-dist-1]) != l.end()){
                curr -= nums[i-dist-1];
                l.erase(l.find(nums[i-dist-1]));
            }
            else{
                r.erase(r.find(nums[i-dist-1]));
            }
            if(nums[i] < *l.rbegin()){
                curr += nums[i];
                l.insert(nums[i]);
            }
            else{
                r.insert(nums[i]);
            }
            while(l.size() < k){
                l.insert(*r.begin());
                curr += *r.begin();
                r.erase(r.find(*r.begin()));
            }
            while(l.size() > k){
                r.insert(*l.rbegin());
                curr -= *l.rbegin();
                l.erase(l.find(*l.rbegin()));
            }

            ans = min(ans, curr); 
        }
        return ans;
    }
};

#include <iostream>

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 3, 2, 6, 4, 2};
    int k1 = 3;
    int dist1 = 3;
    cout << "Example 1 Output: " << sol.minimumCost(nums1, k1, dist1) << " (Expected: 5)" << endl;

    // Example 2
    vector<int> nums2 = {10, 1, 2, 2, 2, 1};
    int k2 = 4;
    int dist2 = 3;
    cout << "Example 2 Output: " << sol.minimumCost(nums2, k2, dist2) << " (Expected: 15)" << endl;

    // Example 3
    vector<int> nums3 = {10, 8, 18, 9};
    int k3 = 3;
    int dist3 = 1;
    cout << "Example 3 Output: " << sol.minimumCost(nums3, k3, dist3) << " (Expected: 36)" << endl;

    return 0;
}
