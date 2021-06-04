//
// Created by NelosG.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class matrix {
public:
    [[nodiscard]] virtual size_t size() const = 0;

    [[nodiscard]] virtual double get(int i, int j) const = 0;

    virtual void set(int i, int j, double element) = 0;

    [[nodiscard]] std::vector<double> multiply_by_vector(const std::vector<double> &vec) const {
        std::vector<double> answer(vec.size());
        for (int i = 0; i < size(); i++) {
            for (int j = 0; j < size(); j++) {
                answer[i] += vec[j] * get(i, j);
            }
        }
        return answer;
    }

    ~matrix() = default;
};

#endif//MATRIX_H
