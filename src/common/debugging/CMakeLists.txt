include_directories(
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/includes
    )

set(SOURCES
    ValueField.cpp
    )

add_library(debugging ${SOURCES})

target_link_libraries(
    debugging
    ${COMMON_LIBRARIES} 
    )