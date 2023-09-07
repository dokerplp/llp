//
// Created by dokerplp on 12/27/22.
//

#ifndef LAB1__UTIL_H
#define LAB1__UTIL_H
#include <fstream>
#include <iostream>
#include <vector>
#include <cassert>

#define KB4 4 * 1024
#define META 256 * 1024 * 1024
#define BOI std::ios::binary | std::ios::out | std::ios::in
#define BIN std::ios::binary

std::string path(const std::vector<std::string>& path);

#endif //LAB1__UTIL_H
