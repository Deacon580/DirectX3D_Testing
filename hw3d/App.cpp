#include "App.h"
#include <sstream>
#include <iomanip>

App::App()
	:
	wnd(800, 600, L"First Game")

{}

int App::Go() {
	
	while (true) {
		if (const auto ecode = Window::ProccessMessages()) {
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame() {
	const float t = timer.Peek();
	std::wstringstream oss;
	oss << "Time elapsed: " << std::setprecision(1) << std::fixed << t << "s";
	wnd.SetTitle(oss.str());
	wnd.Gfx().ClearBuffer(0.0f, 0.5f, 0.0f);
	wnd.Gfx().DrawTestTriangle(
		-timer.Peek(),
		0.0f,
		0.0f
	);
	wnd.Gfx().DrawTestTriangle(timer.Peek(),
		wnd.mouse.GetPosX() / 400.0f - 1.0f,
		-wnd.mouse.GetPosY() / 300.0f + 1.0f
	);
	wnd.Gfx().EndFrame();
}