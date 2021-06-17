//
// Created by NelosG.
//

#ifndef UTILS_H
#define UTILS_H

#include <point.h>

class utils {
public:
    static std::vector<std::vector<double>> vectors_multiplication(const std::vector<double> &x,
                                                                   const std::vector<double> &y);

    static point multiply_matrix_and_Point(const std::vector<std::vector<double>> &m, const point &x);

    static std::vector<std::vector<double>> multiply_matrix_on_scalar(const std::vector<std::vector<double>> &m,
                                                                      double p);

    static std::vector<double> multiply_vector_on_scalar(const std::vector<double> &m,
                                                         double p);

    static std::vector<std::vector<double>> matrices_subtraction(const std::vector<std::vector<double>> &m1,
                                                                 const std::vector<std::vector<double>> &m2);

    static std::vector<std::vector<double>> matrices_multiplication(const std::vector<std::vector<double>> &m1,
                                                                    const std::vector<std::vector<double>> &m2);

    static std::vector<std::vector<double>> matrices_addition(const std::vector<std::vector<double>> &m1,
                                                              const std::vector<std::vector<double>> &m2);

    static point points_addition(const point &x, const point &y);

    static double points_multiplication(const point &x, const point &y);

    static point multiply_on_scalar(const point &x, double l);

    static point points_subtraction(const point &x, const point &y);

    static point negative(const point &x);

    static double norm(const point &x);

    static std::vector<std::vector<double>> create_E(size_t n);
};


#endif//UTILS_H
