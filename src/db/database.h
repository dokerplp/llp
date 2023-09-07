//
// Created by dokerplp on 12/24/22.
//

#ifndef LAB1__DATABASE_H
#define LAB1__DATABASE_H
#include <utility>
#include <vector>
#include <cassert>

#include "meta.h"
#include "node.h"
#include "util.h"


struct database {
    std::string file;
    meta meta_inf;

    database(const std::string& file);

    void create();
    void open();
    void save();

    void add_node(const std::vector<std::string>& par, node node);
    void update_node(std::vector<std::string>& p, const node& node);
    node find_node(const std::vector<std::string>& p);
    void del_node(const std::vector<std::string>& p);

private:
    void del_node(int32_t pos);
    void add_meta(const std::vector<std::string>& p, int32_t pos);
    void del_meta(int32_t pos);

    void add_valid(const std::vector<std::string>& par, const node& node);
    void update_valid(const std::vector<std::string>& par, const node& node);
    void find_valid(const std::vector<std::string>& p);
    void del_valid(const std::vector<std::string>& p);

    std::vector<std::string> parent(const std::vector<std::string>& p);
    std::vector<std::string> child(const std::vector<std::string>& p, const std::string& name);
};


#endif //LAB1__DATABASE_H
