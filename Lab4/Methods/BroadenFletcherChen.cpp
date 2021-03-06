//
// Created by NelosG.
//

#include "BroadenFletcherChen.h"

std::vector<std::vector<double>> BroadenFletcherChen::get_next_H(const std::vector<std::vector<double>> &H,
                                                                 const point &sPoint,
                                                                 const point &yPoint) {
    std::vector<double> s = sPoint.get_coordinates( );
    std::vector<double> y = yPoint.get_coordinates( );
    size_t n = s.size( );

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
