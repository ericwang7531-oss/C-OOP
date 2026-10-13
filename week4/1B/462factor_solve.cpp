#include <iostream>
#include <cmath>
int main()
{
    for(int n = 2; n<462; n++){
        if (462 %n == 0)
        std::cout<<n<<" ";
    }
    std::cout<<"\n"<<std::endl;
    return 0;
}