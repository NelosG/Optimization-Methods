//
// Created by NelosG.
//

#include "Powell.h"

double scalarProduct(const point& p1, const point& p2) {
    double result = 0;
    for (int i = 0; i < p1.get_coordinates().size(); i++) {
        result += p1.get_coordinates()[i] * p2.get_coordinates()[i];
    }
    return result;
}

std::vector<std::vector<double>> Powell::get_next_H(const std::vector<std::vector<double>>& prevG, const point& dx_prev, const point& dw) {
    point dy = utils::points_addition(dx_prev, utils::multiply_matrix_and_Point(prevG, dw));
    return utils::matrices_subtraction(prevG, utils::multiply_matrix_on_scalar(
            utils::vectors_multiplication(dy.get_coordinates(), dy.get_coordinates()), 1.0 / scalarProduct(dw, dy)));

}
