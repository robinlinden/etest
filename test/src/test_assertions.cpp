#include "etest/etest.h"

namespace {

TEST(basic_assertions, work) {
    EXPECT_TRUE(1);
    EXPECT_TRUE(true);
    EXPECT_TRUE("a");

    EXPECT_FALSE(!1);
    EXPECT_FALSE(!true);
    EXPECT_FALSE(!"a");
}

TEST(binary_comparisons, work) {
    EXPECT_EQ(1, 1);
    EXPECT_EQ(true, true);
    EXPECT_EQ("a", "a");

    EXPECT_NE(1, !1);
    EXPECT_NE(true, !true);
    EXPECT_NE("a", "aa");
}

}
