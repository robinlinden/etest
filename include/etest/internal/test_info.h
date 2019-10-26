#pragma once

#include "etest/internal/test_factory.h"

#include <string>

namespace etest::internal {

struct test_info {
    test_info(
            const std::string &_group,
            const std::string &_name,
            const test_factory *f)
        : group(_group), name(_name), factory(f) {}
    const std::string group;
    const std::string name;
    const test_factory *const factory;

    std::string get_display_name() const;
};

}
