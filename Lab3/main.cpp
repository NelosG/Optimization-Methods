#include <runner.h>
#include <matrix_generator.h>

void run(const std::string& path, const std::string& path_for_logs, bool generate_tests) {
    std::vector<std::pair<int,std::vector<int>>> NK;
    std::vector<std::pair<int,std::vector<int>>> NKH;
    for (int i = 1; i < 21; ++i) {
        NKH.emplace_back(i, std::vector<int>());
    }
    for (int i = 10; i < 110; i+=10) {
        NK.emplace_back(i, std::vector<int>());
        for (int j = 0; j < 11; ++j) {
            NK.back().second.emplace_back(j);
        }
    }
//    for (int i = 100; i < 1300; i += 100) {
//        NK.emplace_back(i, std::vector<int>());
//        for (int j = 0; j < 11; ++j) {
//            NK.back().second.emplace_back(j);
//        }
//    }

    if(generate_tests) {
        test_generator::generate_tests(path, "profile", NK, test_generator::test_creation_profile);
        test_generator::generate_tests(path, "regular", NK, test_generator::test_creation_regular);
        test_generator::generate_tests(path, "sparse", NK, test_generator::test_creation_sparse);
        test_generator::generate_tests(path, "Hilbert-profile", NKH, test_generator::test_creation_Hilbert_profile);
        test_generator::generate_tests(path, "Hilbert-regular", NKH, test_generator::test_creation_Hilbert_regular);
    }
    logger lg(path_for_logs);
    std::vector<std::string> heading = {"n", "k", "||x* - x||", "||x* - x|| / ||x*||", "Average diff", "Max diff", "Iterations"};
    lg.set_page("LU_Profile", heading);
    runner::run_all_tests_profile(path, "profile", NK, lg);
    lg.set_page("Gauss_Regular", heading);
    runner::run_all_tests_regular(path, "regular", NK, lg);
    lg.set_page("Conjugate_Sparse", heading);
    runner::run_all_tests_sparse(path, "sparse", NK, lg);


    heading.erase(++heading.begin());
    lg.set_page("LU_Hilbert_Profile", heading);
    runner::run_all_tests_profile(path, "Hilbert-profile", NKH, lg);
    lg.set_page("Gauss_Hilbert_Regular", heading);
    runner::run_all_tests_regular(path, "Hilbert-regular", NKH, lg);
    lg.close();
}

int main() {
    std::string path = "../../tests-files/generated-tests";
    std::string path_for_logs = "../../tests-files/log.xlsx";
    run(path, path_for_logs, false);

}
