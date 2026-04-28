# ⚙️ Algorithms — Lab Collection in C++

> **Re-implemented in C++** · Raw arrays only · No `std::vector` · Pure logic, zero bloat

---

## 📂 Lab Index

| # | Algorithm | Category | Time | Space |
|---|-----------|----------|------|-------|
| 01 | [Power of a Number](#-lab-1--power-of-a-number) | Recursion | O(log n) | O(log n) |
| 02 | [Tower of Hanoi](#-lab-2--tower-of-hanoi) | Recursion | O(2ⁿ) | O(n) |
| 03 | [Permutations of a String](#-lab-3--permutations-of-a-string) | Backtracking | O(n!) | O(n) |
| 04 | [Velocity Reduction](#-lab-4--velocity-reduction) | Recursion | O(k) | O(k) |
| 05 | [Horner's Rule](#-lab-5--horners-rule) | Recursion | O(n) | O(n) |
| 06 | [Find Duplicate](#-lab-6--find-duplicate-in-consecutive-array) | Linear Scan | O(n) | O(1) |
| 07 | [Selection Sort](#-lab-7--selection-sort) | Sorting | O(n²) | O(n) |
| 08 | [Bubble Sort](#-lab-8--bubble-sort) | Sorting | O(n²) | O(n) |
| 09 | [Linear Search](#-lab-9--linear-search) | Searching | O(n) | O(n) |
| 10 | [Binary Search](#-lab-10--binary-search) | Searching | O(log n) | O(log n) |
| 11 | [Insertion Sort](#-lab-11--insertion-sort) | Sorting | O(n²) | O(1) |
| 12 | [Merge Sort](#-lab-12--merge-sort) | Divide & Conquer | O(n log n) | O(n) |
| 13 | [Quick Sort (Recursive)](#-lab-13--quick-sort-recursive) | Divide & Conquer | O(n log n) | O(log n) |
| 14 | [Quick Sort (Iterative)](#-lab-14--quick-sort-iterative) | Divide & Conquer | O(n log n) | O(log n) |
| 15 | [Convex Hull](#-lab-15--convex-hull) | Geometry | O(n log n) | O(n) |
| 16 | [Fractional Knapsack](#-lab-16--fractional-knapsack) | Greedy | O(n log n) | O(1) |
| 17 | [K-th Smallest (Quickselect)](#-lab-17--k-th-smallest-quickselect) | Divide & Conquer | O(n) avg | O(log n) |
| 18 | [Max & Min (D&C)](#-lab-18--max--min-divide--conquer) | Divide & Conquer | O(n) | O(log n) |
| 19 | [Dijkstra's Algorithm](#-lab-19--dijkstras-shortest-path) | Graph / Greedy | O((V+E) log V) | O(V) |
| 20 | [Prim's Algorithm](#-lab-20--prims-mst) | Graph / Greedy | O(V²) | O(V) |
| 21 | [Kruskal's Algorithm](#-lab-21--kruskals-mst) | Graph / Union-Find | O(E log E) | O(V+E) |
| 22 | [Stage Construction](#-lab-22--multistage-graph--stage-construction) | Graph | O(V²) | O(V) |
| 23 | [Backward Multistage](#-lab-23--multistage-graph-backward) | DP / Graph | O(V²) | O(V) |
| 24 | [Forward Multistage](#-lab-24--multistage-graph-forward) | DP / Graph | O(V²) | O(V) |
| 25 | [Matrix Chain Multiplication](#-lab-25--matrix-chain-multiplication) | DP | O(n³) | O(n²) |
| 26 | [Floyd-Warshall](#-lab-26--floyd-warshall) | DP / Graph | O(V³) | O(V²) |
| 27 | [TSP (Bitmask DP)](#-lab-27--travelling-salesman-problem) | DP | O(n² · 2ⁿ) | O(n · 2ⁿ) |
| 28 | [Graph Coloring](#-lab-28--graph-coloring) | Backtracking | Exponential | O(n) |
| 29 | [Hamiltonian Cycle](#-lab-29--hamiltonian-cycle) | Backtracking | O(n!) | O(n) |
| 30 | [N-Queens](#-lab-30--n-queens-problem) | Backtracking | O(n!) | O(n) |
| 31 | [Sum of Subsets](#-lab-31--sum-of-subsets) | Backtracking | Exponential | O(n) |

---

## 🔬 Lab 1 · Power of a Number

**Aim:** Compute xⁿ using divide-and-conquer recursion.

**Optimized — O(log n):**
```cpp
double power(double x, int n) {
    if (n == 0) return 1.0;
    if (n < 0)  return 1.0 / power(x, -n);
    double half = power(x, n / 2);
    return (n % 2 == 0) ? half * half : x * half * half;
}
```

**Simple — O(n):**
```cpp
double simplePower(double x, int n) {
    if (n == 0) return 1.0;
    return x * simplePower(x, n - 1);
}
```

> **Use cases:** Fast exponentiation, modular arithmetic, graphics transformations.

---

## 🗼 Lab 2 · Tower of Hanoi

**Aim:** Print every move to shift `n` disks from source to destination.

```cpp
void TOH(int n, char src, char dest, char aux) {
    if (n <= 0) return;
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", src, dest);
        return;
    }
    TOH(n - 1, src, aux, dest);
    printf("Move disk %d from %c to %c\n", n, src, dest);
    TOH(n - 1, aux, dest, src);
}
```

> **Use cases:** Recursion pedagogy, divide-and-conquer design, state-transition puzzles.

---

## 🔀 Lab 3 · Permutations of a String

**Aim:** Generate all permutations via backtracking.

```cpp
void perm(char s[], int i, int n) {
    if (i == n) {
        printf("%s\n", s);
        return;
    }
    for (int j = i; j < n; j++) {
        char tmp = s[i]; s[i] = s[j]; s[j] = tmp;   // swap in
        perm(s, i + 1, n);
        tmp = s[i]; s[i] = s[j]; s[j] = tmp;         // swap back
    }
}
```

> **Use cases:** Anagram generation, exhaustive combinatorial search.

---

## 🏎️ Lab 4 · Velocity Reduction

**Aim:** Count steps until velocity `v` drops below 1 when reduced by 42.5% each step.

```cpp
int tips(double v, int t) {
    if (v < 1) return t;
    return tips(v - 0.425 * v, t + 1);
}
```

> **Use cases:** Decay simulations, physics-based threshold modeling.

---

## 📐 Lab 5 · Horner's Rule

**Aim:** Represent a polynomial using nested multiplication.

```cpp
// arr holds coefficients, x is the evaluation point
double HR(int arr[], int n, int i, double x) {
    if (i == n - 1) return arr[i];
    return arr[i] + x * HR(arr, n, i + 1, x);
}
```

> **Use cases:** Polynomial evaluation, compiler expression optimization, numerical methods.

---

## 🔍 Lab 6 · Find Duplicate in Consecutive Array

**Aim:** Locate the single duplicate in a consecutive-integer array.

```cpp
int findDup(int nums[], int n) {
    for (int i = 0; i < n; i++)
        if (nums[i] != i) return nums[i];
    return -1;
}
```

> **Use cases:** Data integrity checks, anomaly detection in ordered sequences.

---

## 🔃 Lab 7 · Selection Sort

**Aim:** Recursively sort an array by repeatedly selecting the minimum.

```cpp
void selectionSort(int arr[], int n, int i) {
    if (i >= n) return;
    int minIdx = i;
    for (int j = i + 1; j < n; j++)
        if (arr[j] < arr[minIdx]) minIdx = j;
    int tmp = arr[i]; arr[i] = arr[minIdx]; arr[minIdx] = tmp;
    selectionSort(arr, n, i + 1);
}
```

> **Use cases:** Small datasets, teaching in-place sorting fundamentals.

---

## 🫧 Lab 8 · Bubble Sort

**Aim:** Recursively bubble the largest element to the end each pass.

```cpp
void bubbleSort(int arr[], int n) {
    if (n == 1) return;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1]) {
            int t = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = t;
        }
    bubbleSort(arr, n - 1);
}
```

> **Use cases:** Algorithm complexity demonstrations, nearly-sorted inputs.

---

## 🔎 Lab 9 · Linear Search

**Aim:** Recursively scan an array for a target element.

```cpp
int linearSearch(int arr[], int n, int target, int i) {
    if (i >= n) return -1;
    if (arr[i] == target) return i;
    return linearSearch(arr, n, target, i + 1);
}
```

> **Use cases:** Unsorted small datasets, simple lookup problems.

---

## ⚡ Lab 10 · Binary Search

**Aim:** Efficiently locate a target in a sorted array.

```cpp
int binarySearch(int arr[], int target, int s, int e) {
    if (s > e) return -1;
    int m = s + (e - s) / 2;
    if (arr[m] == target) return m;
    if (arr[m] > target)  return binarySearch(arr, target, s, m - 1);
    return binarySearch(arr, target, m + 1, e);
}
```

> **Use cases:** Sorted database lookups, dictionary search, range queries.

---

## 🃏 Lab 11 · Insertion Sort

**Aim:** Sort by inserting each element into its correct position.

```cpp
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

> **Use cases:** Nearly-sorted data, online/incremental sorting, small datasets.

---

## 🧩 Lab 12 · Merge Sort

**Aim:** Stable O(n log n) sort using divide-and-conquer.

```cpp
void merge(int arr[], int s, int m, int e) {
    int len = e - s + 1;
    int temp[len];
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e)
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    while (i <= m) temp[k++] = arr[i++];
    while (j <= e) temp[k++] = arr[j++];
    for (int x = 0; x < len; x++) arr[s + x] = temp[x];
}

void mergeSort(int arr[], int s, int e) {
    if (s >= e) return;
    int m = s + (e - s) / 2;
    mergeSort(arr, s, m);
    mergeSort(arr, m + 1, e);
    merge(arr, s, m, e);
}
```

> **Use cases:** Large datasets, stable sort requirements, external/file sorting.

---

## ⚡ Lab 13 · Quick Sort (Recursive)

**Aim:** In-place fast sort using a pivot partition strategy.

```cpp
void quickSort(int arr[], int s, int e) {
    if (s >= e) return;
    int pivot = arr[(s + e) / 2];
    int i = s, j = e;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int t = arr[i]; arr[i++] = arr[j]; arr[j--] = t;
        }
    }
    quickSort(arr, s, j);
    quickSort(arr, i, e);
}
```

> **Use cases:** General-purpose in-memory sorting, high-performance applications.

---

## 🔁 Lab 14 · Quick Sort (Iterative)

**Aim:** Quick sort using an explicit stack — no recursion overhead.

```cpp
// Manual stack using a fixed-size array of pairs
void quickSortIter(int arr[], int s, int e) {
    int stack[2 * (e - s + 1)];
    int top = -1;
    stack[++top] = s;
    stack[++top] = e;

    while (top >= 0) {
        int r = stack[top--];
        int l = stack[top--];
        if (l >= r) continue;

        int pivot = arr[(l + r) / 2];
        int i = l, j = r;
        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) {
                int t = arr[i]; arr[i++] = arr[j]; arr[j--] = t;
            }
        }
        if (l < j) { stack[++top] = l; stack[++top] = j; }
        if (i < r) { stack[++top] = i; stack[++top] = r; }
    }
}
```

> **Use cases:** Recursion-limited environments, embedded systems, stack-overflow prevention.

---

## 🌐 Lab 15 · Convex Hull

**Aim:** Compute the convex hull of planar points (Graham Scan / Monotone Chain style).

```cpp
struct Point { int x, y; };

long long cross(Point O, Point A, Point B) {
    return (long long)(A.x - O.x) * (B.y - O.y)
         - (long long)(A.y - O.y) * (B.x - O.x);
}

// Returns hull size; hull[] is filled with result points
int convexHull(Point pts[], int n, Point hull[]) {
    // sort by x then y
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (pts[j].x < pts[i].x || (pts[j].x == pts[i].x && pts[j].y < pts[i].y)) {
                Point t = pts[i]; pts[i] = pts[j]; pts[j] = t;
            }
    int k = 0;
    // lower hull
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(hull[k-2], hull[k-1], pts[i]) <= 0) k--;
        hull[k++] = pts[i];
    }
    // upper hull
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(hull[k-2], hull[k-1], pts[i]) <= 0) k--;
        hull[k++] = pts[i];
    }
    return k - 1;
}
```

> **Use cases:** Computational geometry, collision detection, geographic boundary calculation.

---

## 🎒 Lab 16 · Fractional Knapsack

**Aim:** Maximize value with fractional item selection — greedy by value/weight ratio.

```cpp
// items[][0]=value, items[][1]=weight; sorted descending by ratio beforehand
double fractionalKnapsack(int items[][2], int n, int W) {
    // sort by ratio descending (simple selection-sort style)
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if ((double)items[j][0]/items[j][1] > (double)items[i][0]/items[i][1]) {
                int t0 = items[i][0], t1 = items[i][1];
                items[i][0] = items[j][0]; items[i][1] = items[j][1];
                items[j][0] = t0;          items[j][1] = t1;
            }
    double res = 0;
    for (int i = 0; i < n && W > 0; i++) {
        int take = (W < items[i][1]) ? W : items[i][1];
        res += (double)take * items[i][0] / items[i][1];
        W -= take;
    }
    return res;
}
```

> **Use cases:** Resource allocation, cargo loading, budget optimization.

---

## 🎯 Lab 17 · K-th Smallest (Quickselect)

**Aim:** Find the k-th smallest element without full sorting.

```cpp
int quickselect(int a[], int k, int l, int r) {
    if (l == r) return a[l];
    int pivot = a[l + (r - l) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) { int t = a[i]; a[i++] = a[j]; a[j--] = t; }
    }
    if (k <= j) return quickselect(a, k, l, j);
    if (k >= i) return quickselect(a, k, i, r);
    return a[k];
}
```

> **Use cases:** Median finding, order statistics, top-k ranking.

---

## 📊 Lab 18 · Max & Min (Divide & Conquer)

**Aim:** Find both max and min with fewer comparisons than two linear scans.

```cpp
struct MinMax { int mn, mx; };

MinMax maxMin(int a[], int l, int r) {
    if (l == r) return {a[l], a[l]};
    int m = (l + r) / 2;
    MinMax L = maxMin(a, l, m);
    MinMax R = maxMin(a, m + 1, r);
    return {
        L.mn < R.mn ? L.mn : R.mn,
        L.mx > R.mx ? L.mx : R.mx
    };
}
```

> **Use cases:** Range queries, statistical processing, data normalization.

---

## 🗺️ Lab 19 · Dijkstra's Shortest Path

**Aim:** Single-source shortest path in a non-negative weighted graph.

```cpp
#include <climits>
// graph[u][v] = weight, -1 means no edge; n = vertex count
void dijkstra(int graph[][100], int n, int src, int dist[]) {
    bool visited[100] = {};
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int iter = 0; iter < n - 1; iter++) {
        // pick min-dist unvisited vertex
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!visited[v] && (u == -1 || dist[v] < dist[u])) u = v;
        visited[u] = true;

        for (int v = 0; v < n; v++)
            if (graph[u][v] >= 0 && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
}
```

> **Use cases:** GPS navigation, network routing, map shortest paths.

---

## 🌲 Lab 20 · Prim's MST

**Aim:** Build a Minimum Spanning Tree greedily by always picking the cheapest crossing edge.

```cpp
void prims(int graph[][100], int n) {
    bool used[100] = {};
    int dist[100];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[0] = 0;

    for (int iter = 0; iter < n; iter++) {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (v == -1 || dist[j] < dist[v])) v = j;
        used[v] = true;
        for (int to = 0; to < n; to++)
            if (graph[v][to] >= 0 && graph[v][to] < dist[to])
                dist[to] = graph[v][to];
    }
}
```

> **Use cases:** Network design, cable/pipeline layout, cluster connectivity.

---

## 🔗 Lab 21 · Kruskal's MST

**Aim:** Build MST by sorting edges and merging components with union-find.

```cpp
struct Edge { int u, v, w; };
int parent[100];

int find(int x) { return parent[x] < 0 ? x : (parent[x] = find(parent[x])); }
void unite(int a, int b) { parent[find(a)] = find(b); }

int kruskal(Edge edges[], int eCount, int n) {
    // sort edges by weight (simple bubble sort for clarity)
    for (int i = 0; i < eCount - 1; i++)
        for (int j = 0; j < eCount - i - 1; j++)
            if (edges[j].w > edges[j+1].w) {
                Edge t = edges[j]; edges[j] = edges[j+1]; edges[j+1] = t;
            }
    for (int i = 0; i < n; i++) parent[i] = -1;

    int cost = 0, count = 0;
    for (int i = 0; i < eCount && count < n - 1; i++)
        if (find(edges[i].u) != find(edges[i].v)) {
            unite(edges[i].u, edges[i].v);
            cost += edges[i].w;
            count++;
        }
    return cost;
}
```

> **Use cases:** Minimum-cost network wiring, spanning tree construction.

---

## 🏗️ Lab 22 · Multistage Graph — Stage Construction

**Aim:** Identify each stage (layer) of a multistage directed graph.

```cpp
// Fills stages[][]; returns number of stages
// graph[u][v] = weight (0 or INF means no edge)
int findStages(int graph[][100], int n, int stages[][100], int stageSizes[]) {
    bool visited[100] = {};
    int numStages = 0;
    stageSizes[0] = 1;
    stages[0][0] = 0;
    visited[0] = true;

    for (int s = 0; stageSizes[s] > 0; s++) {
        stageSizes[s + 1] = 0;
        for (int k = 0; k < stageSizes[s]; k++) {
            int u = stages[s][k];
            for (int v = 0; v < n; v++)
                if (graph[u][v] && graph[u][v] != 1e7 && !visited[v]) {
                    stages[s + 1][stageSizes[s + 1]++] = v;
                    visited[v] = true;
                }
        }
        if (stageSizes[s + 1] > 0) numStages = s + 2;
    }
    return numStages;
}
```

> **Use cases:** DAG preprocessing, layered graph structuring.

---

## ➡️ Lab 23 · Multistage Graph — Backward Approach

**Aim:** Shortest path from source to sink using forward cost relaxation.

```cpp
void backwardMultistage(int graph[][100], int stages[][100],
                        int stageSizes[], int numStages, int n,
                        int cost[], int par[]) {
    const int INF = 1e7;
    for (int i = 0; i < n; i++) { cost[i] = INF; par[i] = -1; }
    cost[0] = 0;

    for (int s = 0; s < numStages - 1; s++)
        for (int ki = 0; ki < stageSizes[s]; ki++)
            for (int kj = 0; kj < stageSizes[s + 1]; kj++) {
                int u = stages[s][ki], v = stages[s + 1][kj];
                if (graph[u][v] && graph[u][v] != INF
                    && cost[u] + graph[u][v] < cost[v]) {
                    cost[v] = cost[u] + graph[u][v];
                    par[v] = u;
                }
            }
}
```

---

## ⬅️ Lab 24 · Multistage Graph — Forward Approach

**Aim:** Shortest path using backward DP (cost from destination).

```cpp
void forwardMultistage(int graph[][100], int stages[][100],
                       int stageSizes[], int numStages, int n,
                       int cost[], int d[]) {
    const int INF = 1e7;
    for (int i = 0; i < n; i++) { cost[i] = INF; d[i] = -1; }
    cost[n - 1] = 0;

    for (int s = numStages - 2; s >= 0; s--)
        for (int ki = 0; ki < stageSizes[s]; ki++)
            for (int kj = 0; kj < stageSizes[s + 1]; kj++) {
                int u = stages[s][ki], v = stages[s + 1][kj];
                if (graph[u][v] && graph[u][v] != INF
                    && graph[u][v] + cost[v] < cost[u]) {
                    cost[u] = graph[u][v] + cost[v];
                    d[u] = v;
                }
            }
}
```

---

## 🧮 Lab 25 · Matrix Chain Multiplication

**Aim:** Minimize scalar multiplications for a chain of matrices using DP.

```cpp
void matrixChain(int p[], int n, int m[][100]) {
    for (int i = 1; i <= n; i++) m[i][i] = 0;

    for (int L = 2; L <= n; L++)
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < m[i][j]) m[i][j] = q;
            }
        }
}
```

> **Use cases:** Compiler expression ordering, scientific matrix computation pipelines.

---

## 🌍 Lab 26 · Floyd-Warshall

**Aim:** All-pairs shortest paths in a weighted graph.

```cpp
void floydWarshall(int dist[][100], int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}
```

> **Use cases:** Network routing tables, dense graph analysis, transitive closure.

---

## 🚗 Lab 27 · Travelling Salesman Problem

**Aim:** Find the shortest Hamiltonian cycle using DP with bitmasking.

```cpp
int tspDP(int cost[][20], int n) {
    const int INF = INT_MAX / 4;
    int VIS = 1 << n;
    // 2D DP table on heap: dp[mask][city]
    int dp[1 << 20][20];  // Use smaller n in practice
    for (int m = 0; m < VIS; m++)
        for (int i = 0; i < n; i++) dp[m][i] = INF;
    dp[1][0] = 0;

    for (int mask = 1; mask < VIS; mask++)
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u)) || dp[mask][u] == INF) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                int next = mask | (1 << v);
                if (dp[mask][u] + cost[u][v] < dp[next][v])
                    dp[next][v] = dp[mask][u] + cost[u][v];
            }
        }

    int ans = INF;
    for (int i = 0; i < n; i++)
        if (dp[VIS - 1][i] + cost[i][0] < ans)
            ans = dp[VIS - 1][i] + cost[i][0];
    return ans;
}
```

> **Note:** Practical for n ≤ 20. Allocate `dp` dynamically for larger n.

---

## 🎨 Lab 28 · Graph Coloring

**Aim:** Assign at most `m` colors so no two adjacent vertices share a color.

```cpp
bool isSafeColor(int v, int c, int graph[][100], int color[], int n) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] == 1 && color[i] == c) return false;
    return true;
}

void graphColor(int v, int graph[][100], int color[], int n, int m) {
    if (v == n) {
        for (int i = 0; i < n; i++) printf("%d ", color[i]);
        printf("\n");
        return;
    }
    for (int c = 1; c <= m; c++)
        if (isSafeColor(v, c, graph, color, n)) {
            color[v] = c;
            graphColor(v + 1, graph, color, n, m);
            color[v] = 0;
        }
}
```

> **Use cases:** Register allocation, exam scheduling, frequency assignment.

---

## 🔄 Lab 29 · Hamiltonian Cycle

**Aim:** Find a cycle visiting every vertex exactly once.

```cpp
bool isSafeHam(int k, int graph[][100], int x[], int n) {
    if (graph[x[k-1]][x[k]] == 0) return false;
    for (int i = 0; i < k; i++)
        if (x[i] == x[k]) return false;
    return true;
}

void hamiltonian(int k, int graph[][100], int x[], int n) {
    for (int v = 1; v < n; v++) {
        x[k] = v;
        if (isSafeHam(k, graph, x, n)) {
            if (k == n - 1 && graph[x[k]][x[0]] == 1) {
                for (int i = 0; i < n; i++) printf("%d ", x[i]);
                printf("%d\n", x[0]);
            } else {
                hamiltonian(k + 1, graph, x, n);
            }
        }
    }
    x[k] = 0;
}
```

> **Use cases:** Circuit design, route planning with mandatory stops.

---

## 👑 Lab 30 · N-Queens Problem

**Aim:** Place N queens on an N×N board with no two attacking each other.

```cpp
int solutions = 0;

bool isSafeQueen(int k, int i, int x[]) {
    for (int j = 0; j < k; j++)
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) return false;
    return true;
}

void nQueens(int k, int x[], int n) {
    if (k == n) { solutions++; return; }
    for (int i = 0; i < n; i++)
        if (isSafeQueen(k, i, x)) {
            x[k] = i;
            nQueens(k + 1, x, n);
        }
}
```

> **Use cases:** Constraint satisfaction, backtracking benchmarks, puzzle solvers.

---

## ➕ Lab 31 · Sum of Subsets

**Aim:** Find all subsets whose elements sum to a target W.

```cpp
void sumOfSubsets(int s, int k, int r, int w[], int x[], int n, int W) {
    x[k] = 1;
    if (s + w[k] == W) {
        for (int i = 0; i <= k; i++) if (x[i]) printf("%d ", w[i]);
        printf("\n");
    } else if (k + 1 < n && s + w[k] + w[k+1] <= W) {
        sumOfSubsets(s + w[k], k + 1, r - w[k], w, x, n, W);
    }

    if (k + 1 < n && s + r - w[k] >= W && s + w[k+1] <= W) {
        x[k] = 0;
        sumOfSubsets(s, k + 1, r - w[k], w, x, n, W);
    }
}
```

> **Use cases:** Subset selection, resource budgeting, combinatorial optimization.

---

## 🛠️ Build & Run

All files are standard C++ — compile with any modern compiler:

```bash
# GCC
g++ -O2 -std=c++17 filename.cpp -o out && ./out

# Clang
clang++ -O2 -std=c++17 filename.cpp -o out && ./out
```

No external libraries required. No `std::vector` used anywhere in this collection.

---

## 📁 Repository Structure

```
Algorithms/
├── Lab 1/   → Power of Number
├── Lab 2/   → Tower of Hanoi
├── Lab 3/   → Permutations
├── Lab 4/   → Velocity Reduction
├── Lab 5/   → Horner's Rule
├── Lab 6/   → Find Duplicate
├── Lab 7/   → Selection Sort
├── Lab 8/   → Bubble Sort
├── Lab 9/   → Linear Search
├── Lab 10/  → Binary Search
├── Lab 11/  → Insertion Sort + Merge Sort
├── Lab 12/  → (see Lab 11)
├── Lab 13/  → Quick Sort
└── ...      → Graphs, DP, Backtracking


