//
// Created by NelosG.
//

#ifndef MATRIX_GENERATOR_H
#define MATRIX_GENERATOR_H
#include <functional>
#include <matrix.h>
#include <print_utils.h>
#include <profile_matrix.h>
#include <regular_matrix.h>
#include <sparse_matrix.h>
#include <vector>


namespace matrix_generator {
    const int UPPER_BOUND = 5;

    std::pair<regular_matrix, std::vector<double>> generate_regular(int n, int k);
    std::pair<profile_matrix, std::vector<double>> generate_profile(int n, int k);
    std::pair<sparse_matrix, std::vector<double>> generate_sparse(int n, int k);
    std::pair<regular_matrix, std::vector<double>> generate_Hilbert_regular(int n, int k);
    std::pair<profile_matrix, std::vector<double>> generate_Hilbert_profile(int n, int k);
    std::pair<sparse_matrix, std::vector<double>> generate_Hilbert_sparse(int n, int k);


    double get_row_sum(const std::vector<double> &row);
}// namespace matrix_generator

namespace test_generator {

    void generate_tests(const std::string &path, const std::string &name,
                        const std::vector<std::pair<int, std::vector<int>>> &NK,
                        const std::function<void(const std::string &, const std::string &, int, int)> &test_creation);

    void test_creation_regular(const std::string &path, const std::string &name, int n, int k);
    void test_creation_profile(const std::string &path, const std::string &name, int n, int k);
    void test_creation_sparse(const std::string &path, const std::string &name, int n, int k);
    void test_creation_Hilbert_regular(const std::string &path, const std::string &name, int n, int k);
    void test_creation_Hilbert_profile(const std::string &path, const std::string &name, int n, int k);
    void test_creation_Hilbert_sparse(const std::string &path, const std::string &name, int n, int k);
}// namespace test_generator

#endif//MATRIX_GENERATOR_H
