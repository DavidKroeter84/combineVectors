# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G ${CMAKE_GENERATOR} .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include(GoogleTest)

enable_testing()

# Test sources
set(${PROJECT_NAME}_TEST_HEADERS 
    ${CMAKE_SOURCE_DIR}/src/combine_vectors.h)


set(${PROJECT_NAME}_TEST_SOURCES
    ${CMAKE_SOURCE_DIR}/src/combine_vectors.cpp
    ${CMAKE_SOURCE_DIR}/tst/combine_vectors_test.cpp)

add_executable(combineVectors_test
               ${${PROJECT_NAME}_TEST_HEADERS}
               ${${PROJECT_NAME}_TEST_SOURCES})   

# Link test executable against gtest & gtest_main
target_link_libraries(combineVectors_test gtest gtest_main)

# Add all tests
gtest_discover_tests(${PROJECT_NAME}_test)