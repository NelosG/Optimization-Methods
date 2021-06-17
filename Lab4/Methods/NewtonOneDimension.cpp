//
// Created by NelosG.
//

#include "NewtonOneDimension.h"
#include <iostream>
point NewtonOneDimension::minimum(extended_function f, point x0, double eps) {
    iter = 0;
    point d, s, x(x0);
    do {
        //        std::cout << x.to_string() << '\n';
        iter++;
        d = slay(f.hessian(x), utils::multiply_vector_on_scalar(f.gradient(x), -1));
        double r = count_lambda(f, x, d);
        //        std::cout <<"Одномерное значение дало ответ " << r << '\n';
        s = utils::multiply_on_scalar(d, r);
        x.plus(s);
    } while (utils::norm(s) >= eps);
    return x;
}
