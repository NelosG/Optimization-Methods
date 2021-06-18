//
// Created by NelosG.
//

#ifndef QUASINEWTON_H
#define QUASINEWTON_H

#include <method.h>

class QuasiNewton : public method {
public:
    point minimum(extended_function f, point x0, double eps) override;

protected:
    virtual std::vector<std::vector<double>> get_next_H(const std::vector<std::vector<double>> &H,
                                                       const point &dx_prev,
                                                       const point &yPoint) = 0;
};


#endif //QUASINEWTON_H
