#include<iostream>
#include "../Matrix/Matrix.hpp"

int main()
{
    float a[2][2] = {{1,2},{3,4}};
    matrix::Matrix<float,2,2> ma_4(a);
    std::cout<<ma_4(1,1)<<std::endl;

    matrix::Matrix<float,2,2> MA = ma_4*2;
    std::cout<<MA(3,3)<<std::endl;
    MA.print();

    matrix::Matrix<float,2,2> MB = ma_4*MA;
    MB.print();

    bool hello = matrix::isEqual(MA,MA);
    std::cout<<hello<<std::endl;
    return 0;
}
