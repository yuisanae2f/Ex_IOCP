cmake_minimum_required(VERSION 3.12)

project(Ex_IOCP)

include_directories(client/include)
include_directories(server/include)
include_directories(libglob/include)

add_compile_definitions(-D_GLOBLIB_THREAD_COUNT=30)

file(GLOB_RECURSE GLOBLIB
    "libglob/*.c"
    "libglob/*.h"
)

file(GLOB_RECURSE CLIENT
    "client/*.c"
    "client/*.h"
)

file(GLOB_RECURSE SERVER
    "server/*.c"
    "server/*.h"
)

add_library(${PROJECT_NAME}_LIB ${GLOBLIB})
add_executable(${PROJECT_NAME}_CLIENT ${CLIENT})
add_executable(${PROJECT_NAME}_SERVER ${SERVER})

link_libraries(${PROJECT_NAME}_LIB)
add_dependencies(${PROJECT_NAME}_CLIENT ${PROJECT_NAME}_SERVER)