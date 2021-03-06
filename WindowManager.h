#pragma once

#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__ 
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#elif _WIN32
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#else

#endif


struct WindowManager
{
	GLFWwindow* window;

	int InitWindow()
	{
		// Initialise GLFW
		if (!glfwInit())
		{
			fprintf(stderr, "Failed to initialize GLFW\n");
			return -1;
		}

		glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

																	   // Open a window and create its OpenGL context
		window = glfwCreateWindow(1024, 768, "Minecraft Clone", NULL, NULL);
		if (window == NULL) {
			fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window); // Initialize GLEW
		glewExperimental = true; // Needed in core profile
		if (glewInit() != GLEW_OK) {
			fprintf(stderr, "Failed to initialize GLEW\n");
			return -1;
		}
		
		return 0;
	}
} windowManager;