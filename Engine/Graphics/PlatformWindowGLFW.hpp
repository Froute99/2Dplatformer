/**************************************************************************************
 *	File Name        : PlatformWindowGLFW.cpp
 *	Project Name     : 2D Platformer Engine
 *	Author           : JeongHak Kim
 **************************************************************************************/

#pragma once
#include "EventHandler.hpp"
#include "glfw3.h"

class PlayformWindow {
public:
	GLFWwindow* window;

	bool CanCreateWindow(int width, int height, EventHandler* eventHandler, const char* title) noexcept;
	
	void SwapBuffers() noexcept;
	void PollEvents() noexcept;

	bool IsVsyncOn() noexcept;
	void ToggleVsync() noexcept;

	bool IsFullScreen() noexcept;
	void ToggleFullScreen() noexcept;

	int GetWindowWidth() const noexcept;
	int GetWindowHeight() const noexcept;
	void SetWindowWidth(int newWidth) noexcept;
	void SetWindowHeight(int newHeight) noexcept;
private:
	bool isVsyncOn = false;
	bool isFullScreen = false;
	
	int windowPos[2] = { 0,0 };
	int windowSize[2] = { 0,0 };
	int windowPosBackup[2] = { 0,0 };
	int windowSizeBackup[2] = { 0,0 };
};