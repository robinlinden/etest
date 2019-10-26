#include "etest/internal/test_info.h"

#include <sstream>

namespace etest::internal {

std::string test_info::get_display_name() const {
    std::stringstream ss;
    ss << group << "." << name;
    return ss.str();
}

}
