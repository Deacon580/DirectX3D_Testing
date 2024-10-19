#pragma once
#include "Window.h"
#include "myTimer.h"

class App {
public:
	App();
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	MyTimer timer;
};
