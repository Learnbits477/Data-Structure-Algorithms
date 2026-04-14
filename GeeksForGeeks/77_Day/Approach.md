<h1 align="center">Remove Spaces 🚀</h1>

---

## 💡 Quick Overview

<div align="center">
  <img src="https://img.shields.io/badge/Complexity-O(N)-green" alt="Time Complexity">
  <img src="https://img.shields.io/badge/Space-O(1)-blue" alt="Space Complexity">
</div>

The problem requires us to remove all spaces from a given string `s` in-place while keeping the relative order of the non-space characters intact.

---

## 📝 Approach Details
 
We can accomplish this efficiently by using the built-in C++ STL algorithms. Alternatively, a manual string character matching loop using two pointers could also be used.

### 🔍 Step-by-Step Visual Execution

Consider the string: `s = "a b c"` (Length: 5)

**Initial State:**
| Index | 0 | 1 | 2 | 3 | 4 |
| :---: | :---: | :---: | :---: | :---: | :---: |
| **Char**| `a` | ` ` | `b` | ` ` | `c` |

<br>

**1. Shift Non-Space Characters (`std::remove`):**
The algorithm sweeps through the string and immediately packs valid (non-space) characters to the front. The elements at the end become unneeded duplicates.
| Index | 0 | 1 | 2 | 3 | 4 |
| :---: | :---: | :---: | :---: | :---: | :---: |
| **Char**| `a` | `b` | `c` | ` ` | `c` |

*(Note: The `std::remove` returns a `new_end` iterator pointing to index 3. Anything at or after index 3 is now leftover trash!)*

<br>

**2. Delete Leftovers (`s.erase`):**
The `s.erase` function trims the string directly from our `new_end` all the way to `s.end()`.
| Index | 0 | 1 | 2 |
| :---: | :---: | :---: | :---: |
| **Char**| `a` | `b` | `c` |

**Final Returned String:** `"abc"`

---

### 1. Using C++ STL (Clean Code / Optimal)

1. **`std::remove(s.begin(), s.end(), ' ')`**:
   - The `remove` method shifts all characters that are not a space towards the beginning of the string.
   - It returns an iterator pointing to the new logical end of the string (after all the non-space characters have been compacted to the front).
2. **`s.erase(...)`**:
   - The `erase` method removes the remaining "trash" characters starting from the iterator returned by `std::remove` all the way to the actual string end `s.end()`.

### 2. Two Pointers (Alternative Logic mapping to how remove works internally)

1. Maintain a single `count` variable initialized to `0`. It keeps track of the non-space characters.
2. Iterate through the string `s` with a loop index `i`.
3. When `s[i]` is not a space, assign `s[i]` to `s[count]` and increment `count`.
4. Finally, use `s.resize(count)` or return `s.substr(0, count)`.

---

## 💻 Code Implementation

```cpp
class Solution {
  public:
    string removeSpaces(string& s) {
        // Option 1: Using STL remove and erase
        // Shifts non-space characters to front and returns the new valid end Iterator
        auto new_end = std::remove(s.begin(), s.end(), ' ');
        
        // Erase remaining elements
        s.erase(new_end, s.end());
        
        return s;
    }
};
```

---

## 📈 Complexity Analysis

- **Time Complexity:** **O(N)**
  - The `std::remove()` algorithm processes the string linearly in a single pass of length `N`, doing at most `N` character assignments. Erasing the tail takes `O(N)` at most, keeping the overall time complexity bounded exactly linearly at $O(N)$.
- **Space Complexity:** **O(1)**
  - We are modifying the string in-place without using any auxiliary extra memory vectors or strings. Space used is auxiliary $O(1)$.
