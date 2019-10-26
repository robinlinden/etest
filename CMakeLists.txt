cmake_minimum_required(VERSION 3.14)

project(etest)

add_library(${PROJECT_NAME}
    include/etest/etest.h
    include/etest/internal/macro_magic.h
    include/etest/internal/test.h
    include/etest/internal/test_factory.h
    include/etest/internal/test_info.h
    include/etest/internal/test_macros.h
    include/etest/internal/test_suite.h
    src/test_suite.cpp
)

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME}
    PRIVATE
        cxx_std_17
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
    PRIVATE
        src
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

enable_testing()
add_subdirectory(test)
