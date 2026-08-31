#include <algorithm>
#include <cassert>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace dsa {

class DynamicArray {
private:
    int* data;
    int length;
    int capacity;

    void resize(int newCapacity) {
        int* next = new int[newCapacity];
        for (int i = 0; i < length; i++) {
            next[i] = data[i];
        }
        delete[] data;
        data = next;
        capacity = newCapacity;
    }

public:
    DynamicArray()
        : data(new int[2]), length(0), capacity(2) {}

    ~DynamicArray() {
        delete[] data;
    }

    DynamicArray(const DynamicArray& other)
        : data(new int[other.capacity]), length(other.length), capacity(other.capacity) {
        for (int i = 0; i < length; i++) {
            data[i] = other.data[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) {
            return *this;
        }

        int* next = new int[other.capacity];
        for (int i = 0; i < other.length; i++) {
            next[i] = other.data[i];
        }

        delete[] data;
        data = next;
        length = other.length;
        capacity = other.capacity;
        return *this;
    }

    void pushBack(int value) {
        if (length == capacity) {
            resize(capacity * 2);
        }
        data[length++] = value;
    }

    void insert(int index, int value) {
        if (index < 0 || index > length) {
            throw std::out_of_range("insert index out of range");
        }
        if (length == capacity) {
            resize(capacity * 2);
        }
        for (int i = length; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        length++;
    }

    void removeAt(int index) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("remove index out of range");
        }
        for (int i = index; i + 1 < length; i++) {
            data[i] = data[i + 1];
        }
        length--;
    }

    int& operator[](int index) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("array index out of range");
        }
        return data[index];
    }

    int size() const {
        return length;
    }
};

class SinglyLinkedList {
private:
    struct Node {
        int value;
        Node* next;
        explicit Node(int value) : value(value), next(nullptr) {}
    };

    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    void pushFront(int value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
    }

    void pushBack(int value) {
        Node* node = new Node(value);
        if (head == nullptr) {
            head = node;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = node;
    }

    bool remove(int value) {
        if (head == nullptr) {
            return false;
        }
        if (head->value == value) {
            Node* old = head;
            head = head->next;
            delete old;
            return true;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->value != value) {
            current = current->next;
        }
        if (current->next == nullptr) {
            return false;
        }

        Node* old = current->next;
        current->next = current->next->next;
        delete old;
        return true;
    }

    std::vector<int> toVector() const {
        std::vector<int> values;
        for (Node* current = head; current != nullptr; current = current->next) {
            values.push_back(current->value);
        }
        return values;
    }
};

class Stack {
private:
    std::vector<int> data;

public:
    void push(int value) {
        data.push_back(value);
    }

    int pop() {
        if (data.empty()) {
            throw std::out_of_range("pop from empty stack");
        }
        int value = data.back();
        data.pop_back();
        return value;
    }

    int top() const {
        if (data.empty()) {
            throw std::out_of_range("top from empty stack");
        }
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }
};

class Queue {
private:
    std::deque<int> data;

public:
    void push(int value) {
        data.push_back(value);
    }

    int pop() {
        if (data.empty()) {
            throw std::out_of_range("pop from empty queue");
        }
        int value = data.front();
        data.pop_front();
        return value;
    }

    bool empty() const {
        return data.empty();
    }
};

class Deque {
private:
    std::deque<int> data;

public:
    void pushFront(int value) {
        data.push_front(value);
    }

    void pushBack(int value) {
        data.push_back(value);
    }

    int popFront() {
        if (data.empty()) {
            throw std::out_of_range("pop from empty deque");
        }
        int value = data.front();
        data.pop_front();
        return value;
    }

    int popBack() {
        if (data.empty()) {
            throw std::out_of_range("pop from empty deque");
        }
        int value = data.back();
        data.pop_back();
        return value;
    }
};

class HashTable {
private:
    struct Entry {
        std::string key;
        int value;
        bool active;
    };

    std::vector<std::vector<Entry>> buckets;

    int bucketIndex(const std::string& key) const {
        std::hash<std::string> hash;
        return static_cast<int>(hash(key) % buckets.size());
    }

public:
    explicit HashTable(int bucketCount = 17)
        : buckets(bucketCount) {}

    void put(const std::string& key, int value) {
        std::vector<Entry>& bucket = buckets[bucketIndex(key)];
        for (Entry& entry : bucket) {
            if (entry.active && entry.key == key) {
                entry.value = value;
                return;
            }
        }
        bucket.push_back({key, value, true});
    }

    bool get(const std::string& key, int& value) const {
        const std::vector<Entry>& bucket = buckets[bucketIndex(key)];
        for (const Entry& entry : bucket) {
            if (entry.active && entry.key == key) {
                value = entry.value;
                return true;
            }
        }
        return false;
    }

    bool remove(const std::string& key) {
        std::vector<Entry>& bucket = buckets[bucketIndex(key)];
        for (Entry& entry : bucket) {
            if (entry.active && entry.key == key) {
                entry.active = false;
                return true;
            }
        }
        return false;
    }
};

class BinarySearchTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;
        explicit Node(int value) : value(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool contains(Node* node, int value) const {
        if (node == nullptr) {
            return false;
        }
        if (value == node->value) {
            return true;
        }
        return value < node->value ? contains(node->left, value) : contains(node->right, value);
    }

    void preorder(Node* node, std::vector<int>& values) const {
        if (node == nullptr) {
            return;
        }
        values.push_back(node->value);
        preorder(node->left, values);
        preorder(node->right, values);
    }

    void inorder(Node* node, std::vector<int>& values) const {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, values);
        values.push_back(node->value);
        inorder(node->right, values);
    }

    void postorder(Node* node, std::vector<int>& values) const {
        if (node == nullptr) {
            return;
        }
        postorder(node->left, values);
        postorder(node->right, values);
        values.push_back(node->value);
    }

    void destroy(Node* node) {
        if (node == nullptr) {
            return;
        }
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        destroy(root);
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool contains(int value) const {
        return contains(root, value);
    }

    std::vector<int> preorder() const {
        std::vector<int> values;
        preorder(root, values);
        return values;
    }

    std::vector<int> inorder() const {
        std::vector<int> values;
        inorder(root, values);
        return values;
    }

    std::vector<int> postorder() const {
        std::vector<int> values;
        postorder(root, values);
        return values;
    }

    std::vector<int> levelOrder() const {
        std::vector<int> values;
        if (root == nullptr) {
            return values;
        }

        std::queue<Node*> queue;
        queue.push(root);
        while (!queue.empty()) {
            Node* node = queue.front();
            queue.pop();
            values.push_back(node->value);
            if (node->left != nullptr) {
                queue.push(node->left);
            }
            if (node->right != nullptr) {
                queue.push(node->right);
            }
        }
        return values;
    }
};

class MinHeap {
private:
    std::vector<int> heap;

    void siftUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] <= heap[index]) {
                break;
            }
            std::swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void siftDown(int index) {
        while (true) {
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int smallest = index;

            if (left < static_cast<int>(heap.size()) && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < static_cast<int>(heap.size()) && heap[right] < heap[smallest]) {
                smallest = right;
            }
            if (smallest == index) {
                break;
            }
            std::swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        siftUp(static_cast<int>(heap.size()) - 1);
    }

    int pop() {
        if (heap.empty()) {
            throw std::out_of_range("pop from empty heap");
        }
        int value = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            siftDown(0);
        }
        return value;
    }
};

class Trie {
private:
    struct Node {
        std::unordered_map<char, Node*> children;
        bool word = false;
    };

    Node* root;

    void destroy(Node* node) {
        for (const auto& child : node->children) {
            destroy(child.second);
        }
        delete node;
    }

public:
    Trie() : root(new Node()) {}

    ~Trie() {
        destroy(root);
    }

    void insert(const std::string& word) {
        Node* current = root;
        for (char ch : word) {
            if (current->children.count(ch) == 0) {
                current->children[ch] = new Node();
            }
            current = current->children[ch];
        }
        current->word = true;
    }

    bool search(const std::string& word) const {
        Node* current = root;
        for (char ch : word) {
            if (current->children.count(ch) == 0) {
                return false;
            }
            current = current->children.at(ch);
        }
        return current->word;
    }

    bool startsWith(const std::string& prefix) const {
        Node* current = root;
        for (char ch : prefix) {
            if (current->children.count(ch) == 0) {
                return false;
            }
            current = current->children.at(ch);
        }
        return true;
    }
};

class DisjointSetUnion {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    explicit DisjointSetUnion(int size)
        : parent(size), rank(size, 0) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int value) {
        if (parent[value] != value) {
            parent[value] = find(parent[value]);
        }
        return parent[value];
    }

    bool unite(int first, int second) {
        int rootA = find(first);
        int rootB = find(second);
        if (rootA == rootB) {
            return false;
        }
        if (rank[rootA] < rank[rootB]) {
            std::swap(rootA, rootB);
        }
        parent[rootB] = rootA;
        if (rank[rootA] == rank[rootB]) {
            rank[rootA]++;
        }
        return true;
    }
};

class FenwickTree {
private:
    std::vector<int> tree;

public:
    explicit FenwickTree(int size)
        : tree(size + 1, 0) {}

    void add(int index, int delta) {
        for (index++; index < static_cast<int>(tree.size()); index += index & -index) {
            tree[index] += delta;
        }
    }

    int prefixSum(int index) const {
        int sum = 0;
        for (index++; index > 0; index -= index & -index) {
            sum += tree[index];
        }
        return sum;
    }

    int rangeSum(int left, int right) const {
        return prefixSum(right) - (left == 0 ? 0 : prefixSum(left - 1));
    }
};

class SegmentTree {
private:
    int size;
    std::vector<int> tree;

    void build(const std::vector<int>& values, int node, int left, int right) {
        if (left == right) {
            tree[node] = values[left];
            return;
        }
        int mid = (left + right) / 2;
        build(values, node * 2, left, mid);
        build(values, node * 2 + 1, mid + 1, right);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int query(int node, int left, int right, int queryLeft, int queryRight) const {
        if (queryRight < left || right < queryLeft) {
            return 0;
        }
        if (queryLeft <= left && right <= queryRight) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        return query(node * 2, left, mid, queryLeft, queryRight)
            + query(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
    }

    void update(int node, int left, int right, int index, int value) {
        if (left == right) {
            tree[node] = value;
            return;
        }
        int mid = (left + right) / 2;
        if (index <= mid) {
            update(node * 2, left, mid, index, value);
        } else {
            update(node * 2 + 1, mid + 1, right, index, value);
        }
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

public:
    explicit SegmentTree(const std::vector<int>& values)
        : size(static_cast<int>(values.size())), tree(values.size() * 4, 0) {
        if (!values.empty()) {
            build(values, 1, 0, size - 1);
        }
    }

    int query(int left, int right) const {
        if (size == 0) {
            return 0;
        }
        return query(1, 0, size - 1, left, right);
    }

    void update(int index, int value) {
        if (size != 0) {
            update(1, 0, size - 1, index, value);
        }
    }
};

class Graph {
private:
    std::vector<std::vector<std::pair<int, int>>> adjacency;

public:
    explicit Graph(int vertices)
        : adjacency(vertices) {}

    void addDirectedEdge(int from, int to, int weight = 1) {
        adjacency[from].push_back({to, weight});
    }

    void addUndirectedEdge(int first, int second, int weight = 1) {
        addDirectedEdge(first, second, weight);
        addDirectedEdge(second, first, weight);
    }

    std::vector<std::vector<int>> adjacencyMatrix() const {
        int n = static_cast<int>(adjacency.size());
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        for (int from = 0; from < n; from++) {
            for (const auto& edge : adjacency[from]) {
                matrix[from][edge.first] = edge.second;
            }
        }
        return matrix;
    }

    std::vector<int> bfs(int start) const {
        std::vector<int> order;
        std::vector<bool> visited(adjacency.size(), false);
        std::queue<int> queue;

        visited[start] = true;
        queue.push(start);
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            order.push_back(node);
            for (const auto& edge : adjacency[node]) {
                int next = edge.first;
                if (!visited[next]) {
                    visited[next] = true;
                    queue.push(next);
                }
            }
        }
        return order;
    }

    void dfsHelper(int node, std::vector<bool>& visited, std::vector<int>& order) const {
        visited[node] = true;
        order.push_back(node);
        for (const auto& edge : adjacency[node]) {
            int next = edge.first;
            if (!visited[next]) {
                dfsHelper(next, visited, order);
            }
        }
    }

    std::vector<int> dfs(int start) const {
        std::vector<int> order;
        std::vector<bool> visited(adjacency.size(), false);
        dfsHelper(start, visited, order);
        return order;
    }

    std::vector<int> topologicalSort() const {
        int n = static_cast<int>(adjacency.size());
        std::vector<int> indegree(n, 0);
        for (const auto& edges : adjacency) {
            for (const auto& edge : edges) {
                indegree[edge.first]++;
            }
        }

        std::queue<int> queue;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                queue.push(i);
            }
        }

        std::vector<int> order;
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            order.push_back(node);
            for (const auto& edge : adjacency[node]) {
                if (--indegree[edge.first] == 0) {
                    queue.push(edge.first);
                }
            }
        }
        return order;
    }

    bool hasCycleUndirected() const {
        DisjointSetUnion dsu(static_cast<int>(adjacency.size()));
        for (int from = 0; from < static_cast<int>(adjacency.size()); from++) {
            for (const auto& edge : adjacency[from]) {
                int to = edge.first;
                if (from < to && !dsu.unite(from, to)) {
                    return true;
                }
            }
        }
        return false;
    }

    std::vector<int> dijkstra(int source) const {
        const int inf = std::numeric_limits<int>::max() / 4;
        std::vector<int> distance(adjacency.size(), inf);
        using Node = std::pair<int, int>;
        std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;

        distance[source] = 0;
        pq.push({0, source});
        while (!pq.empty()) {
            auto [currentDistance, node] = pq.top();
            pq.pop();
            if (currentDistance != distance[node]) {
                continue;
            }
            for (const auto& edge : adjacency[node]) {
                int next = edge.first;
                int weight = edge.second;
                if (distance[node] + weight < distance[next]) {
                    distance[next] = distance[node] + weight;
                    pq.push({distance[next], next});
                }
            }
        }
        return distance;
    }

    std::vector<int> bellmanFord(int source) const {
        const int inf = std::numeric_limits<int>::max() / 4;
        int n = static_cast<int>(adjacency.size());
        std::vector<int> distance(n, inf);
        distance[source] = 0;

        for (int pass = 0; pass < n - 1; pass++) {
            for (int from = 0; from < n; from++) {
                if (distance[from] == inf) {
                    continue;
                }
                for (const auto& edge : adjacency[from]) {
                    distance[edge.first] = std::min(distance[edge.first], distance[from] + edge.second);
                }
            }
        }
        return distance;
    }

    std::vector<std::vector<int>> floydWarshall() const {
        const int inf = std::numeric_limits<int>::max() / 4;
        int n = static_cast<int>(adjacency.size());
        std::vector<std::vector<int>> distance(n, std::vector<int>(n, inf));

        for (int i = 0; i < n; i++) {
            distance[i][i] = 0;
        }
        for (int from = 0; from < n; from++) {
            for (const auto& edge : adjacency[from]) {
                distance[from][edge.first] = std::min(distance[from][edge.first], edge.second);
            }
        }
        for (int through = 0; through < n; through++) {
            for (int from = 0; from < n; from++) {
                for (int to = 0; to < n; to++) {
                    if (distance[from][through] + distance[through][to] < distance[from][to]) {
                        distance[from][to] = distance[from][through] + distance[through][to];
                    }
                }
            }
        }
        return distance;
    }

    int primMstWeight() const {
        int n = static_cast<int>(adjacency.size());
        std::vector<bool> used(n, false);
        using Edge = std::pair<int, int>;
        std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;

        pq.push({0, 0});
        int total = 0;
        int visited = 0;
        while (!pq.empty() && visited < n) {
            auto [weight, node] = pq.top();
            pq.pop();
            if (used[node]) {
                continue;
            }
            used[node] = true;
            total += weight;
            visited++;
            for (const auto& edge : adjacency[node]) {
                if (!used[edge.first]) {
                    pq.push({edge.second, edge.first});
                }
            }
        }
        return visited == n ? total : -1;
    }
};

int linearSearch(const std::vector<int>& values, int target) {
    for (int i = 0; i < static_cast<int>(values.size()); i++) {
        if (values[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const std::vector<int>& values, int target) {
    int left = 0;
    int right = static_cast<int>(values.size()) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (values[mid] == target) {
            return mid;
        }
        if (values[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int interpolationSearch(const std::vector<int>& values, int target) {
    int low = 0;
    int high = static_cast<int>(values.size()) - 1;
    while (low <= high && target >= values[low] && target <= values[high]) {
        if (values[low] == values[high]) {
            return values[low] == target ? low : -1;
        }

        int position = low + ((target - values[low]) * (high - low)) / (values[high] - values[low]);
        if (values[position] == target) {
            return position;
        }
        if (values[position] < target) {
            low = position + 1;
        } else {
            high = position - 1;
        }
    }
    return -1;
}

void bubbleSort(std::vector<int>& values) {
    for (int end = static_cast<int>(values.size()) - 1; end > 0; end--) {
        for (int i = 0; i < end; i++) {
            if (values[i] > values[i + 1]) {
                std::swap(values[i], values[i + 1]);
            }
        }
    }
}

void selectionSort(std::vector<int>& values) {
    for (int i = 0; i < static_cast<int>(values.size()); i++) {
        int minIndex = i;
        for (int j = i + 1; j < static_cast<int>(values.size()); j++) {
            if (values[j] < values[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(values[i], values[minIndex]);
    }
}

void insertionSort(std::vector<int>& values) {
    for (int i = 1; i < static_cast<int>(values.size()); i++) {
        int current = values[i];
        int j = i - 1;
        while (j >= 0 && values[j] > current) {
            values[j + 1] = values[j];
            j--;
        }
        values[j + 1] = current;
    }
}

std::vector<int> mergeSort(std::vector<int> values) {
    if (values.size() <= 1) {
        return values;
    }

    int mid = static_cast<int>(values.size()) / 2;
    std::vector<int> left(values.begin(), values.begin() + mid);
    std::vector<int> right(values.begin() + mid, values.end());
    left = mergeSort(left);
    right = mergeSort(right);

    std::vector<int> result;
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(result));
    return result;
}

int partition(std::vector<int>& values, int low, int high) {
    int pivot = values[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (values[j] <= pivot) {
            std::swap(values[i++], values[j]);
        }
    }
    std::swap(values[i], values[high]);
    return i;
}

void quickSort(std::vector<int>& values, int low, int high) {
    if (low >= high) {
        return;
    }
    int pivot = partition(values, low, high);
    quickSort(values, low, pivot - 1);
    quickSort(values, pivot + 1, high);
}

void heapSort(std::vector<int>& values) {
    std::make_heap(values.begin(), values.end());
    std::sort_heap(values.begin(), values.end());
}

std::vector<int> countingSort(const std::vector<int>& values) {
    if (values.empty()) {
        return {};
    }
    int minValue = *std::min_element(values.begin(), values.end());
    int maxValue = *std::max_element(values.begin(), values.end());
    std::vector<int> counts(maxValue - minValue + 1, 0);
    for (int value : values) {
        counts[value - minValue]++;
    }

    std::vector<int> result;
    for (int i = 0; i < static_cast<int>(counts.size()); i++) {
        while (counts[i]-- > 0) {
            result.push_back(i + minValue);
        }
    }
    return result;
}

std::vector<int> radixSort(std::vector<int> values) {
    if (values.empty()) {
        return values;
    }
    int maxValue = *std::max_element(values.begin(), values.end());
    for (int exp = 1; maxValue / exp > 0; exp *= 10) {
        std::vector<int> output(values.size());
        std::vector<int> count(10, 0);
        for (int value : values) {
            count[(value / exp) % 10]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = static_cast<int>(values.size()) - 1; i >= 0; i--) {
            int digit = (values[i] / exp) % 10;
            output[--count[digit]] = values[i];
        }
        values = output;
    }
    return values;
}

std::vector<int> bucketSort(std::vector<int> values, int bucketCount = 5) {
    if (values.empty()) {
        return values;
    }
    int minValue = *std::min_element(values.begin(), values.end());
    int maxValue = *std::max_element(values.begin(), values.end());
    int range = std::max(1, (maxValue - minValue + 1 + bucketCount - 1) / bucketCount);
    std::vector<std::vector<int>> buckets(bucketCount);

    for (int value : values) {
        int index = std::min(bucketCount - 1, (value - minValue) / range);
        buckets[index].push_back(value);
    }

    std::vector<int> result;
    for (std::vector<int>& bucket : buckets) {
        insertionSort(bucket);
        result.insert(result.end(), bucket.begin(), bucket.end());
    }
    return result;
}

int factorialRecursive(int value) {
    return value <= 1 ? 1 : value * factorialRecursive(value - 1);
}

int factorialIterative(int value) {
    int result = 1;
    for (int i = 2; i <= value; i++) {
        result *= i;
    }
    return result;
}

int fibonacciMemo(int n, std::vector<int>& memo) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);
    return memo[n];
}

int fibonacciTabulation(int n) {
    if (n <= 1) {
        return n;
    }
    std::vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

void backtrackPermutations(std::vector<int>& values, int index, std::vector<std::vector<int>>& result) {
    if (index == static_cast<int>(values.size())) {
        result.push_back(values);
        return;
    }
    for (int i = index; i < static_cast<int>(values.size()); i++) {
        std::swap(values[index], values[i]);
        backtrackPermutations(values, index + 1, result);
        std::swap(values[index], values[i]);
    }
}

std::vector<std::vector<int>> permutations(std::vector<int> values) {
    std::vector<std::vector<int>> result;
    backtrackPermutations(values, 0, result);
    return result;
}

int greedyActivitySelection(std::vector<std::pair<int, int>> activities) {
    std::sort(activities.begin(), activities.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    int count = 0;
    int lastEnd = std::numeric_limits<int>::min();
    for (const auto& activity : activities) {
        if (activity.first >= lastEnd) {
            count++;
            lastEnd = activity.second;
        }
    }
    return count;
}

int longestCommonSubsequence(const std::string& first, const std::string& second) {
    std::vector<std::vector<int>> dp(first.size() + 1, std::vector<int>(second.size() + 1, 0));
    for (int i = 1; i <= static_cast<int>(first.size()); i++) {
        for (int j = 1; j <= static_cast<int>(second.size()); j++) {
            if (first[i - 1] == second[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[first.size()][second.size()];
}

std::vector<int> kmpPrefix(const std::string& pattern) {
    std::vector<int> prefix(pattern.size(), 0);
    for (int i = 1, length = 0; i < static_cast<int>(pattern.size());) {
        if (pattern[i] == pattern[length]) {
            prefix[i++] = ++length;
        } else if (length > 0) {
            length = prefix[length - 1];
        } else {
            prefix[i++] = 0;
        }
    }
    return prefix;
}

std::vector<int> kmpSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> matches;
    if (pattern.empty()) {
        return matches;
    }

    std::vector<int> prefix = kmpPrefix(pattern);
    for (int i = 0, j = 0; i < static_cast<int>(text.size());) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == static_cast<int>(pattern.size())) {
                matches.push_back(i - j);
                j = prefix[j - 1];
            }
        } else if (j > 0) {
            j = prefix[j - 1];
        } else {
            i++;
        }
    }
    return matches;
}

std::vector<int> rabinKarp(const std::string& text, const std::string& pattern) {
    const long long base = 256;
    const long long mod = 1000000007;
    std::vector<int> matches;
    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());
    if (m == 0 || m > n) {
        return matches;
    }

    long long highPower = 1;
    long long patternHash = 0;
    long long windowHash = 0;
    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * base + pattern[i]) % mod;
        windowHash = (windowHash * base + text[i]) % mod;
        if (i + 1 < m) {
            highPower = (highPower * base) % mod;
        }
    }

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == windowHash && text.substr(i, m) == pattern) {
            matches.push_back(i);
        }
        if (i < n - m) {
            windowHash = (windowHash - text[i] * highPower) % mod;
            if (windowHash < 0) {
                windowHash += mod;
            }
            windowHash = (windowHash * base + text[i + m]) % mod;
        }
    }
    return matches;
}

int longestSubstringWithoutRepeating(const std::string& text) {
    std::unordered_map<char, int> lastSeen;
    int best = 0;
    int left = 0;
    for (int right = 0; right < static_cast<int>(text.size()); right++) {
        char ch = text[right];
        if (lastSeen.count(ch) != 0) {
            left = std::max(left, lastSeen[ch] + 1);
        }
        lastSeen[ch] = right;
        best = std::max(best, right - left + 1);
    }
    return best;
}

bool twoSumSorted(const std::vector<int>& values, int target) {
    int left = 0;
    int right = static_cast<int>(values.size()) - 1;
    while (left < right) {
        int sum = values[left] + values[right];
        if (sum == target) {
            return true;
        }
        if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}

std::vector<int> prefixSums(const std::vector<int>& values) {
    std::vector<int> prefix(values.size() + 1, 0);
    for (int i = 0; i < static_cast<int>(values.size()); i++) {
        prefix[i + 1] = prefix[i] + values[i];
    }
    return prefix;
}

bool isPowerOfTwo(int value) {
    return value > 0 && (value & (value - 1)) == 0;
}

int countSetBits(int value) {
    int count = 0;
    while (value != 0) {
        value &= value - 1;
        count++;
    }
    return count;
}

int gcdEuclidean(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return std::abs(a);
}

std::vector<int> sieveOfEratosthenes(int limit) {
    std::vector<bool> prime(limit + 1, true);
    std::vector<int> primes;
    if (limit >= 0) {
        prime[0] = false;
    }
    if (limit >= 1) {
        prime[1] = false;
    }
    for (int number = 2; number <= limit; number++) {
        if (!prime[number]) {
            continue;
        }
        primes.push_back(number);
        if (1LL * number * number <= limit) {
            for (int multiple = number * number; multiple <= limit; multiple += number) {
                prime[multiple] = false;
            }
        }
    }
    return primes;
}

long long fastPower(long long base, long long exponent, long long mod = LLONG_MAX) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result = mod == LLONG_MAX ? result * base : (result * base) % mod;
        }
        base = mod == LLONG_MAX ? base * base : (base * base) % mod;
        exponent >>= 1;
    }
    return result;
}

int kruskalMstWeight(int vertices, std::vector<std::tuple<int, int, int>> edges) {
    std::sort(edges.begin(), edges.end(), [](const auto& first, const auto& second) {
        return std::get<2>(first) < std::get<2>(second);
    });

    DisjointSetUnion dsu(vertices);
    int total = 0;
    int used = 0;
    for (const auto& edge : edges) {
        int from = std::get<0>(edge);
        int to = std::get<1>(edge);
        int weight = std::get<2>(edge);
        if (dsu.unite(from, to)) {
            total += weight;
            used++;
        }
    }
    return used == vertices - 1 ? total : -1;
}

} // namespace dsa

int main() {
    using namespace dsa;

    DynamicArray array;
    array.pushBack(1);
    array.pushBack(3);
    array.insert(1, 2);
    assert(array[1] == 2);

    SinglyLinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.remove(1);
    assert((list.toVector() == std::vector<int>{2}));

    Stack stack;
    stack.push(10);
    assert(stack.pop() == 10);

    Queue queue;
    queue.push(20);
    assert(queue.pop() == 20);

    Deque deque;
    deque.pushFront(2);
    deque.pushBack(3);
    assert(deque.popBack() == 3);
    assert(deque.popFront() == 2);

    HashTable table;
    table.put("answer", 42);
    int value = 0;
    assert(table.get("answer", value) && value == 42);

    BinarySearchTree bst;
    for (int number : {5, 3, 7, 4}) {
        bst.insert(number);
    }
    assert(bst.contains(4));
    assert((bst.inorder() == std::vector<int>{3, 4, 5, 7}));

    MinHeap heap;
    heap.push(3);
    heap.push(1);
    assert(heap.pop() == 1);

    Trie trie;
    trie.insert("tree");
    assert(trie.search("tree"));
    assert(trie.startsWith("tr"));

    DisjointSetUnion dsu(3);
    dsu.unite(0, 1);
    assert(dsu.find(0) == dsu.find(1));

    FenwickTree fenwick(5);
    fenwick.add(0, 5);
    fenwick.add(1, 7);
    assert(fenwick.rangeSum(0, 1) == 12);

    SegmentTree segment({1, 2, 3, 4});
    assert(segment.query(1, 3) == 9);
    segment.update(2, 10);
    assert(segment.query(1, 3) == 16);

    std::vector<int> sortedValues = {1, 2, 3, 4, 5};
    assert(linearSearch(sortedValues, 4) == 3);
    assert(binarySearch(sortedValues, 4) == 3);
    assert(interpolationSearch(sortedValues, 4) == 3);

    std::vector<int> unsorted = {5, 1, 4, 2, 3};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    std::vector<int> copy = unsorted;
    bubbleSort(copy);
    assert(copy == expected);
    copy = unsorted;
    selectionSort(copy);
    assert(copy == expected);
    copy = unsorted;
    insertionSort(copy);
    assert(copy == expected);
    assert(mergeSort(unsorted) == expected);
    copy = unsorted;
    quickSort(copy, 0, static_cast<int>(copy.size()) - 1);
    assert(copy == expected);
    copy = unsorted;
    heapSort(copy);
    assert(copy == expected);
    assert(countingSort(unsorted) == expected);
    assert(radixSort(unsorted) == expected);
    assert(bucketSort(unsorted) == expected);

    assert(factorialRecursive(5) == 120);
    assert(factorialIterative(5) == 120);
    std::vector<int> memo(11, -1);
    assert(fibonacciMemo(10, memo) == 55);
    assert(fibonacciTabulation(10) == 55);
    assert(permutations({1, 2, 3}).size() == 6);
    assert(greedyActivitySelection({{1, 3}, {2, 5}, {4, 7}}) == 2);
    assert(longestCommonSubsequence("abcde", "ace") == 3);

    Graph graph(5);
    graph.addUndirectedEdge(0, 1, 2);
    graph.addUndirectedEdge(1, 2, 3);
    graph.addUndirectedEdge(0, 3, 6);
    graph.addUndirectedEdge(1, 3, 8);
    graph.addUndirectedEdge(1, 4, 5);
    graph.addUndirectedEdge(2, 4, 7);
    assert((graph.bfs(0) == std::vector<int>{0, 1, 3, 2, 4}));
    assert(graph.dijkstra(0)[4] == 7);
    assert(graph.bellmanFord(0)[4] == 7);
    assert(graph.floydWarshall()[0][4] == 7);
    assert(graph.primMstWeight() == 16);
    assert(graph.hasCycleUndirected());

    Graph dag(4);
    dag.addDirectedEdge(0, 1);
    dag.addDirectedEdge(0, 2);
    dag.addDirectedEdge(1, 3);
    dag.addDirectedEdge(2, 3);
    assert(dag.topologicalSort().size() == 4);

    assert(kruskalMstWeight(4, {{0, 1, 1}, {1, 2, 2}, {2, 3, 3}, {0, 3, 10}}) == 6);
    assert((kmpSearch("ababcabc", "abc") == std::vector<int>{2, 5}));
    assert((rabinKarp("ababcabc", "abc") == std::vector<int>{2, 5}));
    assert(longestSubstringWithoutRepeating("abcabcbb") == 3);
    assert(twoSumSorted({1, 2, 4, 7}, 9));
    assert((prefixSums({1, 2, 3}) == std::vector<int>{0, 1, 3, 6}));
    assert(isPowerOfTwo(16));
    assert(countSetBits(13) == 3);
    assert(gcdEuclidean(48, 18) == 6);
    assert((sieveOfEratosthenes(10) == std::vector<int>{2, 3, 5, 7}));
    assert(fastPower(2, 10) == 1024);

    std::cout << "All data structure and algorithm examples passed.\n";
    return 0;
}
