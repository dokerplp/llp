//
// Created by dokerplp on 12/29/22.
//

#ifndef LAB1__STRESS_TEST_H
#define LAB1__STRESS_TEST_H
#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>
#include <cassert>

#include "../src/db/attr.h"
#include "../src/db/meta.h"
#include "../src/db/node.h"
#include "../src/db/database.h"
#include "../src/db/load.h"

struct stress_test {
    std::string file = "../file.db";
    std::string big = "../big.db";

    void load(database *db, const std::string& name, size_t n);
    void empty_load_test();
    void big_load_test();

    void insert_time();
    void select_time();
    void update_time();
    void delete_time();
};


#endif //LAB1__STRESS_TEST_H
