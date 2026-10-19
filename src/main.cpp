#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<double> data = {85.5, 90.0, 78.5, 92.0, 88.0};
    double sum = 0.0;
    for (double value : data){
        sum += value;
    }
    std::vector<double> sorted_data = data;
    std::size_t sorted_size = sorted_data.size();
    double mean = sum / data.size();
    double median = 0.0;
    double max_data = data[0];
    double min_data = data[0];
    for (double element : data){
        if (element > max_data){
            max_data = element;
        }
        if (element < min_data){
            min_data = element;
        }
    }
    std::sort(sorted_data.begin(), sorted_data.end());
    if (sorted_size % 2 == 0){
        median = (sorted_data[sorted_size / 2 - 1] + sorted_data[sorted_size / 2]) / 2.0;
    } else {
        median = sorted_data[sorted_size / 2];
    }
    std::cout << "Count: " << data.size() << "\n";
    std::cout << "Mean: " << mean << "\n";
    std::cout << "Median: " << median << "\n";
    std::cout << "Max: " << max_data << "\n";
    std::cout << "Min: " << min_data << "\n";
    return 0;
}