#include <iostream>
int main()
{
    std::cout<<"Please type in the day of the week as digit number 1-7 ";
    int d;
    std::cin>>d;
    switch(d){
        case 1:
        std::cout<<"Today is Monday\n";
        break;
        case 2:
        std::cout<<"Today is Tuesday\n";
        break;
        case 3:
        std::cout<<"Today is Wednesday\n";
        break;
        case 4:
        std::cout<<"Today is Thursday\n";
        break;
        case 5:
        std::cout<<"Today is Friday\n";
        break;
        case 6:
        std::cout<<"Today is Saturday\n";
        break;
        case 7:
        std::cout<<"Today is Sunday\n";
        break;
        default:
        std::cout<<"error;Invalid number\n";
    }
    return 0;
}
    