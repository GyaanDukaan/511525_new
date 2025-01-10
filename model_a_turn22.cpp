#include <iostream>
#include <chrono>
#include <concepts>

template <std::integral T>
void printType(T value) {
    std::cout << "Integral type: " << value << std::endl;
}

template <typename T>
requires (!std::integral<T>)
void printType(T value) {
    std::cout << "Non-integral type: " << value << std::endl;
}

int main() {
    const int iterations = 1000000;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        printType(i);    // Integral type
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "C++23 concepts duration: " << duration.count() << " ms" << std::endl;

    return 0;
}
