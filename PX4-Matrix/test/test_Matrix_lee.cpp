#include "math.hpp"
#include <iostream>

int main() {

  int a[3 * 4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  int b[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  matrix::Matrix<int, 3, 4> m34(a);
  matrix::Matrix<int, 4, 3> m43(b);

  std::cout << m34 << std::endl;
  std::cout << m34(1, 1) << std::endl;
  std::cout << m34 * m43 << std::endl;

  std::cout << matrix::ones<int, 5, 6>() << std::endl;
  std::cout << 5 * m34 << std::endl;

  return 0;
}
