#pragma once

#include "etest/test.h"
#include "etest/internal/test_macros.h"

namespace etest {

void init_etest(int argc, char **argv);
int run_all_tests();

#define TEST(test_group_name, test_name) \
    ETEST_TEST(test_group_name, test_name)

#define TEST_F(fixture_name, test_name) \
    ETEST_TEST_F(fixture_name, test_name)

}
