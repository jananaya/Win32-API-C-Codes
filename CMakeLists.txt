cmake_minimum_required(VERSION 3.18)

project(WIN_API_PROJECT LANGUAGES C)

include_directories("include")

add_executable(
    ${PROJECT_NAME} 
    WIN32 "src/winMain.c" 
    "${CMAKE_CURRENT_SOURCE_DIR}/resources/Menu.rc"
    )
