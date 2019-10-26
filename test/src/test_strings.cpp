#include "etest/etest.h"

#include <string>

TEST(strings, can_be_tested) {
    EXPECT_EQ(std::string("hello"), std::string("bye"));
    EXPECT_EQ("hello", "hella");
}
