#include "statistics.h"
#include <algorithm>
#include <stdexcept>
#include <cmath>

namespace{
double sumSquaredDiff(const std::vector<double>& values){
    double mean = calculateMean(values);
    double total = 0.0;
    for(double value : values){
        total += (value-mean) * (value-mean);
    }
    return total;
}
}
double calculateMean(const std::vector<double>& values){
        if (values.empty()){
            throw std::invalid_argument("The vector is empty. Cannot calculate mean."); // checks the vector if its empty and throws an error if true. DO NOT put try-catch in function, do in main
        }
        double sum = 0.0;
        for (double value : values){
            sum += value;
        }
        return sum / values.size();
    }

double calculateMedian(const std::vector<double>& values){
        double median = 0.0;
        if (values.empty()){
            throw std::invalid_argument("The vector is empty. Cannot calculate median.");
        }
        std::vector<double> sorted_data = values;
        std::size_t sorted_size = sorted_data.size();
        std::sort(sorted_data.begin(), sorted_data.end());
        if (sorted_size % 2 == 0){
            median = (sorted_data[sorted_size / 2 - 1] + sorted_data[sorted_size / 2]) / 2.0;
        } else {
            median = sorted_data[sorted_size / 2];
        }
        return median;
    }

double calculateMin(const std::vector<double>& values){
        if (values.empty()){
            throw std::invalid_argument("The vector is empty. Cannot calculate minimum.");
        }
        double min_data = values[0];
        for (double element : values){
            if (element < min_data){
                min_data = element;
            }
        }
        return min_data;
    }

double calculateMax(const std::vector<double>& values){
        if (values.empty()){
            throw std::invalid_argument("The vector is empty. Cannot calculate maximum.");
        }
        double max_data = values[0];
        for (double element : values){
            if (element > max_data){
                max_data = element;
            }
        }
        return max_data;
    }

double calculateRange(const std::vector<double>& values){
        if (values.empty()){
            throw std::invalid_argument("The vector is empty. Cannot calculate range.");
        }
        double min_data = calculateMin(values);
        double max_data = calculateMax(values);
        return max_data - min_data;
    }

double calculatePopulationVariance(const std::vector<double>& values){
        if (values.empty()){
            throw std::invalid_argument("The vector is empty. Cannot calculate population variance.");
        }
        return sumSquaredDiff(values) / values.size();
    }

double calculateSampleVariance(const std::vector<double>& values){
        if (values.size() < 2){
            throw std::invalid_argument("The vector must contain at least two elements to calculate sample variance.");
        }
        return sumSquaredDiff(values) / (values.size() - 1);
    }

double calculatePopulationStdDev(const std::vector<double>& values){
        return std::sqrt(calculatePopulationVariance(values));
    }

double calculateSampleStdDev(const std::vector<double>& values){
        return std::sqrt(calculateSampleVariance(values));
    }