add_library(Bernard
    src/NeuralNetwork.cpp
)

target_include_directories(Bernard PUBLIC include/)

# target_include_directories(Bratva PUBLIC include/)
# target_include_directories(Bratva PUBLIC Deps/glfw/include/)
# target_include_directories(Bratva PUBLIC Deps/glew-2.2.0/include/)
# target_link_libraries(Bratva glfw)
# target_link_libraries(Bratva glew_s)
# if (UNIX)
#     target_link_libraries(Bratva libGL.so)
# else()
#     target_link_libraries(Bratva opengl32)
# endif()
