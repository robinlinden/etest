#include "etest/etest.h"

#include <iostream>
#include <memory>

namespace etest {

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
    for (const auto &info : info_) {
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

const test_info *test_suite::add_test_info(test_info *info) {
    info_.push_back(info);
    return info;
}

}
