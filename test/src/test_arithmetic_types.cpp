#include "etest/etest.h"

namespace {

TEST(arithmetic_types, can_be_tested) {
    int i = 0;

    EXPECT_EQ(i, 0);
    EXPECT_EQ(i, 0);

    i += 5;

    EXPECT_EQ(i, 5);
    EXPECT_EQ(0.f, 0.0);
    EXPECT_EQ(50, 10 * 5);

    EXPECT_EQ(100, 100.f);

    double j = 10;

    EXPECT_EQ(i + 5, j);
}

}
