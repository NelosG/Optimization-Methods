//
// Created by NelosG.
//

#include <cmath>

#include "sparse_matrix.h"

constexpr const static double eps = 1E-35;

sparse_matrix::sparse_matrix(std::vector<double> di, std::vector<double> al, std::vector<double> au,
                             std::vector<int> ia, std::vector<int> ja) {
    this->al = std::move(al);
    this->au = std::move(au);
    this->diagonal = std::move(di);
    this->ia = std::move(ia);
    this->ja = std::move(ja);
}
sparse_matrix::sparse_matrix(const matrix &mt) {
    diagonal.assign(mt.size(), 0);
    ia.assign(mt.size() + 2, 0);
    std::vector<double> alList;
    std::vector<double> auList;
    std::vector<int> jaList;

    for (int i = 0; i < mt.size(); i++) {
        diagonal[i] = mt.get(i, i);
    }

    ia[0] = 0;
    ia[1] = 0;
    for (int i = 1; i < mt.size(); i++) {
        ia[i + 1] = ia[i] + get_row_profile_length(mt, i, alList, auList, jaList);
    }

    al.assign(alList.size(), 0);
    au.assign(auList.size(), 0);
    ja.assign(jaList.size(), 0);

    for (int i = 0; i < alList.size(); i++) {
        al[i] = alList[i];
        au[i] = auList[i];
        ja[i] = jaList[i];
    }
}
int find(std::vector<int> &vec, int value) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == value) {
            return i + 1;
        }
    }
    return 0;
}
double sparse_matrix::get(int a, int b) const {
    if (a == b) {
        return diagonal[a];
    }
    bool flag = true;
    if (b > a) {
        int temp = b;
        b = a;
        a = temp;
        flag = false;
    }
    std::vector<int> all_columns;
    for (int i = ia[a]; i < ia[a + 1]; i++) {
        all_columns.emplace_back(ja[i]);
    }
    if (find(all_columns, b)) {
        if (flag) {
            return al[ia[a] + find(all_columns, b) - 1];
        } else {
            return au[ia[a] + find(all_columns, b) - 1];
        }
    } else {
        return 0;
    }
}
std::vector<double> sparse_matrix::multiply(std::vector<double> &vector) const {
    int leftBorderInJa = 0;
    std::vector<double> result(vector.size(), 0);
    for (int i = 0; i < diagonal.size(); i++) {
        int cnt = ia[i + 1] - ia[i];
        result[i] += diagonal[i] * vector[i];
        for (int j = 0; j < cnt; j++) {
            int column = ja[leftBorderInJa + j];
            result[i] += al[leftBorderInJa + j] * vector[column];
            result[column] += au[leftBorderInJa + j] * vector[i];
        }
        leftBorderInJa += cnt;
    }
    return result;
}
int sparse_matrix::get_row_profile_length(const matrix &mt, int row,
                                          std::vector<double> &alList, std::vector<double> &auList, std::vector<int> &jaList) {
    int index = 0;
    int count = 0;
    while (index != row) {
        if (std::abs(mt.get(row, index)) >= eps) {
            alList.emplace_back(mt.get(row, index));
            auList.emplace_back(mt.get(index, row));
            jaList.emplace_back(index);
            count++;
        }
        index++;
    }
    return count;
}
