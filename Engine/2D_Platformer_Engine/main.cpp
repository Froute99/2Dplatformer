/**************************************************************************************
 *	File Name        : main.cpp
 *	Project Name     : 2D Platformer Engine
 *	Author           : JeongHak Kim
 **************************************************************************************/

#include <iostream>
#include <GL/glew.h>
#include <glfw3.h>

namespace {
	const int WINDOW_WIDTH = 1280;
	const int WINDOW_HEIGHT = 720;
	const char* WINDOW_TITLE = "2D_Platformer";
}

int main() {

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// initialize glfw, shut down when it failed.
	if (!glfwInit()) {
		glfwTerminate();
		return false;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RED_BITS, 8);
	glfwWindowHint(GLFW_GREEN_BITS, 8);
	glfwWindowHint(GLFW_BLUE_BITS, 8);

	GLFWmonitor* monitor = nullptr;
	GLFWwindow* shareWindow = nullptr;

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, monitor, shareWindow);

	// check window valid, shut down when it failed
	if (!window) {
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);

	// TODO: some callback functions


	// initialize glew, print message when it failed
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		std::cerr << glewGetErrorString(err);
		return false;
	}



	// main loop
	bool isRunning = true;
	while (isRunning) {
		// escape key to turn off.
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

}
