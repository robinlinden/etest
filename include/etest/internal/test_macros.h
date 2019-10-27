#pragma once

#include "etest/internal/macro_magic.h"
#include "etest/internal/test.h"
#include "etest/internal/test_factory.h"
#include "etest/internal/test_info.h"
#include "etest/internal/test_suite.h"

#define ETEST_INTERNAL_MAKE_TEST(group_name, test_name, base_class) \
    class ETEST_CAT2(group_name, test_name) : public base_class { \
    public: \
        std::string group() const override { \
            return std::string(ETEST_TOSTRING(group_name)); \
        } \
        std::string name() const override { \
            return std::string(ETEST_TOSTRING(test_name)); \
        } \
        void test_body() override; \
    }; \
    const etest::internal::test_info *ETEST_CAT3(group_name, test_name, holder) = \
        etest::internal::test_suite::instance()->add_test_info( \
            new etest::internal::test_info( \
                ETEST_TOSTRING(group_name), \
                ETEST_TOSTRING(test_name), \
                new etest::internal::test_factory_impl<ETEST_CAT2(group_name, test_name)>)); \
    void ETEST_CAT2(group_name, test_name)::test_body()

#define ETEST_TEST(test_group_name, test_name) \
    ETEST_INTERNAL_MAKE_TEST(test_group_name, test_name, etest::test)

#define ETEST_TEST_F(fixture, test_name) \
    ETEST_INTERNAL_MAKE_TEST(fixture, test_name, fixture)
