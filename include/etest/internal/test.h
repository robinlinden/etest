#pragma once

#include <sstream>
#include <string>
#include <vector>

namespace etest::internal {

class test {
public:
    virtual ~test() = default;

    virtual std::string group() const = 0;
    virtual std::string name() const = 0;
    virtual void run() = 0;

    std::string display_name() const;

    template<typename T, typename U>
    void EXPECT_EQ(const T &lhs, const U &rhs) {
        if (lhs != rhs) {
            std::stringstream ss;
            ss << "Failed expectation in " << display_name()
                << ": " << lhs << " == " << rhs << std::endl;
            failed_expectations.push_back(ss.str());
        }
    }

    std::vector<std::string> failed_expectations;
};

}
