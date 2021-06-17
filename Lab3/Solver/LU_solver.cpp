//
// Created by NelosG.
//

#include "solver.h"

double count_LU(int i, int j, int ind, double start, const profile_matrix &matrix) {
    double sum = start;
    for (int k = 0; k < ind; k++) {
        sum -= matrix.get(i, k) * matrix.get(k, j);
    }
    return sum;
}

std::pair<std::vector<double>, int> Solver::LU_solve(profile_matrix mt, const std::vector<double> &vec) {
    size_t n = mt.size();
    int iter = 0;
    mt.set(0, 0, mt.get(0, 0));
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            double lij = count_LU(i, j, j, mt.get(i, j), mt);
            mt.set(i, j, lij);
            ++iter;
        }
        for (int j = 0; j < i; j++) {
            double uji = (count_LU(j, i, j, mt.get(j, i), mt)) / mt.get(j, j);
            mt.set(j, i, uji);
            ++iter;
        }
        double lii = count_LU(i, i, i, mt.get(i, i), mt);
        mt.set(i, i, lii);
    }
    std::vector<double> y(n, 0);
    for (int i = 0; i < n; i++) {
        double sum = vec[i];
        for (int j = 0; j < i; j++) {
            sum -= y[j] * mt.get(i, j);
        }
        y[i] = sum / mt.get(i, i);
    }
    std::vector<double> x(n, 0);
    for (int i = (int) n - 1; i >= 0; i--) {
        double sum = y[i];
        for (int j = i + 1; j < n; j++) {
            sum -= mt.get(i, j) * x[j];
        }
        x[i] = sum;
    }
    return {x, iter};
}
