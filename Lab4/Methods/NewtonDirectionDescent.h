//
// Created by NelosG.
//

#ifndef NEWTONDIRECTIONDESCENT_H
#define NEWTONDIRECTIONDESCENT_H
#include "../Utils/extended_function.h"
#include "../Utils/point.h"
#include "../Utils/utils.h"
#include "method.h"

class NewtonDirectionDescent : public method {
public:
    point minimum(extended_function f, point x0, double eps) override;
    ~NewtonDirectionDescent() override = default;
};


#endif//NEWTONDIRECTIONDESCENT_H
