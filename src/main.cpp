#include <iostream>

#include "../test/test.h"
#include "../test/stress_test.h"

using namespace std;

int main(int argc, char** argv) {

    test t;
    t.all_tests();
    cout << endl;

    stress_test st;
    st.select_time();
    cout << endl;
    st.insert_time();
    cout << endl;
    st.update_time();
    cout << endl;
    st.delete_time();

    cout << endl;
    st.empty_load_test();
    st.big_load_test();

    return 0;
}