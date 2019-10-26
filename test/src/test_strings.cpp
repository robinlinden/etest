#include "etest/etest.h"

#include <string>

namespace {

TEST(strings, can_be_tested) {
    EXPECT_EQ("hello", "hello");
    EXPECT_EQ(std::string("bye"), std::string("bye"));
}

}
