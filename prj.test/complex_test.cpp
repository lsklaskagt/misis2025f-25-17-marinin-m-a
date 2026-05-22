#include <complex/complex.hpp>

#include <sstream>
#include <stdexcept>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../prj.thirdparty/doctest.h"

TEST_CASE("[complex] - ctor default") {
    Complex c;
    CHECK(c.re == doctest::Approx(0.0));
    CHECK(c.im == doctest::Approx(0.0));
}

TEST_CASE("[complex] - ctor real") {
    Complex c(3.0);
    CHECK(c.re == doctest::Approx(3.0));
    CHECK(c.im == doctest::Approx(0.0));
}

TEST_CASE("[complex] - ctor real imag") {
    Complex c(3.0, -4.0);
    CHECK(c.re == doctest::Approx(3.0));
    CHECK(c.im == doctest::Approx(-4.0));
}

TEST_CASE("[complex] - op== op!=") {
    CHECK(Complex(1.0, 2.0) == Complex(1.0, 2.0));
    CHECK(!(Complex(1.0, 2.0) == Complex(1.0, 3.0)));
    CHECK(Complex(1.0, 2.0) != Complex(1.0, 3.0));
    CHECK(!(Complex(1.0, 2.0) != Complex(1.0, 2.0)));
}

TEST_CASE("[complex] - op- unary") {
    Complex c(3.0, -4.0);
    const Complex neg = -c;
    CHECK(neg == Complex(-3.0, 4.0));
    CHECK(c == Complex(3.0, -4.0));
}

TEST_CASE("[complex] - op+= Complex") {
    Complex c(1.0, 2.0);
    c += Complex(3.0, 4.0);
    CHECK(c == Complex(4.0, 6.0));
}

TEST_CASE("[complex] - op+= double") {
    Complex c(1.0, 2.0);
    c += 3.0;
    CHECK(c == Complex(4.0, 2.0));
}

TEST_CASE("[complex] - op-= Complex") {
    Complex c(4.0, 6.0);
    c -= Complex(1.0, 2.0);
    CHECK(c == Complex(3.0, 4.0));
}

TEST_CASE("[complex] - op-= double") {
    Complex c(4.0, 2.0);
    c -= 1.0;
    CHECK(c == Complex(3.0, 2.0));
}

TEST_CASE("[complex] - op*= Complex") {
    Complex c(3.0, 4.0);
    c *= Complex(1.0, 2.0);
    CHECK(c == Complex(-5.0, 10.0));
}

TEST_CASE("[complex] - op*= double") {
    Complex c(3.0, 4.0);
    c *= 2.0;
    CHECK(c == Complex(6.0, 8.0));
}

TEST_CASE("[complex] - op/= Complex") {
    Complex c(3.0, 4.0);
    c /= Complex(1.0, 2.0);
    CHECK(c == Complex(2.2, -0.4));
}

TEST_CASE("[complex] - op/= double") {
    Complex c(3.0, 4.0);
    c /= 2.0;
    CHECK(c == Complex(1.5, 2.0));
}

TEST_CASE("[complex] - op/= zero") {
    Complex c(3.0, 4.0);
    CHECK_THROWS_AS(c /= Complex(0.0, 0.0), std::invalid_argument);
    CHECK_THROWS_AS(c /= 0.0, std::invalid_argument);
}

TEST_CASE("[complex] - op+ Complex") {
    CHECK(Complex(1.0, 2.0) + Complex(3.0, 4.0) == Complex(4.0, 6.0));
}

TEST_CASE("[complex] - op+ double") {
    CHECK(Complex(1.0, 2.0) + 3.0 == Complex(4.0, 2.0));
    CHECK(3.0 + Complex(1.0, 2.0) == Complex(4.0, 2.0));
}

TEST_CASE("[complex] - op- Complex") {
    CHECK(Complex(4.0, 6.0) - Complex(1.0, 2.0) == Complex(3.0, 4.0));
}

TEST_CASE("[complex] - op- double") {
    CHECK(Complex(4.0, 2.0) - 1.0 == Complex(3.0, 2.0));
    CHECK(1.0 - Complex(3.0, 4.0) == Complex(-2.0, -4.0));
}

TEST_CASE("[complex] - op* Complex") {
    CHECK(Complex(3.0, 4.0) * Complex(1.0, 2.0) == Complex(-5.0, 10.0));
}

TEST_CASE("[complex] - op* double") {
    CHECK(Complex(3.0, 4.0) * 2.0 == Complex(6.0, 8.0));
    CHECK(2.0 * Complex(3.0, 4.0) == Complex(6.0, 8.0));
}

TEST_CASE("[complex] - op/ Complex") {
    CHECK(Complex(3.0, 4.0) / Complex(1.0, 2.0) == Complex(2.2, -0.4));
    CHECK_THROWS_AS(static_cast<void>(Complex(3.0, 4.0) / Complex(0.0, 0.0)), std::invalid_argument);
}

TEST_CASE("[complex] - op/ double") {
    CHECK(Complex(3.0, 4.0) / 2.0 == Complex(1.5, 2.0));
    CHECK_THROWS_AS(static_cast<void>(Complex(3.0, 4.0) / 0.0), std::invalid_argument);
}

TEST_CASE("[complex] - op/ double Complex") {
    CHECK(10.0 / Complex(3.0, 4.0) == Complex(1.2, -1.6));
    CHECK_THROWS_AS(static_cast<void>(1.0 / Complex(0.0, 0.0)), std::invalid_argument);
}

TEST_CASE("[complex] - write_to") {
    std::ostringstream ss;
    ss << Complex(3.0, 4.0);
    CHECK("{3,4}" == ss.str());

    ss.str("");
    ss << Complex(3.5, -1.25);
    CHECK("{3.5,-1.25}" == ss.str());
}

TEST_CASE("[complex] - read_from") {
    Complex c;
    std::istringstream ss("{3.5,-1.25}");
    ss >> c;
    CHECK(c == Complex(3.5, -1.25));
}

TEST_CASE("[complex] - read_from bad format") {
    Complex c;
    std::istringstream ss("[3.5,-1.25]");
    ss >> c;
    CHECK(ss.fail());
}
