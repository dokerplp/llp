//
// Created by dokerplp on 12/24/22.
//

#include "node.h"

node::node() {}

node::node(const std::string& name) {
    this->name = name;
}

void node::add(const std::string& key, const attr& value) {
    this->attrs[key] = value;
}

void node::serialize(const std::string& file, int32_t pos) {
    std::ofstream fout(file, BOI);
    fout.seekp(META + KB4 * pos);
    cereal::BinaryOutputArchive obin(fout);

    size_t start = fout.tellp();
    obin(id);
    obin(name);
    obin(attrs);
    size_t end = fout.tellp();

    assert(end - start <= KB4);

    fout.close();
}

void node::deserialize(const std::string& file, int32_t pos) {
    std::ifstream fin(file, BOI);
    fin.seekg(META + KB4 * pos);
    cereal::BinaryInputArchive ibin(fin);

    size_t start = fin.tellg();
    ibin(id);
    ibin(name);
    ibin(attrs);
    size_t end = fin.tellg();

    assert(end - start <= KB4);

    fin.close();
}
