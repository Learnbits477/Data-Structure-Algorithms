#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int visibleBuildings(vector<int>& arr) {
        if (arr.empty()) {
            return 0;
        }

        int count = 0;
        int max_height_so_far = 0;

        for (int height : arr) {
            if (height >= max_height_so_far) {
                count++;
                max_height_so_far = height;
            }
        }

        return count;
    }
};

