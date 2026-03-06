# [Smallest window containing all characters](https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1)

## Problem Description

Given two strings `s` and `p`. Find the smallest substring in `s` consisting of all the characters (including duplicates) of the string `p`. Return empty string in case no such substring is present.
If there are multiple such substring of the same length found, return the one with the least starting index.

## Examples

**Example 1:**

```text
Input: s = "timetopractice", p = "toc"
Output: "toprac"
Explanation: "toprac" is the smallest substring in which "toc" can be found.
```

**Example 2:**

```text
Input: s = "zoomlazapzo", p = "oza"
Output: "apzo"
Explanation: "apzo" is the smallest substring in which "oza" can be found.
```

**Example 3:**

```text
Input: s = "zoom", p = "zooe"
Output: ""
Explanation: No substring is present containing all characters of p.
```

## Constraints

- `1 ≤ s.length(), p.length() ≤ 10^6`
- `s`, `p` consists of lowercase english letters

## Problem URL

[Smallest window in a string containing all the characters of another string](https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1)
