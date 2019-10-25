#pragma once

#include <vector>

namespace etest {

class test {
public:
    virtual ~test() = default;
    virtual int run() = 0;
};

class test_factory {
public:
    virtual ~test_factory() = default;
    virtual test *make_test() const = 0;
};

struct test_info {
    test_info(test_factory *f) : factory(f) {}
    test_factory *const factory;
};

class test_suite {
public:
    static test_suite *instance();

    int run();
    const test_info *add_test_info(test_info *info);

private:
    test_suite() = default;
    ~test_suite();

    std::vector<test_info *> info_;
};

inline int run_all_tests() {
    return test_suite::instance()->run();
}

template<typename T>
class test_factory_impl : public test_factory {
public:
    test *make_test() const override { return new T; }
};

#define ETEST_CAT2(start, end)\
  start##_##end

#define ETEST_CAT3(start, middle, end)\
  start##_##middle##_##end

#define TEST(test_group_name, test_name)\
    class ETEST_CAT2(test_group_name, test_name) : public etest::test {\
    public:\
        int run() override;\
    };\
    \
    const etest::test_info *ETEST_CAT3(test_group_name, test_name, holder) =\
        etest::test_suite::instance()->add_test_info(new etest::test_info(\
        new etest::test_factory_impl<ETEST_CAT2(test_group_name, test_name)>));\
    \
    int ETEST_CAT2(test_group_name, test_name)::run()

}
