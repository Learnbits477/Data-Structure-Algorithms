# Palindrome Pairs - Approach
<div align="center">

| [Problem.md](Problem.md) | [Approach.md](Approach.md) | [Solution.cpp](Solution.cpp) | [Main.cpp](Main.cpp) |
| :---: | :---: | :---: | :---: |

</div>

---

> [!TIP]
> Instead of brute-forcing all O(n²) pairs, store every string in a **HashMap**. For each string, try every split point and ask: *"Does the complement that makes a palindrome exist in the map?"* This drops the complexity from O(n²·L) to O(n·L²).

---

## HashMap + Split Logic Breakdown

To solve this efficiently, we use a **HashMap lookup strategy** based on splitting each string at every possible position.

---

### 1. The Core Palindrome Observation

For `arr[i] + arr[j]` to be a palindrome, split `arr[i]` at position `k`:

$$arr[i] = \underbrace{arr[i][0..k-1]}_{\text{prefix}} + \underbrace{arr[i][k..L-1]}_{\text{suffix}}$$

Two cases arise:

- **Case A** — If `prefix` is a palindrome, we need `arr[j] = reverse(suffix)`
  Then: `arr[j] + arr[i]` forms a palindrome.

- **Case B** — If `suffix` is a palindrome, we need `arr[j] = reverse(prefix)`
  Then: `arr[i] + arr[j]` forms a palindrome.

---

### 2. Why HashMap?

Checking every pair `(i, j)` naively is O(n²·L). Instead:

- Store all strings in `map[string] = index` upfront in O(n·L).
- For each split, look up the required complement in O(L) time.
- Total: O(n·L²) — and since `L ≤ 10`, this is effectively O(n).

---

### 3. Step-by-Step Algorithm

1. **Build HashMap**: For each `arr[i]`, store `map[arr[i]] = i`.
2. **Outer loop**: Iterate every string `arr[i]`.
3. **Inner loop**: Try every split point `k` from `0` to `L`.
4. **Case A check**: If `arr[i][0..k-1]` is a palindrome → look up `reverse(suffix)` in map.
5. **Case B check**: If `arr[i][k..L-1]` is a palindrome (and `k != L`) → look up `reverse(prefix)` in map.
6. **On hit**: If lookup succeeds and index differs from `i` → return `true`.
7. **No hit**: Exhausted all strings and splits → return `false`.

---

## Visual Representation

### Logic Flow

```mermaid
flowchart TD
    A([Start]) --> B["PHASE 1: Build HashMap\nmap[arr[i]] = i  for all i"]
    B --> C["PHASE 2: Outer Loop\nfor i = 0 to n-1"]
    C --> D["Inner Loop\nfor k = 0 to L"]
    D --> E["Split arr[i] at k\nprefix = arr[i][0..k-1]\nsuffix = arr[i][k..L-1]"]

    E --> F{"isPalin(prefix)?"}
    E --> G{"isPalin(suffix)?\nguard: k != L"}

    F -- Yes --> H["rev = reverse(suffix)"]
    H --> I{"map has rev\nAND map[rev] != i?"}
    I -- Yes --> R1([Return TRUE])
    I -- No --> D

    G -- Yes --> J["rev = reverse(prefix)"]
    J --> K{"map has rev\nAND map[rev] != i?"}
    K -- Yes --> R1
    K -- No --> D

    F -- No --> D
    G -- No --> D

    D -- "all k done" --> C
    C -- "all i done" --> R2([Return FALSE])
```

---

### String Split Anatomy

```mermaid
flowchart LR
    subgraph Input["arr[0] = geekf   L = 5"]
        direction LR
        G["g"] --- E1["e"] --- E2["e"] --- K["k"] --- F["f"]
    end

    subgraph Split["Split at k = 4"]
        direction LR
        P["prefix = geek\nisPalin? NO"] -. "Case B check" .-> S["suffix = f\nisPalin? YES"]
    end

    subgraph Lookup["HashMap Lookup"]
        direction TB
        Rev["rev = reverse(geek) = keeg"]
        Found["map[keeg] = 3\nindex 3 != 0  valid!"]
        Rev --> Found
    end

    subgraph Result["Result"]
        T(["Return TRUE"])
    end

    Input --> Split
    Split --> Lookup
    Lookup --> Result
```

---

### Dry Run — State Machine

```mermaid
stateDiagram-v2
    [*] --> BuildMap : Start
    BuildMap : Build HashMap
    BuildMap : geekf=0  geeks=1  or=2
    BuildMap : keeg=3   abc=4   bc=5

    BuildMap --> ScanGeekf : i = 0

    ScanGeekf : Scanning arr[0] = geekf
    ScanGeekf --> k0 : k = 0
    ScanGeekf --> k1 : k = 1
    ScanGeekf --> k4 : k = 4

    k0 : prefix=empty  isPalin YES
    k0 : rev(geekf) = fkeeg  NOT in map
    k0 --> ScanGeekf : miss

    k1 : prefix=g  isPalin YES
    k1 : rev(eekf) = fkee  NOT in map
    k1 --> ScanGeekf : miss

    k4 : suffix=f  isPalin YES
    k4 : rev(geek) = keeg  FOUND in map
    k4 : index 3 != 0  valid pair

    k4 --> PairFound : hit

    PairFound : geekf + keeg = geekfkeeg
    PairFound --> [*] : Return TRUE
```

---

## Complexity Analysis

- **Time Complexity**: $O(n \cdot L^2)$
    - Building HashMap: $O(n \cdot L)$
    - Outer loop × inner loop × palindrome check: $O(n \cdot L \cdot L)$
    - Since $L \leq 10$: effectively $O(n)$ in practice
- **Space Complexity**: $O(n \cdot L)$
    - HashMap stores $n$ strings of max length $L$

---

> "The most powerful tool we have as developers is automation." — Scott Hanselman


---

<div align="center">
Happy Coding! 🚀
</div>

