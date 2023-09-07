//
// Created by dokerplp on 12/29/22.
//

#include "stress_test.h"

void stress_test::load(database *db, const std::string& name, size_t n) {
    node node("");
    for (int i = 0; i < n; i++) {
        node.name = name + std::to_string(i);
        db->add_node(std::vector<std::string> {"root"}, node);
    }
}

void stress_test::empty_load_test() {
    database db(file);
    db.create();

    time_t begin, end;
    time(&begin);
    load(&db, "node", 100000);
    time(&end);

    db.save();

    std::cout << "Empty db add 100000 nodes time " << end - begin << "s" << std::endl;
}

void stress_test::big_load_test() {
    fast_load(file, 1000000);
    database db(file);
    db.open();

    time_t begin, end;
    time(&begin);
    load(&db, "node", 100000);
    time(&end);

    db.save();

    std::cout << "Big db add 100000 nodes time " << end - begin << "s"<< std::endl;
}

void stress_test::insert_time() {
    std::cout << "insert time" << std::endl;
    for (int i = 1; i < 21; i++) {
        database db(file);
        db.create();

        load(&db, "node", 1000 * i);
        db.save();

        auto start_time = std::chrono::high_resolution_clock::now();

        load(&db, "test", 1000);

        auto end_time = std::chrono::high_resolution_clock::now();
        auto time = end_time - start_time;


        std::cout << 1000 * i << ";" << time/std::chrono::milliseconds(1) << ";" << std::endl;
    }
}

void stress_test::select_time() {
    std::cout << "select time" << std::endl;
    for (int i = 1; i < 21; i++) {
        database db(file);
        db.create();

        load(&db, "node", 1000 * i);
        db.save();

        auto start_time = std::chrono::high_resolution_clock::now();

        for (int j = 0; j < 1000; j++) {
            auto path = std::vector<std::string> {"root", "node" + std::to_string(j)};
            node n = db.find_node(path);
        }

        auto end_time = std::chrono::high_resolution_clock::now();
        auto time = end_time - start_time;


        std::cout << 1000 * i << ";" << time/std::chrono::milliseconds(1) << ";" << std::endl;
    }
}

void stress_test::update_time() {
    std::cout << "update time" << std::endl;
    for (int i = 1; i < 21; i++) {
        database db(file);
        db.create();

        load(&db, "node", 1000 * i);
        db.save();

        auto start_time = std::chrono::high_resolution_clock::now();

        for (int j = 0; j < 1000; j++) {
            node n("test" + std::to_string(j));
            auto path = std::vector<std::string> {"root", "node" + std::to_string(j)};
            db.update_node(path, n);
        }

        auto end_time = std::chrono::high_resolution_clock::now();
        auto time = end_time - start_time;


        std::cout << 1000 * i << ";" << time/std::chrono::milliseconds(1) << ";" << std::endl;
    }
}

void stress_test::delete_time() {
    std::cout << "delete time" << std::endl;
    for (int i = 1; i < 21; i++) {
        database db(file);
        db.create();

        load(&db, "node", 1000 * i);
        db.save();

        auto start_time = std::chrono::high_resolution_clock::now();

        for (int j = 0; j < 1000; j++) {
            auto path = std::vector<std::string> {"root", "node" + std::to_string(j)};
            db.del_node(path);
        }

        auto end_time = std::chrono::high_resolution_clock::now();
        auto time = end_time - start_time;


        std::cout << 1000 * i << ";" << time/std::chrono::milliseconds(1) << ";" << std::endl;
    }
}