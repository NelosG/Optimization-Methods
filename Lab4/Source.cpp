//
// Created by NelosG.
//

#include "Source.h"
#include <cmath>

void Source::initialise() {

    /// 1
    auto f = [](const point &x) {
        return (x.get(0) * x.get(0) + x.get(1) * x.get(1) - 1.2 * x.get(0) * x.get(1));
    };

    auto gradF = [](const point &x) {
        return std::vector<double>{
                (2 * x.get(0) - 1.2 * x.get(1)),
                (2 * x.get(1) - 1.2 * x.get(0))};
    };

    auto hesF = [](const point &x) {
        return std::vector<std::vector<double>>{
                std::vector<double>{2.0, -1.2},
                std::vector<double>{-1.2, 2.0}};
    };


    //2
    auto f2 = [](const point &x) {
        return (100 * pow(x.get(0), 4) +
                100 * pow(x.get(1), 2) - 200 * pow(x.get(0), 2) * x.get(1) +
                pow(x.get(0), 2) - 2 * x.get(0) + 1);
    };

    auto gradF2 = [](const point &x) {
        return std::vector<double>{
                400 * pow(x.get(0), 3) - 400 * x.get(0) * x.get(1) + 2 * x.get(0) - 2,
                200 * x.get(1) - 200 * pow(x.get(0), 2)};
    };

    auto hesF2 = [](const point &x) {
        return std::vector<std::vector<double>>{
                std::vector<double>{1200 * pow(x.get(0), 2) - 400 * x.get(1) + 2, -400 * x.get(0)},
                std::vector<double>{-400 * x.get(0), 200.0}};
    };

    //3
    auto f3 = [](const point &x) {
        return (pow(pow(x.get(0), 2) + x.get(1) - 11, 2) +
                pow(x.get(0) + pow(x.get(1), 2) - 7, 2));
    };

    auto gradF3 = [](const point &x) {
        return std::vector<double>{
                4 * (pow(x.get(0), 3) + x.get(0) * x.get(1) - 11 * x.get(0)) + 2 * (x.get(0) + pow(x.get(1), 2) - 7),
                2 * (pow(x.get(0), 2) + x.get(1) - 11) + 4 * (x.get(0) * x.get(1) + pow(x.get(1), 3) - 7 * x.get(1))};
    };

    auto hesF3 = [](const point &x) {
        return std::vector<std::vector<double>>{
                std::vector<double>{12 * pow(x.get(0), 2) + 4 * x.get(1) - 42, 4 * (x.get(0) + x.get(1))},
                std::vector<double>{4 * (x.get(0) + x.get(1)), 4 * x.get(0) + 12 * pow(x.get(1), 2) - 26}};
    };

    // 4
    auto f4 = [](const point &x) {
        return (x.get(0) + 10 * x.get(1)) * (x.get(0) + 10 * x.get(1))
               + 5 * (x.get(2) - x.get(3)) * (x.get(2) - x.get(3))
               + (x.get(1) - 2 * x.get(2)) * (x.get(1) - 2 * x.get(2)) * (x.get(1) - 2 * x.get(2)) *
                 (x.get(1) - 2 * x.get(2))
               + 10 * (x.get(0) - x.get(3)) * (x.get(0) - x.get(3)) * (x.get(0) - x.get(3)) * (x.get(0) - x.get(3));
    };

    auto gradF4 = [](const point &x) {
        return std::vector<double>{
                2 *
                (20 * (x.get(0) - x.get(3)) * (x.get(0) - x.get(3)) * (x.get(0) - x.get(3)) + x.get(0) + 10 * x.get(1)),
                4 * (5 * (x.get(0) + 10 * x.get(1)) +
                     (x.get(1) - 2 * x.get(2)) * (x.get(1) - 2 * x.get(2)) * (x.get(1) - 2 * x.get(2))),
                10 * (x.get(2) - x.get(3)) -
                8 * (x.get(1) - 2 * x.get(2)) * (x.get(1) - 2 * x.get(2)) * (x.get(1) - 2 * x.get(2)),
                10 *
                (-4 * (x.get(0) - x.get(3)) * (x.get(0) - x.get(3)) * (x.get(0) - x.get(3)) + x.get(3) - x.get(2))};
    };
    auto hesF4 = [](const point &x) {
        return std::vector<std::vector<double>>{
                {120 * (x.get(0) - x.get(3)) * (x.get(0) - x.get(3)) + 2, 20,                              0,
                                                                                                                       -120 *
                                                                                                                       (x.get(0) -
                                                                                                                        x.get(3)) *
                                                                                                                       (x.get(0) -
                                                                                                                        x.get(3))},
                {20,                                                      12 * (x.get(1) - 2 * x.get(2)) *
                                                                          (x.get(1) - 2 * x.get(2)) + 200, -24 *
                                                                                                           (x.get(1) -
                                                                                                            2 *
                                                                                                            x.get(2)) *
                                                                                                           (x.get(1) -
                                                                                                            2 *
                                                                                                            x.get(2)), 0},
                {0,                                                       -24 * (x.get(1) - 2 * x.get(2)) *
                                                                          (x.get(1) - 2 * x.get(2)),       48 *
                                                                                                           (x.get(1) -
                                                                                                            2 *
                                                                                                            x.get(2)) *
                                                                                                           (x.get(1) -
                                                                                                            2 *
                                                                                                            x.get(2)) +
                                                                                                           10,         -10},
                {-120 * (x.get(0) - x.get(3)) * (x.get(0) -
                                                 x.get(3)),               0,                               -10,        120 *
                                                                                                                       (x.get(0) -
                                                                                                                        x.get(3)) *
                                                                                                                       (x.get(0) -
                                                                                                                        x.get(3)) +
                                                                                                                       10}
        };
    };


    //5
    auto f5 = [](const point &x) {
        return (-2.0 / (0.25 * pow(x.get(0) - 1, 2) + 1.0 / 9 * pow(x.get(1) - 1, 2) + 1) -
                1.0 / (0.25 * pow(x.get(0) - 2, 2) + 1.0 / 9 * pow(x.get(1) - 1, 2) + 1) + 100);
    };
    auto gradF5 = [](const point &x) {
        return std::vector<double>{
                (648 * (x.get(0) - 2)) /
                pow(9 * pow(x.get(0), 2) - 36 * x.get(0) + 4 * pow(x.get(1), 2) - 8 * x.get(1) + 76, 2) +
                (x.get(0) - 1) / pow(0.25 * pow(x.get(0) - 1, 2) + 1.0 / 9 * pow(x.get(1) - 1, 2) + 1, 2),
                2.0 / 9 * (x.get(1) - 1) *
                (2.0 / pow(0.25 * pow(x.get(0) - 1, 2) + 1.0 / 9 * pow(x.get(1) - 1, 2) + 1, 2) +
                 1.0 / pow(0.25 * pow(x.get(0) - 2, 2) + 1.0 / 9 * pow(x.get(1) - 1, 2) + 1, 2))};
    };
    auto hesF5 = [](const point &x) {
        return std::vector<std::vector<double>>{
                std::vector<double>{(-pow(-1 + x.get(0), 2) /
                                     pow(1 + 0.25 * pow(-1 + x.get(0), 2) + 1.0 / 9 * pow(-1 + x.get(1), 2), 3) +
                                     1.0 / pow(1 + 0.25 * pow(-1 + x.get(0), 2) + 1.0 / 9 * pow(-1 + x.get(1), 2), 2) -
                                     (23328 * pow(-2 + x.get(0), 2)) /
                                     pow(76 - 36 * x.get(0) + 9 * x.get(0) * x.get(0) - 8 * x.get(1) +
                                         4 * x.get(1) * x.get(1), 3) + 648 / pow(76 - 36 * x.get(0) +
                                                                                 9 * x.get(0) * x.get(0) -
                                                                                 8 * x.get(1) + 4 * x.get(1) * x.get(1),
                                                                                 2)),
                                    4.0 / 9 * (-1 + x.get(1)) * (-(-1 + x.get(0)) /
                                                                 pow(1 + 1.0 / 4 * pow(-1 + x.get(0), 2) +
                                                                     1.0 / 9 * pow(-1 + x.get(1), 2), 3) -
                                                                 (23328 * (-2 + x.get(0))) /
                                                                 pow(76 - 36 * x.get(0) + 9 * x.get(0) * x.get(0) -
                                                                     8 * x.get(1) + 4 * x.get(1) * x.get(1), 3))},
                std::vector<double>{4.0 / 9 * (-1 + x.get(1)) * (-(-1 + x.get(0)) /
                                                                 pow(1 + 1.0 / 4 * pow(-1 + x.get(0), 2) +
                                                                     1.0 / 9 * pow(-1 + x.get(1), 2), 3) -
                                                                 (23328 * (-2 + x.get(0))) /
                                                                 pow(76 - 36 * x.get(0) + 9 * x.get(0) * x.get(0) -
                                                                     8 * x.get(1) + 4 * x.get(1) * x.get(1), 3)),
                                    2.0 / 9 * (4.0 / 9 * pow(x.get(1) - 1, 2) * (-2.0 /
                                                                                 pow(1.0 / 4 * pow(x.get(0) - 1, 2) +
                                                                                     1.0 / 9 * pow(x.get(1) - 1, 2) + 1,
                                                                                     3) - 1.0 / pow(1.0 / 4 *
                                                                                                    pow(x.get(0) - 2,
                                                                                                        2) + 1.0 / 9 *
                                                                                                             pow(x.get(
                                                                                                                     1) -
                                                                                                                 1, 2) +
                                                                                                    1, 3)) + 1.0 /
                                                                                                             pow(1.0 /
                                                                                                                 4 *
                                                                                                                 pow(x.get(
                                                                                                                         0) -
                                                                                                                     2,
                                                                                                                     2) +
                                                                                                                 1.0 /
                                                                                                                 9 *
                                                                                                                 pow(x.get(
                                                                                                                         1) -
                                                                                                                     1,
                                                                                                                     2) +
                                                                                                                 1, 2) +
                                               2.0 /
                                               pow(1.0 / 4 * pow(x.get(0) - 1, 2) + 1.0 / 9 * pow(x.get(1) - 1, 2) + 1,
                                                   2))}};
    };

    //6
    auto f6 = [](const point &x) {
        return -x.get(0) * sqrt(x.get(1)) + 2 * pow(x.get(0), 2) - 7 * x.get(0) + x.get(1);
    };
    auto gradF6 = [](const point &x) {
        return std::vector<double>{
                4 * x.get(0) - sqrt(x.get(1)) - 7,
                (-x.get(0) / (2 * sqrt(x.get(1)))) + 1};
    };
    auto hesF6 = [](const point &x) {
        return std::vector<std::vector<double>>{
                {4,
                        -1 / (2 * sqrt(x.get(1)))},
                {-1 / (2 * sqrt(x.get(1))),
                        x.get(0) / (4 * x.get(1) * sqrt(x.get(1)))}};
    };


    //7
    auto f7 = [](const point &x) {
        return x.get(0) * x.get(0) + x.get(1) * x.get(1) + x.get(0) * x.get(1) + x.get(0) + x.get(1);
    };
    auto gradF7 = [](const point &x) {
        return std::vector<double>{
                2 * x.get(0) + x.get(1) + 1,
                x.get(0) + 2 * x.get(1) + 1};
    };
    auto hesF7 = [](const point &x) {
        return std::vector<std::vector<double>>{
                {2, 1},
                {1, 2}};
    };


    //data
    this->data = std::vector<Data>{
            Data(extended_function(f, gradF, hesF), point(std::vector<double>{4, 1})),
            Data(extended_function(f2, gradF2, hesF2), point(std::vector<double>{-1.2, 1})),
            Data(extended_function(f3, gradF3, hesF3), point(std::vector<double>{1, 1})),
            Data(extended_function(f4, gradF4, hesF4), point(std::vector<double>{1, 1, 1, 1})),
            Data(extended_function(f5, gradF5, hesF5), point(std::vector<double>{1, 1})),

            Data(extended_function(f6, gradF6, hesF6), point(std::vector<double>{0, 2})),
            Data(extended_function(f6, gradF6, hesF6), point(std::vector<double>{0, 1})),
            Data(extended_function(f6, gradF6, hesF6), point(std::vector<double>{1, 1})),

            Data(extended_function(f7, gradF7, hesF7), point(std::vector<double>{-5, 5})),
            Data(extended_function(f7, gradF7, hesF7), point(std::vector<double>{1, 1})),
            Data(extended_function(f7, gradF7, hesF7), point(std::vector<double>{10, 20}))};
}
