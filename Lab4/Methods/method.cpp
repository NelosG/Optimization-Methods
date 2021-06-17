//
// Created by NelosG.
//

#include <cmath>

#include "method.h"

point method::slay(std::vector<std::vector<double>> h, std::vector<double> f) {
    size_t n = f.size();

    std::vector<int> real(n, 0);
    for (int i = 0; i < n; i++) {
        real[i] = i;
    }

    for (int row = 0; row < n; row++) {
        int sel = row;
        for (int i = row + 1; i < n; i++) {
            if (std::abs(h[real[i]][row]) > std::abs(h[real[sel]][row])) {
                sel = i;
            }
        }
        int tmp = real[sel];
        real[sel] = real[row];
        real[row] = tmp;

        tmp = real[sel];
        real[sel] = real[row];
        real[row] = tmp;

        for (int i = row + 1; i < n; ++i) {
            double c = h[real[i]][row] / h[real[row]][row];
            for (int j = row; j < n; ++j) {
                h[real[i]][j] -= h[real[row]][j] * c;
            }
            f[real[i]] -= f[real[row]] * c;
        }
    }

    std::vector<double> solution(n, 0);
    for (int i = (int) n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = (int) n - 1; j > i; j--) {
            sum += h[real[i]][j] * solution[j];
        }
        solution[i] = (f[real[i]] - sum) / h[real[i]][i];
    }
    return point(solution);
}
double method::count_lambda(extended_function function, point x, point d) {
    auto f = [&function, &x, &d](double l) { return function.value(utils::points_addition(x, utils::multiply_on_scalar(d, l))); };
    double PHI = 2 - (1 + sqrt(5)) / 2;
    double EPS = 0.00001;

    double a = -1000, b = 1000, x1, x2, f1, f2;
    x1 = a + PHI * (b - a);
    x2 = b - PHI * (b - a);
    f1 = f(x1);
    f2 = f(x2);
    while (std::abs(b - a) > EPS) {
        if (f1 < f2) {
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = a + PHI * (b - a);
            f1 = f(x1);
        } else {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = b - PHI * (b - a);
            f2 = f(x2);
        }
    }
    return (x1 + x2) / 2;
}
