#if !defined(LIBGLOB_SANITYCHECK_H)
#define LIBGLOB_SANITYCHECK_H

#include <assert.h>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>

/// @brief 
/// # For Windows
/// 
/// Initialises the framework for socket server.
void libglob_startup();

/// @brief 
/// # For Windows
/// 
/// Clears the framework for socket server.
void libglob_done();
#else
#include <unistd.h>
#include <arpa/inet.h>

/// @brief 
/// # For Linux
/// 
/// Initialises the framework for socket server.
/// 
/// Linux needs no initialisation.
#define libglob_startup()

/// @brief 
/// # For Linux
/// 
/// Clears the framework for socket server.
/// 
/// Linux needs no end.
#define libglob_done()
#endif


#if defined(__cplusplus)
#define globlib_extern extern "C"
#else 
#define globlib_extern extern 
#endif

#endif