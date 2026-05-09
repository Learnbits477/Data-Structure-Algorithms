# [1914. Cyclically Rotating a Grid](https://leetcode.com/problems/cyclically-rotating-a-grid/)

<div align="center">

| [Problem.md](./Problem.md) | [Approach.md](./Approach.md) | [Solution.cpp](./Solution.cpp) | [Main.cpp](./Main.cpp) |
| :--- | :--- | :--- | :--- |

</div>

---

**Difficulty:** `Medium`  
**Accuracy:** `58.4%`

---

## Problem Description

You are given an **m x n** integer matrix `grid`, where **m** and **n** are both even integers, and an integer `k`.

The matrix is composed of several layers. A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the **counter-clockwise** direction.

### Layer Visualization
The matrix is composed of several layers. Each color below represents its own layer:

<div align="center">
<table style="border-collapse: collapse; border: 2px solid #333; font-family: monospace; font-weight: bold; color: #1e293b;">
  <tr>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">1</td>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">1</td>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">1</td>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">1</td>
  </tr>
  <tr>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">1</td>
    <td style="width: 40px; height: 40px; background-color: #fde047; border: 1px solid #a16207; text-align: center;">2</td>
    <td style="width: 40px; height: 40px; background-color: #fde047; border: 1px solid #a16207; text-align: center;">2</td>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">1</td>
  </tr>
  <tr>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">1</td>
    <td style="width: 40px; height: 40px; background-color: #fde047; border: 1px solid #a16207; text-align: center;">2</td>
    <td style="width: 40px; height: 40px; background-color: #fde047; border: 1px solid #a16207; text-align: center;">2</td>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">1</td>
  </tr>
  <tr>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">1</td>
    <td style="width: 40px; height: 40px; background-color: #fde047; border: 1px solid #a16207; text-align: center;">2</td>
    <td style="width: 40px; height: 40px; background-color: #fde047; border: 1px solid #a16207; text-align: center;">2</td>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">1</td>
  </tr>
  <tr>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">1</td>
    <td style="width: 40px; height: 40px; background-color: #fde047; border: 1px solid #a16207; text-align: center;">2</td>
    <td style="width: 40px; height: 40px; background-color: #fde047; border: 1px solid #a16207; text-align: center;">2</td>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">1</td>
  </tr>
  <tr>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">1</td>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">1</td>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">1</td>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">1</td>
  </tr>
</table>
</div>

---

## Examples

### Example 1
**Input:** `grid = [[40,10],[30,20]], k = 1`  
**Output:** `[[10,20],[40,30]]`  

<div align="center">
<table>
<tr>
<td>

**Initial**
<table style="border-collapse: collapse; border: 2px solid #333; font-family: monospace;">
  <tr>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">40</td>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">10</td>
  </tr>
  <tr>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">30</td>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">20</td>
  </tr>
</table>

</td>
<td style="font-size: 24px; padding: 0 20px;"> ➔ </td>
<td>

**Rotated (k=1)**
<table style="border-collapse: collapse; border: 2px solid #333; font-family: monospace;">
  <tr>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">10</td>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">20</td>
  </tr>
  <tr>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">40</td>
    <td style="width: 40px; height: 40px; background-color: #60a5fa; border: 1px solid #1e40af; text-align: center;">30</td>
  </tr>
</table>

</td>
</tr>
</table>
</div>

### Example 2
**Input:** `grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2`  
**Output:** `[[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]`

<div align="center">
<table>
<tr>
<td>

**Initial**
<table style="border-collapse: collapse; border: 2px solid #333; font-family: monospace; font-size: 12px;">
  <tr>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">1</td>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">2</td>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">3</td>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">4</td>
  </tr>
  <tr>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">5</td>
    <td style="width: 30px; height: 30px; background-color: #fde047; text-align: center;">6</td>
    <td style="width: 30px; height: 30px; background-color: #fde047; text-align: center;">7</td>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">8</td>
  </tr>
  <tr>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">9</td>
    <td style="width: 30px; height: 30px; background-color: #fde047; text-align: center;">10</td>
    <td style="width: 30px; height: 30px; background-color: #fde047; text-align: center;">11</td>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">12</td>
  </tr>
  <tr>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">13</td>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">14</td>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">15</td>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">16</td>
  </tr>
</table>

</td>
<td style="font-size: 24px; padding: 0 20px;"> ➔ </td>
<td>

**Rotated (k=2)**
<table style="border-collapse: collapse; border: 2px solid #333; font-family: monospace; font-size: 12px;">
  <tr>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">3</td>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">4</td>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">8</td>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">12</td>
  </tr>
  <tr>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">2</td>
    <td style="width: 30px; height: 30px; background-color: #fde047; text-align: center;">11</td>
    <td style="width: 30px; height: 30px; background-color: #fde047; text-align: center;">10</td>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">16</td>
  </tr>
  <tr>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">1</td>
    <td style="width: 30px; height: 30px; background-color: #fde047; text-align: center;">7</td>
    <td style="width: 30px; height: 30px; background-color: #fde047; text-align: center;">6</td>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">15</td>
  </tr>
  <tr>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">5</td>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">9</td>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">13</td>
    <td style="width: 30px; height: 30px; background-color: #60a5fa; text-align: center;">14</td>
  </tr>
</table>

</td>
</tr>
</table>
</div>

---

## Constraints

- $m == grid.length$
- $n == grid[i].length$
- $2 \le m, n \le 50$
- Both $m$ and $n$ are even integers.
- $1 \le grid[i][j] \le 5000$
- $1 \le k \le 10^9$

---

<div align="center" style="font-size: x-large; font-weight: bold; color: blue;">

# Happy Coding! 🚀

</div>
