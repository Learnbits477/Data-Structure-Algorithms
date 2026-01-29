# Approach: Interleave First Half of the Queue with Second Half

## Intuition

The problem asks us to interleave the first half of the queue with the second half. Since a queue only allows access to the front, we need a way to temporarily store and reorder elements to achieve the desired `[First1, Second1, First2, Second2, ...]` pattern.

A **Stack** (LIFO - Last In First Out) is perfect for this because it can reverse the order of elements. By carefully pushing and popping elements between the queue and a stack, we can align the first half and second half elements correctly at the front of the queue to be interleaved.

## Algorithm Steps

We assume the size of the queue `N` is even. Let `half = N / 2`.

1.  **Push First Half to Stack**:
    - Dequeue the first `half` elements and push them onto a stack.
    - **State**:
      - Queue: `[Second Half]`
      - Stack: `[First Half]` (Top is `N/2`-th element)

2.  **Enqueue Stack content back to Queue**:
    - Pop all elements from the stack and enqueue them back to the queue.
    - This places the First Half at the back of the queue, but in **reverse order**.
    - **State**:
      - Queue: `[Second Half, Reversed First Half]`
      - Stack: `(empty)`

3.  **Move Second Half to Back**:
    - Dequeue data from the front (which is the start of the Second Half) and enqueue it to the back. Do this `half` times.
    - This moves the Second Half behind the Reversed First Half.
    - **State**:
      - Queue: `[Reversed First Half, Second Half]`
      - Stack: `(empty)`

4.  **Push First Half to Stack (Again)**:
    - The front of the queue now contains the Reversed First Half.
    - Dequeue these `half` elements and push them onto the stack.
    - Reversing a reversed sequence restores the **original order**.
    - **State**:
      - Queue: `[Second Half]`
      - Stack: `[First Half]` (Top is `1st` element)

5.  **Interleave**:
    - Now, the Stack top has the next element from the First Half.
    - The Queue front has the next element from the Second Half.
    - Repeat `half` times:
      1.  Pop from Stack, Enqueue to Queue.
      2.  Dequeue from Queue, Enqueue to Queue.
    - **Final State**:
      - Queue: `[1st Element, (N/2+1)-th Element, 2nd Element, ...]`

## Dry Run

**Input**: `[2, 4, 3, 1]` (`N=4`, `half=2`)

1.  **Push first half to stack**:
    - Q: `[3, 1]`
    - S: `[2, 4]` (Top: 4)

2.  **Stack to Queue**:
    - Pop 4 -> Q: `[3, 1, 4]`
    - Pop 2 -> Q: `[3, 1, 4, 2]`
    - S: `[]`

3.  **Move Second Half (`3, 1`) to Back**:
    - Dequeue 3, Enqueue 3 -> Q: `[1, 4, 2, 3]`
    - Dequeue 1, Enqueue 1 -> Q: `[4, 2, 3, 1]`
    - (_Note: Now `4, 2` is the reversed first half at the front_)

4.  **Push First Half (`4, 2`) to Stack**:
    - Dequeue 4, Push 4 -> S: `[4]`
    - Dequeue 2, Push 2 -> S: `[4, 2]` (Top: 2)
    - Q: `[3, 1]`

5.  **Interleave**:
    - **Iteration 1**:
      - Pop Stack (2), Enqueue -> Q: `[3, 1, 2]`
      - Dequeue Q (3), Enqueue -> Q: `[1, 2, 3]`
    - **Iteration 2**:
      - Pop Stack (4), Enqueue -> Q: `[1, 2, 3, 4]`
      - Dequeue Q (1), Enqueue -> Q: `[2, 3, 4, 1]`

**Output**: `[2, 3, 4, 1]` (Correct)

## Complexity Analysis

- **Time Complexity**: `O(N)`
  - We process each element a constant number of times (enqueue/dequeue/push/pop).
  - Specifically, 4 passes over half the elements, and 1 pass for interleaving.
- **Space Complexity**: `O(N)`
  - We use a stack to store `N/2` elements.

## C++ Code Snippet

```cpp
void rearrangeQueue(queue<int> &q) {
    if (q.empty()) return;

    int n = q.size();
    int half = n / 2;
    stack<int> s;

    // 1. Push first half to stack
    for(int i = 0; i < half; ++i) {
        s.push(q.front());
        q.pop();
    }

    // 2. Stack -> Queue (Reverses first half)
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // 3. Move Second half to back
    for(int i = 0; i < half; ++i) {
        q.push(q.front());
        q.pop();
    }

    // 4. Push Reversed First half to stack (Restores order)
    for(int i = 0; i < half; ++i) {
        s.push(q.front());
        q.pop();
    }

    // 5. Interleave
    while(!s.empty()) {
        q.push(s.top()); // From First Half
        s.pop();
        q.push(q.front()); // From Second Half
        q.pop();
    }
}
```
