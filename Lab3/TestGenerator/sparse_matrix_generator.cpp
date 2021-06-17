//
// Created by NelosG.
//

#include <ctime>
#include <random>

#include "matrix_generator.h"

std::pair<sparse_matrix, std::vector<double>> matrix_generator::generate_sparse(int n, int k) {
    std::vector<std::vector<double>> res(n, std::vector<double>(n, 0));
    std::string s = std::to_string(time(nullptr));
    std::seed_seq seed1(s.begin(), s.end());

    std::mt19937 random(seed1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                res[i][j] = -1. * (random() % matrix_generator::UPPER_BOUND);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        res[i][i] = -get_row_sum(res[i]);
        if (i == 0) {
            res[i][i] += 1;
        }
    }
    sparse_matrix sp(res);
    std::vector<double> vector(sp.size(), 0);
    for (int i = 0; i < sp.size(); ++i) {
        vector[i] = i + 1;
    }
    return {sp, sp.multiply_by_vector(vector)};
}

std::pair<sparse_matrix, std::vector<double>> matrix_generator::generate_Hilbert_sparse(int n, int k) {
    auto p = generate_Hilbert_regular(n, k);
    return {sparse_matrix(p.first), p.second};
}
