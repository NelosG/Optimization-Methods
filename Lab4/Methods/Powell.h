//
// Created by NelosG.
//

#ifndef POWELL_H
#define POWELL_H
#include "../Utils/extended_function.h"
#include "../Utils/point.h"
#include "../Utils/utils.h"
#include "method.h"


class Powell : public method {

public:
    point minimum(extended_function f, point x0, double eps) override;
    ~Powell() override = default;

private:
    static std::vector<std::vector<double>> get_next_H(const std::vector<std::vector<double>> &H,
                                                       const point &sPoint,
                                                       const point &yPoint);
};


#endif//POWELL_H
