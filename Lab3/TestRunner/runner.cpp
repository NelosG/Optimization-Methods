//
// Created by NelosG.
//
#include <runner.h>

std::pair<double, double> runner::get_diff(const std::vector<double> &solve) {
    double max = -1;
    double average = 0;
    for (int i = 0; i < solve.size(); ++i) {
        double diff = abs(i + 1 - solve[i]);
        if (max < diff) {
            max = diff;
        }
        average += diff;
    }
    return {average / solve.size(), max};
}

double runner::length(const std::vector<double>& vec) {
    double ans = 0;
    for (auto &i : vec) {
        ans += i * i;
    }
    return ans;
}
std::pair<double, double> runner::get_modules(const std::vector<double> &in_solve) {
    std::vector<double> solve = in_solve;
    std::vector<double> ans(solve.size());
    for (int i = 0; i < solve.size(); i++) {
        solve[i] = -solve[i] + i + 1;
        ans.emplace_back(i + 1);
    }
    return {length(solve), length(solve) / length(ans)};
}

void runner::read_vec(int n, std::fstream &str, std::vector<int> &res) {
    res.assign(n, 0);
    for (int i = 0; i < n; i++) {
        str >> res[i];
    }
}

void runner::read_vec(int n, std::fstream &str, std::vector<double> &res) {
    res.assign(n, 0);
    for (int i = 0; i < n; i++) {
        str >> res[i];
    }
}