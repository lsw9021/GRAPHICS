cmake_minimum_required(VERSION 2.8.6)
project(Homework)
add_compile_options(-std=gnu++11)
add_compile_options(-Wno-deprecated-declarations)
#set( CMAKE_VERBOSE_MAKEFILE on )

find_package(Eigen3 REQUIRED)
find_package(glm REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${EIGEN3_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${GLUT_INCLUDE_DIR})
include_directories(${glm_INCLUDE_DIR})


file(GLOB srcs "*.cpp" "*.h")

add_executable(Homework ${srcs})
target_link_libraries(Homework ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
