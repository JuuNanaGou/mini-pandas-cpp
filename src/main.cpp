#include <iostream>
#include <vector>

int main(){
    std::vector<double> data = {85.5, 90.0, 78.5, 92.0, 88.0};
    double sum = 0.0;
    for (double value : data){
        sum += value;
    }
    double mean = sum / data.size();
    std::cout << "Count: " << data.size() << "\n";
    std:: cout << "Mean: " << mean << "\n";
    return 0;
}