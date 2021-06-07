//
// Created by NelosG.
//

#include <solver.h>
constexpr const static double eps = 1E-35;
double Max = 1.7976931348623157e+308;

std::pair<int, std::pair<std::vector<double>, int>> Solver::Gauss_solve(regular_matrix mt, std::vector<double> vec) {
    size_t n = mt.size();
    std::vector<double> x(n,0);
    int total_iter = 0;
    for (int k = 0; k < n - 1; k++) {
        double maxCoefficient = -Max;
        int maxCoefficientInd = k;
        for (int i = k; i < n; i++) {
            double element = mt.get(i, k);
            if (abs(element) - abs(maxCoefficient) > eps) {
                maxCoefficient = element;
                maxCoefficientInd = i;
            }
        }
        mt.swap_rows(k, maxCoefficientInd);
        double tmp = vec[k];
        vec[k] = vec[maxCoefficientInd];
        vec[maxCoefficientInd] = tmp;
        double kk = mt.get(k, k);
        if (abs(kk) < eps) {
            return {2, {x, total_iter}};
        }
        for (int i = k + 1; i < n; i++) {
            double ik = mt.get(i, k);
            for (int j = k; j < n; j++) {
                mt.set(i, j, mt.get(i, j) - ik * mt.get(k, j) / kk);
                ++total_iter;
            }
            vec[i] -= ik * vec[k] / kk;
        }
    }
    for (int k = (int)n - 1; k >= 0; k--) {
        double sum = vec[k];
        for (int j = k + 1; j < n; j++) {
            sum -= mt.get(k, j) * x[j];
        }
        x[k] = sum / mt.get(k, k);
    }
    return {1, {x, total_iter}};
}
