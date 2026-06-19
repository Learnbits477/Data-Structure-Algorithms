# 💡 Approach — Find the Highest Altitude

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 84.2%](https://img.shields.io/badge/Acceptance-84.2%25-blue?style=for-the-badge)
![Submissions: 927.5K](https://img.shields.io/badge/Submissions-927.5K-brightgreen?style=for-the-badge)

</div>

---

## 🎯 Core Insight

> [!TIP]
> **Prefix Sum Accumulation:** Since we start at altitude 0, the altitude at any point $$i$$ is the prefix sum of the gains up to $$i-1$$.
> By keeping a running sum of the gains and tracking the maximum value it achieves during traversal, we can determine the highest altitude in $$O(n)$$ time and $$O(1)$$ auxiliary space.

---

## 🔩 Step-by-Step Breakdown

**Step 1: Initialize Altitudes**
- The biker starts at point `0` with altitude equal to `0`. We initialize:
  - `current_altitude = 0` (keeps track of the current altitude)
  - `max_altitude = 0` (stores the highest altitude reached so far)

**Step 2: Iterate through Gains**
- Traverse the given `gain` array of size $$n$$ element by element.

**Step 3: Update Current Altitude**
- For each gain `g`, add it to `current_altitude`: `current_altitude += g`.

**Step 4: Update Maximum Altitude**
- Compare `current_altitude` with `max_altitude`, and update `max_altitude` to store the larger value: `max_altitude = max(max_altitude, current_altitude)`.

**Step 5: Return Result**
- After finishing the traversal, `max_altitude` will hold the highest altitude of a point. Return `max_altitude`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A([Start]) --> B["current_altitude = 0<br>max_altitude = 0"]
    B --> C["For each g in gain"]
    C --> D["current_altitude += g"]
    D --> E["max_altitude = max(max_altitude, current_altitude)"]
    E --> F{"Has next element?"}
    F -- Yes --> C
    F -- No --> G["Return max_altitude"]
    G --> H([End])
```

---

## 🧮 Dry Run — Example 1

Input: `gain = [-5, 1, 5, 0, -7]`

| Step / Index | Gain `g` | Updated `current_altitude` | Updated `max_altitude` | Description |
|:---:|:---:|:---:|:---:|:---|
| **Start** | — | $$0$$ | $$0$$ | Initialized state at point 0. |
| **0** | $$-5$$ | $$0 + (-5) = -5$$ | $$\max(0, -5) = 0$$ | Biker moves to point 1. |
| **1** | $$1$$ | $$-5 + 1 = -4$$ | $$\max(0, -4) = 0$$ | Biker moves to point 2. |
| **2** | $$5$$ | $$-4 + 5 = 1$$ | $$\max(0, 1) = 1$$ | Biker moves to point 3 (New highest peak!). |
| **3** | $$0$$ | $$1 + 0 = 1$$ | $$\max(1, 1) = 1$$ | Biker moves to point 4. |
| **4** | $$-7$$ | $$1 + (-7) = -6$$ | $$\max(1, -6) = 1$$ | Biker moves to point 5. |

**Final Output:** `1` ✅

---

## 📊 Complexity Analysis

| Metric | Complexity | Reasoning |
| :---: | :---: | :--- |
| 🕐 Time | $$O(n)$$ | We make a single pass through the `gain` array of length $$n$$. |
| 💾 Space | $$O(1)$$ | Only two integer variables are used to keep track of the altitudes. |

---

> *"The peak is just a prefix sum of the steps we take to get there."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../142_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../144_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
