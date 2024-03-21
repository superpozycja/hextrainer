cmake_minimum_required(VERSION 3.7...3.28)
project(
    hextrainer
    VERSION 0.1
    DESCRIPTION "hex quick maths trainer impress ur friends"
    LANGUAGES C
    )


file(GLOB SOURCES src/*.c)
add_executable(${PROJECT_NAME} ${SOURCES})

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

target_include_directories(
    ${PROJECT_NAME} 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
