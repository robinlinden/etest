#include "etest/etest.h"

#include <cassert>
#include <cstdio>


namespace {

int tests_run = 0;

TEST(etest, can_have_1_test) {
    fprintf(stderr, "hello\n");
    tests_run += 1;
    return 0;
}

TEST(etest, can_have_more_than_1_test) {
    fprintf(stderr, "bye\n");
    tests_run += 10;
    return 0;
}

}

int main(int argc, char **argv) {
    const int result = etest::run_all_tests();
    assert(tests_run == 11);
    return result;
}
