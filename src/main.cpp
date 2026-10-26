#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include "dataset.h"
#include "csv.h"
#include "table.h"
#include "statistics.h"
#include <vector>

int main(){
    std::vector<double> data = {2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0};
    std::cout << "Population Variance: " << calculatePopulationVariance(data) << "\n";
    std::cout << "Sample Variance: " << calculateSampleVariance(data) << "\n";
    std::cout << "Population Standard Deviation: " << calculatePopulationStdDev(data) << "\n";
    std::cout << "Sample Standard Deviation: " << calculateSampleStdDev(data) << "\n";

    std::vector<double> single_data = {5.0};
    std::cout << "Population Variance (single element): " << calculatePopulationVariance(single_data) << "\n";
    try {
        std::cout << "Sample Variance (single element): " << calculateSampleVariance(single_data) << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}