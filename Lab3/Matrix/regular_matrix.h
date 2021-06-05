//
// Created by NelosG.
//

#ifndef REGULAR_MATRIX_H
#define REGULAR_MATRIX_H

#include <matrix.h>


class regular_matrix : public matrix {
private:
    std::vector<std::vector<double>> mt;

public:
    explicit regular_matrix(std::vector<std::vector<double>> mt) : mt(std::move(mt)) {
    }

    explicit regular_matrix(const matrix &mat) {
        mt.assign(mat.size(), std::vector<double>(mat.size(), 0));
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat.size(); ++j) {
                mt[i][j] = mat.get(i, j);
            }
        }
    }

    [[nodiscard]] size_t size() const override {
        return mt.size();
    }

    [[nodiscard]] double get(int i, int j) const override {
        return mt[i][j];
    }

    [[nodiscard]] std::vector<double> get(int i) const {
        return mt[i];
    }

    void set(int i, int j, double element) override {
        mt[i][j] = element;
    }

    void swap_rows(int row1, int row2) {
        std::swap(mt[row1], mt[row2]);
    }

    ~regular_matrix() = default;
};

#endif//REGULAR_MATRIX_H
