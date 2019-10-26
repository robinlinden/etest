#include "etest/etest.h"

namespace {

TEST(etest, can_have_1_test) {
    int i = 0;

    EXPECT_EQ(i, 0);
    EXPECT_EQ(i, 0);

    i += 5;

    EXPECT_EQ(i, 5);
    EXPECT_EQ(0.f, 0.0);
    EXPECT_EQ(50, 10 * 5);

    EXPECT_EQ(5, 100.f);
}

TEST(etest, can_have_more_than_1_test) {
    EXPECT_EQ(1, 2);
    EXPECT_EQ(2.0, 3.0);

    EXPECT_EQ(std::string("hello"), std::string("bye"));
    EXPECT_EQ("hello", "hella");
}

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

TEST(etest, can_have_more_than_2_tests) {
    EXPECT_EQ(amazing{0}, amazing{0});
    EXPECT_EQ(amazing{0}, amazing{1});
}

}

int main(int argc, char **argv) {
    return etest::run_all_tests();
}
