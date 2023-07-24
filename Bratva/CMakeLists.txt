add_subdirectory(Deps/glfw/)
add_subdirectory(Deps/glew-2.2.0/build/cmake/)

file(GLOB RendererSources src/renderer/*.hpp)

message(STATUS "Files: ${RendererSources}")

add_library(Bratva
    src/Window.cpp include/Window.hpp
    src/GameInstance.cpp include/GameInstance.hpp
    src/ecs/Entities.cpp include/ecs/Entities.hpp
    src/renderer/Shaders.cpp include/renderer/Shaders.hpp
    src/renderer/Buffer.cpp include/renderer/Buffer.hpp
    src/renderer/Triangle.cpp include/renderer/Triangle.hpp
    src/util/Vec4.cpp include/util/Vec4.hpp
    include/Debug.hpp
)

target_include_directories(Bratva PUBLIC include/)
target_include_directories(Bratva PUBLIC Deps/glfw/include/)
target_include_directories(Bratva PUBLIC Deps/glew-2.2.0/include/)
target_link_libraries(Bratva glfw)
target_link_libraries(Bratva glew_s)

if (APPLE)
    message(STATUS "Using Apple")
    target_link_libraries(Bratva "-framework OpenGL")
elseif (UNIX)
    message(STATUS "Using UNIX")
    target_link_libraries(Bratva libGL.so)
else()
    message(STATUS "Using Windows")
    target_link_libraries(Bratva opengl32)
endif()
