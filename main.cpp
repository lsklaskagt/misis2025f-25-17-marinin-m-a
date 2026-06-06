#include "prj.labs/rational/rational.hpp"
#include "prj.labs/complex/complex.hpp"
#include "prj.labs/arrayd/arrayd.hpp"

#include <iostream>
#include <stdexcept>

int main() {
    Rational r1(1, 2);
    Rational r2(1, 3);
    std::cout << "r1: " << r1 << ", r2: " << r2 << "\n";

    Rational r_sum = r1 + r2;
    Rational r_mul = r1 * r2;
    std::cout << "r1 + r2: " << r_sum << "\n";
    std::cout << "r1 * r2: " << r_mul << "\n";

    Rational r_mixed = r1 + 2;
    std::cout << "r1 + 2: " << r_mixed << "\n";

    try {
        Rational bad = r1 / 0;
    } catch (const std::invalid_argument& e) {
        std::cout << "Error caught: " << e.what() << "\n";
    }

    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    std::cout << "c1: " << c1 << ", c2: " << c2 << "\n";

    Complex c_sum = c1 + c2;
    Complex c_mul = c1 * c2;
    std::cout << "c1 + c2: " << c_sum << "\n";
    std::cout << "c1 * c2: " << c_mul << "\n";

    Complex c_mixed = 1.0 - c1;
    std::cout << "1.0 - c1: " << c_mixed << "\n";

    try {
        Complex bad = c1 / 0.0;
    } catch (const std::invalid_argument& e) {
        std::cout << "Error caught: " << e.what() << "\n";
    }

    ArrayD arr(3);
    arr[0] = 10.5f;
    arr[1] = 20.5f;
    arr[2] = 30.5f;

    std::cout << "Array: ";
    for (std::ptrdiff_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    arr.insert(1, 99.9f);
    std::cout << "After insert: ";
    for (std::ptrdiff_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    arr.remove(2);
    std::cout << "After remove: ";
    for (std::ptrdiff_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    arr.resize(5);
    std::cout << "After resize: ";
    for (std::ptrdiff_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
