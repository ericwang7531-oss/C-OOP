#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> load_data(const std::string& filename);

int main()
{
    std::string filename = "data.txt";

    std::ifstream infile(filename);
    if(!infile){
        std::cerr<<"ERROR: failed to open the file \""<<filename<<"\"for reading - aborting \n";
        return 1;
    }

    std::cout<<"File \""<<filename<<"\" opened successfully \n";
    
    std::vector<int> data;

    int n;
    while(infile>>n)
        data.push_back(n);
    
    std::cout << "Loaded " << data.size() << " entries from the file \"" << filename << "\"\n";
    infile.close();

    std::cout<<" "<<std::endl;
    return 0;
}