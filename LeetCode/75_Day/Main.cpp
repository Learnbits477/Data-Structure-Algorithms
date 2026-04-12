#include <iostream>
#include <string>
#include <vector>
#include "Solution.cpp"

void test(string word, int expected) {
    Solution sol;
    int result = sol.minimumDistance(word);
    cout << "Word: " << word << " | Expected: " << expected << " | Result: " << result;
    if (result == expected) {
        cout << " ✅ PASSED" << endl;
    } else {
        cout << " ❌ FAILED" << endl;
    }
}

int main() {
    cout << "--- LeetCode 1320: Minimum Distance to Type a Word Using Two Fingers ---" << endl;
    cout << endl;
    
    test("CAKE", 3);
    test("HAPPY", 6);
    test("NEW", 3); // N(2,1), E(0,4), W(3,4). dist(N,E)=5, dist(N,W)=4. Optimal: N to E (free), N to W (free) -> 0? No, 'N' is at (2,1), 'E' is at (0,4), 'W' is at (3,4).
    // Let's re-eval NEW:
    // F1 at N (0)
    // F1 to E (dist(N,E) = |2-0| + |1-4| = 5) OR F2 to E (0)
    // F2 at E.
    // F1 to W (|2-3| + |1-4| = 4) OR F2 to W (|0-3| + |4-4| = 3)
    // Best: Finger 2 to E (0), Finger 2 to W (3). Total 3. Correct.
    
    test("YEAR", 7);
    
    return 0;
}
