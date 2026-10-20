#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>


int main(int argc, char* argv[])
{   
    if (argc<3){
        std::cerr <<"Usage "<<argv[0]<<"<input_file> <output_file> [v_thresh] [t_min]\n";
        return 1;
    }

    std::string input_file = argv[1];
    std::string output_file = argv[2];
    double v_thresh = 0.5;
    double t_min_sec = 0.3;
    if (argc >=4 ){
        if(argc >= 5){
        t_min_sec = std::stod(argv[4]);
        }
        v_thresh = std::stod(argv[3]);
    }
    double t_min_ms = t_min_sec *1000.0; 

    // Part 2
    std::ifstream infile (input_file);

    std::string header;
    infile>>header;
    if (header !="ECG"){
        std::cerr<<"Invalid file format. Missing ECG identifier.\n";
        return 1;
    }

    double sampling_interval;
    infile>>sampling_interval;
    
    std::vector<double> voltages;
    double v;
    while(infile>>v){
        voltages.push_back(v);
    }
    infile.close();
 return 0;
}

