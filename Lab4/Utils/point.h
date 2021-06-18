//
// Created by NelosG.
//

#ifndef POINT_H
#define POINT_H

#include <sstream>
#include <string>
#include <utility>
#include <vector>

class point {

    std::vector<double> coordinates;

public:
    point() = default;

    explicit point(std::vector<double> coordinates) : coordinates(std::move(coordinates)) {
    }

    point(const point &p) = default;

    [[nodiscard]] const std::vector<double> &get_coordinates() const {
        return coordinates;
    }

    double get(int i) const {
        return coordinates[i];
    }

    void add(point y) {
        for (int i = 0; i < y.coordinates.size(); i++) {
            coordinates[i] += y.coordinates[i];
        }
    }

    std::string to_string() const {
        std::stringstream ss;
        ss << "(";
        for (auto i : coordinates) {
            ss << i << "; ";
        }
        return ss.str().substr(0, ss.str().size() - 2) + ")";
    }
};


#endif//POINT_H
