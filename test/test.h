//
// Created by dokerplp on 12/29/22.
//

#ifndef LAB1__TEST_H
#define LAB1__TEST_H
#include <iostream>
#include <cassert>

#include "../src/db/attr.h"
#include "../src/db/meta.h"
#include "../src/db/node.h"
#include "../src/db/database.h"

struct test {

    std::string file = "../file.db";

    void all_tests();
    void add_test();
    void del_test();
    void child_test();
    void update_test();

};


#endif //LAB1__TEST_H
