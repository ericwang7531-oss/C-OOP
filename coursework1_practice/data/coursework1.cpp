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
    
    std::vector<int> peak_indices;
    int last_peak_index = -1;

    for (size_t i = 1; i < voltages.size() - 1; ++i) {
        if (voltages[i] > v_thresh && voltages[i] > voltages[i - 1] && voltages[i] > voltages[i + 1]) {
            double time_elapsed = (last_peak_index == -1) ? t_min_ms : (i - last_peak_index) * sampling_interval;
            if (time_elapsed >= t_min_ms) {
                peak_indices.push_back(i);
                last_peak_index = i;
            }
        }
    }

    if (peak_indices.size() < 2) {
        std::cerr << "Not enough peaks detected to compute HRV.\n";
        return 1;
    }

    std::vector<double> rr_intervals;
    double min_rr = 1e9, max_rr = -1, sum_rr = 0;

    for (size_t i = 1; i < peak_indices.size(); ++i) {
        double rr = (peak_indices[i] - peak_indices[i - 1]) * sampling_interval;
        rr_intervals.push_back(rr);
        if (rr < min_rr) min_rr = rr;
        if (rr > max_rr) max_rr = rr;
        sum_rr += rr;
    }
    double mean_rr = sum_rr / rr_intervals.size(); 


    double sum_sq_diff = 0;
    for (size_t i = 1; i < rr_intervals.size(); ++i) {
        double diff = rr_intervals[i] - rr_intervals[i - 1];
        sum_sq_diff += diff * diff;
    }
    double rmssd = sqrt(sum_sq_diff / (rr_intervals.size() - 1));

    std::string stress_level;
    if (rmssd > 50) stress_level = "low";           
    else if (rmssd >= 20) stress_level = "moderate"; 
    else stress_level = "high";                     

    std::ofstream outfile(output_file);
    if (!outfile.is_open()) {
        std::cerr << "Error opening output file.\n";
        return 1;
    }

    outfile << "data file: " << input_file << "\n";

    outfile << "min/mean/max RR interval: " << min_rr << " " << mean_rr << " " << max_rr << "\n";
    outfile << std::fixed << std::setprecision(3);
    outfile << "RMSSD: " << rmssd << "\n";
    outfile << "stress level: " << stress_level << "\n";

    outfile.close();

 return 0;
}

