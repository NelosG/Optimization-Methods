//
// Created by NelosG.
//

#include "GoldenSection.h"

#include <cmath>

double GoldenSection::optimize(double leftBound, double rightBound, double eps, const std::function<double(double)> &func) {
    const static double TAU = (std::sqrt(5) - 1) / 2;
    double a = leftBound, b = rightBound;
    double x1 = a + (3 - std::sqrt(5)) * (b - a) / 2;
    double x2 = a + (std::sqrt(5) - 1) * (b - a) / 2;
    double fX1 = func(x1);
    double fX2 = func(x2);
    while ((b - a) / 2 > eps) {
        if (fX1 - fX2 <= 0) {
            b = x2;
            x2 = x1;
            fX2 = fX1;
            x1 = b - TAU * (b - a);
            fX1 = func(x1);
        } else {
            a = x1;
            x1 = x2;
            fX1 = fX2;
            x2 = a + TAU * (b - a);
            fX2 = func(x2);
        }
    }
    return (a + b) / 2;
}
