# [Kirchhoff's Matrix Tree Theorem: Logic & Visualization](https://www.geeksforgeeks.org/problems/total-number-of-spanning-trees-in-a-graph/1)

<div align="center">

| [Problem.md](./Problem.md) | [Approach.md](./Approach.md) | [Solution.cpp](./Solution.cpp) | [Main.cpp](./Main.cpp) | [Theorem_Logic.md](./Theorem_Logic.md) |
| :--- | :--- | :--- | :--- | :--- |

</div>

---

## 🏗️ The Mathematical Foundation

Kirchhoff's Matrix Tree Theorem provides a bridge between **Graph Theory** and **Linear Algebra**. It allows us to count structural properties (spanning trees) using matrix determinants.

### 1. Matrix Definitions

To understand the theorem, we define three primary matrices:

#### A. Adjacency Matrix ($A$)
- $A_{ij} = 1$ if vertices $i$ and $j$ are connected.
- $A_{ij} = 0$ otherwise.
- It represents the "connections".

#### B. Degree Matrix ($D$)
- A diagonal matrix where $D_{ii} = \text{degree of vertex } i$.
- It represents the "capacity" of each vertex.

#### C. Laplacian Matrix ($L$)
- defined as **$L = D - A$**.
- This matrix encodes the "flow" constraints of the graph.

---

## 🔄 Visual Logic Flow

The following diagram illustrates the step-by-step transformation of a graph into a numerical result:

```mermaid
graph TD
    subgraph Input_Phase ["Graph Input"]
        G["Graph G: V vertices, E edges"]
    end

    subgraph Construction_Phase ["Matrix Construction"]
        D_mat["<b>Degree Matrix D</b><br/>Diagonal: deg(v)"]
        A_mat["<b>Adjacency Matrix A</b><br/>1 if edge exists"]
        L_mat["<b>Laplacian Matrix L</b><br/>L = D - A"]
        
        G --> D_mat
        G --> A_mat
        D_mat --> L_mat
        A_mat --> L_mat
    end

    subgraph Transformation_Phase ["The Cofactor Rule"]
        L_reduced["<b>Reduced Laplacian L'</b><br/>Remove ANY row i and column i"]
    end

    subgraph Calculation_Phase ["Determinant Computation"]
        Gauss["Gaussian Elimination"]
        Upper["Upper Triangular Form"]
        Det["Determinant = Product of Diagonals"]
        
        L_reduced --> Gauss
        Gauss --> Upper
        Upper --> Det
    end

    L_mat --> L_reduced
    Det --> Final["Total Spanning Trees"]

    style Input_Phase fill:#f5f5f5,stroke:#333
    style Construction_Phase fill:#e1f5fe,stroke:#01579b
    style Transformation_Phase fill:#fff3e0,stroke:#e65100
    style Calculation_Phase fill:#f1f8e9,stroke:#33691e
    style Final fill:#ffd54f,stroke:#f57f17,stroke-width:3px
```

---

## 🔢 Step-by-Step Example

Consider a Triangle graph ($K_3$) with vertices $\{0, 1, 2\}$.

### Step 1: Laplacian Matrix
For $K_3$, each vertex has degree 2.
$$
L = \begin{pmatrix} 
2 & -1 & -1 \\
-1 & 2 & -1 \\
-1 & -1 & 2
\end{pmatrix}
$$

### Step 2: Remove Last Row & Column
$$
L' = \begin{pmatrix} 
2 & -1 \\
-1 & 2
\end{pmatrix}
$$

### Step 3: Compute Determinant
$$
\det(L') = (2 \times 2) - (-1 \times -1) = 4 - 1 = 3
$$
**Result:** 3 Spanning Trees.

---

## 🧪 Why does this work? (Intuition)

The Laplacian matrix is related to the **Incidence Matrix** $B$ of the graph ($L = BB^T$). The **Cauchy-Binet Formula** then shows that the determinant of a submatrix of $L$ is a sum of squares of determinants of submatrices of $B$. In graph theory, these submatrices of $B$ correspond exactly to the spanning trees of the graph.

---

<div align="center">

# Happy Coding! 🚀

</div>
