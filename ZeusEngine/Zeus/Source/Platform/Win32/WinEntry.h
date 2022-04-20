#include "Zeus.h"
#include "IApplication.h"

extern IApplication* EntryApplication();

INT CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	auto EntryApp = EntryApplication();

	EntryApp->Initialize();

	MSG msg = { nullptr };
	while (msg.message != WM_QUIT)
	{
		// If any window messages, process them
		// Non-blocking
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			EntryApp->Update();
		}
	}

	return 0;
}
