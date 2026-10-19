#include <iostream>
#include <stdexcept>
#include "dataset.h"

int main(){
    Dataset scores("Quiz scores",{85.5, 90.0, 78.5, 92.0, 88.0});
    Dataset scores_copy = scores; //somehow creates perfect copy??
    Dataset empty("Empty dataset",{});
    scores_copy.addValue(100.0);
    try {
        std::cout << "Dataset: " << scores.name() << "\n";
        std::cout << "Count: " << scores.size() << "\n";
        std::cout << "Mean: " << scores.mean() << "\n";
        std::cout << "Median: " << scores.median() << "\n";
        std::cout << "Min: " << scores.min() << "\n";
        std::cout << "Max: " << scores.max() << "\n";
        std::cout << "Range: " << scores.range() << "\n";
        std::cout << "Dataset: " << scores_copy.name() << "\n";
        std::cout << "Count: " << scores_copy.size() << "\n";
        std::cout << "Mean: " << scores_copy.mean() << "\n";
        std::cout << "Median: " << scores_copy.median() << "\n";
        std::cout << "Min: " << scores_copy.min() << "\n";
        std::cout << "Max: " << scores_copy.max() << "\n";
        std::cout << "Range: " << scores_copy.range() << "\n";
        std::cout << "Dataset: " << empty.name() << "\n";
        std::cout << "Count: " << empty.size() << "\n";
        std::cout << "Mean: " << empty.mean() << "\n";
        std::cout << "Median: " << empty.median() << "\n";
        std::cout << "Min: " << empty.min() << "\n";
        std::cout << "Max: " << empty.max() << "\n";
        std::cout << "Range: " << empty.range() << "\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
    return 0;
}