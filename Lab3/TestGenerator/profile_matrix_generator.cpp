//
// Created by NelosG.
//
#include <matrix_generator.h>

std::pair<profile_matrix, std::vector<double>> matrix_generator::generate_profile(int n, int k) {
    auto p = generate_regular(n, k);
    return {profile_matrix(p.first), p.second};
}

std::pair<profile_matrix, std::vector<double>> matrix_generator::generate_Hilbert_profile(int n, int k) {
    auto p = generate_Hilbert_regular(n, k);
    return {profile_matrix(p.first), p.second};
}
