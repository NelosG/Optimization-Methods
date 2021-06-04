//
// Created by NelosG.
//

#include <iomanip>
#include <print_utils.h>
#include <sstream>

namespace print_utils {

    std::string print(const regular_matrix &mt, int precision) {
        std::stringstream ss;
        ss << std::fixed;
        ss << std::setprecision(precision);
        for (int i = 0; i < mt.size() - 1; ++i) {
            ss << print(mt.get(i), precision) << '\n';
        }
        ss << print(mt.get((int)mt.size() - 1), precision);
        return ss.str();
    }

    std::string print(const profile_matrix &mt, int precision) {
        std::stringstream ss;
        ss << std::fixed;
        ss << std::setprecision(precision);
        ss << print(mt.get_diagonal(), precision, true) << "\n\n";
        ss << print(mt.get_al(), precision, true) << "\n\n";
        ss << print(mt.get_au(), precision, true) << "\n\n";
        ss << print(mt.get_ia(), precision, true) << "\n\n";

        return ss.str();
    }

    std::string print(const sparse_matrix &mt, int precision) {
        std::stringstream ss;
        ss << std::fixed;
        ss << std::setprecision(precision);
        ss << print(mt.get_diagonal(), precision, true) << "\n\n";
        ss << print(mt.get_al(), precision, true) << "\n\n";
        ss << print(mt.get_au(), precision, true) << "\n\n";
        ss << print(mt.get_ia(), precision, true) << "\n\n";
        ss << print(mt.get_ja(), precision, true) << "\n\n";
        return ss.str();
    }

    std::string print(const std::vector<int> &vec, int precision) {
        return print(vec,precision, false);
    }
    std::string print(const std::vector<double> &vec, int precision) {
        return print(vec,precision, false);
    }

    std::string print(const std::vector<double> &vec, int precision, bool print_size) {
        std::stringstream ss;
        ss << std::fixed;
        ss << std::setprecision(precision);
        if(print_size) {
            ss << vec.size() << " ";
        }
        if(vec.empty()) {
            return ss.str();
        }
        for (int i = 0; i < vec.size() - 1; ++i) {
            ss << vec[i] << " ";
        }
        ss << vec[vec.size() - 1];
        return ss.str();
    }

    std::string print(const std::vector<int> &vec, int precision, bool print_size) {
        std::stringstream ss;
        ss << std::fixed;
        ss << std::setprecision(precision);
        if(print_size) {
            ss << vec.size() << " ";
        }
        if(vec.empty()) {
            return ss.str();
        }
        for (int i = 0; i < vec.size() - 1; ++i) {
            ss << vec[i] << " ";
        }
        ss << vec[vec.size() - 1];
        return ss.str();
    }

    std::string print(const std::vector<double> &vec) {
        return print(vec, 5);
    }

    std::string print(const std::vector<int> &vec) {
        return print(vec, 5);
    }

    std::string print(const regular_matrix &vec) {
        return print(vec, 5);
    }

    std::string print(const profile_matrix &vec) {
        return print(vec, 5);
    }

    std::string print(const sparse_matrix &vec) {
        return print(vec, 5);
    }

    std::string print_diff(const std::vector<double> &solve) {
        double max = -1;
        double average = 0;
        for (int i = 0; i < solve.size(); ++i) {
            double diff = abs(i + 1 - solve[i]);
            if (max < diff) {
                max = diff;
            }
            average += diff;
        }
        return "Average: " + std::to_string(average / solve.size()) + "        maxDiff: " + std::to_string(max) + '\n';
    }
}// namespace print_utils
