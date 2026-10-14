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

    std::cout<<"File\""<<filename<<"\" opened successfully \n";
    
    return 0;
}