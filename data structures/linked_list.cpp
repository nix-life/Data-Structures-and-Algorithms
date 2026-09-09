#include <iostream>
#include <memory>

struct Node {
    int data;
    std::unique_ptr<Node> next;

    Node(int val) : data(val), next(nullptr) {}
};

void printList(const Node* node) {
    while (node) {
        std::cout << node->data << " -> ";
        node = node->next.get();
    }
    std::cout << "null\n";
}

int main() {
    auto node1 = std::make_unique<Node>(3);
    auto node2 = std::make_unique<Node>(5);
    auto node3 = std::make_unique<Node>(13);
    auto node4 = std::make_unique<Node>(2);

    node3->next = std::move(node4);
    node2->next = std::move(node3);
    node1->next = std::move(node2);

    printList(node1.get());

    return 0;
}
