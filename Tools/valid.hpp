#ifndef _VAILD_HPP_
#define _VAILD_HPP_

/**
 *
 *@file
 *
 *@author
 *
 *@data
 *
 *@version
 *
 *@brief
 *
 *@copyright
 *
 */

#include "../PrintControl/print_control.h"
#include <assert.h>
#include <math.h>


namespace matrix {

/**
 * Compare if two floating point numbers are equal
 *
 * NAN is considered equal to NAN and -NAN
 * INFINITY is considered equal INFINITY but not -INFINITY
 *
 * @param x right side of equality check
 * @param y left side of equality check
 * @param eps numerical tolerance of the check
 * @return true if the two values are considered equal, false otherwise
 */
template <typename Type>
bool isEqualF(const Type x, const Type y, const Type eps = 1e-4f) {
  return (fabs(x - y) <= eps) || (isnan(x) && isnan(y)) ||
         (isinf(x) && isinf(y) && isnan(x - y));
}

} // namespace matrix

#endif
