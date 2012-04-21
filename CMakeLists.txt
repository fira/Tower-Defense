cmake_minimum_required(VERSION 2.8)
project(Tower-Defense)
file(
    GLOB_RECURSE
    source_files
    src/*
)

link_libraries(
   ${SDL_LIBRARY}
   ${SDLIMAGE_LIBRARY}
   SDLmain
)

add_executable(
    ../src/towerdefense
    ${source_files}
)

Find_Package(SDL REQUIRED)
Find_Package(SDL_image REQUIRED)
Find_Package(SDL_ttf REQUIRED)

set(CMAKE_C_FLAGS "-O0 -g -Wall -std=c99")
