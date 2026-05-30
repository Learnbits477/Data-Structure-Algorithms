# 💡 Approach — Replace with XOR of Adjacent

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 75.8%](https://img.shields.io/badge/Accuracy-75.8%25-yellow?style=for-the-badge)
![Submissions: 66K+](https://img.shields.io/badge/Submissions-66K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)

</div>

---

## 🧠 Core Insight

> [!TIP]
> The key challenge is that every element must be replaced using the **original** values of its neighbours — not values already modified in the same pass.
>
> Instead of using an auxiliary array (which costs **O(n)** space), we can maintain a single `prev` variable that tracks the **original value of the left neighbour** as we sweep left-to-right. This lets us perform the transformation **in-place in O(1) extra space**.

---

## 🔩 Step-by-Step Breakdown

**Step 1 — Save the original first element.**
Before modifying anything, store `prev = arr[0]`. This value will be used as the "original left neighbour" for `arr[1]`.

**Step 2 — Update the first element.**
`arr[0]` has only one neighbour: `arr[1]`.
Apply: `arr[0] = arr[0] ^ arr[1]`.

**Step 3 — Sweep through middle elements (`i = 1` to `n-2`).**
For each index `i`:
1. Save `temp = arr[i]` (original value of current element, needed as `prev` for next iteration).
2. Compute `arr[i] = prev ^ arr[i+1]` (original left neighbour XOR original right neighbour — `arr[i+1]` is still unmodified).
3. Update `prev = temp`.

**Step 4 — Update the last element.**
`arr[n-1]` has only one neighbour on the left. At this point `prev` holds the original value of `arr[n-2]`.
Apply: `arr[n-1] = prev ^ arr[n-1]`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A([🚀 Start]) --> B["prev = arr[0]\nSave original first element"]
    B --> C["arr[0] = arr[0] ^ arr[1]\nUpdate first element"]
    C --> D["i = 1"]
    D --> E{i ≤ n-2 ?}
    E -- Yes --> F["temp = arr[i]\nSave original arr[i]"]
    F --> G["arr[i] = prev ^ arr[i+1]\nXOR original left & right neighbours"]
    G --> H["prev = temp\nShift saved original forward"]
    H --> I["i++"]
    I --> E
    E -- No --> J["arr[n-1] = prev ^ arr[n-1]\nUpdate last element using saved prev"]
    J --> K([✅ Done — Array transformed in-place])
```

---

## 🔍 Dry Run — Example 1

`arr = [2, 1, 4, 7]`

| Step | Action | `prev` | Array State |
|:----:|:------:|:------:|:-----------:|
| Init | `prev = arr[0]` | `2` | `[2, 1, 4, 7]` |
| Step 2 | `arr[0] = 2^1 = 3` | `2` | `[3, 1, 4, 7]` |
| i=1 | `temp=1`, `arr[1]=2^4=6`, `prev=1` | `1` | `[3, 6, 4, 7]` |
| i=2 | `temp=4`, `arr[2]=1^7=6`, `prev=4` | `4` | `[3, 6, 6, 7]` |
| Step 4 | `arr[3]=4^7=3` | — | `[3, 6, 6, 3]` ✅ |

---

## 📊 Complexity Analysis

| Complexity Type  | Value  | Reasoning |
|:----------------:|:------:|:---------:|
| **Time**         | `O(n)` | Single left-to-right sweep through the array |
| **Auxiliary Space** | `O(1)` | Only two scalar variables (`prev`, `temp`) used |

---

> *"The art of programming is the art of organizing complexity."*
> — **Edsger W. Dijkstra**

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../122_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../124_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
