#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

/**
 *
 *@file Vector.hpp
 *
 *@author lee-shun
 *
 *@data 2020-08-11
 *
 *@version
 *
 *@brief
 *
 *@copyright
 *
 */
#include "../Matrix/Matrix.hpp"
#include "../PrintControl/print_control.h"
#include <iostream>
#include <string.h>
#include <math.h>
namespace vector {
template <typename Type, size_t M>
class Vector : public matrix::Matrix<Type, M, 1> {
public:
  typedef matrix::Matrix<Type, M, 1> MatrixM1;

  Vector() = default;
  Vector(const MatrixM1 &other) : MatrixM1(other) {}

  explicit Vector(const Type data_[M]) : MatrixM1(data_) {}

  inline const Type &operator()(size_t i) const {
    assert(i < M);

    const MatrixM1 &v = *this;
    return v(i, 0);
  }
  inline Type &operator()(size_t i) {
    assert(i < M);

    MatrixM1 &v = *this;
    return v(i, 0);
  }

  Type dot(const MatrixM1 &b) const {
    const Vector &a(*this);
    Type r(0);
    for (size_t i = 0; i < M; i++) {
      r += a(i) * b(i, 0);
    }
    return r;
  }

  inline Type operator*(const MatrixM1 &b) const {
    const Vector &a(*this);
    return a.dot(b);
  }

  inline Vector operator*(Type b) const {
    return Vector(MatrixM1::operator*(b));
  }

  /**
   * @note 此处使用了标准库的sqrt（）函数实现
   */
  Type norm() const {
    const Vector &a(*this);
    return Type(sqrt(a.dot(a)));
  }

  Type norm_squared() const {
    const Vector &a(*this);
    return a.dot(a);
  }

  inline Type length() const { return norm(); }

  inline void normalize() { (*this) /= norm(); }

  Vector unit() const { return (*this) / norm(); }

  Vector unit_or_zero(const Type eps = Type(1e-5)) const {
    const Type n = norm();
    if (n > eps) {
      return (*this) / n;
    }
    return Vector();
  }

  inline Vector normalized() const { return unit(); }

  bool longerThan(Type testVal) const {
    return norm_squared() > testVal * testVal;
  }

  Vector esqrt() const {
    const Vector &a(*this);
    Vector r;
    for (size_t i = 0; i < M; i++) {
      r(i) = Type(sqrt(a(i)));
    }
    return r;
  }
};

} // namespace vector
#endif
