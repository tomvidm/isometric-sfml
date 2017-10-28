cmake_minimum_required(VERSION 3.0)

project(Pierogi)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

message(STATUS ${SFML_ROOT})

# Find packages
find_package(SFML 2.4 REQUIRED system window graphics network audio)

set(COMMON_LIBRARIES
    ${SFML_LIBRARIES}
    )

# Add subdirectories
add_subdirectory(src)