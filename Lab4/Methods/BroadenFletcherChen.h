//
// Created by NelosG.
//

#ifndef BROADENFLETCHERCHEN_H
#define BROADENFLETCHERCHEN_H
#include "../Utils/extended_function.h"
#include "../Utils/point.h"
#include "../Utils/utils.h"
#include "method.h"

class BroadenFletcherChen : public method {
public:
    point minimum(extended_function f, point x0, double eps) override;

    ~BroadenFletcherChen() override = default;

private:
    static std::vector<std::vector<double>> get_next_H(const std::vector<std::vector<double>> &H,
                                                       const point &sPoint,
                                                       const point &yPoint);
};


#endif//BROADENFLETCHERCHEN_H
