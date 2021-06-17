//
// Created by NelosG.
//

#ifndef EXTENDED_FUNCTION_H
#define EXTENDED_FUNCTION_H
#include "point.h"
#include <functional>

class extended_function {
    std::function<double(point)> f;
    std::function<std::vector<double>(point)> gradientF;
    std::function<std::vector<std::vector<double>>(point)> hessianF;

public:
    extended_function(const std::function<double(point)> &f,
                      const std::function<std::vector<double>(point)> &gradientF,
                      const std::function<std::vector<std::vector<double>>(point)> &hessianF) {
        this->f = f;
        this->gradientF = gradientF;
        this->hessianF = hessianF;
    }

    double value(const point &x) {
        return f(x);
    }

    std::vector<double> gradient(const point &x) {
        return gradientF(x);
    }

    std::vector<std::vector<double>> hessian(const point &x) {
        return hessianF(x);
    }
};


#endif//EXTENDED_FUNCTION_H
