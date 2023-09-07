//
// Created by dokerplp on 12/24/22.
//

#include "database.h"

database::database(const std::string& file) {
    this->file = file;
}

void database::create() {
    meta_inf.serialize(file, BIN);
}

void database::open() {
    meta_inf.deserialize(file);
}

void database::save() {
    meta_inf.serialize(file, BOI);
}

void database::add_meta(const std::vector<std::string>& p, int32_t pos) {
    std::string key = path(p);
    meta_inf.position[key] = pos;
    meta_inf.path[pos] = key;
    int32_t par = meta_inf.position[path(parent(p))];
    meta_inf.children[par].insert(pos);
    meta_inf.children[pos] = std::unordered_set<int32_t>();
}

void database::add_valid(const std::vector<std::string>& par, const node& node) {
    assert(!par.empty());
    assert(meta_inf.position.find(path(par)) != meta_inf.position.end());
    assert(meta_inf.position.find(path(child(par, node.name))) == meta_inf.position.end());
}

void database::add_node(const std::vector<std::string>& parent, node node) {
    add_valid(parent, node);

    node.id = ++meta_inf.count;
    if (!meta_inf.free.empty()) {
        node.id = meta_inf.free.back();
        meta_inf.free.pop_back();
    }

    node.serialize(file, node.id);
    add_meta(child(parent, node.name), node.id);
}

void database::find_valid(const std::vector<std::string>& p) {
    assert(p.size() > 1);
    assert(meta_inf.position.find(path(p)) != meta_inf.position.end());
}

node database::find_node(const std::vector<std::string>& p) {
    find_valid(p);

    node n;
    n.deserialize(file, meta_inf.position[path(p)]);
    return n;
}

void database::del_meta(int32_t pos) {
    meta_inf.count--;
    meta_inf.free.push_back(pos);
    meta_inf.children.erase(pos);
    meta_inf.position.erase(meta_inf.path[pos]);
    meta_inf.path.erase(pos);
}

void database::del_node(int32_t pos) {
    std::ofstream fout(file, BOI);
    cereal::BinaryOutputArchive obin(fout);

    std::vector<int32_t> v;
    v.push_back(pos);
    while (!v.empty()) {
        int32_t cur = v.back();
        v.pop_back();
        fout.seekp(META + KB4 * cur, fout.beg);

        for (int32_t c: meta_inf.children[cur]) v.push_back(c);
        del_meta(cur);
    }
    fout.close();
}

void database::del_valid(const std::vector<std::string>& p) {
    assert(p.size() > 1);
    assert(meta_inf.position.find(path(p)) != meta_inf.position.end());
}

void database::del_node(const std::vector<std::string>& p) {
    del_valid(p);

    int32_t pos = meta_inf.position[path(p)];
    int32_t par = meta_inf.position[path(parent(p))];
    meta_inf.children[par].erase(pos);

    del_node(pos);
}

void database::update_valid(const std::vector<std::string>& p, const node& node) {
    assert(p.size() > 1);
    assert(meta_inf.position.find(path(p)) != meta_inf.position.end());
}

void database::update_node(std::vector<std::string>& p, const node& node) {
    update_valid(p, node);

    del_node(p);
    p.pop_back();
    add_node(p, node);
}

std::vector<std::string> database::parent(const std::vector<std::string>& p) {
    std::vector<std::string> parent_path = p;
    parent_path.pop_back();
    return parent_path;
}

std::vector<std::string> database::child(const std::vector<std::string>& p, const std::string& name) {
    std::vector<std::string> new_path = p;
    new_path.emplace_back(name);
    return new_path;
}

