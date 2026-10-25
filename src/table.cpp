#include "table.h"
#include "csv.h"
#include <fstream>
#include <stdexcept>

Table::Table(const std::string& path){
    std::ifstream file(path);
    if(!file.is_open()){
        throw std::runtime_error("Could not open file: " + path);
    }
    std::string line;
    if(!std::getline(file, line)){
        throw std::runtime_error("File is empty: " + path);
    }

    headers_ = splitLine(line);
    for(std::size_t i = 0; i < headers_.size(); ++i){
        indexByName_[headers_[i]] = i;
    }
    while(std::getline(file, line)){
        std::vector<std::string> cells = splitLine(line);
        if(cells.empty()){
            continue;
        }
        if(cells.size() != headers_.size()){
            throw std::runtime_error("Row has wrong number of cells: " + line);
        }
        rows_.push_back(cells);
    }
}
std::size_t Table::rowCount() const{
    return rows_.size();
}
std::size_t Table::columnCount() const{
    return headers_.size();
}
const std::vector<std::string>& Table::headers() const{
    return headers_;    
}
std::size_t Table::columnIndex(const std::string& column) const{
    auto it = indexByName_.find(column);
    if(it == indexByName_.end()){
        throw std::runtime_error("Column not found: " + column);
    }
    return it->second;
}
const std::string& Table::cell(std::size_t row, const std::string& column) const{
    if(row >= rows_.size()){
        throw std::runtime_error("Row index out of bounds: " + std::to_string(row));
    }
    std::size_t colIndex = columnIndex(column);
    return rows_[row][colIndex];
}
std::vector<std::string> Table::textColumn(const std::string& column) const{
    std::size_t colIndex = columnIndex(column);
    std::vector<std::string> result;
    for(const auto& row : rows_){
        result.push_back(row[colIndex]);
    }
    return result;
}
Dataset Table::numericColumn(const std::string& column) const{
    std::size_t colIndex = columnIndex(column);
    std::vector<double> values;
    for(const auto& row : rows_){
        const std::string& text = row[colIndex];
        try{
            std::size_t used = 0;
            double value = std::stod(text, &used);
            if(used != text.size()){
                throw std::invalid_argument("trailing characters");
            }
            values.push_back(std::stod(row[colIndex]));
        } catch(const std::invalid_argument&){
            throw std::runtime_error("Non-numeric value in column: " + column);
        }
    }
    return Dataset(column, values);
}