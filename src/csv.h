#pragma once
#include <string>
#include <vector>
#include "dataset.h"

std::vector<std::string> splitLine(const std::string& line);

Dataset loadColumn(const std::string& path, std::size_t columnIndex);