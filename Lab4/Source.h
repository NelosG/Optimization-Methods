//
// Created by NelosG.
//

#ifndef SOURCE_H
#define SOURCE_H


#include "Utils/extended_function.h"
#include "Utils/point.h"
#include <utility>
#include <vector>
class Source;
class Data {
    extended_function function;
    point point;

public:
    Data(extended_function function, const class point &point) : function(std::move(function)), point(point) {
    }
    friend class Source;
};
class Source {
    int mod = 1;
    std::vector<Data> data;

public:
    Source() {
        initialise();
    }

    [[nodiscard]] extended_function get_function() const {
        return data[mod].function;
    }

    [[nodiscard]] size_t get_mods_count() const {
        return data.size();
    }

    [[nodiscard]] point get_point() const {
        return data[mod].point;
    }

    void change_mod(int md) {
        this->mod = md;
    }

private:
    void initialise();
};


#endif//SOURCE_H
