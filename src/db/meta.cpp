//
// Created by dokerplp on 12/24/22.
//

#include "meta.h"

meta::meta() {
    this->count = 0;
    this->children = std::unordered_map<int32_t, std::unordered_set<int32_t>>();
    this->free = std::vector<int32_t>();
    this->position = std::unordered_map<std::string, int32_t>();
    this->path = std::unordered_map<int32_t, std::string>();
    children[0] = std::unordered_set<int32_t>();
    position["/root"] = 0;
    path[0] = "/root";
}

void meta::serialize(const std::string &file, std::ios::openmode mode) {
    std::ofstream fout(file, mode);
    fout.seekp(0);
    cereal::BinaryOutputArchive obin(fout);

    size_t start = fout.tellp();
    obin(count);
    obin(children);
    obin(free);
    obin(position);
    obin(path);
    size_t end = fout.tellp();

    assert(end - start <= META);

    fout.close();
}

void meta::deserialize(const std::string &file) {
    std::ifstream fin(file, BOI);
    fin.seekg(0);
    cereal::BinaryInputArchive ibin(fin);

    size_t start = fin.tellg();
    ibin(count);
    ibin(children);
    ibin(free);
    ibin(position);
    ibin(path);
    size_t end = fin.tellg();

    assert(end - start <= META);

    fin.close();
}