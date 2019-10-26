#include "etest/etest.h"

namespace {

struct amazing {
    int a;
};

bool operator!=(const amazing& lhs, const amazing& rhs) {
    return lhs.a != rhs.a;
}

std::ostream &operator<<(std::ostream &os, const amazing& a) {
    os << "amazing[" << a.a << "]";
    return os;
}

TEST(user_defined_types, can_be_tested) {
    EXPECT_EQ(amazing{0}, amazing{0});
    EXPECT_EQ(amazing{5}, amazing{5});
}

}
