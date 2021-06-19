//
// Created by NelosG.
//

#include "Newton.h"

point Newton::minimum(extended_function f, point x0, double eps) {
    iter = 1;
    point x(x0);
    point s(utils::negative(point(f.gradient(x))));
    x.add(s);
    do {
        iter++;
        point g(f.gradient(x));
        s = slay(f.hessian(x), utils::negative(g).get_coordinates( ));
        x.add(s);
    } while (utils::norm(s) >= eps);
    return x;
}
