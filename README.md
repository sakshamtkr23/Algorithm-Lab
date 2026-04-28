# Algorithm-Lab 

## Practical-1: Tower of Hanoi

### Aim
Transfer `n` disks from source to destination using an auxiliary rod via recursion.

---

### Algorithm (Recursive)

**Algorithm: TOH(n, src, dest, aux)**

1. If $n \leq 0$, return
2. If $n = 1$:
   - Print "Move disk 1 from src to dest"
   - Return
3. Call $TOH(n-1, src, aux, dest)$
4. Print "Move disk n from src to dest"
5. Call $TOH(n-1, aux, dest, src)$

---

### Time Complexity (TC)
- $O(2^n)$

---

### Space Complexity (SC)
- $O(n)$ (recursion stack)

---

### Code

```cpp
void TOH(int n, char src, char dest, char aux) {
    if (n <= 0) return;
    if (n == 1) {
        cout << "Move disk 1 from " << src << " to " << dest << endl;
        return;
    }
    TOH(n - 1, src, aux, dest);
    cout << "Move disk " << n << " from " << src << " to " << dest << endl;
    TOH(n - 1, aux, dest, src);
}
```

---

### Use Cases
- Understanding recursion deeply
- Divide-and-conquer strategy demonstration
- Puzzle solving and state transitions

---

## Practical-2: Bouncing Ball Simulation

### Aim
Simulate the bouncing of a ball dropped from height `h`, computing total distance travelled using recursion.

---

### Algorithm (Recursive Reduction)

**Algorithm: BOUNCE(h, factor)**

1. If $h < threshold$, return $h$
2. Compute next height $h' = h \times factor$
3. Return $h + 2 \times BOUNCE(h')$

---

### Time Complexity (TC)
- $O(k)$, where $k$ is number of bounces

---

### Space Complexity (SC)
- $O(k)$

---

### Code

```cpp
double bounce(double h, double factor) {
    if (h < 0.01) return h;
    double next = h * factor;
    return h + 2 * bounce(next, factor);
}
```

---

### Use Cases
- Physics-based modeling
- Decay/attenuation simulations
- Iterative threshold problems

---

## Practical-3: Binary Exponentiation

### Aim
Compute $x^n$ efficiently using divide-and-conquer recursion (fast power).

---

### Algorithm (Optimized — Divide and Conquer)

**Algorithm: POWER(x, n)**

1. If $n = 0$, return 1
2. If $n < 0$, return $1 / POWER(x, -n)$
3. Compute $y = POWER(x, n/2)$
4. If $n$ is even, return $y \times y$
5. Else return $x \times y \times y$

---

### Time Complexity (TC)
- $O(\log n)$

---

### Space Complexity (SC)
- $O(\log n)$

---

### Code

```cpp
double power(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) return 1.0 / power(x, -n);
    double half = power(x, n / 2);
    if (n % 2 == 0) return half * half;
    return x * half * half;
}
```

---

### Use Cases
- Fast exponentiation
- Modular exponentiation (cryptography)
- Graphics and simulation computations

---

## Practical-4: String Permutation

### Aim
Generate all permutations of a string using recursion and backtracking.

---

### Algorithm (Backtracking)

**Algorithm: PERM(s, i)**

1. If $i = n$:
   - Output current permutation of string $s$
   - Return
2. For $j = i$ to $n-1$:
   - Swap $s[i]$ and $s[j]$
   - Call $PERM(s, i+1)$
   - Swap back $s[i]$ and $s[j]$ (backtracking)

---

### Time Complexity (TC)
- $O(n!)$

---

### Space Complexity (SC)
- $O(n)$ (recursion depth)

---

### Code

```cpp
void perm(string& s, int i) {
    if (i == s.size()) {
        cout << s << endl;
        return;
    }
    for (int j = i; j < (int)s.size(); j++) {
        swap(s[i], s[j]);
        perm(s, i + 1);
        swap(s[i], s[j]);
    }
}
```

---

### Use Cases
- Anagram generation
- Combinatorial problems
- Testing all possible arrangements

---

### Graphs
![Permutation Graph](LAB-1/Images/Permutation.png)

---

## Practical-5: Linear Search

### Aim
Find a target element in an array using recursive linear search.

---

### Algorithm (Recursive Linear Search)

**Algorithm: LS(arr, target, i)**

1. If $i \geq n$, return -1
2. If $arr[i] = target$, return $i$
3. Return $LS(arr, target, i+1)$

---

### Time Complexity (TC)
- Best: $O(1)$
- Average/Worst: $O(n)$

---

### Space Complexity (SC)
- $O(n)$

---

### Code

```cpp
int LS(int arr[], int target, int i, int n) {
    if (i >= n) return -1;
    if (arr[i] == target) return i;
    return LS(arr, target, i + 1, n);
}
```

---

### Use Cases
- Small datasets
- Basic searching problems

---

### Graphs
![Linear Search Time Complexity Graph](LAB-1/Images/Linear.png)

---

## Practical-6: Horner's Rule

### Aim
Represent and evaluate a polynomial efficiently using Horner's Rule via recursion.

---

### Algorithm (Recursive Horner's Rule)

**Algorithm: HR(i, arr, x)**

1. If $i = n-1$, return $arr[i]$
2. Return $arr[i] + x \times HR(i+1, arr, x)$

---

### Time Complexity (TC)
- $O(n)$

---

### Space Complexity (SC)
- $O(n)$

---

### Code

```cpp
double HR(int i, int arr[], int n, double x) {
    if (i == n - 1) return arr[i];
    return arr[i] + x * HR(i + 1, arr, n, x);
}
```

---

### Use Cases
- Polynomial evaluation
- Compiler optimizations
- Numerical computations

---

## Practical-7: Bubble Sort

### Aim
Sort an array using recursive bubble sort and measure execution time.

---

### Algorithm (Recursive Bubble Sort)

**Algorithm: BB(arr, n)**

1. If $n = 1$, return
2. For $i = 0$ to $n-2$:
   - If $arr[i] > arr[i+1]$, swap them
3. Call $BB(arr, n-1)$

---

### Time Complexity (TC)
- Best: $O(n)$
- Average/Worst: $O(n^2)$

---

### Space Complexity (SC)
- $O(n)$

---

### Code

```cpp
void bb(int arr[], int n) {
    if (n == 1) return;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    bb(arr, n - 1);
}
```

---

### Use Cases
- Teaching sorting basics
- Understanding algorithm complexity

---

### Graphs
![Bubble Sort Time Complexity Graph](LAB-1/Images/Bubble.png)

---

## Practical-8: Selection Sort

### Aim
Sort an array using recursive selection sort.

---

### Algorithm (Recursive Selection Sort)

**Algorithm: SS(arr, i)**

1. If $i \geq n$, return
2. Find index of minimum element in $arr[i \dots n-1]$
3. Swap $arr[i]$ with minimum element
4. Call $SS(arr, i+1)$

---

### Time Complexity (TC)
- $O(n^2)$

---

### Space Complexity (SC)
- $O(n)$

---

### Code

```cpp
void ss(int arr[], int i, int n) {
    if (i >= n) return;
    int minIdx = i;
    for (int j = i + 1; j < n; j++)
        if (arr[j] < arr[minIdx]) minIdx = j;
    swap(arr[i], arr[minIdx]);
    ss(arr, i + 1, n);
}
```

---

### Use Cases
- Learning sorting fundamentals
- Small datasets where simplicity matters

---

### Graphs
![Selection Sort Time Complexity Graph](LAB-1/Images/Selection.png)

---

## Practical-9: Missing Number Finder

### Aim
Find the missing number in an array containing integers from 1 to n.

---

### Algorithm (Mathematical Approach)

**Algorithm: MISSING(arr, n)**

1. Compute expected sum $= n \times (n+1) / 2$
2. Compute actual sum of all elements in $arr$
3. Return $expectedSum - actualSum$

---

### Time Complexity (TC)
- $O(n)$

---

### Space Complexity (SC)
- $O(1)$

---

### Code

```cpp
int missingNumber(int arr[], int n) {
    int expected = n * (n + 1) / 2;
    int actual = 0;
    for (int i = 0; i < n - 1; i++) actual += arr[i];
    return expected - actual;
}
```

---

### Use Cases
- Data validation
- Detecting anomalies in integer sequences

---

## Practical-10: First Duplicate Finder

### Aim
Find the first duplicate element in an array.

---

### Algorithm (Hash-based Scan)

**Algorithm: FIND-DUP(arr, n)**

1. Create a visited set
2. For $i = 0$ to $n-1$:
   - If $arr[i]$ is already in set, return $arr[i]$
   - Else insert $arr[i]$ into set
3. Return -1

---

### Time Complexity (TC)
- $O(n)$

---

### Space Complexity (SC)
- $O(n)$

---

### Code

```cpp
int firstDuplicate(int arr[], int n) {
    unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        if (seen.count(arr[i])) return arr[i];
        seen.insert(arr[i]);
    }
    return -1;
}
```

---

### Use Cases
- Data deduplication
- Anomaly detection in sequences

---

## Practical-11: Insertion Sort

### Aim
Sort an array using insertion sort and measure performance.

---

### Algorithm (Insertion Sort)

**Algorithm: IS(arr)**

1. For $i = 1$ to $n-1$:
   - Set $key = arr[i]$, $j = i-1$
   - While $j \geq 0$ and $arr[j] > key$:
     - Shift $arr[j]$ to $arr[j+1]$, decrement $j$
   - Insert $key$ at $j+1$

---

### Time Complexity (TC)
- Best: $O(n)$
- Average/Worst: $O(n^2)$

---

### Space Complexity (SC)
- $O(1)$

---

### Code

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

---

### Use Cases
- Small datasets
- Nearly sorted arrays
- Online/incremental sorting

---

### Graphs
![Insertion Sort Time Complexity Graph](LAB-2/Images/InsertionSort.png)

---

## Practical-12: Binary Search

### Aim
Search for a target in a sorted array using recursive binary search.

---

### Algorithm (Recursive Binary Search)

**Algorithm: BS(arr, t, s, e)**

1. If $s > e$, return -1
2. Compute $m = \lfloor (s+e)/2 \rfloor$
3. If $arr[m] = t$, return $m$
4. If $arr[m] > t$, return $BS(arr, t, s, m-1)$
5. Else return $BS(arr, t, m+1, e)$

---

### Time Complexity (TC)
- Best: $O(1)$
- Average/Worst: $O(\log n)$

---

### Space Complexity (SC)
- $O(\log n)$

---

### Code

```cpp
int BS(int arr[], int t, int s, int e) {
    if (s > e) return -1;
    int m = s + (e - s) / 2;
    if (arr[m] == t) return m;
    if (arr[m] > t) return BS(arr, t, s, m - 1);
    return BS(arr, t, m + 1, e);
}
```

---

### Use Cases
- Efficient searching in sorted data
- Databases and lookup systems

---

### Graphs
![Binary Search Time Complexity Graph](LAB-2/Images/BinarySearch.png)

---

## Practical-13: Quick Sort

### Aim
Sort an array using quick sort and observe performance characteristics.

---

### Algorithm (Divide and Conquer)

**Algorithm: QS(arr, s, e)**

1. If $s \geq e$, return
2. Choose pivot element
3. Partition array:
   - Elements $<$ pivot on left
   - Elements $>$ pivot on right
4. Recursively apply on left and right partitions

---

### Time Complexity (TC)
- Best/Average: $O(n \log n)$
- Worst: $O(n^2)$

---

### Space Complexity (SC)
- Average: $O(\log n)$
- Worst: $O(n)$

---

### Code

```cpp
void qs(int arr[], int s, int e) {
    if (s >= e) return;
    int pivot = arr[(s + e) / 2], i = s, j = e;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) swap(arr[i++], arr[j--]);
    }
    qs(arr, s, j);
    qs(arr, i, e);
}
```

---

### Use Cases
- General-purpose in-memory sorting
- High-performance applications

---

### Graphs
![Quick Sort Time Complexity Graph](LAB-3/Images/QuickSort.png)

---

## Practical-14: Merge Sort

### Aim
Sort an array using merge sort and analyze performance for different input sizes.

---

### Algorithm (Divide and Conquer)

**Algorithm: MS(arr, s, e)**

1. If $s \geq e$, return
2. Compute $m = \lfloor (s+e)/2 \rfloor$
3. Call $MS(arr, s, m)$
4. Call $MS(arr, m+1, e)$
5. Merge the two sorted halves

---

### Time Complexity (TC)
- $O(n \log n)$ (all cases)

---

### Space Complexity (SC)
- $O(n)$

---

### Code

```cpp
void merge(int arr[], int s, int m, int e) {
    int n1 = m - s + 1, n2 = e - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[s + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = s;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void ms(int arr[], int s, int e) {
    if (s >= e) return;
    int m = s + (e - s) / 2;
    ms(arr, s, m);
    ms(arr, m + 1, e);
    merge(arr, s, m, e);
}
```

---

### Use Cases
- Large datasets requiring stable sort
- External sorting systems

---

### Graphs
![Merge Sort Time Complexity Graph](LAB-3/Images/MergeSort.png)

---

## Practical-15: Iterative Quick Sort

### Aim
Implement quick sort using an explicit stack instead of recursion.

---

### Algorithm (Iterative using Stack)

**Algorithm: QSI(arr, s, e)**

1. Initialize stack and push $(s, e)$
2. While stack is not empty:
   - Pop range $(l, r)$
   - Partition array around pivot
   - Push valid left and right subarrays onto stack

---

### Time Complexity (TC)
- Average: $O(n \log n)$

---

### Space Complexity (SC)
- Average: $O(\log n)$

---

### Code

```cpp
void qsi(int arr[], int s, int e) {
    stack<pair<int,int>> st;
    st.push({s, e});
    while (!st.empty()) {
        auto [l, r] = st.top(); st.pop();
        if (l >= r) continue;
        int pivot = arr[(l + r) / 2], i = l, j = r;
        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) swap(arr[i++], arr[j--]);
        }
        if (l < j) st.push({l, j});
        if (i < r) st.push({i, r});
    }
}
```

---

### Graphs
![Iterative Quick Sort Time Complexity Graph](LAB-4/Images/QuickSort.png)

---

## Practical-16: Binary Search (1/3 Variant)

### Aim
Implement a ternary search that narrows the search space to one-third at each step.

---

### Algorithm (Ternary Search)

**Algorithm: BS13(arr, t, s, e)**

1. If $s > e$, return -1
2. Compute $m1 = s + (e-s)/3$ and $m2 = e - (e-s)/3$
3. If $arr[m1] = t$, return $m1$
4. If $arr[m2] = t$, return $m2$
5. If $t < arr[m1]$, recurse on $[s, m1-1]$
6. Else if $t > arr[m2]$, recurse on $[m2+1, e]$
7. Else recurse on $[m1+1, m2-1]$

---

### Time Complexity (TC)
- $O(\log_3 n)$

---

### Space Complexity (SC)
- $O(\log_3 n)$

---

### Code

```cpp
int bs13(int arr[], int t, int s, int e) {
    if (s > e) return -1;
    int m1 = s + (e - s) / 3;
    int m2 = e - (e - s) / 3;
    if (arr[m1] == t) return m1;
    if (arr[m2] == t) return m2;
    if (t < arr[m1]) return bs13(arr, t, s, m1 - 1);
    if (t > arr[m2]) return bs13(arr, t, m2 + 1, e);
    return bs13(arr, t, m1 + 1, m2 - 1);
}
```

---

### Use Cases
- Searching in sorted data
- Theoretical comparison with binary search

---

## Practical-17: Permutation Generator

### Aim
Generate all permutations of a given integer sequence using backtracking.

---

### Algorithm (Backtracking)

**Algorithm: PERMGEN(arr, i)**

1. If $i = n$, output current arrangement
2. For $j = i$ to $n-1$:
   - Swap $arr[i]$ and $arr[j]$
   - Call $PERMGEN(arr, i+1)$
   - Swap back

---

### Time Complexity (TC)
- $O(n!)$

---

### Space Complexity (SC)
- $O(n)$

---

### Code

```cpp
void permGen(int arr[], int i, int n) {
    if (i == n) {
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << endl;
        return;
    }
    for (int j = i; j < n; j++) {
        swap(arr[i], arr[j]);
        permGen(arr, i + 1, n);
        swap(arr[i], arr[j]);
    }
}
```

---

### Use Cases
- Generating all orderings of elements
- Combinatorial search and testing

---

### Graphs
![Permutation Generator Graph](LAB-4/Images/Permutation.png)

---

## Practical-18: Fractional Knapsack

### Aim
Maximize value in a knapsack by allowing fractional items using a greedy approach.

---

### Algorithm (Greedy)

**Algorithm: KNAPSACK(W, wt, val)**

1. Compute value/weight ratio for each item
2. Sort items in decreasing order of ratio
3. For each item:
   - Take as much as possible (fully or fractionally)
   - Reduce remaining capacity $W$
4. Return total value

---

### Time Complexity (TC)
- $O(n \log n)$

---

### Space Complexity (SC)
- $O(1)$ (excluding input)

---

### Code

```cpp
double fractionalKnapsack(int W, int wt[], int val[], int n) {
    vector<pair<double,int>> ratio(n);
    for (int i = 0; i < n; i++) ratio[i] = {(double)val[i]/wt[i], i};
    sort(ratio.rbegin(), ratio.rend());
    double res = 0;
    for (auto& [r, i] : ratio) {
        if (W == 0) break;
        int take = min(W, wt[i]);
        res += take * r;
        W -= take;
    }
    return res;
}
```

---

### Use Cases
- Resource allocation problems
- Budget optimization
- Cargo loading

---

### Graphs
![Fractional Knapsack Time Complexity Graph](LAB-5/Images/KnapSack.png)

---

## Practical-19: Convex Hull

### Aim
Compute the convex hull of a set of 2D points using Graham Scan.

---

### Algorithm (Graham Scan)

**Algorithm: CONVEX-HULL(points)**

1. Find the lowest point as pivot
2. Sort remaining points by polar angle relative to pivot
3. For each point:
   - While last three points make a non-left turn, pop the stack
   - Push current point onto stack
4. Stack contains the convex hull vertices

---

### Time Complexity (TC)
- $O(n \log n)$

---

### Space Complexity (SC)
- $O(n)$

---

### Code

```cpp
int orientation(Point p, Point q, Point r) {
    int val = (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}
void convexHull(Point pts[], int n) {
    int minY = 0;
    for (int i = 1; i < n; i++)
        if (pts[i].y < pts[minY].y) minY = i;
    swap(pts[0], pts[minY]);
    sort(pts + 1, pts + n, compare);
    stack<Point> s;
    s.push(pts[0]); s.push(pts[1]); s.push(pts[2]);
    for (int i = 3; i < n; i++) {
        while (s.size() > 1 && orientation(nextToTop(s), s.top(), pts[i]) != 2)
            s.pop();
        s.push(pts[i]);
    }
}
```

---

### Use Cases
- Computational geometry
- Collision detection in games
- Geographic boundary mapping

---

### Graphs
![Convex Hull Time Complexity Graph](LAB-5/Images/ConvexHull.png)

---

## Practical-20: Kth Smallest (Quickselect)

### Aim
Find the k-th smallest element in an array more efficiently than full sorting.

---

### Algorithm (Quickselect)

**Algorithm: QUICKSELECT(a, k, l, r)**

1. If $l = r$, return $a[l]$
2. Choose a pivot and partition the array
3. If $k \leq j$, recurse on left partition
4. If $k \geq i$, recurse on right partition
5. Else return $a[k]$

---

### Time Complexity (TC)
- Average: $O(n)$
- Worst: $O(n^2)$

---

### Space Complexity (SC)
- Average: $O(\log n)$

---

### Code

```cpp
int quickselect(int a[], int k, int l, int r) {
    if (l == r) return a[l];
    int pivot = a[l + (r - l) / 2], i = l, j = r;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) swap(a[i++], a[j--]);
    }
    if (k <= j) return quickselect(a, k, l, j);
    if (k >= i) return quickselect(a, k, i, r);
    return a[k];
}
```

---

### Use Cases
- Order statistics
- Median finding
- Top-K selection problems

---

### Graphs
![K-th Smallest Time Complexity Graph](LAB-5/Images/KthSmallest.png)

---

## Practical-21: Maxmin (Divide and Conquer)

### Aim
Find both the maximum and minimum elements of an array simultaneously using divide-and-conquer.

---

### Algorithm (Divide and Conquer)

**Algorithm: MAX-MIN(a, l, r)**

1. If $l = r$, return $(a[l], a[l])$
2. Compute $m = \lfloor (l+r)/2 \rfloor$
3. $(max_1, min_1) = MAX\text{-}MIN(a, l, m)$
4. $(max_2, min_2) = MAX\text{-}MIN(a, m+1, r)$
5. Return $(\max(max_1, max_2),\ \min(min_1, min_2))$

---

### Time Complexity (TC)
- $O(n)$

---

### Space Complexity (SC)
- $O(\log n)$

---

### Code

```cpp
pair<int,int> maxmin(int a[], int l, int r) {
    if (l == r) return {a[l], a[l]};
    int m = (l + r) / 2;
    auto [max1, min1] = maxmin(a, l, m);
    auto [max2, min2] = maxmin(a, m + 1, r);
    return {max(max1, max2), min(min1, min2)};
}
```

---

### Use Cases
- Simultaneous min-max queries
- Statistical range computations

---

### Graphs
![Max-Min Time Complexity Graph](LAB-5/Images/MaxMin.png)

---

## Practical-22: Dijkstra's Shortest Path

### Aim
Compute shortest paths from a single source in a weighted graph with non-negative weights.

---

### Algorithm (Greedy with Priority Queue)

**Algorithm: DIJKSTRA(graph, src)**

1. Initialize $dist[]$ with infinity, set $dist[src] = 0$
2. Use a min-priority queue to pick node with minimum distance
3. For each adjacent vertex, update distance if shorter path found
4. Repeat until all vertices are processed

---

### Time Complexity (TC)
- $O((V + E) \log V)$

---

### Space Complexity (SC)
- $O(V)$

---

### Code

```cpp
vector<int> dijkstra(vector<vector<pair<int,int>>>& g, int src, int n) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [w, v] : g[u])
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
    }
    return dist;
}
```

---

### Use Cases
- GPS and navigation systems
- Network routing protocols
- Single-source shortest path

---

### Graphs
![Dijkstra's Shortest Path Graph](LAB-6/Images/Dijkstra.png)

---

## Practical-23: Prim's Algorithm for MST

### Aim
Construct a Minimum Spanning Tree using Prim's greedy approach.

---

### Algorithm (Greedy)

**Algorithm: PRIMS(graph)**

1. Initialize all vertices as not in MST; set $dist[0] = 0$
2. Repeat $n$ times:
   - Select vertex $v$ with minimum $dist$ not yet in MST
   - Mark $v$ as in MST
   - Update $dist$ of its neighbours

---

### Time Complexity (TC)
- $O(V^2)$ (matrix) / $O(E \log V)$ (with heap)

---

### Space Complexity (SC)
- $O(V)$

---

### Code

```cpp
void prims(int graph[][100], int n) {
    vector<int> dist(n, INT_MAX);
    vector<bool> inMST(n, false);
    dist[0] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!inMST[j] && (v == -1 || dist[j] < dist[v])) v = j;
        inMST[v] = true;
        for (int to = 0; to < n; to++)
            if (graph[v][to] && graph[v][to] < dist[to])
                dist[to] = graph[v][to];
    }
}
```

---

### Use Cases
- Network cable/road design
- Cluster analysis

---

## Practical-24: Activity Selection

### Aim
Select the maximum number of non-overlapping activities from a given list.

---

### Algorithm (Greedy)

**Algorithm: ACTIVITY-SELECT(start, finish)**

1. Sort activities by finish time
2. Select first activity; track last finish time
3. For each remaining activity:
   - If start time $\geq$ last finish time, select it and update last finish
4. Return selected activities

---

### Time Complexity (TC)
- $O(n \log n)$

---

### Space Complexity (SC)
- $O(1)$

---

### Code

```cpp
void activitySelection(int start[], int finish[], int n) {
    cout << "Activity 0 selected\n";
    int lastFinish = finish[0];
    for (int i = 1; i < n; i++) {
        if (start[i] >= lastFinish) {
            cout << "Activity " << i << " selected\n";
            lastFinish = finish[i];
        }
    }
}
```

---

### Use Cases
- Job/task scheduling
- Meeting room allocation
- CPU process scheduling

---

## Practical-25: Cycle Detection

### Aim
Detect cycles in a directed graph using DFS.

---

### Algorithm (DFS-based)

**Algorithm: CYCLE-DETECT(graph)**

1. Mark all vertices as unvisited
2. For each unvisited vertex, run DFS
3. Track the current recursion stack
4. If a visited vertex is found in the current stack, a cycle exists

---

### Time Complexity (TC)
- $O(V + E)$

---

### Space Complexity (SC)
- $O(V)$

---

### Code

```cpp
bool dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& rec) {
    vis[u] = rec[u] = true;
    for (int v : adj[u]) {
        if (!vis[v] && dfs(v, adj, vis, rec)) return true;
        if (rec[v]) return true;
    }
    rec[u] = false;
    return false;
}
bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<bool> vis(n, false), rec(n, false);
    for (int i = 0; i < n; i++)
        if (!vis[i] && dfs(i, adj, vis, rec)) return true;
    return false;
}
```

---

### Use Cases
- Deadlock detection in operating systems
- Dependency cycle detection
- Circuit analysis

---

## Practical-26: Kruskal's Algorithm for MST

### Aim
Construct a Minimum Spanning Tree by sorting edges and avoiding cycles using Union-Find.

---

### Algorithm (Greedy + Union-Find)

**Algorithm: KRUSKAL(edges, V)**

1. Sort all edges by weight
2. Initialize disjoint sets for all vertices
3. For each edge:
   - If it connects two different components, include it in MST and union them
4. Repeat until MST has $V-1$ edges

---

### Time Complexity (TC)
- $O(E \log E)$

---

### Space Complexity (SC)
- $O(V + E)$

---

### Code

```cpp
int find(int parent[], int x) {
    if (parent[x] != x) parent[x] = find(parent, parent[x]);
    return parent[x];
}
void kruskal(vector<tuple<int,int,int>>& edges, int n) {
    sort(edges.begin(), edges.end());
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);
    int cost = 0;
    for (auto [w, u, v] : edges) {
        int pu = find(parent.data(), u), pv = find(parent.data(), v);
        if (pu != pv) { parent[pu] = pv; cost += w; }
    }
}
```

---

### Use Cases
- Minimum cost network design
- Road/pipeline construction planning

---

### Graphs
![Kruskal's MST Time Complexity Graph](LAB-6/Images/Kruskal.png)

---

## Practical-27: Multistage Graph (Backward Approach)

### Aim
Find the shortest path in a multistage graph using the backward DP approach.

---

### Algorithm

**Algorithm: BACKWARD-MS(graph)**

1. Initialize $cost[source] = 0$, all others infinity
2. For each stage layer from source:
   - For each vertex $u$ in current stage:
     - Relax edges to all vertices $v$ in next stage
3. Track parent array to reconstruct path

---

### Time Complexity (TC)
- $O(V^2)$

---

### Space Complexity (SC)
- $O(V)$

---

### Code

```cpp
void backwardMS(int graph[][100], int n) {
    vector<int> cost(n, INT_MAX), parent(n, -1);
    cost[0] = 0;
    for (int u = 0; u < n - 1; u++)
        for (int v = u + 1; v < n; v++)
            if (graph[u][v] && cost[u] + graph[u][v] < cost[v]) {
                cost[v] = cost[u] + graph[u][v];
                parent[v] = u;
            }
}
```

---

### Use Cases
- Shortest path in staged networks
- DAG-based optimization problems
- Network flow planning

---

## Practical-28: Multistage Graph (Forward Approach)

### Aim
Find the shortest path in a multistage graph using forward dynamic programming.

---

### Algorithm

**Algorithm: FORWARD-MS(graph)**

1. Initialize $cost[destination] = 0$, all others infinity
2. Traverse stages backward from destination:
   - Compute minimum cost for each vertex using next stage
3. Store decisions in $d[]$ for path reconstruction

---

### Time Complexity (TC)
- $O(V^2)$

---

### Space Complexity (SC)
- $O(V)$

---

### Code

```cpp
void forwardMS(int graph[][100], int n) {
    vector<int> cost(n, INT_MAX), d(n, -1);
    cost[n - 1] = 0;
    for (int u = n - 2; u >= 0; u--)
        for (int v = u + 1; v < n; v++)
            if (graph[u][v] && graph[u][v] + cost[v] < cost[u]) {
                cost[u] = graph[u][v] + cost[v];
                d[u] = v;
            }
}
```

---

### Use Cases
- Dynamic programming on DAGs
- Decision optimization problems
- Multistage shortest path

---

## Practical-29: Matrix Chain Multiplication

### Aim
Find the optimal parenthesization of a matrix chain to minimize scalar multiplications.

---

### Algorithm (Dynamic Programming)

**Algorithm: MATRIX-CHAIN(p)**

1. Let $n = length(p) - 1$; initialize $m[i][i] = 0$
2. For chain length $L = 2$ to $n$:
   - For $i = 1$ to $n-L+1$:
     - Set $j = i + L - 1$, $m[i][j] = \infty$
     - For $k = i$ to $j-1$: compute cost and update minimum

---

### Time Complexity (TC)
- $O(n^3)$

---

### Space Complexity (SC)
- $O(n^2)$

---

### Code

```cpp
void matrixChainOrder(int p[], int n) {
    int m[n][n];
    for (int i = 0; i < n; i++) m[i][i] = 0;
    for (int L = 2; L <= n; L++)
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                if (q < m[i][j]) m[i][j] = q;
            }
        }
}
```

---

### Use Cases
- Optimizing matrix operations in scientific computing
- Compiler optimization (expression evaluation order)
- Graphics transformations

---

### Graphs
![Matrix Chain Multiplication Time Complexity Graph](LAB-8/Images/MCM.png)

---

## Practical-30: Floyd-Warshall

### Aim
Compute shortest paths between all pairs of vertices in a weighted graph.

---

### Algorithm (Dynamic Programming)

**Algorithm: FLOYD-WARSHALL(dist)**

1. For each intermediate vertex $k$:
2. For each pair $(i, j)$:
   - Update $dist[i][j] = \min(dist[i][j],\ dist[i][k] + dist[k][j])$

---

### Time Complexity (TC)
- $O(V^3)$

---

### Space Complexity (SC)
- $O(V^2)$

---

### Code

```cpp
void floydWarshall(int dist[][100], int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}
```

---

### Use Cases
- Network routing protocols
- All-pairs shortest path in dense graphs
- Transitive closure (reachability problems)

---

### Graphs
![Floyd-Warshall All-Pairs Shortest Path Graph](LAB-9/Images/FloydWarshall.png)

---

## Practical-31: Longest Common Subsequence

### Aim
Find the length of the longest common subsequence between two strings.

---

### Algorithm (Dynamic Programming)

**Algorithm: LCS(X, Y, m, n)**

1. Build a 2D DP table $dp[m+1][n+1]$, initialized to 0
2. For $i = 1$ to $m$, for $j = 1$ to $n$:
   - If $X[i] = Y[j]$: $dp[i][j] = dp[i-1][j-1] + 1$
   - Else: $dp[i][j] = \max(dp[i-1][j],\ dp[i][j-1])$
3. Return $dp[m][n]$

---

### Time Complexity (TC)
- $O(mn)$

---

### Space Complexity (SC)
- $O(mn)$

---

### Code

```cpp
int LCS(string X, string Y, int m, int n) {
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (X[i-1] == Y[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    return dp[m][n];
}
```

---

### Use Cases
- Diff tools and version control
- DNA sequence alignment in bioinformatics
- Plagiarism detection

---

## Practical-32: Traveling Salesman Problem (DP)

### Aim
Solve TSP efficiently using Dynamic Programming with bitmask.

---

### Algorithm (DP with Bitmasking)

**Algorithm: TSP-DP(n, cost)**

1. Use bitmask to represent set of visited cities
2. Initialize $dp[1][0] = 0$, all others infinity
3. Iterate over all subsets; for each state update reachable cities
4. Return minimum of $dp[allVisited][i] + cost[i][0]$ for all $i$

---

### Time Complexity (TC)
- $O(n^2 \cdot 2^n)$

---

### Space Complexity (SC)
- $O(n \cdot 2^n)$

---

### Code

```cpp
int tspDP(int n, int cost[][20]) {
    int VIS = 1 << n;
    vector<vector<int>> dp(VIS, vector<int>(n, INT_MAX / 2));
    dp[1][0] = 0;
    for (int mask = 1; mask < VIS; mask++)
        for (int u = 0; u < n; u++)
            if ((mask & (1 << u)) && dp[mask][u] < INT_MAX / 2)
                for (int v = 0; v < n; v++)
                    if (!(mask & (1 << v)))
                        dp[mask|(1<<v)][v] = min(dp[mask|(1<<v)][v], dp[mask][u] + cost[u][v]);
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) ans = min(ans, dp[VIS-1][i] + cost[i][0]);
    return ans;
}
```

---

### Use Cases
- Logistics and route optimization
- Circuit board drilling
- Optimization problems with constraints

---

## Practical-33: 0/1 Knapsack

### Aim
Maximize value in a knapsack where items cannot be taken fractionally.

---

### Algorithm (Dynamic Programming)

**Algorithm: KNAPSACK-01(W, wt, val, n)**

1. Build DP table $dp[n+1][W+1]$
2. For $i = 1$ to $n$, for $w = 0$ to $W$:
   - If $wt[i] \leq w$: $dp[i][w] = \max(dp[i-1][w],\ val[i] + dp[i-1][w-wt[i]])$
   - Else: $dp[i][w] = dp[i-1][w]$
3. Return $dp[n][W]$

---

### Time Complexity (TC)
- $O(nW)$

---

### Space Complexity (SC)
- $O(nW)$

---

### Code

```cpp
int knapsack01(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w-wt[i-1]]);
            else dp[i][w] = dp[i-1][w];
        }
    return dp[n][W];
}
```

---

### Use Cases
- Resource allocation with hard constraints
- Budget optimization
- Portfolio selection problems

---

## Practical-34: N-Queens Problem

### Aim
Place N queens on an $N \times N$ chessboard such that no two queens attack each other.

---

### Algorithm (Backtracking)

**Algorithm: N-QUEENS(k, x, n)**

1. If $k = n$, a valid solution is found
2. For each column $i = 0$ to $n-1$:
   - If placing queen at $(k, i)$ is safe:
     - Place queen at $x[k] = i$
     - Recurse for row $k+1$

---

### Time Complexity (TC)
- $O(n!)$

---

### Space Complexity (SC)
- $O(n)$

---

### Code

```cpp
bool isSafe(int k, int col, int x[]) {
    for (int j = 0; j < k; j++)
        if (x[j] == col || abs(x[j] - col) == abs(j - k))
            return false;
    return true;
}
void nQueens(int k, int x[], int n, int& solutions) {
    if (k == n) { solutions++; return; }
    for (int i = 0; i < n; i++) {
        if (isSafe(k, i, x)) {
            x[k] = i;
            nQueens(k + 1, x, n, solutions);
        }
    }
}
```

---

### Use Cases
- Constraint satisfaction problems
- Puzzle solving
- Backtracking optimization techniques

---

### Graphs
![N-Queens Time Complexity Graph](LAB-10/Images/NQ.png)

---

## Practical-35: Subset Sum

### Aim
Find all subsets of a given set whose elements sum to a target value.

---

### Algorithm (Backtracking with Bounding)

**Algorithm: SUM-OF-SUBSETS(s, k, r, w, x, n, W)**

1. Include current element $w[k]$:
   - If $s + w[k] = W$, output solution
   - Else recurse if promising
2. Exclude current element:
   - Recurse if remaining elements can still reach $W$

---

### Time Complexity (TC)
- Exponential (worst case)

---

### Space Complexity (SC)
- $O(n)$

---

### Code

```cpp
void subsetSum(int s, int k, int r, int w[], int x[], int n, int W) {
    x[k] = 1;
    if (s + w[k] == W) {
        for (int i = 0; i <= k; i++) if (x[i]) cout << w[i] << " ";
        cout << endl;
    } else if (k + 1 < n && s + w[k] + w[k+1] <= W) {
        subsetSum(s + w[k], k + 1, r - w[k], w, x, n, W);
    }
    if (k + 1 < n && s + r - w[k] >= W && s + w[k+1] <= W) {
        x[k] = 0;
        subsetSum(s, k + 1, r - w[k], w, x, n, W);
    }
}
```

---

### Use Cases
- Subset selection problems
- Resource allocation
- Combinatorial optimization

---

### Graphs
![Sum of Subsets Time Complexity Graph](LAB-10/Images/SumOfSubsets.png)

---

## Practical-36: Chromatic Number (Graph Coloring)

### Aim
Assign the minimum number of colors to vertices such that no two adjacent vertices share the same color.

---

### Algorithm (Backtracking)

**Algorithm: GRAPH-COLORING(graph, m)**

1. Assign colors one by one to vertices
2. Check if current color assignment is safe (no adjacent vertex has same color)
3. If safe, recurse for next vertex
4. If all vertices are colored, solution is found

---

### Time Complexity (TC)
- Exponential in worst case

---

### Space Complexity (SC)
- $O(n)$

---

### Code

```cpp
bool isSafeC(int v, int c, int graph[][100], int color[], int n) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] && color[i] == c) return false;
    return true;
}
void graphColoring(int v, int graph[][100], int color[], int n, int m) {
    if (v == n) {
        for (int i = 0; i < n; i++) cout << color[i] << " ";
        cout << endl; return;
    }
    for (int c = 1; c <= m; c++) {
        if (isSafeC(v, c, graph, color, n)) {
            color[v] = c;
            graphColoring(v + 1, graph, color, n, m);
            color[v] = 0;
        }
    }
}
```

---

### Use Cases
- Register allocation in compilers
- Scheduling problems
- Frequency/channel assignment in networks

---

## Practical-37: Hamiltonian Graph

### Aim
Find a Hamiltonian cycle in a graph (visiting every vertex exactly once) using backtracking.

---

### Algorithm (Backtracking)

**Algorithm: HAMILTONIAN(graph)**

1. Start from vertex 0
2. Recursively add adjacent unvisited vertices to path
3. If all vertices visited, check if last vertex connects back to first
4. If yes, Hamiltonian cycle found; else backtrack

---

### Time Complexity (TC)
- $O(n!)$

---

### Space Complexity (SC)
- $O(n)$

---

### Code

```cpp
bool isSafeH(int v, int graph[][100], int path[], int pos, int n) {
    if (!graph[path[pos-1]][v]) return false;
    for (int i = 0; i < pos; i++) if (path[i] == v) return false;
    return true;
}
bool hamiltonian(int graph[][100], int path[], int pos, int n) {
    if (pos == n)
        return graph[path[pos-1]][path[0]] == 1;
    for (int v = 1; v < n; v++) {
        if (isSafeH(v, graph, path, pos, n)) {
            path[pos] = v;
            if (hamiltonian(graph, path, pos + 1, n)) return true;
            path[pos] = -1;
        }
    }
    return false;
}
```

---

### Use Cases
- Route planning visiting every location once
- Circuit design and PCB testing
- NP-completeness studies

---
