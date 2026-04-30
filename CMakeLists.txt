cmake_minimum_required(VERSION 3.15)

project(System_monitor CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(System_monitor
    src/main.cpp
    src/server/http_server.cpp
    src/monitor/system_stats.cpp
    src/api/api_handler.cpp
)

# Windows precisa de linkeditar winsock
if(WIN32)
    target_link_libraries(System_monitor ws2_32)
endif()