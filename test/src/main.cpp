#include "etest/etest.h"

int main(int argc, char **argv) {
    etest::init_etest(argc, argv);
    return etest::run_all_tests();
}
