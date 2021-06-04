//
// Created by NelosG.
//

#include <profile_matrix.h>

profile_matrix::profile_matrix(const matrix &mt) {
    ia.assign(mt.size() + 1, 0);
    ia[0] = 1;
    ia[1] = 1;

    for (int i = 0; i < mt.size(); i++) {
        diagonal.emplace_back(mt.get(i, i));
    }
    int counter = 0;
    for (int row = 1; row < mt.size(); row++) {
        bool wasNotZero = false;
        for (int j = 0; j < row; j++) {
            double element = mt.get(row, j);
            if (element != 0) {
                wasNotZero = true;
            }
            if (wasNotZero) {
                counter++;
                al.emplace_back(element);
                au.emplace_back(mt.get(j, row));
            }
        }
        ia[row + 1] = counter + ia[row];
        counter = 0;
    }
}

profile_matrix::profile_matrix(std::vector<double> diagonal, std::vector<double> al,
                               std::vector<double> au, std::vector<int> ia) {
    this->diagonal = std::move(diagonal);
    this->al = std::move(al);
    this->au = std::move(au);
    this->ia = std::move(ia);
}

double profile_matrix::get(int i, int j) const {
    if (i == j) {
        return diagonal[i];
    }
    if (j < i) {
        return get_U_O_L_element(true, i, j);
    } else {
        return get_U_O_L_element(false, j, i);
    }
}

void profile_matrix::set(int i, int j, double element) {
    if (i == j) {
        diagonal[i] = element;
    } else if (j < i) {
        setUpperOrLower(i, j, element, true);
    } else {
        setUpperOrLower(j, i, element, false);
    }
}

double profile_matrix::get_U_O_L_element(bool isLower, int i, int j) const {
    if (j < i - profile_length(i)) {
        return 0.;
    }
    if (isLower) {
        return al[index_in_triangle(i, j)];
    } else {
        return au[index_in_triangle(i, j)];
    }
}
