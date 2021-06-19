//
// Created by NelosG.
//

#ifndef NEWTON_H
#define NEWTON_H

#include <extended_function.h>
#include <method.h>
#include <utils.h>

class Newton : public method {
public:
    point minimum(extended_function f, point x0, double eps) override;

    ~Newton() override = default;
};

#endif//NEWTON_H
