#pragma once

#include "etest/internal/test.h"

namespace etest::internal {

class test_factory {
public:
    virtual ~test_factory() = default;
    virtual test *make_test() const = 0;
};

template<typename T>
class test_factory_impl : public test_factory {
public:
    test *make_test() const override { return new T; }
};

}
