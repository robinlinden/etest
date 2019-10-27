#include "etest/etest.h"

#include <string>

namespace {

class strings_fixture : public etest::test {
public:
    void set_up() override {
        b = new std::string("trainspotting");
    }

    void tear_down() override {
        delete b;
    }

    std::string a{"trainspotting"};
    std::string *b;
};

TEST(strings, can_be_tested) {
    EXPECT_EQ("hello", "hello");
    EXPECT_EQ(std::string("bye"), std::string("bye"));
}

TEST_F(strings_fixture, seems_to_work) {
    EXPECT_EQ(a, *b);
}

}
