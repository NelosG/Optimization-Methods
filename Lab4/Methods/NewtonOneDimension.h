//
// Created by NelosG.
//

#ifndef NEWTONONEDIMENSION_H
#define NEWTONONEDIMENSION_H

#include <extended_function.h>
#include <method.h>
#include <point.h>
#include <utils.h>

class NewtonOneDimension : public method {
public:
    point minimum(extended_function f, point x0, double eps) override;
    ~NewtonOneDimension() override = default;
};


#endif//NEWTONONEDIMENSION_H
