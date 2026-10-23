#pragma once
#include <map>
#include <string>
#include <vector>
#include "dataset.h"

class Table {
public:
    explicit Table(const std::string& path);
    std::size_t rowCount() const;
    std::size_t columnCount() const;
    const std::vector<std::string>& headers() const;

    const std::string& cell(std::size_t row, const std::string& column) const;
    std::vector<std::string> textColumn(const std::string& column) const;
    Dataset numericColumn(const std::string& column) const;

private:
    std::size_t columnIndex(const std::string& column) const;

    std::vector<std::string> headers_;
    std::vector<std::vector<std::string>> rows_;
    std::map<std::string, std::size_t> indexByName_;
};