#include "pch.h"

WCHAR WindowClass[MAX_NAME_STRING];
WCHAR WindowTitle[MAX_NAME_STRING];

INT WindowWidth;
INT WindowHeight;

LRESULT CALLBACK ProcessWindow(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, message, wparam, lparam);
}

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	// Init global variables

	wcscpy_s(WindowClass, TEXT("ZeusEngineClass"));
	wcscpy_s(WindowTitle, TEXT("Zeus Engine Test"));
	WindowHeight = 768;
	WindowWidth = 1366;

	// Window class init

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);

	wcex.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

	wcex.lpszClassName = WindowClass;

	wcex.lpszMenuName = nullptr;

	wcex.hInstance = HInstance();

	wcex.lpfnWndProc = ProcessWindow;

	RegisterClassEx(&wcex);

	// Create and displaying window
	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
							0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);

	if (!hWnd)
	{
		// Something went wrong during creation, exit
		// TODO: Better communication method for why its shutdown later (Logger)
		MessageBox(nullptr, L"Failed To Create The Window!", nullptr, 0);
		return 0;
	}

	ShowWindow(hWnd, SW_SHOW);

	// Message events

	MSG msg = {nullptr};
	while (msg.message != WM_QUIT)
	{
		// If any window messages, process them
		// Non-blocking
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}