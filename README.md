# etest

## Description

Small and reasonable test framework.

## Building

Clone!

`git clone https://github.com/robinlinden/etest.git`

Build!

```sh
mkdir build && cd build
cmake ..
make
make test
```

## Including in your project

CMakeLists.txt
```cmake
include(FetchContent)

FetchContent_Declare(ETest
    GIT_REPOSITORY https://github.com/robinlinden/etest.git
)
FetchContent_MakeAvailable(ETest)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        etest::etest
)
```

my_test.cpp
```cpp
#include <etest/etest.h>

#include <iostream>
#include <string>

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

TEST(etest_example, things_seem_to_work) {
    EXPECT_EQ(amazing{0}, amazing{0});
    EXPECT_EQ(amazing{5}, amazing{5});
}

TEST(etest_example, ints_also_work) {
    EXPECT_EQ(10, 5 * 2);
}

TEST(etest_example, same_with_strings) {
    EXPECT_EQ(std::string("beep beep boop"), std::string("beep beep boop"));
}

} // namespace

int main(int argc, char **argv) {
    etest::init_etest(argc, argv);
    return etest::run_all_tests();
}
```
