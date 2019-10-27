#pragma once

#include "etest/internal/test_info.h"

#include <vector>

namespace etest::internal {

class test_suite {
public:
    static test_suite *instance();

    int run();
    void filter_tests(const std::string &active_pattern);
    std::vector<std::string> list_tests() const;

    const test_info *add_test_info(test_info *info);

private:
    test_suite() = default;
    ~test_suite();

    std::vector<test_info *> get_active_tests() const;

    std::string active_pattern_{".*"};
    std::vector<test_info *> info_;
};

}
