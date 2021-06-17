//
// Created by NelosG.
//

#include "Newton.h"
#include <iostream>
point Newton::minimum(extended_function f, point x0, double eps) {
    iter = 1;
    //    std::cout << x0.to_string() << '\n';
    point x(x0);
    point p = slay(f.hessian(x), utils::multiply_vector_on_scalar(f.gradient(x), -1));
    while (utils::norm(p) >= eps) {
        iter++;
        x.plus(p);
        p = slay(f.hessian(x), utils::multiply_vector_on_scalar(f.gradient(x), -1));
        //        std::cout << x.to_string() << '\n';
    }
    return x;
}
