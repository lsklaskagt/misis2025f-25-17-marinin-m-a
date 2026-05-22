#include <iostream>
#include "rational.hpp"

int main() {
    try {
        std::cout << "Тест создания и вывода\n";
        Rational r1(4, 8);
        Rational r2(-1, -2);
        std::cout << "r1 (должно быть 1/2): " << r1 << "\n";
        std::cout << "r2 (должно быть 1/2): " << r2 << "\n";

        std::cout << "\nТест сравнения\n";
        std::cout << std::boolalpha;
        std::cout << "r1 == r2? " << (r1 == r2) << " (ожидается true)\n";

        std::cout << "\nТест арифметики\n";
        Rational r3(1, 3);
        Rational res_add = r1 + r3;
        std::cout << r1 << " + " << r3 << " = " << res_add << " (ожидается 5/6)\n";

        Rational res_sub = 2 - r1;
        std::cout << "2 - " << r1 << " = " << res_sub << " (ожидается 3/2)\n";

        std::cout << "\nТест ввода\n";
        Rational r4;
        std::cout << "Введите дробь в формате num/den (например, 3/5): ";
        if (std::cin >> r4) {
            std::cout << "Вы ввели успешную дробь: " << r4 << "\n";
        } else {
            std::cout << "Ошибка ввода!\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << "\n";
    }
    return 0;
}
