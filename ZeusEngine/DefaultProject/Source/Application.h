#pragma once

class Application
{
public:
	Application();
	~Application();

public:
	// Called to initialize the application
	VOID Initialize();

	// Called on a loop when the application is running
	VOID Update();
};