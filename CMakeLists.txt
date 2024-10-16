cmake_minimum_required(VERSION 3.10)

project(Ex_IOCP)

file(GLOB_RECURSE CLIENT
    "client/*.c"
    "client/*.h"
)

file(GLOB_RECURSE SERVER
    "server/*.c"
    "server/*.h"
)

add_executable(${PROJECT_NAME}_CLIENT ${CLIENT})
add_executable(${PROJECT_NAME}_SERVER ${SERVER})

add_dependencies(${PROJECT_NAME}_CLIENT ${PROJECT_NAME}_SERVER)