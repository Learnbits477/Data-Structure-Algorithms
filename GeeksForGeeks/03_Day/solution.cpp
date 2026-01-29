#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        if (q.empty()) return;

        int n = q.size();
        int half = n / 2;
        stack<int> s;

        // 1. Push first half to stack
        for (int i = 0; i < half; ++i) {
            s.push(q.front());
            q.pop();
        }

        // 2. Enqueue stack items back to queue (reverses order of first half)
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        // 3. Move the new first half (originally second half) to the back
        // The queue now has [Second Half, Reverse First Half]
        // We want to move Second Half to the back to get [Reverse First Half, Second Half]
        for (int i = 0; i < half; ++i) {
            q.push(q.front());
            q.pop();
        }

        // 4. Push first half (which is now reversed at the front) to stack again
        // Queue: [Reverse First Half, Second Half] -> Stack gets Reverse First Half -> Stack has First Half in correct order (Top is First Element)
        // Wait, "Reverse First Half" was pushed. Stack will reverse it again.
        // Let's trace carefully.
        // Original: [1, 2, 3, 4]
        // Step 1: Q=[3, 4], S=[1, 2] (Top 2)
        // Step 2: Q=[3, 4, 2, 1]
        // Step 3: Q=[2, 1, 3, 4]
        // Step 4: Push [2, 1] to Stack. S=[2, 1] (Top 1). Q=[3, 4]
        // See, now Stack top is 1 (Original First), and Queue front is 3 (Original First of Second Half).
        // Correct.
        for (int i = 0; i < half; ++i) {
            s.push(q.front());
            q.pop();
        }

        // 5. Interleave
        while (!s.empty()) {
            // Push from Stack (First Half element)
            q.push(s.top());
            s.pop();

            // Push from Queue (Second Half element)
            q.push(q.front());
            q.pop();
        }
    }
};

// Helper function to print queue
void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    queue<int> q1;
    q1.push(2); q1.push(4); q1.push(3); q1.push(1);
    cout << "Input: [2, 4, 3, 1]\n";
    sol.rearrangeQueue(q1);
    cout << "Output: ";
    printQueue(q1);

    // Test Case 2
    queue<int> q2;
    q2.push(3); q2.push(5);
    cout << "Input: [3, 5]\n";
    sol.rearrangeQueue(q2);
    cout << "Output: ";
    printQueue(q2);

    return 0;
}
