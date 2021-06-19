//
// Created by NelosG.
//

#ifndef BROADENFLETCHERCHEN_H
#define BROADENFLETCHERCHEN_H

#include <extended_function.h>
#include <point.h>
#include <utils.h>
#include <QuasiNewton.h>

class BroadenFletcherChen : public QuasiNewton {
public:

    ~BroadenFletcherChen() override = default;

private:
    std::vector<std::vector<double>> get_next_H(const std::vector<std::vector<double>> &H,
                                                const point &sPoint,
                                                const point &yPoint) override;
};


#endif//BROADENFLETCHERCHEN_H
