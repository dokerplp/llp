//
// Created by dokerplp on 12/24/22.
//

#ifndef LAB1__META_H
#define LAB1__META_H
#include <fstream>
#include <iostream>
#include <cinttypes>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cassert>

#include <cereal/archives/binary.hpp>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/unordered_set.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>

#include "util.h"

struct meta {
    int32_t count = 0;
    std::unordered_map<int32_t, std::unordered_set<int32_t>> children;
    std::unordered_map<std::string, int32_t> position;
    std::unordered_map<int32_t, std::string> path;
    std::vector<int32_t> free;

    meta();

    void serialize(const std::string& file, std::ios::openmode mode);
    void deserialize(const std::string& file);
};


#endif //LAB1__META_H
