//
// Created by NelosG.
//

#ifndef REGULAR_RUNNER_H
#define REGULAR_RUNNER_H

#include <string>

#include <logger.h>
#include <profile_matrix.h>
#include <regular_matrix.h>
#include <sparse_matrix.h>

namespace runner {
    std::pair<regular_matrix, std::vector<double>> test_read_regular(const std::string &path);

    std::pair<profile_matrix, std::vector<double>> test_read_profile(const std::string &path);

    std::pair<sparse_matrix, std::vector<double>> test_read_sparse(const std::string &path);

    void run_all_tests_regular(const std::string &path, const std::string &name, const std::vector<std::pair<int, std::vector<int>>> &NK, logger &lg);

    void run_all_tests_profile(const std::string &path, const std::string &name, const std::vector<std::pair<int, std::vector<int>>> &NK, logger &lg);

    void run_all_tests_sparse(const std::string &path, const std::string &name, const std::vector<std::pair<int, std::vector<int>>> &NK, logger &lg);

    std::pair<double, double> get_diff(const std::vector<double> &solve);

    std::pair<double, double> get_modules(const std::vector<double> &solve);

    double length(const std::vector<double> &vec);

    void read_vec(int n, std::fstream &str, std::vector<int> &res);
    void read_vec(int n, std::fstream &str, std::vector<double> &res);

}// namespace runner
#endif//REGULAR_RUNNER_H
