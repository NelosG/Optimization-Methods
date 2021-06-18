//
// Created by NelosG.
//

#include "NewtonOneDimension.h"

point NewtonOneDimension::minimum(extended_function f, point x0, double eps) {
    iter = 0;
    point d, s, x(x0);
    do {
        iter++;
        d = slay(f.hessian(x), utils::multiply_vector_on_scalar(f.gradient(x), -1));
        double r = count_alpha(f, x, d, eps);
        if(log) {
            *lg << "one dimension: a = " << r << '\n';
        }
        s = utils::multiply_on_scalar(d, r);
        x.add(s);
    } while (utils::norm(s) >= eps);
    return x;
}
