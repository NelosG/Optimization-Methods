//
// Created by NelosG.
//

#include "Newton.h"

point Newton::minimum(extended_function f, point x0, double eps) {
    iter = 1;
    point x(x0);
    point p = slay(f.hessian(x), utils::multiply_vector_on_scalar(f.gradient(x), -1));
    while (utils::norm(p) >= eps) {
        iter++;
        x.add(p);
        p = slay(f.hessian(x), utils::multiply_vector_on_scalar(f.gradient(x), -1));
    }
    return x;
}
