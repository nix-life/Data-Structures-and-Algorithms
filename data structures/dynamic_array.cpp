#include "dynamic_array.hpp"
#include <iostream>

int main() {
    Array<int> a;
    a.add(1);
    a.add(2);
    a.add(3);

    std::cout << a.toString() << std::endl; // [1, 2, 3]
}