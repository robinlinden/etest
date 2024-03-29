#pragma once

#include <sstream>
#include <string>
#include <vector>

namespace etest {

class test {
public:
    virtual ~test() = default;

    virtual std::string group() const = 0;
    virtual std::string name() const = 0;
    virtual void set_up() {}
    virtual void test_body() = 0;
    virtual void tear_down() {}

    void run();
    std::string display_name() const;

    template<typename T>
    void EXPECT_TRUE(const T &lhs) {
        if (lhs) {
            return;
        }
        std::stringstream ss;
        ss << "Failed expectation in " << display_name()
            << ": " << lhs << std::endl;
        failed_expectations.push_back(ss.str());
    }

    template<typename T>
    void EXPECT_FALSE(const T &lhs) {
        if (!lhs) {
            return;
        }
        std::stringstream ss;
        ss << "Failed expectation in " << display_name()
            << ": !" << lhs << std::endl;
        failed_expectations.push_back(ss.str());
    }

    template<typename T, typename U>
    void EXPECT_EQ(const T &lhs, const U &rhs) {
        if (lhs == rhs) {
            return;
        }
        std::stringstream ss;
        ss << "Failed expectation in " << display_name()
            << ": " << lhs << " == " << rhs << std::endl;
        failed_expectations.push_back(ss.str());
    }

    template<typename T, typename U>
    void EXPECT_NE(const T &lhs, const U &rhs) {
        if (lhs != rhs) {
            return;
        }
        std::stringstream ss;
        ss << "Failed expectation in " << display_name()
            << ": " << lhs << " != " << rhs << std::endl;
        failed_expectations.push_back(ss.str());
    }

    std::vector<std::string> failed_expectations;
};

}
