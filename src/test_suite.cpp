#include "etest/internal/test_suite.h"

#include <iostream>
#include <memory>
#include <regex>

namespace etest::internal {

test_suite *test_suite::instance() {
    static test_suite suite;
    return &suite;
}

test_suite::~test_suite() {
    for (auto *info : info_) {
        delete info;
    }
}

int test_suite::run() {
    std::vector<std::string> errors;
    for (const auto *info : get_active_tests()) {
        std::unique_ptr<test> t{info->factory->make_test()};
        t->run();
        if (t->failed_expectations.size() != 0) {
            errors.reserve(errors.size() + t->failed_expectations.size());
            errors.insert(
                errors.end(),
                t->failed_expectations.begin(),
                t->failed_expectations.end());
        }
    }

    for (const auto &error : errors) {
        std::cerr << error;
    }

    return errors.empty() ? 0 : 1;
}

void test_suite::filter_tests(const std::string &active_pattern) {
    active_pattern_ = active_pattern;
}

std::vector<std::string> test_suite::list_tests() const {
    std::vector<std::string> tests_names;
    for (const auto *info : get_active_tests()) {
        tests_names.push_back(info->get_display_name());
    }

    return tests_names;
}

const test_info *test_suite::add_test_info(test_info *info) {
    info_.push_back(info);
    return info;
}

std::vector<test_info *> test_suite::get_active_tests() const {
    const auto pattern = std::basic_regex(active_pattern_);
    std::vector<test_info *> active_tests;

    for (auto *info : info_) {
        if (std::regex_match(info->get_display_name(), pattern)) {
            active_tests.push_back(info);
        }
    }

    return active_tests;
}

}
