//
// Created by NelosG.
//

#include "Powell.h"

point Powell::minimum(extended_function f, point x0, double eps) {
    point x(x0);
    point w = utils::negative(point(f.gradient(x)));
    size_t n = w.get_coordinates().size();
    std::vector<std::vector<double>> H = utils::create_E(n);
    //    std::cout << x.to_string() << '\n';
    while (utils::norm(w) >= eps) {
        iter++;
        point p = utils::multiply_matrix_and_Point(H, w);
        double alpha = count_lambda(f, x, p);
        point d = utils::multiply_on_scalar(p, alpha);
        point next_x = utils::points_addition(x, d);

        point next_w = utils::negative(point(f.gradient(next_x)));
        H = get_next_H(H, utils::points_subtraction(next_x, x), utils::points_subtraction(next_w, w));
        x = next_x;
        w = next_w;
        //        std::cout << x.to_string() << '\n';
    }
    return x;
}
std::vector<std::vector<double>> Powell::get_next_H(const std::vector<std::vector<double>> &H, const point &sPoint, const point &yPoint) {
    std::vector<double> s = sPoint.get_coordinates();
    std::vector<double> y = yPoint.get_coordinates();
    size_t n = s.size();

    double del = 0;
    for (int i = 0; i < n; i++) {
        del += y[i] * s[i];
    }
    double p = 1 / del;
    return utils::matrices_subtraction(H, utils::multiply_matrix_on_scalar(utils::vectors_multiplication(s, s), p));
}
