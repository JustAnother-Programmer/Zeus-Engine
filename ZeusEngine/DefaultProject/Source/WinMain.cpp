/* Filename: WinMain.cpp
 * Author: JustAnotherProgrammer
 * Created 2022
*/

#include "pch.h"

// Global Variables
#pragma region GlobalVariables

WCHAR WindowClass[MAX_NAME_STRING];
WCHAR WindowTitle[MAX_NAME_STRING];

INT WindowWidth;
INT WindowHeight;

HICON hIcon;

#pragma endregion

// Forward declarations
#pragma region Pre-Declarations

VOID InitializeVariables();
VOID CreateWindowClass();
VOID InitializeWindow();
VOID BeginMessageLoop();
LRESULT CALLBACK ProcessWindow(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam);

#pragma endregion

// Operations
#pragma region Operations

/* int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	InitializeVariables();

	CreateWindowClass();

	InitializeWindow();

	BeginMessageLoop();

	return 0;
} */

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

#pragma endregion


#pragma region Functions

// Initialize Global Variables
VOID InitializeVariables()
{
	LoadString(HInstance(), IDS_PERGAMENAME, WindowTitle, MAX_NAME_STRING);
	LoadString(HInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING);

	WindowHeight = 768;
	WindowWidth = 1366;

	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON));
}

// Create the Main Window Class
VOID CreateWindowClass()
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);

	wcex.hIcon = hIcon;
	wcex.hIconSm = hIcon;

	wcex.lpszClassName = WindowClass;

	wcex.lpszMenuName = nullptr;

	wcex.hInstance = HInstance();

	wcex.lpfnWndProc = ProcessWindow;

	RegisterClassEx(&wcex);
}

VOID InitializeWindow()
{
	const HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
		0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);

	if (!hWnd)
	{
		// Something went wrong during creation, exit
		// TODO: Better communication method for why its shutdown later (Logger)
		MessageBox(nullptr, L"Failed To Create The Window!", nullptr, 0);
		PostQuitMessage(0);
	}

	ShowWindow(hWnd, SW_SHOW);
}

VOID BeginMessageLoop()
{
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
}

#pragma endregion