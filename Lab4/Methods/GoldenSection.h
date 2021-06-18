//
// Created by NelosG.
//

#ifndef GOLDENSECTION_H
#define GOLDENSECTION_H

#include <functional>

class GoldenSection {
public:
    static double optimize(double leftBound, double rightBound, double eps, const std::function<double(double)> &func);
};


#endif //GOLDENSECTION_H
