//
// Created by NelosG.
//

#ifndef SOLVER_H
#define SOLVER_H

#include <profile_matrix.h>
#include <regular_matrix.h>
#include <sparse_matrix.h>

namespace Solver {
    std::pair<std::vector<double>, int> LU_solve(profile_matrix mt, const std::vector<double> &vec);

    std::pair<int, std::pair<std::vector<double>, int>> Gauss_solve(regular_matrix mt, std::vector<double> vec);

    std::pair<std::vector<double>, int> Conjugate_solve(const sparse_matrix &mt, const std::vector<double> &vec);

}// namespace Solver


#endif//SOLVER_H
