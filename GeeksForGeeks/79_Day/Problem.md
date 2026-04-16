# [🔢 Implement Atoi](https://www.geeksforgeeks.org/problems/implement-atoi/1)

<div align="center">

[![GeeksForGeeks](https://img.shields.io/badge/GeeksForGeeks-0F9D58?style=for-the-badge&logo=geeksforgeeks&logoColor=white)](https://www.geeksforgeeks.org/problems/implement-atoi/1)
[![Difficulty](https://img.shields.io/badge/Difficulty-Medium-FFA500?style=for-the-badge)](https://www.geeksforgeeks.org/problems/implement-atoi/1)
[![Accuracy](https://img.shields.io/badge/Accuracy-32.58%25-red?style=for-the-badge)](https://www.geeksforgeeks.org/problems/implement-atoi/1)
[![Points](https://img.shields.io/badge/Points-4-blue?style=for-the-badge)](https://www.geeksforgeeks.org/problems/implement-atoi/1)
[![Avg Time](https://img.shields.io/badge/Avg%20Time-15%20min-purple?style=for-the-badge)](https://www.geeksforgeeks.org/problems/implement-atoi/1)

</div>

---

## 📌 Problem Statement

Given a string `s`, convert it into a **32-bit signed integer** (similar to C's `atoi()` function) **without using any built-in conversion functions**.

---

## 📋 Conversion Rules

```
┌─────────────────────────────────────────────────────────────────┐
│  STEP 1 │ IGNORE LEADING WHITESPACES                            │
│         │ Skip all ' ' characters at the beginning              │
├─────────────────────────────────────────────────────────────────┤
│  STEP 2 │ CHECK SIGN                                            │
│         │ Read '+' or '-'. Default sign is positive (+)         │
├─────────────────────────────────────────────────────────────────┤
│  STEP 3 │ READ DIGITS                                           │
│         │ Accumulate digits. Stop at non-digit or end of string │
│         │ If no digits found → return 0                         │
├─────────────────────────────────────────────────────────────────┤
│  STEP 4 │ HANDLE OVERFLOW                                       │
│         │  > 2147483647  →  return  2147483647  (INT_MAX)       │
│         │  < -2147483648 →  return -2147483648  (INT_MIN)       │
└─────────────────────────────────────────────────────────────────┘
```

---

## 🧩 Valid Integer Range

```
   INT_MIN                              INT_MAX
      │                                    │
 ─2147483648 ◄──────── 32-bit Signed ────► 2147483647
      │                  Integer            │
     -2³¹                                 2³¹-1
```

---

## 📖 Examples

### ✅ Example 1 — Basic Negative Number
```
Input  : s = "-123"
Output : -123
Reason : Valid signed integer, return as-is.
```

### ✅ Example 2 — Sign Without Digits
```
Input  : s = " -"
Output : 0
Reason : No digits follow the sign → return 0.
```

### ✅ Example 3 — Positive Overflow
```
Input  : s = " 1231231231311133"
Output : 2147483647
Reason : Exceeds INT_MAX → clamp to 2³¹ − 1.
```

### ✅ Example 4 — Negative Overflow (Underflow)
```
Input  : s = "-999999999999"
Output : -2147483648
Reason : Below INT_MIN → clamp to −2³¹.
```

### ✅ Example 5 — Non-Digit Termination
```
Input  : s = "  -0012gfg4"
Output : -12
Reason : Stops reading at 'g' (non-digit). Returns -12.

   s:  ' '  ' '  '-'  '0'  '0'  '1'  '2'  'g'  'f'  'g'  '4'
        ↑↑       ↑    ←─────────────────→    ↑
      SKIP    SIGN        DIGITS           STOP
```

---

## ⚙️ Constraints

| Parameter     | Bound        |
| :------------ | :----------- |
| String length | `1 ≤ \|s\| ≤ 15` |
| Output range  | `[−2³¹, 2³¹ − 1]` |

---

## 🏷️ Topic Tags

`Strings` · `Parsing` · `Implementation` · `Overflow Handling`

---

## 🔗 Problem Link

> 👉 [Implement Atoi — GeeksForGeeks](https://www.geeksforgeeks.org/problems/implement-atoi/1)
