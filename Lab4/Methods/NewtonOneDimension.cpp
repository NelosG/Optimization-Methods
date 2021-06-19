//
// Created by NelosG.
//

#include "NewtonOneDimension.h"

point NewtonOneDimension::minimum(extended_function f, point x0, double eps) {
    iter = 1;
    point x(x0);
    point d(utils::negative(point(f.gradient(x))));
    double r = count_alpha(f, x, d, eps);
    point s = utils::multiply_on_scalar(d, r);
    x.add(s);
    do {
        iter++;
        point g(f.gradient(x));
        d = slay(f.hessian(x), utils::negative(g).get_coordinates( ));
        r = count_alpha(f, x, d, eps);
        s = utils::multiply_on_scalar(d, r);
        x.add(s);
    } while (utils::norm(s) >= eps);
    return x;
}
