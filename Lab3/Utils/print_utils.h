//
// Created by NelosG.
//

#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H
#include <profile_matrix.h>
#include <regular_matrix.h>
#include <sparse_matrix.h>
#include <string>
#include <vector>
namespace print_utils {
    std::string print(const regular_matrix &mt, int precision);

    std::string print(const profile_matrix &mt, int precision);

    std::string print(const sparse_matrix &mt, int precision);

    std::string print(const std::vector<double> &vec, int precision, bool print_size);

    std::string print(const std::vector<int> &vec, int precision, bool print_size);

    std::string print(const std::vector<double> &vec, int precision);

    std::string print(const std::vector<int> &vec, int precision);

    std::string print(const std::vector<double> &vec);

    std::string print(const std::vector<int> &vec);

    std::string print(const regular_matrix &vec);

    std::string print(const profile_matrix &vec);

    std::string print(const sparse_matrix &vec);

    std::string print_diff(const std::vector<double> &solve);
}// namespace print_utils


#endif//PRINT_UTILS_H
