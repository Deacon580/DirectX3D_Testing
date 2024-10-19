#pragma once
#include "Window.h"
#include "myTimer.h"

class App {
public:
	App();
	int Go();
	~App();
private:
	void DoFrame();
private:
	Window wnd;
	MyTimer timer;
	std::vector<std::unique_ptr<class Box>> boxes;
};
