set(${PROJECT_NAME}_HEADERS 
    ${CMAKE_CURRENT_SOURCE_DIR}/combine_vectors.h)


set(${PROJECT_NAME}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/combine_vectors.cpp)

# Add executable target with source files listed in SOURCE and HEADER variables
add_executable(combineVectors ${${PROJECT_NAME}_HEADERS}
                             ${${PROJECT_NAME}_SOURCES})

install(TARGETS combineVectors)                      