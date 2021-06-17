//
// Created by NelosG.
//

#ifndef NEWTON_H
#define NEWTON_H
#include "../Utils/extended_function.h"
#include "../Utils/utils.h"
#include "method.h"

class Newton : public method {
    int iter = 0;

public:
    point minimum(extended_function f, point x0, double eps) override;

    ~Newton() override = default;
};
#endif//NEWTON_H
