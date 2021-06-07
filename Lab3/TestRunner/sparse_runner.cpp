//
// Created by NelosG.
//
#include <file_utils.h>
#include <matrix_generator.h>
#include <runner.h>
#include <solver.h>

std::pair<sparse_matrix, std::vector<double>> runner::test_read_sparse(const std::string &path) {
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
    std::vector<int> ia;
    read_vec(n, str, ia);

    str >> n;
    std::vector<int> ja;
    read_vec(n, str, ja);

    str >> n;
    std::vector<double> vec;
    read_vec(n, str, vec);

    return {sparse_matrix(diagonal, al, au, ia, ja), vec};
}

void run_test_sparse(const std::pair<sparse_matrix, std::vector<double>> &p, int n, int k,
                     logger &lg) {
    auto conjugate = Solver::Conjugate_solve(p.first, p.second);
    auto pair1 = runner::get_modules(conjugate.first);
    auto pair2 = runner::get_diff(conjugate.first);
    lg << n;
    if (k >= 0) {
        lg << k;
    }
    lg << conjugate.second;
    std::vector<double> fminAx = p.second;
    std::vector<double> Ax = p.first.multiply_by_vector(conjugate.first);
    for (int i = 0; i < Ax.size(); ++i) {
        fminAx[i] -= Ax[i];
    }
    lg << pair1.first << pair1.second << (pair1.second / (runner::length(fminAx) / runner::length(p.second)));
    lg << pair2.first << pair2.second;
    lg.next_line();
}

void runner::run_all_tests_sparse(const std::string &path, const std::string &name,
                                  const std::vector<std::pair<int, std::vector<int>>> &NK, logger &lg) {
    std::string cur_path = path + "/" + name;
    for (auto &[n, vecK] : NK) {
        if (!vecK.empty()) {
            for (auto &k : vecK) {
                run_test_sparse(test_read_sparse(cur_path + std::to_string(n) + "_" + std::to_string(k) + ".txt"),
                                n, k,
                                lg);
            }
        } else {
            run_test_sparse(test_read_sparse(cur_path + std::to_string(n) + ".txt"),
                            n, -1,
                            lg);
        }
        lg.flush();
    }
}
