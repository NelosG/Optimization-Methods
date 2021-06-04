//
// Created by NelosG.
//
#include <boost/asio/io_context.hpp>
#include <boost/asio/post.hpp>
#include <boost/asio/thread_pool.hpp>
#include <boost/thread/thread.hpp>
#include <file_utils.h>
#include <matrix_generator.h>

void test_generator::generate_tests(const std::string &path, const std::string &name,
                                    const std::vector<std::pair<int, std::vector<int>>> &NK,
                                    const std::function<void(const std::string &, const std::string &, int, int)> &test_creation) {
    int count = std::thread::hardware_concurrency();
    count = count == 1 ? count : count - 1;
    boost::asio::thread_pool pool(count);

        for (auto &[n, vecK] : NK) {
            if(!vecK.empty()) {
                for (auto &k : vecK) {
                    boost::asio::post(pool, [&path, &name, &test_creation, &n, &k]() { test_creation(path, name, n, k); });
                }
            } else {
                boost::asio::post(pool, [&path, &name, &test_creation, &n]() { test_creation(path, name, n, -1); });
            }
        }
    pool.join();
}


void create_regular(const std::string &path, const std::string &name, int n, int k,
                    const std::function<std::pair<regular_matrix, std::vector<double>>(int, int)> &gen_func) {
    auto str = file_utils::open_file(path + "/" + name + std::to_string(n) + (k >= 0 ? ("_" + std::to_string(k)) : "") + ".txt", false);
    auto p = gen_func(n, k);
    int precision = 100;
    str << n << "\n\n"
        << print_utils::print(p.first, precision) << "\n\n";
    str << print_utils::print(p.second, precision) << '\n';
    str.close();
}

void create_profile(const std::string &path, const std::string &name, int n, int k,
                    const std::function<std::pair<profile_matrix, std::vector<double>>(int, int)> &gen_func) {
    auto str = file_utils::open_file(path + "/" + name + std::to_string(n) + (k >= 0 ? ("_" + std::to_string(k)) : "") + ".txt", false);
    auto p = gen_func(n, k);
    int precision = 100;
    str << print_utils::print(p.first, precision) << "\n\n";
    str << print_utils::print(p.second, precision, true) << '\n';
    str.close();
}

void create_sparse(const std::string &path, const std::string &name, int n, int k,
                    const std::function<std::pair<sparse_matrix, std::vector<double>>(int, int)> &gen_func) {
    auto str = file_utils::open_file(path + "/" + name + std::to_string(n) + (k >= 0 ? ("_" + std::to_string(k)) : "") + ".txt", false);
    auto p = gen_func(n, k);
    int precision = 100;
    str << print_utils::print(p.first, precision) << "\n\n";
    str << print_utils::print(p.second, precision, true) << '\n';
    str.close();
}


void test_generator::test_creation_regular(const std::string &path, const std::string &name, int n, int k) {
    create_regular(path, name, n, k, matrix_generator::generate_regular);
}

void test_generator::test_creation_profile(const std::string &path, const std::string &name, int n, int k) {
    create_profile(path, name, n, k, matrix_generator::generate_profile);
}

void test_generator::test_creation_sparse(const std::string &path, const std::string &name, int n, int k) {
    create_sparse(path, name, n, k, matrix_generator::generate_sparse);
}


void test_generator::test_creation_Hilbert_regular(const std::string &path, const std::string &name, int n, int k) {
    create_regular(path, name, n, k, matrix_generator::generate_Hilbert_regular);
}
void test_generator::test_creation_Hilbert_profile(const std::string &path, const std::string &name, int n, int k) {
    create_profile(path, name, n, k, matrix_generator::generate_Hilbert_profile);
}

std::vector<double> matrix_generator::multiply_by_vector(const matrix& mt) {
    std::vector<double> vector(mt.size(), 0);
    for (int i = 0; i < mt.size(); ++i) {
        vector[i] = i+1;
    }
    std::vector<double> answer(mt.size());
    for (int row = 0; row < mt.size(); row++) {
        for (int col = 0; col < mt.size(); col++) {
            answer[row] += vector[col] * mt.get(row, col);
        }
    }
    return answer;
}