//
// Created by NelosG.
//

#ifndef PROFILE_MATRIX_H
#define PROFILE_MATRIX_H

#include <matrix.h>
#include <regular_matrix.h>

class profile_matrix : public matrix {
public:
    profile_matrix(std::vector<double> diagonal, std::vector<double> al,
                   std::vector<double> au, std::vector<int> ia);

    explicit profile_matrix(const matrix &mt);

    explicit profile_matrix(const std::vector<std::vector<double>> &mt)
        : profile_matrix(regular_matrix(mt)) {
    }

    [[nodiscard]] size_t size() const override {
        return diagonal.size();
    }

    [[nodiscard]] double get(int i, int j) const override;

    void set(int i, int j, double element) override;

    [[nodiscard]] std::vector<double> get_diagonal() const {
        return diagonal;
    }

    [[nodiscard]] std::vector<double> get_al() const {
        return al;
    }

    [[nodiscard]] std::vector<double> get_au() const {
        return au;
    }

    [[nodiscard]] std::vector<int> get_ia() const {
        return ia;
    }

    ~profile_matrix() = default;

private:
    [[nodiscard]] int profile_length(int i) const {
        return ia[i + 1] - ia[i];
    }

    [[nodiscard]] int index_in_triangle(int i, int j) const {
        return ia[i] - 1 + j - i + profile_length(i);
    }

    [[nodiscard]] double get_UOL_element(bool isLower, int i, int j) const;

    void set_UOL(int i, int j, double element, bool is_lower);

    std::vector<double> diagonal;
    std::vector<double> al;
    std::vector<double> au;
    std::vector<int> ia;
};

#endif//PROFILE_MATRIX_H
