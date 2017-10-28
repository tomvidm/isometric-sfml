add_subdirectory(modules)
add_subdirectory(common)

include_directories(
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/includes
    ${SFML_INCLUDE_DIR}
    )

set(SOURCES 
    main.cpp
    )

set(LIBRARIES
# common
    vector
    debugging
    physics
    )

add_executable(main ${SOURCES})

target_link_libraries(
    main 
    ${COMMON_LIBRARIES} 
    ${LIBRARIES}
    )