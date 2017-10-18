#pragma once

#include "WindowManager.h"
#include <GLFW/glfw3.h>

struct InputManager
{
	int Init()
	{
		glfwSetInputMode(windowManager.window, GLFW_STICKY_KEYS, GL_TRUE);
		return 0;
	}
} inputManager;