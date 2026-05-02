#include <iostream>
#include "Solution.cpp"

using namespace std;

int main() {
    int n = 4, k = 2;
    kQueues ks(n, k);

    cout << "Executing Queries on kQueues(n=" << n << ", k=" << k << ")\n" << endl;

    // Queries: [[1, 5, 0], [1, 3, 0], [1, 1, 1], [2, 0], [1, 4, 1], [1, 1, 0], [3, 1], [4]] 
    // Output: [5, false, true]
    
    // 1 enqueue(5, 0)
    ks.enqueue(5, 0);
    cout << "enqueue(5, 0) executed." << endl;
    
    // 2 enqueue(3, 0)
    ks.enqueue(3, 0);
    cout << "enqueue(3, 0) executed." << endl;
    
    // 3 enqueue(1, 1)
    ks.enqueue(1, 1);
    cout << "enqueue(1, 1) executed." << endl;
    
    // 4 dequeue(0) -> expect 5
    cout << "Dequeue(0): " << ks.dequeue(0) << " (Expected: 5)" << endl; 
    
    // 5 enqueue(4, 1)
    ks.enqueue(4, 1);
    cout << "enqueue(4, 1) executed." << endl;
    
    // 6 enqueue(1, 0)
    ks.enqueue(1, 0);
    cout << "enqueue(1, 0) executed." << endl;
    
    // 7 isEmpty(1) -> expect false
    cout << "isEmpty(1): " << (ks.isEmpty(1) ? "true" : "false") << " (Expected: false)" << endl;
    
    // 8 isFull() -> expect true
    cout << "isFull(): " << (ks.isFull() ? "true" : "false") << " (Expected: true)" << endl;
    
    return 0;
}
