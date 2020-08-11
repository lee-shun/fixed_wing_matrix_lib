#ifndef _VECTOR3_HPP_
#define _VECTOR3_HPP_

/**
  *
  *@file 
  *
  *@author lee-shun
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
/**
 * @file Vector3.hpp
 *
 * 3D vector class.
 *
 * @author James Goppert <james.goppert@gmail.com>
 */

#pragma once

#include "Vector.hpp"

namespace vector
{


template<typename Type>
class Vector3 : public Vector<Type, 3>
{
public:

    typedef matrix::Matrix<Type, 3, 1> Matrix31;

    Vector3() = default;

    Vector3(const Matrix31 & other) :
        Vector<Type, 3>(other)
    {
    }

    explicit Vector3(const Type data_[3]) :
        Vector<Type, 3>(data_)
    {
    }

    Vector3(Type x, Type y, Type z) {
        Vector3 &v(*this);
        v(0) = x;
        v(1) = y;
        v(2) = z;
    }

    Vector3 cross(const Matrix31 & b) const {
        const Vector3 &a(*this);
        return {a(1)*b(2,0) - a(2)*b(1,0), -a(0)*b(2,0) + a(2)*b(0,0), a(0)*b(1,0) - a(1)*b(0,0)};
    }

    /**
     * Override matrix ops so Vector3 type is returned
     */

    inline Vector3 operator+(Vector3 other) const
    {
        return Matrix31::operator+(other);
    }

    inline Vector3 operator-(Vector3 other) const
    {
        return Matrix31::operator-(other);
    }

    inline Vector3 operator-() const
    {
        return Matrix31::operator-();
    }

    inline Vector3 operator*(Type scalar) const
    {
        return Matrix31::operator*(scalar);
    }

    inline Type operator*(Vector3 b) const
    {
        return Vector<Type, 3>::operator*(b);
    }

    inline Vector3 operator%(const Matrix31 & b) const {
        return (*this).cross(b);
    }

    /**
     * Override vector ops so Vector3 type is returned
     */
    inline Vector3 unit() const {
        return Vector3(Vector<Type, 3>::unit());
    }

    inline Vector3 normalized() const {
        return unit();
    }

};

typedef Vector3<float> Vector3f;

} // namespace matrix

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */

#endif
