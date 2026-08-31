# Data Structures and Algorithms

This repository contains notes and implementations for common data structures and algorithms. Use this README as a quick outline of the major topics: what each one is for, when it is useful, and why it matters.

## Data Structures

### Arrays
Contiguous collections of elements accessed by index. Arrays provide fast random access, but inserting or deleting in the middle is expensive because elements may need to shift.

### Dynamic Arrays
Resizable arrays that grow when capacity is reached. They keep array-style indexing while allowing append operations to be efficient on average.

### Strings
Sequences of characters often treated like arrays with extra operations. Many algorithm problems involve string matching, parsing, hashing, or dynamic programming over strings.

### Linked Lists
Collections of nodes where each node points to the next node, and sometimes the previous node. Linked lists support efficient insertion and deletion when the target node is known, but they do not support fast indexing.

### Stacks
Last-in, first-out structures where the most recently added item is removed first. Stacks are used for recursion, undo operations, expression parsing, backtracking, and depth-first search.

### Queues
First-in, first-out structures where the oldest item is removed first. Queues are used for scheduling, buffering, breadth-first search, and level-order traversal.

### Deques
Double-ended queues that support insertion and removal from both the front and back. Deques are useful for sliding-window problems, monotonic queues, and flexible queue or stack behavior.

### Hash Tables
Key-value structures that use a hash function to map keys to array positions. They provide average constant-time lookup, insertion, and deletion, and are widely used for sets, maps, frequency counting, and caching.

### Sets
Collections of unique values. Sets are useful for membership checks, duplicate removal, intersections, unions, and tracking visited states.

### Maps
Collections of key-value pairs. Maps are useful when data must be looked up by an identifier, such as counting frequencies or storing graph adjacency lists.

### Trees
Hierarchical structures made of nodes connected by edges. Trees are used to model nested relationships and support efficient search, organization, and traversal.

### Binary Trees
Trees where each node has at most two children. They are common in traversal problems and form the basis for binary search trees, heaps, and expression trees.

### Binary Search Trees
Binary trees where left descendants are smaller than the current node and right descendants are larger. Balanced binary search trees support efficient searching, insertion, deletion, and ordered traversal.

### Balanced Trees
Self-balancing search trees such as AVL trees, Red-Black trees, B-trees, and B+ trees. They maintain logarithmic height to keep operations efficient even after many insertions and deletions.

### Heaps
Tree-based structures where the highest-priority element is kept at the root. Min-heaps and max-heaps are used for priority queues, scheduling, graph algorithms, and finding top-k elements.

### Priority Queues
Queues where removal is based on priority rather than insertion order. They are commonly implemented with heaps and are central to algorithms like Dijkstra's shortest path and Huffman coding.

### Tries
Prefix trees used to store strings character by character. Tries are useful for autocomplete, spell checking, dictionary lookup, prefix matching, and word-search problems.

### Graphs
Collections of vertices connected by edges. Graphs model networks such as roads, dependencies, social connections, state transitions, and communication systems.

### Adjacency Matrices
Two-dimensional graph representations where each cell records whether an edge exists between two vertices. They provide fast edge checks but use significant space for sparse graphs.

### Adjacency Lists
Graph representations where each vertex stores a list of its neighbors. They are space-efficient for sparse graphs and are commonly used for traversal and shortest-path algorithms.

### Disjoint Set Union
Also called Union-Find, this structure tracks groups of connected components. It supports efficient merging and lookup operations and is used in Kruskal's algorithm, connectivity problems, and cycle detection.

### Segment Trees
Tree structures that answer range queries and support updates efficiently. They are used for problems involving range sums, minimums, maximums, or custom aggregate values.

### Fenwick Trees
Also called Binary Indexed Trees, these structures efficiently handle prefix sums and point updates. They are simpler than segment trees but support fewer kinds of operations.

## Algorithms

### Searching
Algorithms that locate an item or determine whether it exists in a collection.

### Linear Search
Checks each element one by one. It works on unsorted data but takes linear time.

### Binary Search
Repeatedly halves a sorted search space. It is efficient for sorted arrays and can also be used on abstract monotonic conditions.

### Interpolation Search
Estimates where a target may be based on value distribution. It can be faster than binary search for uniformly distributed sorted data but performs poorly when data is uneven.

### Sorting
Algorithms that arrange data in a chosen order, usually ascending or descending.

### Bubble Sort
Repeatedly swaps adjacent elements that are out of order. It is simple but inefficient and mainly useful for learning.

### Selection Sort
Repeatedly selects the smallest remaining element and places it in position. It is easy to understand but inefficient for large datasets.

### Insertion Sort
Builds a sorted section one element at a time. It is efficient for small or nearly sorted inputs.

### Merge Sort
Splits data into halves, sorts each half, and merges the results. It has reliable `O(n log n)` time complexity and is stable when implemented carefully.

### Quick Sort
Partitions data around a pivot and recursively sorts each side. It is fast in practice but can degrade to quadratic time with poor pivot choices.

### Heap Sort
Builds a heap and repeatedly removes the maximum or minimum element. It guarantees `O(n log n)` time and sorts in place, but it is not stable.

### Counting Sort
Counts occurrences of each value in a limited range. It can run in linear time when the value range is small.

### Radix Sort
Sorts numbers or strings digit by digit. It can be efficient when keys have fixed length and a suitable base.

### Bucket Sort
Distributes elements into buckets, sorts each bucket, and combines them. It works well when input values are evenly distributed.

### Recursion
A technique where a function solves a problem by calling itself on smaller subproblems. Recursion is common in trees, divide-and-conquer algorithms, backtracking, and dynamic programming.

### Iteration
Repeats work using loops instead of function calls. Iterative solutions often use less memory than recursive ones and avoid call-stack limits.

### Divide and Conquer
Splits a problem into smaller independent parts, solves them, and combines the results. Merge sort, quick sort, and binary search are classic examples.

### Backtracking
Builds possible solutions step by step and abandons paths that cannot work. It is used for permutations, combinations, Sudoku, N-Queens, and constraint-solving problems.

### Greedy Algorithms
Make the best local choice at each step with the goal of reaching a global optimum. Greedy methods are used in interval scheduling, Huffman coding, and some graph algorithms, but they require proof that local choices are safe.

### Dynamic Programming
Solves problems by reusing answers to overlapping subproblems. It is used for optimization and counting problems such as knapsack, longest common subsequence, shortest paths, and edit distance.

### Memoization
Top-down dynamic programming that stores results of recursive calls. It avoids repeated work while keeping the recursive structure clear.

### Tabulation
Bottom-up dynamic programming that fills a table from known base cases. It often avoids recursion and gives precise control over computation order.

### Graph Traversal
Algorithms that visit vertices and edges in a graph.

### Depth-First Search
Explores as far as possible along a path before backtracking. DFS is used for connected components, cycle detection, topological sorting, path finding, and tree traversal.

### Breadth-First Search
Explores neighbors level by level. BFS finds the shortest path in unweighted graphs and is used for level-order traversal and minimum-step problems.

### Topological Sort
Orders vertices in a directed acyclic graph so every dependency appears before the item that depends on it. It is used in build systems, course scheduling, and dependency resolution.

### Shortest Path Algorithms
Find the minimum-cost path between vertices in a graph.

### Dijkstra's Algorithm
Finds shortest paths from one source in a graph with non-negative edge weights. It commonly uses a priority queue.

### Bellman-Ford Algorithm
Finds shortest paths from one source and can handle negative edge weights. It can also detect negative-weight cycles.

### Floyd-Warshall Algorithm
Finds shortest paths between every pair of vertices. It is simple but uses cubic time, so it is best for smaller graphs.

### Minimum Spanning Tree Algorithms
Find a lowest-cost set of edges that connects all vertices in a weighted undirected graph.

### Kruskal's Algorithm
Builds a minimum spanning tree by adding edges in increasing weight order while avoiding cycles. It commonly uses Disjoint Set Union.

### Prim's Algorithm
Builds a minimum spanning tree by expanding from a starting vertex using the cheapest available edge. It commonly uses a priority queue.

### Cycle Detection
Determines whether a graph contains a cycle. DFS is often used for directed graphs, while Disjoint Set Union is common for undirected graphs.

### Tree Traversals
Algorithms for visiting every node in a tree.

### Preorder Traversal
Visits the current node before its children. It is useful for copying trees and serializing structure.

### Inorder Traversal
Visits the left subtree, current node, then right subtree. In a binary search tree, this produces sorted order.

### Postorder Traversal
Visits children before the current node. It is useful for deleting trees, evaluating expression trees, and computing subtree values.

### Level-Order Traversal
Visits nodes one level at a time using a queue. It is useful for breadth-first processing of trees.

### String Matching
Algorithms that search for patterns inside text.

### Knuth-Morris-Pratt
Uses a prefix table to avoid rechecking characters after a mismatch. It finds patterns in linear time.

### Rabin-Karp
Uses rolling hashes to compare substrings efficiently. It is useful for multiple pattern checks and plagiarism-style matching, though hash collisions must be handled.

### Sliding Window
Maintains a moving range over an array or string. It is useful for substring, subarray, and fixed or variable window optimization problems.

### Two Pointers
Uses two indexes that move through a collection to reduce nested-loop work. It is common in sorted arrays, linked lists, pair-sum problems, and partitioning.

### Prefix Sums
Precomputes cumulative totals so range-sum queries can be answered quickly. Prefix techniques also extend to frequencies, XOR values, and two-dimensional grids.

### Bit Manipulation
Uses binary operations directly on integers. It is useful for flags, subsets, parity checks, masks, and low-level optimization.

### Mathematical Algorithms
Algorithms based on number theory or arithmetic properties.

### Euclidean Algorithm
Computes the greatest common divisor efficiently. It is also the basis for simplifying fractions and modular arithmetic techniques.

### Sieve of Eratosthenes
Finds all prime numbers up to a limit efficiently. It marks multiples of each prime as composite.

### Fast Exponentiation
Computes powers using repeated squaring. It reduces exponentiation from linear time to logarithmic time and is often used with modular arithmetic.

## Core Complexity Concepts

### Time Complexity
Describes how running time grows as input size increases. Common classes include `O(1)`, `O(log n)`, `O(n)`, `O(n log n)`, `O(n^2)`, and `O(2^n)`.

### Space Complexity
Describes how memory usage grows as input size increases. Extra arrays, recursion stacks, hash tables, and graph representations all affect space complexity.

### Big O Notation
Describes an upper bound on growth rate. It helps compare algorithms independently of machine speed or implementation details.

### Stability
A sorting property where equal elements keep their original relative order. Stability matters when sorting records by multiple fields.

### In-Place Algorithms
Algorithms that use only a small amount of extra memory. In-place methods are useful when memory is limited.

## Repository Topics

- `search`: Linear search, binary search, interpolation search, depth-first search, and breadth-first search.
- `sort`: Bubble sort, selection sort, insertion sort, merge sort, and quick sort.
- `concepts`: Recursion, graph basics, hash tables, and tree concepts.
- `data structures`: Implementations such as dynamic arrays and other core structures.
- `implementations/dsa_reference.cpp`: A self-contained C++ reference file implementing the major data structures, algorithms, and concepts described above, with assertion-based examples in `main`.
