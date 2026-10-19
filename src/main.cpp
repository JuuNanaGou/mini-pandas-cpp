#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

double calculateMean(const std::vector<double>& values){
        if (values.empty()){
            throw std::invalid_argument("The vector is empty. Cannot calculate mean."); // checks the vector if its empty and throws an error if true. DO NOT put try-catch in function, do in main
        }
        double sum = 0.0;
        for (double value : values){
            sum += value;
        }
        return sum / values.size();
    }

double calculateMedian(const std::vector<double>& values){
        double median = 0.0;
        if (values.empty()){
            throw std::invalid_argument("The vector is empty. Cannot calculate median.");
        }
        std::vector<double> sorted_data = values;
        std::size_t sorted_size = sorted_data.size();
        std::sort(sorted_data.begin(), sorted_data.end());
        if (sorted_size % 2 == 0){
            median = (sorted_data[sorted_size / 2 - 1] + sorted_data[sorted_size / 2]) / 2.0;
        } else {
            median = sorted_data[sorted_size / 2];
        }
        return median;
    }

    double calculateMin(const std::vector<double>& values){
        if (values.empty()){
            throw std::invalid_argument("The vector is empty. Cannot calculate minimum.");
        }
        double min_data = values[0];
        for (double element : values){
            if (element < min_data){
                min_data = element;
            }
        }
        return min_data;
    }

double calculateMax(const std::vector<double>& values){
        if (values.empty()){
            throw std::invalid_argument("The vector is empty. Cannot calculate maximum.");
        }
        double max_data = values[0];
        for (double element : values){
            if (element > max_data){
                max_data = element;
            }
        }
        return max_data;
    }

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