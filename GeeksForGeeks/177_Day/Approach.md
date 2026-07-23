# 💡 Approach — Check Preorder of BST

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 36.84%](https://img.shields.io/badge/Accuracy-36.84%25-orange?style=for-the-badge)
![Submissions: 46K+](https://img.shields.io/badge/Submissions-46K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)
![Company Tags](https://img.shields.io/badge/Company%20Tags-Morgan%20Stanley%20%7C%20Microsoft%20%7C%20Adobe-black?style=for-the-badge)

</div>

---

## 🎯 Core Insight

> [!TIP]
> **Upper and Lower Bounds in Preorder Traversal of a BST**
> 
> 1. **BST Property**: For any node $V$:
>    - All nodes in its **left subtree** must have values $< V$.
>    - All nodes in its **right subtree** must have values $> V$.
> 
> 2. **Preorder Traversal Pattern**: Preorder visits nodes in the order **Root $\to$ Left $\to$ Right**.
>    - When we descend into left subtrees, values typically decrease or change.
>    - As soon as we find a value greater than the current node, it means we have transitioned into a **right subtree**.
>    - Once we transition into the right subtree of a node $V$, we can **never** see any value smaller than $V$ again. Thus, $V$ becomes the new lower bound (or `root`) for all subsequent elements.
> 
> 3. **Monotonic Stack Approach**:
>    - We can use a stack to keep track of ancestral nodes.
>    - The stack will store nodes representing the path we are currently exploring (which behaves like a decreasing sequence because we continue to go left).
>    - If we encounter a node `arr[i]` that is greater than `stack.top()`, we are moving to a right subtree. We pop all elements from the stack that are smaller than `arr[i]`. The last popped element represents the root of the subtree we are exiting. We update our `root` (lower bound) limit to this popped value.
>    - If we ever encounter an element smaller than the current `root` limit, the preorder traversal is **invalid**, and we return `0` (false).

---

## 🔩 Step-by-Step Breakdown

### 1. Initialization
- Create an empty stack `s`.
- Initialize `root = INT_MIN` to represent our lower bound constraint.

### 2. Traverse the Array
For each element `arr[i]` in the array:
- **Constraint Check**: If `arr[i] < root`, return `0` (false).
- **Find Ancestor / Update Lower Bound**: While the stack is not empty and `s.top() < arr[i]`:
  - Update `root = s.top()`.
  - Pop the element from the stack.
- **Push to Stack**: Push `arr[i]` onto the stack.

### 3. Return Success
- If the loop finishes without violating the constraint, return `1` (true).

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start(["Start: canRepresentBST(arr)"]) --> Init["Initialize stack s\nroot = INT_MIN\nn = arr.size()"]
    
    Init --> LoopStart["For i = 0 to n - 1"]
    
    LoopStart --> CheckViolate{"arr[i] < root?"}
    CheckViolate -- "Yes" --> RetFalse["Return 0 (False)"]
    CheckViolate -- "No" --> StackLoop{"!s.empty() && s.top() < arr[i]?"}
    
    StackLoop -- "Yes" --> PopStack["root = s.top()\ns.pop()"]
    PopStack --> StackLoop
    
    StackLoop -- "No" --> PushStack["s.push(arr[i])"]
    PushStack --> NextIter["i++"]
    
    NextIter --> CheckEnd{"i < n?"}
    CheckEnd -- "Yes" --> CheckViolate
    CheckEnd -- "No" --> RetTrue["Return 1 (True)"]
    
    RetFalse --> End(["End"])
    RetTrue --> End
```

---

## 🧮 Dry Run — Example 1

### Input
`arr[] = [2, 4, 3]`

| Step | Element (`arr[i]`) | Constraint (`root`) | Stack State (top at right) | Action & Explanation |
| :---: | :---: | :---: | :---: | :--- |
| **0** | — | `INT_MIN` | `[]` | Initial state |
| **1** | **2** | `INT_MIN` | `[2]` | $2 > \text{INT\_MIN}$. Push $2$. |
| **2** | **4** | `INT_MIN` | `[4]` | $4 > 2$ (stack top). Pop $2$, set `root = 2`. Push $4$. |
| **3** | **3** | `2` | `[4, 3]` | $3 > 2$. Since $3 < 4$, stack loop doesn't execute. Push $3$. |

**Result**: Loop finishes successfully. Returns `1` (True).

---

## ⏱️ Complexity Analysis

- **Time Complexity**: $O(N)$ because every element is pushed onto and popped from the stack at most once.
- **Auxiliary Space**: $O(N)$ to store the stack of size at most $N$.

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../176_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../178_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
