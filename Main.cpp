#include "WindowManager.h"
#include "InputManager.h"
#include "DrawManager.h"

int main()
{

	windowManager.InitWindow();

	inputManager.Init();

	drawManager.Init();
		
	do 
	{
		drawManager.Draw();
		glfwSwapBuffers(windowManager.window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(windowManager.window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(windowManager.window) == 0);

	return 0;
}