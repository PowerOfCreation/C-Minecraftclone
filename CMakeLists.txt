cmake_minimum_required(VERSION 3.5)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "Generate installation target" FORCE)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_library(GLEW_LIBRARY NAMES glew.lib glew32.lib libglew.a libglew32.a PATH_SUFFIXES lib64 libx32)
add_subdirectory(glfw)

set( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++" )

include_directories(
	${OPENGL_INCLUDE_DIRS}
	glfw/include
)
set (CMAKE_CXX_STANDARD 11)
add_definitions(-DGLEW_STATIC)
add_executable(main Main.cpp texture.cpp shader.cpp FastNoise.cpp)
target_link_libraries(main
	glfw
	${GLEW_LIBRARY}
	${OPENGL_LIBRARIES}
)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/vertex.glsl ${CMAKE_CURRENT_BINARY_DIR}/vertex.glsl COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/fragment.glsl ${CMAKE_CURRENT_BINARY_DIR}/fragment.glsl COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dirt.bmp ${CMAKE_CURRENT_BINARY_DIR}/dirt.bmp COPYONLY)
