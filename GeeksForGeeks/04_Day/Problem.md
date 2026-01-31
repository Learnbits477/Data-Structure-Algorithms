# Implement k Queues in a Single Array

**Difficulty**: Hard  
**Accuracy**: 61.88%  
**Submissions**: 2K+  
**Points**: 8

## Problem Statement

You are given two integers `n` and `k`. Your task is to implement a class `kQueues` that uses a single array of size `n` to simulate `k` independent queues.

The class should support the following operations:

1.  **enqueue(x, i)**: Adds the element `x` into the `i`-th queue.
2.  **dequeue(i)**: Removes the front element from the `i`-th queue and returns it. Returns `-1` if the queue is empty.
3.  **isEmpty(i)**: Returns `true` if `i`-th queue is empty, else return `false`.
4.  **isFull()**: Returns `true` if the array is completely full and no more elements can be inserted, otherwise `false`.

There will be a sequence of `q` queries represented as:

- `1 x i` : Call `enqueue(x, i)`
- `2 i` : Call `dequeue(i)`
- `3 i` : Call `isEmpty(i)`
- `4` : Call `isFull()`

The driver code will process the queries, call the corresponding functions, and print the results of `dequeue`, `isEmpty`, and `isFull` operations.
You only need to implement the above four functions.

### Example 1:

**Input**:
`n = 4, k = 2, q = 8`
`queries = [[1, 5, 0], [1, 3, 0], [1, 1, 1], [2, 0], [1, 4, 1], [1, 1, 0], [3, 1], [4]]`

**Output**:
`[5, false, true]`

**Explanation**:
Queries on the queue are as follows:

- `enqueue(5, 0)` → `queue0 = [5]`
- `enqueue(3, 0)` → `queue0 = [5, 3]`
- `enqueue(1, 1)` → `queue1 = [1]`
- `dequeue(0)` → returns `5`, `queue0 = [3]`
- `enqueue(4, 1)` → `queue1 = [1, 4]`
- `enqueue(1, 0)` → `queue0 = [3, 1]`
- `isEmpty(1)` → `false`
- `isFull()` → `true`

### Example 2:

**Input**:
`n = 6, k = 3, q = 4`
`queries = [[1, 3, 2], [2, 0], [1, 2, 1], [3, 2]]`

**Output**:
`[-1, false]`

**Explanation**:
Queries on the queue are as follows:

- `enqueue(3, 2)` → `queue2 = [3]`
- `dequeue(0)` → `queue0` is empty, returns `-1`
- `enqueue(2, 1)` → `queue1 = [2]`
- `isEmpty(2)` → `false`

### Constraints:

- $1 \le q \le 10^5$
- $1 \le k \le n \le 10^5$
- $0 \le \text{values on the queues} \le 10^9$
