cmake_minimum_required(VERSION 3.16)
project(ClockworkEngine VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()
#find_library(GLFW glfw3)
#find_library(GLM glm_static)
include_directories(include)

file(GLOB ClockworkEngine "src/*.cpp" "src/*.c" "include/*.h")
add_executable(ClockworkEngine ${ClockworkEngine})
#target_link_libraries(ClockworkEngine ${GLFW} ${GLM})

include(CPACK)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})