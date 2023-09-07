//
// Created by dokerplp on 12/24/22.
//

#ifndef LAB1__NODE_H
#define LAB1__NODE_H
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
#include "attr.h"

struct node {
    int32_t id{};
    std::string name;
    std::unordered_map<std::string, attr> attrs;

    node();
    explicit node(const std::string& name);
    void add(const std::string& key, const attr& value);

    void serialize(const std::string& file, int32_t pos);
    void deserialize(const std::string& file, int32_t pos);
};


#endif //LAB1__NODE_H
