#pragma once

#include "etest/internal/test_macros.h"
#include "etest/internal/test_suite.h"

namespace etest {

void init_etest(int argc, char **argv);

inline int run_all_tests() {
    return internal::test_suite::instance()->run();
}

#define TEST(test_group_name, test_name) \
    ETEST_TEST(test_group_name, test_name)

}
