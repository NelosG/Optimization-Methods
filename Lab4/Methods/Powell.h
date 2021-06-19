//
// Created by NelosG.
//

#ifndef POWELL_H
#define POWELL_H

#include <extended_function.h>
#include <point.h>
#include <utils.h>
#include <QuasiNewton.h>


class Powell : public QuasiNewton {

public:
    ~Powell() override = default;

private:
    std::vector<std::vector<double>> get_next_H(const std::vector<std::vector<double>> &H,
                                                const point &dx_prev,
                                                const point &yPoint) override;
};


#endif//POWELL_H
