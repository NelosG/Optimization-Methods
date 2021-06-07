#include <ctime>
#include <file_utils.h>
#include <matrix_generator.h>
#include <runner.h>
#include <chrono>
#include <boost/asio/post.hpp>
#include <boost/asio/thread_pool.hpp>
#include <thread>


void run(const std::string &path, const std::string &path_for_logs, bool generate_tests, int mode) {
    std::vector<std::pair<int, std::vector<int>>> NK;
    std::vector<std::pair<int, std::vector<int>>> NKH;
    std::vector<std::pair<int, std::vector<int>>> NKS;
    std::vector<std::pair<int, std::vector<int>>> NKSH;


    for (int i = 2; i < 21; ++i) {
        NKH.emplace_back(i, std::vector<int>());
    }
    for (int i : {10, 100, 500, 1000}) {
        NK.emplace_back(i, std::vector<int>());
        NKH.emplace_back(i, std::vector<int>());
        for (int j = 0; j < 11; ++j) {
            NK.back().second.emplace_back(j);
        }
    }

    for (int i : {10, 100, 300, 500, 700, 1000}) {
        NKS.emplace_back(i, std::vector<int>());
    }


    for (int i = 2; i < 20; ++i) {
        NKSH.emplace_back(i, std::vector<int>());
    }
    for (int i = 20; i < 120; i += 20) {
        NKSH.emplace_back(i, std::vector<int>());
    }
    for (int i = 200; i < 1200; i += 200) {
        NKSH.emplace_back(i, std::vector<int>());
    }

    if (generate_tests) {
        test_generator::generate_tests(path, "profile", NK, test_generator::test_creation_profile);
        test_generator::generate_tests(path, "regular", NK, test_generator::test_creation_regular);
        test_generator::generate_tests(path, "sparse", NKS, test_generator::test_creation_sparse);
        if(mode == 2) {
            test_generator::generate_tests(path, "Hilbert-profile", NKH, test_generator::test_creation_Hilbert_profile);
            test_generator::generate_tests(path, "Hilbert-regular", NKH, test_generator::test_creation_Hilbert_regular);
            test_generator::generate_tests(path, "Hilbert-sparse", NKSH, test_generator::test_creation_Hilbert_sparse);
        }
    }
    std::vector<std::string> heading = {"n", "k", "||x* - x||", "||x* - x|| / ||x*||", "Average diff", "Max diff", "Iterations"};
    std::vector<std::string> sparse_heading = {"n", "Iterations", "||x* - x||", "||x* - x||/||x*||", "cond(A)", "Average diff", "Max diff"};
    logger lg(path_for_logs);

    {
        lg.set_page("LU_Profile", heading);
        runner::run_all_tests_profile(path, "profile", NK, lg);

        lg.set_page("Gauss_Regular", heading);
        runner::run_all_tests_regular(path, "regular", NK, lg)
                ;
        lg.set_page("Conjugate_Sparse", sparse_heading);
        runner::run_all_tests_sparse(path, "sparse", NKS, lg);
    }

    if(mode == 2) { // Hilbert
        heading.erase(--heading.end());
        heading[1] = "Iterations";
        lg.set_page("LU_Hilbert_Profile", heading);
        runner::run_all_tests_profile(path, "Hilbert-profile", NKH, lg);

        lg.set_page("Gauss_Hilbert_Regular", heading);
        runner::run_all_tests_regular(path, "Hilbert-regular", NKH, lg);

        lg.set_page("Conjugate_Hilbert_Sparse", sparse_heading);
        runner::run_all_tests_sparse(path, "Hilbert-sparse", NKSH, lg);
    }
    lg.close();
}

int main() {
    int count = 7;
    boost::asio::thread_pool pool(count);
    using namespace std::chrono_literals;

    for (int i = 1; i <= count; ++i) {
        boost::asio::post(pool, [i](){
          std::cout << "Start:" << i << '\n';
          long long start = time(nullptr);
          std::string path = "../../tests-files/generated-tests" + (i == 1 ? "" : std::to_string(i));
          std::string path_for_logs = "../../tests-files/log" + (i == 1 ? "" : std::to_string(i)) + ".xlsx";
          run(path, path_for_logs, true, (i == 1 ? 2 : 1));
          std::cout << time(nullptr) - start << "Sec\n";
        });
        std::this_thread::sleep_for(20ms * (13*i +i&1*17 + (i<<2) /3 * 7));
    }
    pool.join();
    file_utils::delete_temp_files("./");
}
