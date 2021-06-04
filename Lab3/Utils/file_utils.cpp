//
// Created by NelosG.
//
#include <file_utils.h>
std::fstream file_utils::open_file(const std::string &filename, bool add) {
    std::filesystem::path p(filename);
    p = proximate(p);
    std::filesystem::create_directories(p.parent_path());

    std::fstream fstr;
    if (add && std::filesystem::exists(p)) {
        fstr.open(p, std::ios_base::out | std::ios_base::in | std::ios_base::app);
    } else {
        fstr.open(p, std::ios_base::out | std::ios_base::in | std::ios_base::trunc);
    }
    return fstr;
}

void file_utils::reset(std::fstream &fstr) {
    fstr.seekg(0);
}

void file_utils::to_end(std::fstream &fstr) {
    fstr.seekg(fstr.width() - 1);
}

bool file_utils::delete_file(const std::string &filename) {
    std::filesystem::path p(filename);
    p = proximate(p);
    return std::filesystem::remove(p);
}

bool file_utils::delete_file(const std::string &filename, int count_parent_dirs_for_delete) {
    std::filesystem::path p(filename);
    p = proximate(p);
    std::filesystem::path prev("../");
    for (int i = 0; i < count_parent_dirs_for_delete; ++i) {
        if (p.parent_path().empty() || equivalent(p.parent_path(), prev)) {
            break;
        }
        p = p.parent_path();
    }
    return std::filesystem::remove_all(p);
}
