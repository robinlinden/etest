project(test_etest)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/test_arithmetic_types.cpp
    src/test_assertions.cpp
    src/test_strings.cpp
    src/test_user_defined_types.cpp
)

add_test(${PROJECT_NAME} ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME}
    PRIVATE
        cxx_std_17
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        etest::etest
)
