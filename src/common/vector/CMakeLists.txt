include_directories(
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/includes
    ${SFML_INCLUDE_DIR}
    )

set(SOURCES
    Vector.cpp
    )

add_library(vector ${SOURCES})

target_link_libraries(
    vector
    ${COMMON_LIBRARIES} 
    )