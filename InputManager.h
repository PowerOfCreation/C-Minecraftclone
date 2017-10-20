#pragma once

#include "WindowManager.h"
#ifdef __linux__ 
#include <GLFW/glfw3.h>
#elif _WIN32
#include "GLFW/glfw3.h"
#endif


struct InputManager
{
	int Init()
	{
		glfwSetInputMode(windowManager.window, GLFW_STICKY_KEYS, GL_TRUE);
		return 0;
	}
} inputManager;