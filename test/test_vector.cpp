#include "../Vector/Vector.hpp"

int main() {

  float a[3] = {1, 2, 3};
  vector::Vector<float, 3> v1(a);
  std::cout << v1.norm() << std::endl;
  return 0;
}
