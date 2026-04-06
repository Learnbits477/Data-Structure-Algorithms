# [Huffman Encoding](https://www.geeksforgeeks.org/problems/huffman-encoding3345/1)

## Problem Description

Given a string `s` of distinct characters and their corresponding frequency `f[ ]` i.e. character `s[i]` has `f[i]` frequency. You need to build the Huffman tree and return all the huffman codes in preorder traversal of the tree.

**Note:** While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

## Examples

**Example 1:**

```text
Input:
s = "abcdef"
f = [5, 9, 12, 13, 16, 45]
Output:
[0, 100, 101, 1100, 1101, 111]
```

**Explanation:**

```text
           [100]
          /     \
      [f 45]    [55]
               /    \
             [25]   [30]
            /   \   /   \
       [c 12][d 13][14] [e 16]
                   /  \
                [a 5][b 9]
```

HuffmanCodes will be:
f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111

## Constraints

- `1 <= s.size() == f.size() <= 26`
