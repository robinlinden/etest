#include "etest/internal/test.h"

#include <sstream>

namespace etest::internal {

std::string test::display_name() const {
    std::stringstream ss;
    ss << group() << "." << name();
    return ss.str();
}

}
