# Approach: Gale-Shapley Algorithm

## Intuition

The **Stable Marriage Problem** is solved using the **Gale-Shapley algorithm**. The core principle is that men propose to women in their preference order. A woman accepts if she's free or if she prefers the new suitor over her current partner. This ensures no pair (man, woman) exists where both would prefer each other over their assigned partners.

## Step-by-Step Logic

### 1. Precomputation of Preferences
To quickly check if a woman prefers a new suitor, we convert her preference list into a rank-based lookup table.

```cpp
vector<vector<int>> womenPref(n, vector<int>(n));
for (int w = 0; w < n; w++) {
    for (int rank = 0; rank < n; rank++) {
        // stores the rank of man m for woman w
        womenPref[w][women[w][rank]] = rank;
    }
}
```

### 2. Initialization
We use arrays to track partners and a queue to manage men who are currently "free" (unengaged).

```cpp
vector<int> womenPartner(n, -1);
vector<int> menPartner(n, -1);
vector<int> nextPref(n, 0); // index of the next woman to propose to
queue<int> freeMen;

for (int m = 0; m < n; m++) freeMen.push(m);
```

### 3. Execution (The Proposal Process)
We iterate while there are free men. Each man proposes to the next woman on his list.

```cpp
while (!freeMen.empty()) {
    int m = freeMen.front();
    int w = men[m][nextPref[m]];
    nextPref[m]++; 

    if (womenPartner[w] == -1) {
        // Woman is free, engage them
        womenPartner[w] = m;
        menPartner[m] = w;
        freeMen.pop();
    } else {
        int m1 = womenPartner[w];
        // Check if woman w prefers new suitor m over current partner m1
        if (womenPref[w][m] < womenPref[w][m1]) {
            womenPartner[w] = m;
            menPartner[m] = w;
            freeMen.pop();
            
            menPartner[m1] = -1;
            freeMen.push(m1); // previous partner becomes free
        }
    }
}
```

### 4. Conclusion
Once the queue is empty, everyone is matched stably. We return the matching from the men's perspective.

```cpp
return menPartner;
```

## Complexity

- **Time Complexity:** $\mathcal{O}(N^2)$
  - Building the preference matrix takes $\mathcal{O}(N^2)$.
  - There are at most $N^2$ proposals, each taking $\mathcal{O}(1)$ time.
- **Space Complexity:** $\mathcal{O}(N^2)$
  - Storing the `womenPref` matrix requires $\mathcal{O}(N^2)$ space.
