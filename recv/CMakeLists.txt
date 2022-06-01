cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME RecvTest)
project(${PROJECT_NAME})

file(GLOB TARGET_SRC main.cpp)
add_executable(${PROJECT_NAME} ${TARGET_SRC})
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

find_package(cppzmq)
target_link_libraries(${PROJECT_NAME} cppzmq)
