cmake_minimum_required(VERSION 3.10)
project(BowlingScoreCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Cmake variables
set(EXECUTABLE_CALCULATOR_FILE ${PROJECT_NAME}Exe)
set(TEST_NAME ${PROJECT_NAME}-Tests)
set(EXECUTABLE_TEST_FILE ${PROJECT_NAME}-TestsExe)

#cpp files for BowlingScoreCalculator compilation
set(CALCULATOR_SOURCE_FILES
    calculator.cpp
    )
#cpp files for BowlingScoreCalculator-Tests compilation

enable_testing()
add_test(NAME ${TEST_NAME} COMMAND ${EXECUTABLE_TEST_FILE})

add_library(lib STATIC ${CALCULATOR_SOURCE_FILES} )
add_executable(${EXECUTABLE_CALCULATOR_FILE} main.cpp)
add_executable(${EXECUTABLE_TEST_FILE} ./tests/test.cpp)
target_link_libraries(${EXECUTABLE_CALCULATOR_FILE} lib)
target_link_libraries(${EXECUTABLE_TEST_FILE} lib)
target_compile_options(${EXECUTABLE_CALCULATOR_FILE} PRIVATE -Wall -Wextra -Werror)
target_compile_options(${EXECUTABLE_TEST_FILE} PRIVATE -Wall)



