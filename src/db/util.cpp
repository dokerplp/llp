//
// Created by dokerplp on 12/27/22.
//

#include "util.h"

std::string path(const std::vector<std::string>& path) {
    std::string ret;
    for (const std::string& s : path) {
        ret += "/";
        ret += s;
    }
    return ret;
}