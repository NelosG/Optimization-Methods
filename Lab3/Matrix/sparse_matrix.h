//
// Created by NelosG.
//

#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <matrix.h>
#include <regular_matrix.h>

class sparse_matrix : public matrix {
    std::vector<double> diagonal;
    std::vector<double> al;
    std::vector<double> au;
    std::vector<int> ia;
    std::vector<int> ja;

public:
    sparse_matrix(std::vector<double> di, std::vector<double> al, std::vector<double> au,
                  std::vector<int> ia, std::vector<int> ja);

    explicit sparse_matrix(const matrix &mt);

    explicit sparse_matrix(const std::vector<std::vector<double>>& mt) : sparse_matrix(regular_matrix(mt)){}

    [[nodiscard]] double get(int a, int b) const override;


    [[nodiscard]] size_t size() const override {
        return diagonal.size();
    }

    void set(int a, int b, double value) override {

    }

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

    [[nodiscard]] std::vector<int> get_ja() const {
        return ja;
    }

    std::vector<double> smartMultiplication(std::vector<double> &vector) const;

    ~sparse_matrix() = default;

private:
    static int getRowProfileLen(const matrix &mt, int row, std::vector<double> &alList,
                         std::vector<double> &auList, std::vector<int> &jaList);
};


#endif//SPARSE_MATRIX_H
