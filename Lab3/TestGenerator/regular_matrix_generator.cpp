//
// Created by NelosG.
//

#include <ctime>
#include <matrix_generator.h>
#include <random>
#include <string>

std::vector<std::vector<double>> generate_matrix(int n, int k) {
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
        for (int j = 0; j < n; j++) {
            if (res[i][j] == 0) {
                res[j][i] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        res[i][i] = -matrix_generator::get_row_sum(res[i]);
        if (i == 0) {
            res[i][i] += pow(10.0, -k);
        }
    }
    return res;
}


std::pair<regular_matrix, std::vector<double>> matrix_generator::generate_regular(int n, int k) {
    regular_matrix matrix(generate_matrix(n, k));
    std::vector<double> vector(matrix.size(), 0);
    for (int i = 0; i < matrix.size(); ++i) {
        vector[i] = i + 1;
    }
    return {matrix, multiply_by_vector(matrix, vector)};
}

std::pair<regular_matrix, std::vector<double>> matrix_generator::generate_Hilbert_regular(int n, int k) {
    std::vector<std::vector<double>> data(n, std::vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            data[i][j] = 1. / (i + j + 1);
        }
    }
    regular_matrix matrix(data);
    std::vector<double> vector(matrix.size(), 0);
    for (int i = 0; i < matrix.size(); ++i) {
        vector[i] = i + 1;
    }
    return {matrix, multiply_by_vector(matrix, vector)};
}
