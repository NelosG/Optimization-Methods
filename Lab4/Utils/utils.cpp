//
// Created by NelosG.
//

#include "utils.h"
point utils::multiply_on_scalar(const point &x, double l) {
    size_t n = x.get_coordinates().size();
    std::vector<double> c(n, 0);
    for (int i = 0; i < n; i++) {
        c[i] = x.get_coordinates()[i] * l;
    }
    return point(c);
}
point utils::points_subtraction(const point &x, const point &y) {
    size_t n = x.get_coordinates().size();
    std::vector<double> c(n, 0);
    for (int i = 0; i < n; i++) {
        c[i] = x.get_coordinates()[i] - y.get_coordinates()[i];
    }
    return point(c);
}
point utils::multiply_matrix_and_Point(const std::vector<std::vector<double>> &m, const point &x) {
    size_t n = m.size();
    std::vector<double> c(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i] += m[i][j] * x.get_coordinates()[j];
        }
    }
    return point(c);
}
std::vector<std::vector<double>> utils::vectors_multiplication(const std::vector<double> &x,
                                                               const std::vector<double> &y) {
    size_t n = x.size();
    std::vector<std::vector<double>> m(n, std::vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = x[i] * y[j];
        }
    }
    return m;
}
std::vector<std::vector<double>> utils::multiply_matrix_on_scalar(const std::vector<std::vector<double>> &m,
                                                                  double p) {
    size_t n = m.size();
    std::vector<std::vector<double>> m1(n, std::vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m1[i][j] = m[i][j] * p;
        }
    }
    return m1;
}
std::vector<std::vector<double>> utils::matrices_subtraction(const std::vector<std::vector<double>> &m1,
                                                             const std::vector<std::vector<double>> &m2) {
    size_t n = m1.size();
    std::vector<std::vector<double>> m(n, std::vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return m;
}
std::vector<std::vector<double>> utils::matrices_multiplication(const std::vector<std::vector<double>> &m1,
                                                                const std::vector<std::vector<double>> &m2) {
    size_t n = m1.size();
    std::vector<std::vector<double>> m(n, std::vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                m[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return m;
}
std::vector<std::vector<double>> utils::matrices_addition(const std::vector<std::vector<double>> &m1,
                                                          const std::vector<std::vector<double>> &m2) {
    size_t n = m1.size();
    std::vector<std::vector<double>> m(n, std::vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return m;
}
point utils::points_addition(const point &x, const point &y) {
    size_t n = x.get_coordinates().size();
    std::vector<double> c(n, 0);
    for (int i = 0; i < n; i++) {
        c[i] = x.get_coordinates()[i] + y.get_coordinates()[i];
    }
    return point(c);
}
point utils::negative(const point &x) {
    std::vector<double> new_coord = x.get_coordinates();
    for (auto &i : new_coord) {
        i *= -1;
    }
    return point(new_coord);
}
std::vector<double> utils::multiply_vector_on_scalar(const std::vector<double> &m, double p) {
    size_t n = m.size();
    std::vector<double> m1(n, 0);
    for (int i = 0; i < n; i++) {
        m1[i] = m[i] * p;
    }
    return m1;
}
double utils::points_multiplication(const point &x, const point &y) {
    double sum = 0;
    for (int i = 0; i < x.get_coordinates().size(); i++) {
        sum += x.get(i) * y.get(i);
    }
    return sum;
}
double utils::norm(const point &x) {
    double res = 0;
    for (double c : x.get_coordinates()) {
        res += c * c;
    }
    return sqrt(res);
}
std::vector<std::vector<double>> utils::create_E(size_t n) {
    std::vector<std::vector<double>> H(n, std::vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        H[i][i] = 1;
    }
    return H;
}
