cmake_minimum_required(VERSION 3.12)
project(Kaelock VERSION 1.0.0)

option(BUILD_TEST "Build test executable" OFF)

add_subdirectory(Bratva)

add_executable(Kaelock src/Pong.cpp)

#target_include_directories(Kaelock PRIVATE Bratva/include/)
target_link_libraries(Kaelock Bratva)



if (BUILD_TEST)
    add_executable(Test test/Test.cpp test/BratvaTest.hpp)
    target_link_libraries(Test Bratva)
endif()
