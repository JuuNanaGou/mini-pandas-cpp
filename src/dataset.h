#pragma once
#include <string>
#include <vector>

class Dataset
{
public:
    Dataset(const std::string &name, const std::vector<double> &values);
    void addValue(double value);
    std::size_t size() const;
    const std::string &name() const;
    double mean() const;
    double median() const;
    double min() const;
    double max() const;
    double range() const;
private:
    std::string name_;
    std::vector<double> values_;
};