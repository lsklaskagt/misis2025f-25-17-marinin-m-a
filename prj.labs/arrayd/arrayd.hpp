#pragma once
#ifndef MARININ_M_A_25_17_ARRAYD_HPP
#define MARININ_M_A_25_17_RATIONAL_HPP

#include <cstddef>

class ArrayD {
public:
  ArrayD() = default;

  ArrayD(const ArrayD&);
  
  //! \param size - начальный размер, 0 < size
  ArrayD(const std::ptrdiff_t size);
  
  ~ArrayD();
  
  ArrayD& operator=(const ArrayD&);

  [[nodiscard]] std::ptrdiff_t size() const noexcept { return size_; }
  
  //! \param size - новый размер, 0 <= size
  void resize(const std::ptrdiff_t size);
  
  //! \param idx - индекс  элемента, 0 <= idx < Size()
  [[nodiscard]] float& operator[](const std::ptrdiff_t idx);
  [[nodiscard]] float operator[](const std::ptrdiff_t idx) const;

  //! \param idx - индекс вставляемого элемента, 0 <= idx <= size 
  void insert(const std::ptrdiff_t idx, const float val);

  //! \param idx - индекс удаляемого элемента, 0 <= idx < size 
  void remove(const std::ptrdiff_t idx);

private:
  std::ptrdiff_t capacity_ = 0;  //!< размер буффера
  std::ptrdiff_t size_ = 0;      //!< число элементов в массиве
  float* data_ = nullptr;             //!< буффер
};

#endif //MARININ_M_A_25_17_ARRAYD_HPP
