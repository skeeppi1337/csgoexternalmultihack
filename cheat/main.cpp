#include "gui.h"
#include "memory.h"
#include <iostream>
#include "globals.h"
#include <thread>
#include "hacks.h"
#include <vector>
#include "vector.h"

int __stdcall wWinMain(
	HINSTANCE instance,
	HINSTANCE previousInstance,
	PWSTR arguments,
	int commandShow)
{
	// create gui
	gui::CreateHWindow("skeephook");
	gui::CreateDevice();
	gui::CreateImGui();

	//memory class

	auto mem = Memory{ "csgo.exe" };
	
	globals::clientAddress = mem.GetModuleAddress("client.dll");
	globals::engineAddress = mem.GetModuleAddress("engine.dll");

	std::cout << "client address: " << mem.GetModuleAddress("client.dll") << std::endl;
	std::cout << "engine address: " << mem.GetModuleAddress("engine.dll") << std::endl;

	std::thread(hacks::cheatThread, mem).detach(); //heräte cheateille

	while (gui::isRunning)
	{
		gui::BeginRender();
		gui::Render();
		gui::EndRender();

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

	// destroy gui
	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyHWindow();

	return EXIT_SUCCESS;
}
