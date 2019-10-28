#include "etest/etest.h"

#include "etest/internal/test_suite.h"

#include <iostream>
#include <string>
#include <vector>

namespace etest {

void init_etest(int argc, char **argv) {
    std::vector<std::string> flags;
    for (int i = 1; i < argc; ++i) {
        flags.push_back(argv[i]);
    }

    // We find and set the filter before the other flags so things like --list
    // are definitely filtered.
    bool found_filter = false;
    for (const auto &flag : flags) {
        if (flag == std::string("--filter")) {
            found_filter = true;
            continue;
        }

        if (found_filter) {
            internal::test_suite::instance()->filter_tests(flag);
            break;
        }
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

int run_all_tests() {
    return internal::test_suite::instance()->run();
}

}
