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

        // 3. Dequeue and enqueue the original second half elements to the back
        for (int i = 0; i < half; ++i) {
            q.push(q.front());
            q.pop();
        }

        // 4. Push reversed first half to stack (corrects order for interleaving)
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
