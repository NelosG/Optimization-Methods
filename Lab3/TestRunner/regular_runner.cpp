//
// Created by NelosG.
//
#include <file_utils.h>
#include <print_utils.h>
#include <runner.h>
#include <solver.h>

std::pair<regular_matrix, std::vector<double>> runner::test_read_regular(const std::string &path) {
    auto str = file_utils::open_file(path, true);
    int n;
    str >> n;
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n, 0));
    std::vector<double> vec(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            str >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        str >> vec[i];
    }
    return {regular_matrix(matrix), vec};
}

void run_test_regular(const std::pair<regular_matrix, std::vector<double>> &p, int n, int k,
                      logger &lg) {
    lg << n;
    if (k >= 0) {
        lg << k;
    }
    auto gaus = Solver::Gauss_solve(p.first, p.second);
    if (gaus.first == 1) {
        auto pair1 = runner::get_modules(gaus.second.first);
        auto pair2 = runner::get_diff(gaus.second.first);
        lg << pair1.first << pair1.second << pair2.first << pair2.second << gaus.second.second;
    } else {
        lg << "no or many solutions";
        lg << "no or many solutions";
        lg << "no or many solutions";
        lg << "no or many solutions";
        lg << "no or many solutions";
    }
    lg.next_line();
}

void runner::run_all_tests_regular(const std::string &path, const std::string &name,
                                   const std::vector<std::pair<int, std::vector<int>>> &NK, logger &lg) {
    std::string cur_path = path + "/" + name;
    for (auto &[n, vecK] : NK) {
        if (!vecK.empty()) {
            for (auto &k : vecK) {
                run_test_regular(test_read_regular(cur_path + std::to_string(n) + "_" + std::to_string(k) + ".txt"),
                                 n, k,
                                 lg);
            }
        } else {
            run_test_regular(test_read_regular(cur_path + std::to_string(n) + ".txt"),
                             n, -1,
                             lg);
        }
    }
}