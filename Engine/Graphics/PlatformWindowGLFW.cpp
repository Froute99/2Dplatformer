/**************************************************************************************
 *	File Name        : PlatformWindowGLFW.cpp
 *	Project Name     : 2D Platformer Engine
 *	Author           : JeongHak Kim
 **************************************************************************************/

#include "glew.h"
#include "PlatformWindowGLFW.hpp"

EventHandler* eventHandler;

bool PlayformWindow::CanCreateWindow(int width, int height, EventHandler* eventHandlerPtr, const char* title) noexcept
{
	eventHandler = eventHandlerPtr;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

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

	window = glfwCreateWindow(width, height, title, monitor, shareWindow);

	if (!window) {
		glfwTerminate();
		return false;
	}

	ToggleVsync();
	windowSize[0] = width;
	windowSize[1] = height;

	glfwMakeContextCurrent(window);

}

void PlayformWindow::SwapBuffers() noexcept
{
	glfwSwapBuffers(window);
}

void PlayformWindow::PollEvents() noexcept
{
	glfwPollEvents();
}

bool PlayformWindow::IsVsyncOn() noexcept
{
	return isVsyncOn;
}

void PlayformWindow::ToggleVsync() noexcept
{
}

bool PlayformWindow::IsFullScreen() noexcept
{
	return isFullScreen;
}

void PlayformWindow::ToggleFullScreen() noexcept
{
}

int PlayformWindow::GetWindowWidth() const noexcept
{
	return windowSize[0];
}

int PlayformWindow::GetWindowHeight() const noexcept
{
	return windowSize[1];
}

void PlayformWindow::SetWindowWidth(int newWidth) noexcept
{
	windowSize[0] = newWidth;
}

void PlayformWindow::SetWindowHeight(int newHeight) noexcept
{
	windowSize[1] = newHeight;
}
