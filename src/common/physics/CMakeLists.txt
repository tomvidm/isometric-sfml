include_directories(
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/includes
    ${SFML_INCLUDE_DIR}
    )

set(SOURCES
    Strandbeest.cpp
    Leg.cpp
    Joint.cpp
    )

add_library(physics ${SOURCES})

target_link_libraries(
    physics
    ${COMMON_LIBRARIES} 
    )