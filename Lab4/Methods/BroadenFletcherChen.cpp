//
// Created by NelosG.
//

#include <iostream>

#include "BroadenFletcherChen.h"

point BroadenFletcherChen::minimum(extended_function f, point x0, double eps) {
    point x(x0);
    point gradient(f.gradient(x));
    size_t n = gradient.get_coordinates().size();
    std::vector<std::vector<double>> H = utils::create_E(n);
    //    std::cout << x.to_string() << '\n';
    while (utils::norm(gradient) >= eps) {
        iter++;
        point p = utils::negative(utils::multiply_matrix_and_Point(H, gradient));
        double alpha = count_lambda(f, x, p);
        point d = utils::multiply_on_scalar(p, alpha);
        point nextX = utils::points_addition(x, d);

        point next_gradient(f.gradient(nextX));
        H = get_next_H(H, utils::points_subtraction(nextX, x), utils::points_subtraction(next_gradient, gradient));
        x = nextX;
        gradient = next_gradient;
        //        std::cout << x.to_string() << '\n';
    }
    return x;
}
std::vector<std::vector<double>> BroadenFletcherChen::get_next_H(const std::vector<std::vector<double>> &H,
                                                                 const point &sPoint,
                                                                 const point &yPoint) {
    std::vector<double> s = sPoint.get_coordinates();
    std::vector<double> y = yPoint.get_coordinates();
    size_t n = s.size();

    double del = 0;
    for (int i = 0; i < n; i++) {
        del += y[i] * s[i];
    }
    double p = 1 / del;

    std::vector<std::vector<double>> next_c =
            utils::matrices_subtraction(utils::create_E(n),
                                        utils::multiply_matrix_on_scalar(utils::vectors_multiplication(s, y), p));
    next_c = utils::matrices_multiplication(next_c, H);
    next_c = utils::matrices_multiplication(next_c,
                                            utils::matrices_subtraction(
                                                    utils::create_E(n), utils::multiply_matrix_on_scalar(
                                                                                utils::vectors_multiplication(y, s), p)));
    next_c = utils::matrices_addition(next_c, utils::multiply_matrix_on_scalar(utils::vectors_multiplication(s, s), p));
    return next_c;
}
