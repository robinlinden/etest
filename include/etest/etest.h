#pragma once

#include "etest/internal/test_macros.h"
#include "etest/internal/test_suite.h"

#include <string>

namespace etest {

inline int run_all_tests() {
    return internal::test_suite::instance()->run();
}

#define TEST(test_group_name, test_name) \
    ETEST_TEST(test_group_name, test_name)

}
