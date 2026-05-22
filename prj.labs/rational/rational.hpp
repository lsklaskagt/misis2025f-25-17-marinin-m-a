#pragma once
#ifndef MARININ_M_A_25_17_RATIONAL_HPP
#define MARININ_M_A_25_17_RATIONAL_HPP

#include <cstdint>
#include <iosfwd>

class Rational {
public:
  Rational() = default;
  Rational(const Rational&) = default;
  explicit Rational(const std::int32_t num) noexcept : num_(num) { }
  Rational(const std::int32_t num, const std::int32_t den);
  ~Rational() = default;
  Rational& operator=(const Rational&) = default;

  [[nodiscard]] std::int32_t num() const noexcept { return num_; }
  [[nodiscard]] std::int32_t den() const noexcept { return den_; }

  [[nodiscard]] bool operator==(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator!=(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator<(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator<=(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator>(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator>=(const Rational& rhs) const noexcept;

  [[nodiscard]] Rational operator-() const noexcept { return { -num_, den_ }; }

  Rational& operator+=(const Rational& rhs) noexcept;
  Rational& operator-=(const Rational& rhs) noexcept;
  Rational& operator*=(const Rational& rhs) noexcept;
  Rational& operator/=(const Rational& rhs);

  Rational& operator+=(const int32_t rhs) noexcept;
  Rational& operator-=(const int32_t rhs) noexcept;
  Rational& operator*=(const int32_t rhs) noexcept;
  Rational& operator/=(const int32_t rhs);

  std::ostream& WriteTo(std::ostream& ostrm) const noexcept;
  std::istream& ReadFrom(std::istream& istrm) noexcept;

private:
  std::int32_t num_ = 0;
  std::int32_t den_ = 1;

  void Normalize() noexcept;
};

[[nodiscard]] Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const Rational& rhs);

[[nodiscard]] Rational operator+(const Rational& lhs, const int32_t rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const int32_t rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const int32_t rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const int32_t rhs);

[[nodiscard]] Rational operator+(const int32_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const int32_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const int32_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const int32_t lhs, const Rational& rhs);

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept;

std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept;

#endif //MARININ_M_A_25_17_RATIONAL_HPP
