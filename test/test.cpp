//
// Created by dokerplp on 12/29/22.
//

#include "test.h"

void test::all_tests() {
    add_test();
    del_test();
    child_test();
    update_test();
}

void test::add_test() {
    std::cout << "ADD TEST STARTED" << std::endl;

    database db(file);
    db.create();

    node n("test");
    n.add("int", 4324);
    n.add("bool", false);
    n.add("float", 53453.4534f);
    n.add("string", "hello world!");
    n.add("string2", "goodbye world!");

    db.add_node(std::vector<std::string> {"root"}, n);

    auto p = std::vector<std::string> {"root", "test"};
    node nn = db.find_node(p);
    assert(nn.attrs["int"].get_int() == 4324);
    assert(nn.attrs["bool"].get_bool() == false);
    assert(nn.attrs["float"].get_float() == 53453.4534f);
    assert(nn.attrs["string"].get_string() == "hello world!");
    assert(nn.attrs["string2"].get_string() == "goodbye world!");

    assert(db.meta_inf.count == 1);
    assert(db.meta_inf.children.find(nn.id) != db.meta_inf.children.end());
    assert(db.meta_inf.path.find(nn.id) != db.meta_inf.path.end());
    assert(db.meta_inf.position.find(path(p)) != db.meta_inf.position.end());

    std::cout << "ADD TEST SUCCEEDED" << std::endl;
}

void test::del_test() {
    std::cout << "DEL TEST STARTED" << std::endl;

    database db(file);
    db.create();

    node n("test");
    n.add("int", 4324);
    n.add("bool", false);
    n.add("float", 53453.4534f);
    n.add("string", "hello world!");
    n.add("string2", "goodbye world!");

    db.add_node(std::vector<std::string> {"root"}, n);
    auto p = std::vector<std::string> {"root", "test"};
    node nn = db.find_node(p);
    db.del_node(p);

    assert(db.meta_inf.count == 0);
    assert(db.meta_inf.children.find(nn.id) == db.meta_inf.children.end());
    assert(db.meta_inf.path.find(nn.id) == db.meta_inf.path.end());
    assert(db.meta_inf.position.find(path(p)) == db.meta_inf.position.end());
    assert(db.meta_inf.free[0] == nn.id);

    std::cout << "DEL TEST SUCCEEDED" << std::endl;
}

void test::child_test() {
    std::cout << "CHILD ADD TEST STARTED" << std::endl;

    database db(file);
    db.create();

    node n1("n1");
    node n2("n2");
    node n3("n3");
    node n4("n4");
    node n5("n5");

    db.add_node(std::vector<std::string> {"root"}, n1);
    db.add_node(std::vector<std::string> {"root", "n1"}, n2);
    db.add_node(std::vector<std::string> {"root", "n1"}, n3);
    db.add_node(std::vector<std::string> {"root", "n1", "n3"}, n4);
    db.add_node(std::vector<std::string> {"root"}, n5);

    node nn1 = db.find_node(std::vector<std::string> {"root", "n1"});
    node nn2 = db.find_node(std::vector<std::string> {"root", "n1", "n2"});
    node nn3 = db.find_node(std::vector<std::string> {"root", "n1", "n3"});
    node nn4 = db.find_node(std::vector<std::string> {"root", "n1", "n3", "n4"});
    node nn5 = db.find_node(std::vector<std::string> {"root", "n5"});

    assert(db.meta_inf.count == 5);
    assert(db.meta_inf.children[0].find(nn1.id) != db.meta_inf.children[0].end());
    assert(db.meta_inf.children[nn1.id].find(nn2.id) != db.meta_inf.children[nn1.id].end());
    assert(db.meta_inf.children[nn1.id].find(nn3.id) != db.meta_inf.children[nn1.id].end());
    assert(db.meta_inf.children[nn3.id].find(nn4.id) != db.meta_inf.children[nn3.id].end());
    assert(db.meta_inf.children[0].find(nn5.id) != db.meta_inf.children[0].end());

    db.del_node(std::vector<std::string> {"root", "n1"});
    auto free = db.meta_inf.free;
    assert(free[0] == nn1.id);
    assert(free[1] == nn2.id);
    assert(free[2] == nn3.id);
    assert(free[3] == nn4.id);
    assert(db.meta_inf.path.size() == 2);
    assert(db.meta_inf.position.size() == 2);

    std::cout << "CHILD ADD TEST SUCCEEDED" << std::endl;
}

void test::update_test() {
    std::cout << "UPDATE TEST STARTED" << std::endl;

    database db(file);
    db.create();

    node n("test");
    n.add("int", 4324);
    n.add("bool", false);
    n.add("float", 53453.4534f);
    n.add("string", "hello world!");
    n.add("string2", "goodbye world!");

    db.add_node(std::vector<std::string> {"root"}, n);

    node nn("aboba");
    nn.add("int", "one");
    nn.add("bool", 12);
    nn.add("float", true);
    nn.add("string", "new string");

    auto p = std::vector<std::string> {"root", "test"};
    db.update_node(p, nn);

    auto pp = std::vector<std::string> {"root", "aboba"};
    node nnn = db.find_node(pp);

    assert(nnn.attrs["int"].get_type() == attr::STRING);
    assert(nnn.attrs["bool"].get_type() == attr::INT);
    assert(nnn.attrs["float"].get_type() == attr::BOOL);
    assert(nnn.attrs["string"].get_type() == attr::STRING);
    assert(nnn.attrs.find("string2") == nnn.attrs.end());

    assert(nnn.attrs["int"].get_string() == "one");
    assert(nnn.attrs["bool"].get_int() == 12);
    assert(nnn.attrs["float"].get_bool() == true);
    assert(nnn.attrs["string"].get_string() == "new string");

    std::cout << "UPDATE TEST SUCCEEDED" << std::endl;
}