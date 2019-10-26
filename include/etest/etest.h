#pragma once

#include <string>
#include <sstream>
#include <vector>

namespace etest {

class test {
public:
    virtual ~test() = default;

    virtual std::string name() = 0;
    virtual void run() = 0;

    template<typename T, typename U>
    void EXPECT_EQ(const T &lhs, const U &rhs) {
        if (lhs != rhs) {
            std::stringstream ss;
            ss << "Failed expectation in " << name()
                << ": " << lhs << " == " << rhs << std::endl;
            failed_expectations.push_back(ss.str());
        }
    }

    std::vector<std::string> failed_expectations;
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

#define ETEST_STRINGIFY(x) #x
#define ETEST_TOSTRING(x) ETEST_STRINGIFY(x)

#define ETEST_CAT2(start, end)\
    start##_##end

#define ETEST_CAT3(start, middle, end)\
    start##_##middle##_##end

#define TEST(test_group_name, test_name)\
    class ETEST_CAT2(test_group_name, test_name) : public etest::test {\
    public:\
        std::string name() override {\
            return std::string(\
                ETEST_TOSTRING(ETEST_CAT2(test_group_name, test_name)));\
        }\
        void run() override;\
    };\
    \
    const etest::test_info *ETEST_CAT3(test_group_name, test_name, holder) =\
        etest::test_suite::instance()->add_test_info(new etest::test_info(\
        new etest::test_factory_impl<ETEST_CAT2(test_group_name, test_name)>));\
    \
    void ETEST_CAT2(test_group_name, test_name)::run()

}
