cmake_minimum_required(VERSION 3.5)

add_definitions(-DGLEW_STATIC)

set (CMAKE_CXX_STANDARD 11)
add_executable(main Main.cpp texture.cpp shader.cpp FastNoise.cpp)
find_package(OpenGL REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} )

IF (WIN32)
  target_link_libraries(main ${CMAKE_CURRENT_SOURCE_DIR}/GLEW_1130.lib ${CMAKE_CURRENT_SOURCE_DIR}/glfw3.lib ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${X11_LIBRARIES})
 configure_file(${CMAKE_CURRENT_SOURCE_DIR}/vertex.glsl ${CMAKE_CURRENT_BINARY_DIR}/Debug/vertex.glsl COPYONLY)
 configure_file(${CMAKE_CURRENT_SOURCE_DIR}/fragment.glsl ${CMAKE_CURRENT_BINARY_DIR}/Debug/fragment.glsl COPYONLY)
 configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dirt.bmp ${CMAKE_CURRENT_BINARY_DIR}/Debug/dirt.bmp COPYONLY)
ELSE()
  include_directories( ${X11_INCLUDE_DIRS} )
  find_package(X11 REQUIRED)
  target_link_libraries(main ${CMAKE_CURRENT_SOURCE_DIR}/libGLEW.a ${CMAKE_CURRENT_SOURCE_DIR}/libglfw3.a ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${X11_LIBRARIES} X11 Xxf86vm pthread dl Xrandr Xinerama Xcursor)
ENDIF()
