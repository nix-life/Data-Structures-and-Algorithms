# Data-Structures-and-Algorithms
Simple Data Structures and Algorithms as well as concepts required for the algorithms


## Current Algorithms Created:

1. Search Algorithms
* Arrays
    * Linear Search
    * Binary Search
    * Interpolation Search
* Graphs
    * Depth First Search (In Progress)
    * Breadth First Search

2. Sort Algorithms
* Bubble Sort 
* Selection Sort
* Insertion Sort
* Merge Sort
* Quick Sort

3. Concepts
* Recursion
    * Simple recursion method and comaprison between iteration and recusion (recursion.java)
    * An example of recursion with a factorial calculator (recursion_factorial.java)
    * Another example of recursion by creating the power of two numbers
* Hash Table
* Graphs
    * Types of graphs - there are two main types of graphs:
        * Undirected Graph - A graph that goes both ways - two nodes that are connected can reach each other
        * Directed Graph - A graph that sometimes goes one way - two nodes connected can result in one node reaching the other while the other does not
    * Ways to represent graphs - there are also two main ways to represent graphs:
        * Adjacency Matrix - A 2D array list that has one row and column for each node. If there is adjacency, the value of the array is 1 and if there is not the value would be 0. 
            * Time Complexity: O(1)
            * Space Copmlexity: O(V^2)
        * Adjacency List - An array or arrayList of LinkedLists. Each element is a seperate linked list and each header within the linked list would contain an address of a node. All nodes that are connected are in one linked list but it is only directing one way. For example, a linked list could have B -> E but not E -> B because they are different addresses. A node that is not adjacent should still be added.
            * Time Complexity: O(V)
            * Space Complexity: O(V + E)

## Tasks in progress:
* Explaining each algorithm in README
* Adding more concepts required for algorithms