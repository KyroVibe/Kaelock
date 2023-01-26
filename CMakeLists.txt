cmake_minimum_required(VERSION 3.12)
project(Kaelock VERSION 1.0.0)

add_subdirectory(Bratva)

add_executable(Kaelock src/Pong.cpp)

#target_include_directories(Kaelock PRIVATE Bratva/include/)
target_link_libraries(Kaelock Bratva)
