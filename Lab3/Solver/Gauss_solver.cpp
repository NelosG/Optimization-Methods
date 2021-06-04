//
// Created by NelosG.
//

#include <solver.h>
constexpr const static double eps = 1E-35;


bool pivoting(regular_matrix &mt, int row, int col) {
    int maxLineIndex = row;
    double localMax = 0.0;
    for (int i = row; i < mt.size(); i++) {
        if (abs(mt.get(i, col)) > localMax) {
            maxLineIndex = i;
            localMax = abs(mt.get(i, col));
        }
    }
    if (localMax <= eps)
        return false;
    mt.swap_rows(row, maxLineIndex);
    return true;
}

bool madeTriangularView(regular_matrix &mt, std::vector<double> &vec, int row, int col) {
    for (int i = row + 1; i < mt.size(); i++) {
        double delta = mt.get(i, col) / mt.get(row, col);
        for (int j = col; j < mt.size(); j++)
            mt.set(i, j, mt.get(i, j) - delta * mt.get(row, j));
        vec[i] = vec[i] - delta * vec[row];
        bool checkZeroLine = true;
        for (int j = col; j < mt.size(); j++) {
            if (abs(mt.get(i, j)) > eps)
                checkZeroLine = false;
        }
        if (checkZeroLine) {
            if (abs(vec[i]) > eps)
                return true;
        }
        if (checkZeroLine) {
            for (int j = 0; j < mt.size(); j++) {
                mt.set(i, j, 0.0);
            }
            vec[i] = 0.0;
        }
    }
    return false;
}

bool checkIncompatibleLine(const regular_matrix &mt, const std::vector<double> &vec, int row) {
    for (int i = 0; i < mt.size(); i++) {
        if (abs(mt.get(row, i)) > eps)
            return false;
    }
    return abs(vec[row]) > eps;
}

bool checkManySolution(const regular_matrix &mt, int row) {
    for (int i = 0; i < mt.size(); i++) {
        if (abs(mt.get(row, i)) > eps)
            return false;
    }
    return true;
}

void madeDiagView(regular_matrix &mt, std::vector<double> &vec, int col) {
    for (int i = col - 1; i >= 0; i--) {
        double delta = mt.get(i, col) / mt.get(col, col);
        mt.set(i, col, mt.get(i, col) - delta * mt.get(col, col));
        vec[i] = vec[i] - delta * vec[col];
    }
}

std::pair<int, std::pair<std::vector<double>, int>> Solver::Gauss_solve(regular_matrix mt, std::vector<double> vec) {
    std::vector<double> answer(mt.size(), 0);
    int iter = 0;
    for (int col = 0, row = 0; col < mt.size() && row < mt.size(); row++) {
        col = row;
        ++iter;
        while (col < mt.size() && !pivoting(mt, row, col)) {
            col++;
        }
        if (col < mt.size())
            if (madeTriangularView(mt, vec, row, col))
                return {0, {answer, iter}};
    }
    for (int row = 0; row < mt.size(); row++)
        if (checkIncompatibleLine(mt, vec, row))
            return {0, {answer, iter}};
    for (int row = 0; row < mt.size(); row++) {
        if (checkManySolution(mt, row))
            return {2, {answer, iter}};
    }
    for (int row = (int) mt.size() - 1; row > 0; row--) {
        madeDiagView(mt, vec, row);
        ++iter;
    }
    for (int column = 0; column < mt.size(); ++column) {
        answer[column] = vec[column] / mt.get(column, column);
    }
    return {1, {answer, iter}};
}
