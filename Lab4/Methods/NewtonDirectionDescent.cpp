//
// Created by NelosG.
//

#include "NewtonDirectionDescent.h"

point NewtonDirectionDescent::minimum(extended_function f, point x0, double eps) {
    iter = 1;
    point x(x0);
    //    std::cout << x.to_string() << '\n';
    point d(utils::multiply_vector_on_scalar(f.gradient(x), -1));
    double r = count_lambda(f, x, d);
    point s = utils::multiply_on_scalar(d, r);
    x.plus(s);
    //    std::cout << x.to_string() << '\n';
    do {
        iter++;
        point g(f.gradient(x));
        s = slay(f.hessian(x), utils::multiply_vector_on_scalar(
                                       point(g.get_coordinates()).get_coordinates(), -1));
        if (utils::points_multiplication(s, g) < 0) {
            d = s;
        } else {
            d = utils::negative(g);
        }
        r = count_lambda(f, x, d);
        s = utils::multiply_on_scalar(d, r);
        x.plus(s);
        //        std::cout << x.to_string() << '\n';
    } while (utils::norm(s) >= eps);
    return x;
}
