#include <iostream>
#include <cmath>

int main()
{
    float pi = 3.1415926;
    float x, r;
    std::cout<<"Please type in value x"<<std::endl;
    std::cin>>x;
    r = std::sqrt(2*pi/std::abs(x))*std::exp(2*std::pow(std::sin(0.1*x),2));
    std::cout<<"r = "<<r<<std::endl;
    return 0;
}