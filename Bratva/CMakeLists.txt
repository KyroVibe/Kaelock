add_subdirectory(Deps/glfw/)
add_subdirectory(Deps/glew-2.2.0/build/cmake/)
add_library(Bratva
    src/Window.cpp include/Window.hpp
    src/GameInstance.cpp include/GameInstance.hpp
    src/ecs/Entitys.cpp include/ecs/Entitys.hpp
)

target_include_directories(Bratva PUBLIC include/)
target_include_directories(Bratva PUBLIC Deps/glfw/include/)
target_include_directories(Bratva PUBLIC Deps/glew-2.2.0/include/)
target_link_libraries(Bratva glfw)
target_link_libraries(Bratva glew_s)
if (UNIX)
    target_link_libraries(Bratva libGL.so)
else()
    target_link_libraries(Bratva opengl32)
endif()
