#pragma once

#include "etest/internal/macro_magic.h"
#include "etest/internal/test.h"
#include "etest/internal/test_factory.h"
#include "etest/internal/test_info.h"
#include "etest/internal/test_suite.h"

#define ETEST_TEST(test_group_name, test_name)\
    class ETEST_CAT2(test_group_name, test_name) : public etest::internal::test {\
    public:\
        std::string name() override {\
            return std::string(ETEST_TOSTRING(ETEST_CAT2(test_group_name, test_name)));\
        }\
        void run() override;\
    };\
    \
    const etest::internal::test_info *ETEST_CAT3(test_group_name, test_name, holder) =\
        etest::internal::test_suite::instance()->add_test_info(\
            new etest::internal::test_info(\
                ETEST_TOSTRING(test_group_name),\
                ETEST_TOSTRING(test_name),\
                new etest::internal::test_factory_impl<ETEST_CAT2(test_group_name, test_name)>));\
    \
    void ETEST_CAT2(test_group_name, test_name)::run()
