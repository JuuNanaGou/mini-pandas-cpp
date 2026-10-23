#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include "dataset.h"
#include "csv.h"
#include "table.h"
#include <vector>

int main(){
    try {
        Table grades("data/grades.csv");
        std::cout << "Rows: " << grades.rowCount() << "\n";

        std::vector<std::string> names = grades.textColumn("name");
        Dataset mathScores = grades.numericColumn("math");
        Dataset scienceScores = grades.numericColumn("science");

        std::cout << names[0] << "'s math score: " << grades.cell(0, "math") << "\n";
        std::cout << names[0] << "'s science score: " << grades.cell(0, "science") << "\n";
        std::cout << "Math mean: " << mathScores.mean() << "\n";
        std::cout << "Science mean: " << scienceScores.mean() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}