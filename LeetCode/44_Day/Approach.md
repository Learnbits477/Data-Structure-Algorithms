# Approach for "Maximize Spanning Tree Stability with Upgrades"

## Intuition

The problem asks us to find a valid spanning tree (using exactly `n - 1` edges without cycles that includes all mandatory edges) such that the **minimum edge strength** (defined as stability) is maximized, given that we can upgrade at most `k` optional edges. An upgrade doubles the strength of an edge.

To maximize the minimum strength, a **binary search on the answer** is highly suitable. The strength values and possible upgraded strength values define our search space, ranging from `1` up to `2 * 10^5`.

For a given minimum strength `X` (our candidate stability), we need to check if we can form a spanning tree where **every edge has strength at least `X`** using at most `k` upgrades.

## Algorithm

1. **Mandatory Edges (must == 1):**
   - We MUST include all such edges.
   - If these edges form a cycle, we can immediately return `-1` because a valid spanning tree cannot contain a cycle.
   - These edges cannot be upgraded. Their true strength is fixed. If any mandatory edge has a strength `< X`, then `X` is unachievable. Hence, the max stability is bounded by the minimum strength of all mandatory edges (let's call it `min_must`).

2. **Connecting the Graph:**
   - Before binary searching, we tentatively add all mandatory and optional edges to a Disjoint Set Union (DSU) to check if the graph can be fully connected. If not (more than 1 component remains), we return `-1`.

3. **Binary Search `X`:**
   - The search range is `low = 1` to `high = min(min_must, 2 * max_optional_strength)`. If there are no optional edges needed (because mandatory edges already form a spanning tree), the answer is directly `min_must`.
   - To `check(X)`:
     - We start with a DSU already containing the mandatory edges.
     - We evaluate all optional edges:
       - **Cost 0 Edges:** Strength is already `>= X`. These edges are "free". We union their endpoints first, greedily adding as many as possible without introducing cycles.
       - **Cost 1 Edges:** Strength `< X` but `strength * 2 >= X`. We can use these, but each consumes one of our `k` available upgrades. We add them next to the DSU without introducing cycles and keep track of how many we use (`cost1_count`).
       - Any edge with `strength * 2 < X` is unusable and ignored.
     - After considering both sets of edges, if the graph is fully connected (`DSU.components == 1`) and the number of upgrades used is within budget (`cost1_count <= k`), then `X` is achievable.

4. **Kruskal's Optimization:**
   - Since we prioritize Cost 0 edges over Cost 1 edges, we are effectively running Kruskal's algorithm on edge weights `0` and `1`. This guarantees we form the minimal cost spanning tree for ensuring all edges have strength `>= X`.

## Complexity

- **Time Complexity:**
  - Constructing the initial DSU takes `O(E * α(N))`, where `E` is the number of edges.
  - Binary search evaluates `check(X)` up to `log2(2 * 10^5) ≈ 18` times.
  - Each `check(X)` takes `O(E * α(N))` time.
  - Total time complexity: `O(E * α(N) * log(MaxStrength))`, which easily runs within the time limit.
- **Space Complexity:** `O(N + E)` for storing edges and the Disjoint Set Union data structure.
