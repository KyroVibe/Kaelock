cmake_minimum_required(VERSION 3.12)

set(CXX_STANDARD 11)

project(Kaelock VERSION 1.0.0)

add_subdirectory(Bratva)

add_executable(Kaelock src/Pong.cpp)

#target_include_directories(Kaelock PRIVATE Bratva/include/)
target_link_libraries(Kaelock Bratva)

add_custom_target(Resources
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/Res/
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Res ${CMAKE_BINARY_DIR}/Res
        COMMENT "copying ${CMAKE_SOURCE_DIR}/Res to ${CMAKE_BINARY_DIR}/Res"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
add_dependencies(Kaelock Resources)
