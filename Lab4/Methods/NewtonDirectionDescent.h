//
// Created by NelosG.
//

#ifndef NEWTONDIRECTIONDESCENT_H
#define NEWTONDIRECTIONDESCENT_H

#include <extended_function.h>
#include <method.h>
#include <point.h>
#include <utils.h>

class NewtonDirectionDescent : public method {
public:
    point minimum(extended_function f, point x0, double eps) override;
    ~NewtonDirectionDescent() override = default;
};


#endif//NEWTONDIRECTIONDESCENT_H
