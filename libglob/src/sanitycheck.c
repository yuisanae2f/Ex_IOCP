#include <sanitycheck.h>

#ifdef _WIN32
static WSADATA wsaData;

void libglob_startup() {
    WSAStartup(MAKEWORD(2, 2), &wsaData);
}

void libglob_done() {
    WSACleanup();
}

#endif