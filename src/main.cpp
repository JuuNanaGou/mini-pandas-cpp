#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "statistics.h"

int main(){
    std::vector<double> data = {85.5, 90.0, 78.5, 92.0, 88.0};
    try {
        std::cout << "Count: " << data.size() << "\n";
        std::cout << "Mean: " << calculateMean(data) << "\n";
        std::cout << "Median: " << calculateMedian(data) << "\n";
        std::cout << "Min: " << calculateMin(data) << "\n";
        std::cout << "Max: " << calculateMax(data) << "\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << "\n";
    }
    return 0;
}