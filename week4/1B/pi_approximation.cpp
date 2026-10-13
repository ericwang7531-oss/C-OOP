#include <iostream>
#include <cmath>
int main()
{
    double pi; 
    float c = 0;
    long int n = 1;
    while (1.0/(n*n)>1e-15)
    {
        c = c + 1.0/(n*n);
        n = n+1;
    }
    pi = sqrt(6*c);
    std::cout<<"pi value after approximation is "<<pi<<std::endl;
    std::cout<<"iteration round "<<n<<std::endl;
    
    return 0;
}