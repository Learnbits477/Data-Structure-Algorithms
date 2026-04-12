# 🧩 1320. Minimum Distance to Type a Word Using Two Fingers

**Source:** [LeetCode #1320](https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/)  
**Difficulty:** `Hard`  
**Topics:** `Dynamic Programming`, `Manhattan Distance`, `State Management`

---

## 📜 Problem Overview

You are given a keyboard layout in a 2D plane. Each English uppercase letter is mapped to a specific $(x, y)$ coordinate. Your goal is to find the **minimum total distance** to type a given `word` using exactly two fingers.

### ⌨️ Keyboard Layout
The keyboard is organized in 6 columns as follows:

![Keyboard Layout](keyboard_layout.png)

| Row | Col 0 | Col 1 | Col 2 | Col 3 | Col 4 | Col 5 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **0** | A (0,0) | B (0,1) | C (0,2) | D (0,3) | E (0,4) | F (0,5) |
| **1** | G (1,0) | H (1,1) | I (1,2) | J (1,3) | K (1,4) | L (1,5) |
| **2** | M (2,0) | N (2,1) | O (2,2) | P (2,3) | Q (2,4) | R (2,5) |
| **3** | S (3,0) | T (3,1) | U (3,2) | V (3,3) | W (3,4) | X (3,5) |
| **4** | Y (4,0) | Z (4,1) | | | | |

---

## 📏 Core Rules & Mechanics

1.  **Distance Formula:** The distance between letter $P_1(x_1, y_1)$ and $P_2(x_2, y_2)$ is the **Manhattan Distance**:
    $$ \mathcal{D} = |x_1 - x_2| + |y_1 - y_2| $$
    
2.  **Free Initial Placement:**
    > [!IMPORTANT]
    > Your fingers can start anywhere. The very first move of each finger (to its first letter) has **zero cost**. 
    
3.  **Two-Finger Strategy:** You can choose which finger types each character in the word. One finger must move from its current position to the next character's position.

---

## 🧪 Examples & Trace

### Example 1: `word = "CAKE"`
| Step | Character | Action | Cost | Total |
| :--- | :---: | :--- | :---: | :---: |
| 1 | **C** | Finger 1 starts at 'C' | 0 | 0 |
| 2 | **A** | Finger 1 moves from 'C'(0,2) to 'A'(0,0) | $|0-0| + |2-0| = 2$ | 2 |
| 3 | **K** | Finger 2 starts at 'K'(1,4) | 0 | 2 |
| 4 | **E** | Finger 2 moves from 'K'(1,4) to 'E'(0,4) | $|1-0| + |4-4| = 1$ | **3** |

**Output:** `3`

---

## ⚙️ Constraints

- `2 <= word.length <= 300`
- `word` consists of uppercase English letters.
