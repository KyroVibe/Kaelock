add_subdirectory(Deps/glfw/)
add_library(Bratva src/Window.cpp include/Window.hpp)

target_include_directories(Bratva PUBLIC include/)
target_include_directories(Bratva PUBLIC Deps/glfw/include/)
target_link_libraries(Bratva glfw)
target_link_libraries(Bratva opengl32)
