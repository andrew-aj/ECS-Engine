cmake_minimum_required(VERSION 3.16)
project(ClockworkEngine VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()
find_library(GLFW glfw3)
#find_library(GLM glm_static)
include_directories(include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")

file(GLOB ClockworkEngine "src/*.cpp" "src/*.c" "src/Main/*.cpp" "src/OpenGL/*.cpp" "src/Rendering/*.cpp" "include/*.h" "include/Main/*.h" "include/OpenGL/*.h" "include/Rendering/*.h")
add_executable(ClockworkEngine ${ClockworkEngine})
target_link_libraries(ClockworkEngine ${GLFW} )#${GLM})

include(CPACK)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})