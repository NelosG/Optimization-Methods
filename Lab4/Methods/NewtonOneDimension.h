//
// Created by NelosG.
//

#ifndef NEWTONONEDIMENSION_H
#define NEWTONONEDIMENSION_H
#include "../Utils/extended_function.h"
#include "../Utils/point.h"
#include "../Utils/utils.h"
#include "method.h"

class NewtonOneDimension : public method {
public:
    point minimum(extended_function f, point x0, double eps) override;
    ~NewtonOneDimension() override = default;
};


#endif//NEWTONONEDIMENSION_H
