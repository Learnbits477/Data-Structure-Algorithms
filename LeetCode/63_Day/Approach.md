# Approach: 3474. Lexicographically Smallest Generated String

## Problem Analysis

The goal is to determine the lexicographically smallest string `word` such that:
1. For each $i$ where `str1[i] == 'T'`, the window `word[i...i+m-1]` equals `str2`.
2. For each $i$ where `str1[i] == 'F'`, the window `word[i...i+m-1]` does not equal `str2`.

---

## Step-by-Step Implementation

### Step 1: Initial Constraints ('T')
We first fill all characters required by the 'T' conditions. If we encounter a conflict, the problem is impossible.

```cpp
for (int i = 0; i < n; i++) {
    if (str1[i] == 'T') {
        for (int j = 0; j < m; j++) {
            if (res[i+j] != '?' && res[i+j] != str2[j]) return ""; 
            res[i+j] = str2[j];
        }
    }
}
```

### Step 2: Tracking Window Status ('F')
For each 'F' index, we track the number of unknowns (`?`) and mismatches with `str2` to quickly identify restricted indices.

```cpp
vector<int> unknownCount(n, 0), mismatchCount(n, 0);
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (res[i+j] == '?') unknownCount[i]++;
        else if (res[i+j] != str2[j]) mismatchCount[i]++;
    }
    // Already matches str2 but str1[i] is 'F'
    if (str1[i] == 'F' && unknownCount[i] == 0 && mismatchCount[i] == 0) return "";
}
```

### Step 3: Greedy Filling
We iterate left-to-right. For each `?`, we collect "forbidden" characters from 'F' windows that have only one `?` left (at index `i`) and no other mismatches.

```cpp
for (int i = 0; i < totalLen; i++) {
    if (res[i] != '?') continue;
    
    vector<bool> forbidden(26, false);
    for (int j = max(0, i - m + 1); j <= min(n - 1, i); j++) {
        if (str1[j] == 'F' && unknownCount[j] == 1 && mismatchCount[j] == 0) {
            forbidden[str2[i - j] - 'a'] = true;
        }
    }
    
    // Pick smallest character not forbidden
    for (int k = 0; k < 26; k++) {
        if (!forbidden[k]) {
            res[i] = (char)('a' + k);
            break;
        }
    }
    
    // Update mismatch and unknown counts for covered windows
    for (int j = max(0, i - m + 1); j <= min(n - 1, i); j++) {
        unknownCount[j]--;
        if (res[i] != str2[i - j]) mismatchCount[j]++;
    }
}
```

---

## Complexity Analysis

- **Time Complexity**: $O((n+m) \cdot m)$. With $n=10^4, m=500$, total operations are $\approx 5 \times 10^6$, fitting well within 1s.
- **Space Complexity**: $O(n+m)$ for status arrays and the result string.

---

[Problem Link](https://leetcode.com/problems/lexicographically-smallest-generated-string/)
