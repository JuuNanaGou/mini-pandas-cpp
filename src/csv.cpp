#include "csv.h"
#include <sstream>
#include "dataset.h"
#include <sstream>
#include <stdexcept>
#include <string>
#include <fstream>

namespace{
    std::string trim(const std::string& text){
        const std::string whitespace = " \t\r\n";
        std::size_t start = text.find_first_not_of(whitespace);
        if(start == std::string::npos){
            return "";
        }
        std::size_t end = text.find_last_not_of(whitespace);
        return text.substr(start, end - start + 1);
    }
}
std::vector<std::string> splitLine(const std::string& line) {
    std::vector<std::string> cells;
    std::stringstream ss(line);
    std::string cell;

    while (std::getline(ss, cell, ',')) {
        cells.push_back(trim(cell));
    }
    if(!line.empty() && line.back() == ',') {
        cells.push_back("");
    }
    return cells;
}

Dataset loadColumn(const std::string& path, std::size_t columnIndex) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + path);
    }
    std::string line;
    if (!std::getline(file, line)){
        throw std::runtime_error("File is empty: " + path);
    }
    std::vector<std::string> headerCells = splitLine(line);
    if(columnIndex >= headerCells.size()) {
        throw std::out_of_range("Column index out of range: " + path);
    }
    std::string columnName = headerCells[columnIndex];
    std::vector<double> values;
    while(std::getline(file,line)){
        std::vector<std::string> cells = splitLine(line);
        if (columnIndex >= cells.size()) {
            throw std::runtime_error("Row is missing column " + std::to_string(columnIndex) + " : " + line);
        }
        try {
            values.push_back(std::stod(cells[columnIndex]));
        } catch (const std::invalid_argument& ){
            throw std::runtime_error("Invalid number in column " + std::to_string(columnIndex) + " : " + cells[columnIndex]);
        }
    }
    return Dataset(columnName, values);
}