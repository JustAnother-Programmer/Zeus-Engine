#include "pch.h"
#include "Application.h"
#include "Platform/Win32/WinEntry.h"

ENTRYAPP(Application)

Application::Application()
{
	
}

Application::~Application()
{
	
}

VOID Application::Initialize()
{
	MessageBox(nullptr, L"Init called", nullptr, 0);
}

VOID Application::Update()
{
	MessageBox(nullptr, L"Update called", nullptr, 0);
}
