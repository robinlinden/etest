#pragma once

#include "etest/internal/test_factory.h"

namespace etest::internal {

struct test_info {
    test_info(test_factory *f) : factory(f) {}
    test_factory *const factory;
};

}
