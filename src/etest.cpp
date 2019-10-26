#include "etest/etest.h"

#include <iostream>
#include <string>
#include <vector>

namespace etest {

void init_etest(int argc, char **argv) {
    std::vector<std::string> flags;
    for (int i = 1; i < argc; ++i) {
        flags.push_back(argv[i]);
    }

    for (const auto &flag : flags) {
        if (flag == std::string("--list")) {
            const auto test_names = internal::test_suite::instance()->list_tests();
            for (const auto &name : test_names) {
                std::cout << name << std::endl;
            }

            exit(0);
        }
    }
}

}
