//
// Created by NelosG.
//

#include "QuasiNewton.h"

point QuasiNewton::minimum(extended_function f, point x0, double eps) {
    point x(x0);
    point w = utils::negative(point(f.gradient(x)));
    size_t n = w.get_coordinates().size();
    std::vector<std::vector<double>> G = utils::create_E(n);
    point dx = utils::multiply_on_scalar(w, count_alpha(f, x, w, eps));
    x.add(dx);
    while (utils::norm(dx) >= eps) {
        iter++;
        point prevW(w);
        w = utils::negative(point(f.gradient(x)));
        point dw = utils::points_subtraction(w, prevW);
        G = get_next_H(G, dx, dw);
        point p = utils::multiply_matrix_and_Point(G, w);
        double alpha = count_alpha(f, x, p, eps);
        dx = utils::multiply_on_scalar(p, alpha);
        x.add(dx);
    }
    return x;
}
