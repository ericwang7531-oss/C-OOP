#include <iostream>
#include <cmath>
int main()
{  std::cout<<"Prime numbers from 1-100\n";
   
   for (int i =2; i<100;i++){ 
    bool isprime = true;
    for(int n = 2; n<i; n++){
        if (i%n == 0)
            isprime = false;
    }
    if (isprime)
    std::cout<<i<<" ";
    }
    
    return 0;
}