#pragma once

#include <sstream>
#include <string>
#include <vector>

namespace etest::internal {

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

}
