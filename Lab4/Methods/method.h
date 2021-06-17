//
// Created by NelosG.
//

#ifndef METHOD_H
#define METHOD_H

#include <vector>

#include <extended_function.h>
#include <point.h>
#include <utils.h>

class method {

protected:
    int iter = 0;

public:
    virtual point minimum(extended_function f, point x0, double eps) = 0;

    [[nodiscard]] int count_of_iterations() const {
        return iter;
    }

    static point slay(std::vector<std::vector<double>> h, std::vector<double> f);

    static double count_lambda(extended_function function, point x, point d);

    virtual ~method() = default;
};
#endif//METHOD_H
