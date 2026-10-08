#include <iostream>
int main()
{
    std::cout<<"Please type in ur height in m"<<"\n";
    float h;
    std::cin>>h;
    std::cout<<"Now please type in ur weight in kg"<<"\n";
    float w;
    std::cin>>w;
    float BMI;
    BMI = w/h/h;
    std::cout<<"Your BMI is "<<BMI<<std::endl;
    if (BMI<18.5)
        std::cout<<"You are underweight"<<std::endl;
    else if (BMI>=18.5&&BMI<25)
        std::cout<<"You are healthy"<<std::endl;
    else if (BMI>=25&&BMI<30)
        std::cout<<"Your are overweight"<<std::endl;
    else
        std::cout<<"Your are obese"<<std::endl;
    return 0;
}