#if !defined(GLOBLIB_THREADPOOL_H)
#define GLOBLIB_THREADPOOL_H

#include "sanitycheck.h"
#include <stdint.h>
#include <pthread.h>

/// @brief Trial of putting all thread flags on single variable.
static_assert(((uint8_t)_GLOBLIB_THREAD_COUNT) <= 0x40, "Thread Capacity Cannot be over 64.");

/// @brief
/// Predefined Threading Capacity
#define GLOBLIB_THREAD_COUNT _GLOBLIB_THREAD_COUNT

#define globlib_thread_READY 0
#define globlib_thread_OCCUPIED 1


#if _GLOBLIB_THREAD_COUNT <= 0x8

/// @brief 
/// Boolean Vector type for thread flags.
typedef uint8_t globlib_threadvec_t;

#elif _GLOBLIB_THREAD_COUNT <= 0x10

/// @brief 
/// Boolean Vector type for thread flags.
typedef uint16_t globlib_threadvec_t;

#elif _GLOBLIB_THREAD_COUNT <= 0x20

/// @brief 
/// Boolean Vector type for thread flags.
typedef uint32_t globlib_threadvec_t;

#else

/// @brief 
/// Boolean Vector type for thread flags.
typedef uint64_t globlib_threadvec_t;

#endif

/// @brief Trial of putting all thread flags on single variable.
globlib_extern globlib_threadvec_t Globlib_gThreadFlags;

#endif