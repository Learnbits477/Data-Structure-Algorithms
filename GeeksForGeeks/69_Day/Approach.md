# Huffman Encoding

## Approach

The optimal way to build a Huffman tree is to use a Greedy Approach, implemented with the help of a **Min-Heap (Priority Queue)**. By embedding a deterministic tree evaluation structure, we ensure the correct placement.

### Step-by-Step Implementation:

**1. Node Representation & Custom Comparator:**
Create a `Node` class containing the character frequency (`data`) and `index` alongside pointers to its children. A custom comparator ensures frequencies are prioritized sequentially, and `index` handles stable tie breaks correctly.

```cpp
class Node {
  public:
    int data;
    int index;
    Node *left, *right;

    Node(int d, int i) {
        data = d;
        index = i;
        left = right = nullptr;
    }

    Node(Node* l, Node* r) {
        data = l->data + r->data;
        index = min(l->index, r->index);
        left = l;
        right = r;
    }
};

class Compare {
  public:
    bool operator()(Node* a, Node* b) {
        if (a->data != b->data)
            return a->data > b->data;
        return a->index > b->index;
    }
};
```

**2. Min-Heap Initialization:**
Initialize a priority queue configured to handle `Node` structures using the custom comparator. Add elements reflecting their string positions to natively lock-in their index stability.

```cpp
    int n = S.length();
    priority_queue<Node*, vector<Node*>, Compare> pq;
    
    for (int i = 0; i < n; i++) {
        Node* tmp = new Node(f[i], i);
        pq.push(tmp);
    }

    if (n == 1)
        return {"0"};
```

**3. Huffman Tree Construction:**
Iteratively extract the two elements possessing the smallest frequencies. Combine them into a joint parent node, taking the smallest relational index, and feed it right back. Repeat until a singular node bridges the tree structure.

```cpp
    while (pq.size() >= 2) {
        Node* l = pq.top();
        pq.pop();

        Node* r = pq.top();
        pq.pop();

        Node* newNode = new Node(l, r);
        pq.push(newNode);
    }
```

**4. Prefix Code Traversal:**
Perform a string-accumulating recursion starting from the resulting root. Traverse left by appending `0` and traverse right appending `1`. Leaf nodes capture the encoded combinations directly.

```cpp
    void preOrder(Node* root, vector<string>& ans, string curr) {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr) {
            if (curr == "")
                curr = "0";
            ans.push_back(curr);
            return;
        }

        preOrder(root->left, ans, curr + '0');
        preOrder(root->right, ans, curr + '1');
    }
```

### Complexity
- **Time Complexity:** **O(N log N)** overall, since each insertion and extraction operate inside the min-heap consuming bounded `O(log N)` complexity.
- **Space Complexity:** **O(N)** for priority queue component tracking and the upper recursive traversal stack.
