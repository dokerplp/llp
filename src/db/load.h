//
// Created by dokerplp on 12/29/22.
//

#ifndef LAB1__LOAD_H
#define LAB1__LOAD_H
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

#include "database.h"
#include "attr.h"

void fast_load(const std::string& file, size_t n);



#endif //LAB1__LOAD_H
