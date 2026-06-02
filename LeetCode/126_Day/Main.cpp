#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void runTest(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration, int expected) {
    Solution sol;
    int result = sol.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
    
    cout << "Input: landStartTime = [";
    for (size_t i = 0; i < landStartTime.size(); ++i) cout << landStartTime[i] << (i == landStartTime.size() - 1 ? "" : ", ");
    cout << "], landDuration = [";
    for (size_t i = 0; i < landDuration.size(); ++i) cout << landDuration[i] << (i == landDuration.size() - 1 ? "" : ", ");
    cout << "], waterStartTime = [";
    for (size_t i = 0; i < waterStartTime.size(); ++i) cout << waterStartTime[i] << (i == waterStartTime.size() - 1 ? "" : ", ");
    cout << "], waterDuration = [";
    for (size_t i = 0; i < waterDuration.size(); ++i) cout << waterDuration[i] << (i == waterDuration.size() - 1 ? "" : ", ");
    cout << "]\n";
    
    cout << "Expected: " << expected << "\n";
    cout << "Output: " << result << "\n";
    
    if (result == expected) {
        cout << "✅ PASSED\n\n";
    } else {
        cout << "❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🔢 Earliest Finish Time for Land and Water Rides I — Test Suite\n\n";
    
    vector<int> landStart1 = {2, 8};
    vector<int> landDur1 = {4, 1};
    vector<int> waterStart1 = {6};
    vector<int> waterDur1 = {3};
    runTest(landStart1, landDur1, waterStart1, waterDur1, 9);
    
    vector<int> landStart2 = {5};
    vector<int> landDur2 = {3};
    vector<int> waterStart2 = {1};
    vector<int> waterDur2 = {10};
    runTest(landStart2, landDur2, waterStart2, waterDur2, 14);
    
    return 0;
}
