#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void runTest(int mass, vector<int> asteroids, bool expected) {
    Solution sol;
    bool result = sol.asteroidsDestroyed(mass, asteroids);
    
    cout << "Input: mass = " << mass << ", asteroids = [";
    for (size_t i = 0; i < asteroids.size(); ++i) {
        cout << asteroids[i] << (i == asteroids.size() - 1 ? "" : ", ");
    }
    cout << "]\n";
    cout << "Expected: " << (expected ? "true" : "false") << " | "
         << "Actual: " << (result ? "true" : "false") << "\n";
    
    if (result == expected) {
        cout << "✅ PASSED\n\n";
    } else {
        cout << "❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🔢 Destroying Asteroids — Test Suite\n";
    cout << "----------------------------------------\n\n";

    runTest(10, {3, 9, 19, 5, 21}, true);
    runTest(5, {4, 9, 23, 4}, false);

    return 0;
}
