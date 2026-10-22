#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include "dataset.h"
#include "csv.h"

int main(){
    try {
        Dataset math = loadColumn("data/grades.csv", 1);
        std::cout << "Dataset: " << math.name() << "\n";
        std::cout << "Count: " << math.size() << "\n";
        std::cout << "Mean: " << math.mean() << "\n";
        std::cout << "Median: " << math.median() << "\n";
        std::cout << "Min: " << math.min() << "\n";
        std::cout << "Max: " << math.max() << "\n";
        std::cout << "Range: " << math.range() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}