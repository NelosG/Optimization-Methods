//
// Created by NelosG.
//

#include "runner.h"

#include <file_utils.h>
#include <logger.h>
#include <print_utils.h>
#include <solver.h>

std::pair<profile_matrix, std::vector<double>> runner::test_read_profile(const std::string &path) {
    auto str = file_utils::open_file(path, true);
    int n;

    str >> n;
    std::vector<double> diagonal;
    read_vec(n, str, diagonal);

    str >> n;
    std::vector<double> al;
    read_vec(n, str, al);

    str >> n;
    std::vector<double> au;
    read_vec(n, str, au);

    str >> n;
    std::vector<int> ai;
    read_vec(n, str, ai);

    str >> n;
    std::vector<double> vec;
    read_vec(n, str, vec);

    return {profile_matrix(diagonal, al, au, ai), vec};
}

void run_test_profile(const std::pair<profile_matrix, std::vector<double>> &p, int n, int k,
                      logger &lg) {
    auto lu = Solver::LU_solve(p.first, p.second);
    auto pair1 = runner::get_modules(lu.first);
    auto pair2 = runner::get_diff(lu.first);
    lg << n;
    if (k >= 0) {
        lg << k << pair1.first << pair1.second << pair2.first << pair2.second << lu.second;
    } else {
        lg << lu.second << pair1.first << pair1.second << pair2.first << pair2.second;
    }
    lg.next_line();
}

void runner::run_all_tests_profile(const std::string &path, const std::string &name,
                                   const std::vector<std::pair<int, std::vector<int>>> &NK, logger &lg) {
    std::string cur_path = path + "/" + name;
    for (auto &[n, vecK] : NK) {
        if (!vecK.empty()) {
            for (auto &k : vecK) {
                run_test_profile(test_read_profile(cur_path + std::to_string(n) + "_" + std::to_string(k) + ".txt"),
                                 n, k,
                                 lg);
            }
        } else {
            run_test_profile(test_read_profile(cur_path + std::to_string(n) + ".txt"),
                             n, -1,
                             lg);
        }
        lg.flush();
    }
}
