#include "dataset.h"
#include "statistics.h"

Dataset::Dataset(const std::string &name, const std::vector<double> &values)
    : name_(name), values_(values)
    { }

void Dataset::addValue(double value)
{
    values_.push_back(value);
}

std::size_t Dataset::size() const
{
    return values_.size();
}

const std::string &Dataset::name() const
{
    return name_;
}

double Dataset::mean() const
{
    return calculateMean(values_);
}

double Dataset::median() const
{
    return calculateMedian(values_);
}

double Dataset::min() const
{
    return calculateMin(values_);
}

double Dataset::max() const
{
    return calculateMax(values_);
}

double Dataset::range() const
{
    return calculateRange(values_);
}