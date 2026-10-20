#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string filename = "data.txt";

    std::ifstream infile(filename);
    if(!infile){
        std::cerr<<"ERROR: failed to open the file \""<<filename<<"\"for reading - aborting \n";
        return 1;
    }

    std::cout<<"File \""<<filename<<"\" opened successfully \n";
    
    int n,data_num;
    double sum = 0;
    data_num = 0;

    while (infile>>n)
        std::cout<<n<<" ";
        data_num = data_num+1;
        sum = sum+n;
    std::cout<<" "<<std::endl;
    
    std::cout<<"Mean value of all data value is "<<sum/data_num<<"\n";
    infile.close();

    std::cout<<" "<<std::endl;
    return 0;
}