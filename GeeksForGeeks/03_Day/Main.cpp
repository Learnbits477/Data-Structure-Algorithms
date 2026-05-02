#include <iostream>
#include <queue>
#include <vector>
#include "Solution.cpp"

using namespace std;

// Helper function to print and clear the queue
void printQueue(queue<int>& q) {
    cout << "[";
    while (!q.empty()) {
        cout << q.front();
        q.pop();
        if (!q.empty()) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    // Example 1
    queue<int> q1;
    vector<int> v1 = {2, 4, 3, 1};
    for(int x : v1) q1.push(x);
    
    cout << "Input: [2, 4, 3, 1]" << endl;
    sol.rearrangeQueue(q1);
    cout << "Output: ";
    printQueue(q1);
    cout << "Expected: [2, 3, 4, 1]" << endl << endl;
    
    // Example 2
    queue<int> q2;
    vector<int> v2 = {3, 5};
    for(int x : v2) q2.push(x);
    
    cout << "Input: [3, 5]" << endl;
    sol.rearrangeQueue(q2);
    cout << "Output: ";
    printQueue(q2);
    cout << "Expected: [3, 5]" << endl;
    
    return 0;
}
