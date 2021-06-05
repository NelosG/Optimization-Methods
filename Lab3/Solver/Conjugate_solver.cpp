//
// Created by NelosG.
//
#include <solver.h>

static const double eps = 1E-10;


std::vector<double> subtractVectors(std::vector<double> a, const std::vector<double> &b) {
    for (int i = 0; i < a.size(); ++i) {
        a[i] -= b[i];
    }
    return a;
}

double scalar(const std::vector<double> &a, const std::vector<double> &b) {
    double res = 0;
    for (int i = 0; i < a.size(); ++i) {
        res += a[i] * b[i];
    }
    return res;
}

std::vector<double> multiply(double alpha, std::vector<double> b) {
    for (double &i : b) {
        i *= alpha;
    }
    return b;
}

std::vector<double> sumVectors(std::vector<double> a, const std::vector<double> &b) {
    for (int i = 0; i < a.size(); ++i) {
        a[i] += b[i];
    }
    return a;
}

std::pair<std::vector<double>, int> Solver::Conjugate_solve(const sparse_matrix &A, const std::vector<double> &f) {
    std::vector<double> x0(f.size(), 0);
    x0[0] = 1;
    std::vector<double> r0 = subtractVectors(f, A.smartMultiplication(x0));
    std::vector<double> z0 = r0;
    int MAX_ITERATIONS = 100000;
    int k = 1;
    for (; k < MAX_ITERATIONS; k++) {
        std::vector<double> Az0 = A.smartMultiplication(z0);
        double alphaK = scalar(r0, r0) / scalar(Az0, z0);
        std::vector<double> xK = sumVectors(x0, multiply(alphaK, z0));
        std::vector<double> rK = subtractVectors(r0, multiply(alphaK, Az0));
        double betaK = scalar(rK, rK) / scalar(r0, r0);
        std::vector<double> zK = sumVectors(rK, multiply(betaK, z0));
        if (sqrt(scalar(rK, rK) / scalar(f, f)) < eps) {
            return {xK, k};
        }
        x0 = xK;
        z0 = zK;
        r0 = rK;
    }
    return {x0, k};
}
