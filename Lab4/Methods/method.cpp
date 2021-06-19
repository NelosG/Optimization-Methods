//
// Created by NelosG.
//

#include <cmath>

#include "method.h"
#include <GoldenSection.h>

double Max = 1.7976931348623157e+308;

point method::slay(std::vector<std::vector<double>> mt, std::vector<double> vec) {
    size_t n = mt.size( );
    std::vector<double> x(n, 0);
    int total_iter = 0;
    for (int k = 0; k < n - 1; k++) {
        double maxCoefficient = -Max;
        int maxCoefficientInd = k;
        for (int i = k; i < n; i++) {
            double element = mt[i][k];
            if (std::abs(element) - std::abs(maxCoefficient) > 0) {
                maxCoefficient = element;
                maxCoefficientInd = i;
            }
        }
        std::swap(mt[k], mt[maxCoefficientInd]);
        double tmp = vec[k];
        vec[k] = vec[maxCoefficientInd];
        vec[maxCoefficientInd] = tmp;
        double kk = mt[k][k];
        for (int i = k + 1; i < n; i++) {
            double ik = mt[i][k];
            for (int j = k; j < n; j++) {
                mt[i][j] = mt[i][j] - ik * mt[k][j] / kk;
                ++total_iter;
            }
            vec[i] -= ik * vec[k] / kk;
        }
    }
    for (int k = (int) n - 1; k >= 0; k--) {
        double sum = vec[k];
        for (int j = k + 1; j < n; j++) {
            sum -= mt[k][j] * x[j];
        }
        x[k] = sum / mt[k][k];
    }
    return point(x);
}

double method::count_alpha(extended_function function, point x, point d, double eps) {
    auto uniFunction = [&function, &x, &d](double alpha) {
        return function.value(utils::points_addition(x, utils::multiply_on_scalar(d, alpha)));
    };
    double lo = -10, hi = 200;
    double alpha = hi / 10000;
    while (alpha < hi) {
        double minimum = GoldenSection::optimize(lo, alpha, 1e-9, uniFunction);
        if (alpha - minimum <= eps) {
            alpha *= 2;
        } else {
            return minimum;
        }
    }
    return alpha;
}
