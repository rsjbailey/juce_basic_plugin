cmake_minimum_required(VERSION 3.22)
project(plugin_example VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS FALSE)

add_subdirectory(external/JUCE)
add_subdirectory(src)

