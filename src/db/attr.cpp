//
// Created by dokerplp on 12/24/22.
//

#include "attr.h"


attr::attr(){};

attr::attr(const int32_t v) {
    this->tag = INT;
    this->int_val = v;
}

attr::attr(const bool v) {
    this->tag = BOOL;
    this->bool_val = v;
}

attr::attr(const float v) {
    this->tag = FLOAT;
    this->float_val = v;
}

attr::attr(const char* v) {
    this->tag = STRING;
    this->string_val = v;
}

attr::type attr::get_type() {
    return tag;
}
int32_t attr::get_int() {
    return int_val;
}
bool attr::get_bool() {
    return bool_val;
}
float attr::get_float() {
    return float_val;
}
std::string attr::get_string() {
    return string_val;
}