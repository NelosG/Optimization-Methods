//
// Created by NelosG.
//

#include "Source.h"
void Source::initialise() {

    /// 1
    auto f = [](point x) {
        return (x.get(0) * x.get(0) + x.get(1) * x.get(1) - 1.2 * x.get(0) * x.get(1));
    };

    auto gradF = [](point x) {
        return std::vector<double>{
                (2 * x.get(0) - 1.2 * x.get(1)),
                (2 * x.get(1) - 1.2 * x.get(0))};
    };

    auto hesF = [](point x) {
        return std::vector<std::vector<double>>{
                std::vector<double>{2.0, -1.2},
                std::vector<double>{-1.2, 2.0}};
    };


    //2
    auto f2 = [](point x) {
        return (100 * pow(x.get(0), 4) +
                100 * pow(x.get(1), 2) - 200 * pow(x.get(0), 2) * x.get(1) +
                pow(x.get(0), 2) - 2 * x.get(0) + 1);
    };

    auto gradF2 = [](point x) {
        return std::vector<double>{
                400 * pow(x.get(0), 3) - 400 * x.get(0) * x.get(1) + 2 * x.get(0) - 2,
                200 * x.get(1) - 200 * pow(x.get(0), 2)};
    };

    auto hesF2 = [](point x) {
        return std::vector<std::vector<double>>{
                std::vector<double>{1200 * pow(x.get(0), 2) - 400 * x.get(1) + 2, -400 * x.get(0)},
                std::vector<double>{-400 * x.get(0), 200.0}};
    };

    //3
    auto f3 = [](point x) {
        return (pow(pow(x.get(0), 2) + x.get(1) - 11, 2) +
                pow(x.get(0) + pow(x.get(1), 2) - 7, 2));
    };

    auto gradF3 = [](point x) {
        return std::vector<double>{
                4 * (pow(x.get(0), 3) + x.get(0) * x.get(1) - 11 * x.get(0)) + 2 * (x.get(0) + pow(x.get(1), 2) - 7),
                2 * (pow(x.get(0), 2) + x.get(1) - 11) + 4 * (x.get(0) * x.get(1) + pow(x.get(1), 3) - 7 * x.get(1))};
    };

    auto hesF3 = [](point x) {
        return std::vector<std::vector<double>>{
                std::vector<double>{12 * pow(x.get(0), 2) + 4 * x.get(1) - 42, 4 * (x.get(0) + x.get(1))},
                std::vector<double>{4 * (x.get(0) + x.get(1)), 4 * x.get(0) + 12 * pow(x.get(1), 2) - 26}};
    };

    // 4
    auto f4 = [](point x) {
        return (pow(x.get(0) + 10 * x.get(1), 2) + 5 * pow(x.get(2) - x.get(3), 2) +
                pow(x.get(1) - 2 * x.get(2), 4) + 10 * pow(x.get(0) - x.get(3), 4));
    };

    auto gradF4 = [](point x) {
        return std::vector<double>{
                2 * (20 * pow(x.get(0) - x.get(3), 3) + x.get(0) + 10 * x.get(1)),
                4 * (5 * (x.get(0) + 10 * x.get(1)) + pow(x.get(1) - 2 * x.get(2), 3)),
                10 * (x.get(2) - x.get(3)) - 8 * pow(x.get(1) - 2 * x.get(2), 3),
                10 * (-4 * pow(x.get(0) - x.get(3), 3) - x.get(2) + x.get(3))};
    };
    auto hesF4 = [](point x) {
        return std::vector<std::vector<double>>{
                std::vector<double>{120 * pow(x.get(0) - x.get(3), 2) + 2, 20, 0, -120 * pow(x.get(0) - x.get(3), 2)},
                std::vector<double>{20, 200 + 12 * pow((x.get(1) - 2 * x.get(2)), 2), -24 * pow(x.get(1) - 2 * x.get(2), 2), 0},
                std::vector<double>{0, -24 * pow(x.get(1) - 2 * x.get(2), 2), 10 + 48 * (x.get(1) - 2 * x.get(2)), -10},
                std::vector<double>{-120 * pow(x.get(0) - x.get(3), 2), 0, -10, 120 * pow(x.get(0) - x.get(3), 2) + 10}};
    };


    //5
    auto f5 = [](point x) {
        return (-2.0 / (0.25 * pow(x.get(0) - 1, 2) + 1.0 / 9 * pow(x.get(1) - 1, 2) + 1) -
                1.0 / (0.25 * pow(x.get(0) - 2, 2) + 1.0 / 9 * pow(x.get(1) - 1, 2) + 1) + 100);
    };
    auto gradF5 = [](point x) {
        return std::vector<double>{
                (648 * (x.get(0) - 2)) / pow(9 * pow(x.get(0), 2) - 36 * x.get(0) + 4 * pow(x.get(1), 2) - 8 * x.get(1) + 76, 2) + (x.get(0) - 1) / pow(0.25 * pow(x.get(0) - 1, 2) + 1.0 / 9 * pow(x.get(1) - 1, 2) + 1, 2),
                2.0 / 9 * (x.get(1) - 1) * (2.0 / pow(0.25 * pow(x.get(0) - 1, 2) + 1.0 / 9 * pow(x.get(1) - 1, 2) + 1, 2) + 1.0 / pow(0.25 * pow(x.get(0) - 2, 2) + 1.0 / 9 * pow(x.get(1) - 1, 2) + 1, 2))};
    };
    auto hesF5 = [](point x) {
        return std::vector<std::vector<double>>{
                std::vector<double>{(-pow(-1 + x.get(0), 2) / pow(1 + 0.25 * pow(-1 + x.get(0), 2) + 1.0 / 9 * pow(-1 + x.get(1), 2), 3) +
                                     1.0 / pow(1 + 0.25 * pow(-1 + x.get(0), 2) + 1.0 / 9 * pow(-1 + x.get(1), 2), 2) - (23328 * pow(-2 + x.get(0), 2)) / pow(76 - 36 * x.get(0) + 9 * x.get(0) * x.get(0) - 8 * x.get(1) + 4 * x.get(1) * x.get(1), 3) + 648 / pow(76 - 36 * x.get(0) + 9 * x.get(0) * x.get(0) - 8 * x.get(1) + 4 * x.get(1) * x.get(1), 2)),
                                    4.0 / 9 * (-1 + x.get(1)) * (-(-1 + x.get(0)) / pow(1 + 1.0 / 4 * pow(-1 + x.get(0), 2) + 1.0 / 9 * pow(-1 + x.get(1), 2), 3) - (23328 * (-2 + x.get(0))) / pow(76 - 36 * x.get(0) + 9 * x.get(0) * x.get(0) - 8 * x.get(1) + 4 * x.get(1) * x.get(1), 3))},
                std::vector<double>{4.0 / 9 * (-1 + x.get(1)) * (-(-1 + x.get(0)) / pow(1 + 1.0 / 4 * pow(-1 + x.get(0), 2) + 1.0 / 9 * pow(-1 + x.get(1), 2), 3) - (23328 * (-2 + x.get(0))) / pow(76 - 36 * x.get(0) + 9 * x.get(0) * x.get(0) - 8 * x.get(1) + 4 * x.get(1) * x.get(1), 3)),
                                    2.0 / 9 * (4.0 / 9 * pow(x.get(1) - 1, 2) * (-2.0 / pow(1.0 / 4 * pow(x.get(0) - 1, 2) + 1.0 / 9 * pow(x.get(1) - 1, 2) + 1, 3) - 1.0 / pow(1.0 / 4 * pow(x.get(0) - 2, 2) + 1.0 / 9 * pow(x.get(1) - 1, 2) + 1, 3)) + 1.0 / pow(1.0 / 4 * pow(x.get(0) - 2, 2) + 1.0 / 9 * pow(x.get(1) - 1, 2) + 1, 2) + 2.0 / pow(1.0 / 4 * pow(x.get(0) - 1, 2) + 1.0 / 9 * pow(x.get(1) - 1, 2) + 1, 2))}};
    };

    //6
    auto f6 = [](point x) {
        return (3 * pow(x.get(0), 2) + x.get(0) * x.get(1) +
                2 * pow(x.get(1), 2) - x.get(0) - 4 * x.get(1));
    };
    auto gradF6 = [](point x) {
        return std::vector<double>{
                (6 * x.get(0) + x.get(1) - 1),
                (x.get(0) + 4 * x.get(1) - 4)};
    };
    auto hesF6 = [](point x) {
        return std::vector<std::vector<double>>{
                std::vector<double>{6, 1},
                std::vector<double>{1, 4}};
    };


    //7
    auto f7 = [](point x) {
        return (-x.get(1) * sqrt(x.get(0)) + 2 * pow(x.get(1), 2) + x.get(0) - 14 * x.get(1));
    };
    auto gradF7 = [](point x) {
        return std::vector<double>{
                (-x.get(1) / (2 * sqrt(x.get(0)))) + 1,
                (-sqrt(x.get(0)) + 4 * x.get(1) - 14)};
    };
    auto hesF7 = [](point x) {
        return std::vector<std::vector<double>>{
                std::vector<double>{x.get(1) / (4 * x.get(0) * sqrt(x.get(0))), -1 / (2 * sqrt(x.get(0)))},
                std::vector<double>{-1 / (2 * sqrt(x.get(0))), 4}};
    };


    //data
    this->data = std::vector<Data>{
            Data(extended_function(f, gradF, hesF), point(std::vector<double>{4, 1})),
            // 2.1 begins here, mod = 1
            Data(extended_function(f2, gradF2, hesF2), point(std::vector<double>{-1.2, 1})),
            Data(extended_function(f3, gradF3, hesF3), point(std::vector<double>{1, 1})),
            Data(extended_function(f4, gradF4, hesF4), point(std::vector<double>{1, 1, 1, 1})),
            Data(extended_function(f5, gradF5, hesF5), point(std::vector<double>{1, 1})),
            // for 1.1: 3x^2+xy+2y^2-x-4y, min point: (0, 1)
            Data(extended_function(f6, gradF6, hesF6), point(std::vector<double>{-15, -5})),
            // for 1.2: -y*sqrt(x)+2*y^2+x-14y, min point: (4, 4)
            Data(extended_function(f7, gradF7, hesF7), point(std::vector<double>{3, 5}))};
}
