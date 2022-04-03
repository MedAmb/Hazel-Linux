#pragma once

#include "Log.h"

#ifdef HZ_ENABLE_ASSERTION
#define HZ_CORE_ASSERT(x, ...)                                  \
    {                                                           \
        if (!(x))                                               \
        {                                                       \
            HZ_CORE_ERROR("Assertion failed: %s", __VA_ARGS__ ); \
            __builtin_trap();                                   \
        }                                                       \
    }
#define HZ_ASSERT(x, ...)                                  \
    {                                                      \
        if (!(x))                                          \
        {                                                  \
            HZ_ERROR("Assertion failed: %s", __VA_ARGS__ ); \
            __builtin_trap();                              \
        }                                                  \
    }
#else
#define HZ_CORE_ASSERT(x, ...)
#define HZ_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)