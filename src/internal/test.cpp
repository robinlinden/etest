#include "etest/internal/test.h"

#include <sstream>

namespace etest {

void test::run() {
    set_up();
    test_body();
    tear_down();
}

std::string test::display_name() const {
    std::stringstream ss;
    ss << group() << "." << name();
    return ss.str();
}

}
