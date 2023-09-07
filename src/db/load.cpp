//
// Created by dokerplp on 12/29/22.
//

#include "load.h"

void fast_load(const std::string& file, size_t n) {
    database db(file);
    db.create();

    std::ofstream fout(file, BOI);
    cereal::BinaryOutputArchive obin(fout);

    for (size_t i = 0; i < n; i++) {
        fout.seekp(META + KB4 * i);
        std::string name = "load" + std::to_string(i);

        obin(++db.meta_inf.count);
        obin(name);
        obin(std::unordered_map<std::string, attr>());

        db.meta_inf.children[0].insert(i + 1);
        db.meta_inf.position[name] = i + 1;
        db.meta_inf.path[i + 1] = name;
    }

    fout.seekp(0);
    obin(db.meta_inf.count);
    obin(db.meta_inf.children);
    obin(db.meta_inf.free);
    obin(db.meta_inf.position);
    obin(db.meta_inf.path);

    fout.close();
}
