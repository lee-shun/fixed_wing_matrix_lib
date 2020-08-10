#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

/**
 *
 *@file Matrix
 *
 *@author lee-shun
 *
 *@data 2020-8-10
 *
 *@version
 *
 *@brief
 *
 *@copyright
 *
 */
#include "../PrintControl/print_control.h"
#include "../Tools/valid.hpp"
#include <iostream>
#include <string.h>

namespace matrix {

template <typename Type, size_t M, size_t N> class Matrix {
private:
  Type _data[M][N]{};

public:
  Matrix() = default;

  explicit Matrix(const Type data_[M * N]) {
    memcpy(_data, data_, sizeof(_data));
  }

  explicit Matrix(const Type data_[M][N]) {
    memcpy(_data, data_, sizeof(_data));
  }

  Matrix(const Matrix &other) { memcpy(_data, other._data, sizeof(_data)); }

  /**
   * 运算符重载
   * */

  /**
   * TODO:
   * 异常的判断和抛出
   * */
  inline const Type &operator()(size_t i, size_t j) const {
    return _data[i][j];
  }

  inline Type &operator()(size_t i, size_t j) { return _data[i][j]; }

  Matrix<Type, M, N> &operator=(const Matrix<Type, M, N> &other) {
    if (this != &other) {
      memcpy(_data, other._data, sizeof(_data));
    }
    return (*this);
  }

  void copyTo(Type dst[M * N]) const {
    memcpy(dst, _data, sizeof(Type) * M * N);
  }

  /**
   * 展开成为一维
   * */
  void copyToColumnMajor(Type dst[M * N]) const {
    const Matrix<Type, M, N> &self = *this;

    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        dst[i + (j * M)] = self(i, j);
      }
    }
  }

  /**
   * Matrix Operations
   */

  /**
   * 矩阵乘法
   * */
  template <size_t P>
  Matrix<Type, M, P> operator*(const Matrix<Type, N, P> &other) const {
    const Matrix<Type, M, N> &self = *this;
    Matrix<Type, M, P> res;
    res.setZero();

    for (size_t i = 0; i < M; i++) {
      for (size_t k = 0; k < P; k++) {
        for (size_t j = 0; j < N; j++) {
          res(i, k) += self(i, j) * other(j, k);
        }
      }
    }

    return res;
  }

  /**
   * 元素乘法
   * */
  Matrix<Type, M, N> emult(const Matrix<Type, M, N> &other) const {
    Matrix<Type, M, N> res;
    const Matrix<Type, M, N> &self = *this;

    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        res(i, j) = self(i, j) * other(i, j);
      }
    }

    return res;
  }

  /**
   * 元素除法
   * */
  Matrix<Type, M, N> edivide(const Matrix<Type, M, N> &other) const {
    Matrix<Type, M, N> res;
    const Matrix<Type, M, N> &self = *this;

    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        res(i, j) = self(i, j) / other(i, j);
      }
    }

    return res;
  }

  /**
   * 矩阵加法
   * */
  Matrix<Type, M, N> operator+(const Matrix<Type, M, N> &other) const {
    Matrix<Type, M, N> res;
    const Matrix<Type, M, N> &self = *this;

    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        res(i, j) = self(i, j) + other(i, j);
      }
    }

    return res;
  }

  /**
   * 矩阵减法
   * */
  Matrix<Type, M, N> operator-(const Matrix<Type, M, N> &other) const {
    Matrix<Type, M, N> res;
    const Matrix<Type, M, N> &self = *this;

    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        res(i, j) = self(i, j) - other(i, j);
      }
    }

    return res;
  }

  /**
   * 矩阵减法
   * unary minus
   * */
  Matrix<Type, M, N> operator-() const {
    Matrix<Type, M, N> res;
    const Matrix<Type, M, N> &self = *this;

    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        res(i, j) = -self(i, j);
      }
    }

    return res;
  }

  void operator+=(const Matrix<Type, M, N> &other) {
    Matrix<Type, M, N> &self = *this;
    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        self(i, j) += other(i, j);
      }
    }
  }

  void operator-=(const Matrix<Type, M, N> &other) {
    Matrix<Type, M, N> &self = *this;
    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        self(i, j) -= other(i, j);
      }
    }
  }

  template <size_t P> void operator*=(const Matrix<Type, N, P> &other) {
    Matrix<Type, M, N> &self = *this;
    self = self * other;
  }

  /**
   * Scalar Operations
   */

  Matrix<Type, M, N> operator*(Type scalar) const {
    Matrix<Type, M, N> res;
    const Matrix<Type, M, N> &self = *this;

    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        res(i, j) = self(i, j) * scalar;
      }
    }

    return res;
  }

  inline Matrix<Type, M, N> operator/(Type scalar) const {
    return (*this) * (1 / scalar);
  }

  Matrix<Type, M, N> operator+(Type scalar) const {
    Matrix<Type, M, N> res;
    const Matrix<Type, M, N> &self = *this;

    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        res(i, j) = self(i, j) + scalar;
      }
    }

    return res;
  }

  inline Matrix<Type, M, N> operator-(Type scalar) const {
    return (*this) + (-1 * scalar);
  }

  void operator*=(Type scalar) {
    Matrix<Type, M, N> &self = *this;

    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        self(i, j) *= scalar;
      }
    }
  }

  void operator/=(Type scalar) {
    Matrix<Type, M, N> &self = *this;
    self *= (Type(1) / scalar);
  }

  inline void operator+=(Type scalar) {
    Matrix<Type, M, N> &self = *this;
    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        self(i, j) += scalar;
      }
    }
  }

  inline void operator-=(Type scalar) {
    Matrix<Type, M, N> &self = *this;
    self += (-scalar);
  }

  bool operator==(const Matrix<Type, M, N> &other) const {
    return isEqual(*this, other);
  }

  bool operator!=(const Matrix<Type, M, N> &other) const {
    const Matrix<Type, M, N> &self = *this;
    return !(self == other);
  }

  /**
   * 矩阵函数
   * */

  Matrix<Type, N, M> transpose() const {
    Matrix<Type, N, M> res;
    const Matrix<Type, M, N> &self = *this;

    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        res(j, i) = self(i, j);
      }
    }

    return res;
  }

  /* tranpose alias */
  inline Matrix<Type, N, M> T() const { return transpose(); }

  void setZero() { memset(_data, 0, sizeof(_data)); }

  inline void zero() { setZero(); }

  void setAll(Type val) {
    Matrix<Type, M, N> &self = *this;

    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        self(i, j) = val;
      }
    }
  }

  inline void setOne() { setAll(1); }

  void setIdentity() {
    setZero();
    Matrix<Type, M, N> &self = *this;

    for (size_t i = 0; i < M && i < N; i++) {
      self(i, i) = 1;
    }
  }

  inline void identity() { setIdentity(); }

  inline void swapRows(size_t a, size_t b) {
    assert(a < M);
    assert(b < M);

    if (a == b) {
      return;
    }

    Matrix<Type, M, N> &self = *this;

    for (size_t j = 0; j < N; j++) {
      Type tmp = self(a, j);
      self(a, j) = self(b, j);
      self(b, j) = tmp;
    }
  }

  inline void swapCols(size_t a, size_t b) {
    assert(a < N);
    assert(b < N);

    if (a == b) {
      return;
    }

    Matrix<Type, M, N> &self = *this;

    for (size_t i = 0; i < M; i++) {
      Type tmp = self(i, a);
      self(i, a) = self(i, b);
      self(i, b) = tmp;
    }
  }

  Matrix<Type, M, N> abs() const {
    Matrix<Type, M, N> r;
    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        r(i, j) = Type(fabs((*this)(i, j)));
      }
    }
    return r;
  }

  Type max() const {
    Type max_val = (*this)(0, 0);
    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        Type val = (*this)(i, j);
        if (val > max_val) {
          max_val = val;
        }
      }
    }
    return max_val;
  }

  Type min() const {
    Type min_val = (*this)(0, 0);
    for (size_t i = 0; i < M; i++) {
      for (size_t j = 0; j < N; j++) {
        Type val = (*this)(i, j);
        if (val < min_val) {
          min_val = val;
        }
      }
    }
    return min_val;
  }

  void print() const {
    for (size_t i = 0; i < M; i++) {
      printf("[");
      for (size_t j = 0; j < M; j++) {
        std::cout << (_data[i][j]) << " ";
      }
      printf("]\n");
    }
  }

  Type col_num() const { return N; }

  Type row_num() const { return M; }

}; /*Matrix class*/

template <typename Type, size_t M, size_t N> Matrix<Type, M, N> zeros() {
  Matrix<Type, M, N> m;
  m.setZero();
  return m;
}

template <typename Type, size_t M, size_t N> Matrix<Type, M, N> ones() {
  Matrix<Type, M, N> m;
  m.setOne();
  return m;
}

template <typename Type, size_t M, size_t N>
Matrix<Type, M, N> operator*(Type scalar, const Matrix<Type, M, N> &other) {
  return other * scalar;
}

template <typename Type, size_t M, size_t N>
bool isEqual(const Matrix<Type, M, N> &x, const Matrix<Type, M, N> &y,
             const Type eps = 1e-4f) {
  for (size_t i = 0; i < M; i++) {
    for (size_t j = 0; j < N; j++) {
      if (!isEqualF(x(i, j), y(i, j), eps)) {
        return false;
      }
    }
  }
  return true;
}

} // namespace matrix

#endif
