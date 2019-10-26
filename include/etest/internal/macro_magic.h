#pragma once

#define ETEST_STRINGIFY(x) #x
#define ETEST_TOSTRING(x) ETEST_STRINGIFY(x)

#define ETEST_CAT2(start, end)\
    start##_##end

#define ETEST_CAT3(start, middle, end)\
    start##_##middle##_##end
