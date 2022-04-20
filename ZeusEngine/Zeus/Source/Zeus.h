#pragma once

// TODO: Other platform support possibly
#ifdef WIN32

#include <Windows.h>

#endif

#ifdef BUILD_DLL
	#define ZEUS_API __declspec(dllexport)
#else
	#define ZEUS_API __declspec(dllimport)
#endif