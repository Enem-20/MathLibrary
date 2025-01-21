#include <iostream>

#include "Vector.hpp"

int main() {
    constexpr static Vector<int, 4> vec1(1.1, 3, 4, 5);
    constexpr static Vector<int, 4> vec2(1, 5, 4, 3);

    //auto scalar = vec1 ^ vec2;
//
    std::cout << vec1.x;

    return 0;
}